#include <stdio.h>
int main(){
  int n,temp;
  printf("Enter number of Processes: ");
  scanf("%d",&n);
  int at[n],bt[n],ct[n],tat[n],wt[n],pid[n];
  float atat = 0.0, awt=0.0;
  printf("Enter Process Details: \n");
  for(int i =0;i<n;i++){
    printf("Process %d\n",i+1);
    printf("Enter PID, AT, and BT:\n");
    scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
  }
  for(int i = 0;i<n-1;i++){
    for(int j = 0;j<n-1-i;j++){
      if(at[j]>at[j+1]){
        temp = at[j];at[j] = at[j+1];at[j+1] = temp;
        temp = bt[j];bt[j] = bt[j+1];bt[j+1] = temp;
        temp = pid[j];pid[j]=pid[j+1]; pid[j+1] = temp;
      }
    }
  }
  int time = 0;
  for(int i = 0;i<n;i++){
    if(time<at[i])
      time = at[i];
    ct[i] = time+bt[i];
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    time = ct[i];
  }
  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
  for(int i =0;i<n;i++)
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i], at[i],bt[i],ct[i],tat[i],wt[i]);
  for(int i =0;i<n;i++){
    atat +=tat[i];
    awt +=wt[i];
  }
  atat/=n;
  awt/=n;
  printf("Average TAT: %f\nAverage WT: %f",atat,awt);
  return 0;
}
