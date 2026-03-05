#include <stdio.h>

int main(){
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements into the array: ");
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
  }

  //BUBBLE SORT
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(a[j]>a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }

  printf("The Sorted Array is: ");
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
