#include <stdio.h>
int main(){
  int f[50] = {0};
  int n,a,st,len,c,i;
  printf("Enter no. of blocks already allocated");
  scanf("%d", &n);
  printf("Enter the block numbers: ");
  for(i=0;i<n;i++){
    scanf("%d", &a);
    if(a>=0 && a<50)
      f[a] = 1;
  }
  
  while(1){
    int allocated = 0;
    printf("Enter the starting point and length: ");
    scanf("%d%d", &st, &len);
    for(i=st;i<50 && allocated<len;i++){
      if(f[i]==0){
        f[i] = 1;
        printf("\n%d -> %d",i,f[i]);
        allocated++;
      }
      else
        printf("\n%d -> Already Allocated",i);
    }
    printf("Do you want to add more files? (yes-1, no-0)");
    scanf("%d", &c);
    if(c==0) break;
  }
  return 0;
}
