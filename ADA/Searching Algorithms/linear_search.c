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

  int key;
  printf("Enter the element to be searched: ");
  scanf("%d", &key);

  for(int i=0;i<n;i++){
    if(key==a[i]){
      printf("The element is found.");
      return 0;
    }
  }
  printf("The element is not found.");
}
