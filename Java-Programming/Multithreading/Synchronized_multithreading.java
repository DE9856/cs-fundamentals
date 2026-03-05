//Producer Class
class Producer extends Thread {
    Message m;

    Producer(Message m) {
        this.m = m;
    }

    public void run() {
        m.produce("Hello from Producer");
    }
}


//Consumer Class
class Consumer extends Thread {
    Message m;

    Consumer(Message m) {
        this.m = m;
    }

    public void run() {
        m.consume();
    }
}

//Methods
class Message {
    private String msg;
    private boolean empty = true;
    // Producer method
    synchronized void produce(String message) {
        while (!empty) {
            try {
                wait();   // wait until message is consumed
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        msg = message;
        empty = false;
        System.out.println("Produced: " + msg);
        notify();  // notify consumer
    }
    // Consumer method
    synchronized void consume() {
        while (empty) {
            try {
                wait();   // wait until message is produced
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Consumed: " + msg);
        empty = true;
        notify();  // notify producer
    }
}

//Main.java
public class ThreadMessagingDemo {
    public static void main(String[] args) {
        Message m = new Message();

        Producer p = new Producer(m);
        Consumer c = new Consumer(m);

        p.start();
        c.start();
    }
}
