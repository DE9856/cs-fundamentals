#include <stdio.h>
int fr[3];

void display(){
  for(int i=0;i<3;i++)
    printf("%d\t",fr[i]);
  printf("\n");
}

int main(){
  int n,i,j,found,page[50], last[3], pf = 0, t=0;
  printf("Enter the number of pages: ");
  scanf("%d", &n);
  printf("Enter the page numbers: ");
  for(i=0;i<n;i++)
    scanf("%d", &page[i]);
  for(i=0;i<3;i++){
    fr[i] = -1;
    last[i] = -1;
  }
  
  for(i=0;i<n;i++){
    found = 0;
    t++;
    for(int j=0;j<3;j++){
      if(page[i]==fr[j]){
        found = 1;
        last[j] = t;
      }
    }
    if(!found){
      int k=0;
      for(j=0;j<3;j++){
        if(fr[j]==-1){
          k = j;
          break;
        }
        else if(last[j]<last[k])
          k = j;
      }
      fr[k] = page[i];
      last[k] = t;
      pf++;
    }
    display();
  }
  printf("The number of page faults are: %d\n",pf);
  return 0;
}
