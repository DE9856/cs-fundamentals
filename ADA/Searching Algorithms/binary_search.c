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

  int key;
  printf("Enter the value to be found: ");
  scanf("%d", &key);
  int left = 0, right = n-1;
  //Binary Search
  while(left<=right){
    int mid = (left+right)/2;
    if(key==a[mid]){
      printf("The element is found.");
      return 0;
    }
    else if(key > mid)
      left = mid+1;
    else 
      right = mid-1;
  }
  printf("The element is not found.");
}
