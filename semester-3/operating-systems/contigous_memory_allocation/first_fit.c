#include <stdio.h>
#define MAX 25
int main(){
  int block[MAX], file[MAX], frag[MAX], used[MAX] = {0}, alloc[MAX];
  int nb,nf,i,j;
  
  printf("Enter the number of blocks: ");
  scanf("%d", &nb);
  printf("Enter the number of files: ");
  scanf("%d", &nf);
  printf("Enter the sized of the blocks: ");
  for(i=0;i<nb;i++)
    scanf("%d", &block[i]);
  printf("Enter the sizes of the files: ");
  for(i=0;i<nf;i++){
    scanf("%d", &file[i]);
    alloc[i] = -1;
  }
  
  for(i=0;i<nf;i++){
    for(j=0;j<nb;j++){
      if(!used[j] && block[j]>=file[i]){
        alloc[i] = j;
        frag[i] = block[j] - file[i];
        used[j] = 1;
        break;
      }
    }
    if(alloc[i]==-1)
      frag[i]=-1;
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
