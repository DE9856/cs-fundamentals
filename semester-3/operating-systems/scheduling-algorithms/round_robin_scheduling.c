  #include <stdio.h>
  struct P{
    int pid,at,bt,ct,tat,wt,rt;
  };
  int main(){
    int n,tq;
    float atat=0.0,awt=0.0;
    printf("Enter number of Processes and Time Quantum: ");
    scanf("%d%d",&n,&tq);
    struct P p[n],temp;
    for(int i=0;i<n;i++){
      printf("Enter AT, and BT for Process %d", i+1);
      p[i].pid = i+1;
      scanf("%d%d",&p[i].at,&p[i].bt);
      p[i].rt = p[i].bt;
    }
    for(int i=0;i<n-1;i++){
      for(int j =0;j<n-i-1;j++){
        if(p[j].at>p[j+1].at){
            temp = p[j];p[j] = p[j+1];p[j+1] = temp;
          }
      }
    }
   int q[1000],front=0,rear=0,next=0,completed=0,time=0;
   if(p[0].at>0)
    time = p[0].at;
  while(next<n && p[next].at<time)
    q[rear++] = next++;
  while(completed<n){
    if(front==rear){
      time = p[next].at;
      q[rear++] = next++;
      continue;
    }
    int i = q[front++];
    int exec = (p[i].rt>tq)?tq:p[i].rt;
    p[i].rt-=exec;
    time+=exec;
    while(next<n && p[next].at<=time)
      q[rear++] = next++;
    if(p[i].rt==0){
      p[i].ct = time;
      p[i].tat = p[i].ct - p[i].at;
      p[i].wt = p[i].tat - p[i].bt;
      completed++;
      atat+=p[i].tat;
      awt+=p[i].wt;
    }
    else
      q[rear++] = i;
  }
  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
      for (int i = 0; i < n; i++) {
          printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                 p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
      }
      printf("Average WT = %.2f\n", awt / n);
      printf("Average TAT = %.2f\n", atat / n);
      return 0;
  }
