#include <stdio.h>
#define MAX 25

int main(){
  int block[MAX], file[MAX], frag[MAX],alloc[MAX], used[MAX] = {0};
  int nb,nf,i,j,worst,max;
  
  printf("Enter the number of blocks: ");
  scanf("%d", &nb);
  printf("Enter the number of files: ");
  scanf("%d", &nf);
  
  printf("Enter the sizes of the blocks: ");
  for(i=0;i<nb;i++)
    scanf("%d", &block[i]);
    
  printf("Enter the sizes of the files: ");
  for(i=0;i<nf;i++){
    scanf("%d", &file[i]);
    alloc[i] = -1;
  }
  
  for(i=0;i<nf;i++){
    max = -1, worst = -1;
    for(j=0;j<nb;j++){
      if(!used[j] && block[j]>=file[i] && block[j] - file[i]>=max){
        max = block[j] - file[i];
        worst = j;
      }
    }
    if(worst!=-1){
      alloc[i] = worst;
      frag[i] = max;
      used[worst] = 1;
    }
    else
      frag[i] = -1;
  }
  
  printf("\nFile No.\t\tFile Size.\t\tBlock No.\t\tBlock Size.\t\tFragment");
  for(i=0;i<nf;i++){
    if(alloc[i]!=-1)
      printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",i+1, file[i], alloc[i]+1, block[alloc[i]], frag[i]);
    else
      printf("\n%d\t\t%d\t\tNot Allocated",i+1, file[i]);
  }
  return 0;
}
