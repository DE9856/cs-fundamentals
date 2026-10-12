//Server Code First
//Name this UDPServer.java
import java.net.*;
import java.util.Scanner;
public class UDPServer{
    public static void main(String[] args) throws Exception{
        DatagramSocket serverSocket = new DatagramSocket();
        InetAddress clientAddress = InetAddress.getByName("localhost");
        Scanner sc = new Scanner(System.in);
        System.out.println("Server is ready. Type messages to send to client: ");
        while(true){
            System.out.println("Server: ");
            String message = sc.nextLine();
            byte[] buffer = message.getBytes();
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length, clientAddress, 9876);
            serverSocket.send(packet);
            if(message.equalsIgnoreCase("exit")){
                break;
            }        
        }
        serverSocket.close();
        System.out.println("Server Closed");
    }
}


//Client Code Next
//Name this UDPClient.java
import java.net.*;
public class UDPClient{
    public static void main(String[] args) throws Exception{
        DatagramSocket clientSocket = new DatagramSocket(9876);
        byte[] buffer = new byte[1024];
        System.out.println("Client is running...Waiting for server messages. \n");
        while(true){
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            clientSocket.receive(packet);
            String message = new String(packet.getData(), 0, packet.getLength());
            if(message.equalsIgnoreCase("exit")){
                break;
            }    
            System.out.println("Message from Server: "+ message);
      
        }
        clientSocket.close();
        System.out.println("Client Closed");
    }
}

