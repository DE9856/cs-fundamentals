#include <stdio.h>
int fr[3];

void display(){
  for(int i=0;i<3;i++)
    printf("%d\t",fr[i]);
  printf("\n");
}

int main(){
  int n,page[50],i,j,found,pf=0,top=0;
  printf("Enter the number of pages: ");
  scanf("%d", &n);
  printf("Enter the page numbers: ");
  for(int i=0;i<12;i++)
    scanf("%d", &page[i]);
  for(i=0;i<3;i++){
    fr[i] = -1;
  }
  for(i=0;i<n;i++){
    found =0;
    for(j=0;j<3;j++){
      if(page[i]==fr[j]){
        found = 1;
        break;
      }
    }
    if(!found){
      fr[top] = page[i];
      top = (top+1)%3;
      pf++;
    }
  display();
  }
  printf("The number of page faults are: %d\n",pf);
}
