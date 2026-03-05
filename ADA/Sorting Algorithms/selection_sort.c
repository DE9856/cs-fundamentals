#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000
int arr[MAX];
clock_t start,end;

void sort(int arr[], int n){
	for(int i=0;i<=n-2;i++){
		int min = i;
		for(int j=i+1;j<=n-1;j++){
			if (arr[j]<arr[min])
				min = j;
		}	
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

int main(){
	int n;
	printf("Enter number of values to be sorted: ");
	scanf("%d", &n);
	
	printf("\nValues being entered into the array\n");
	for(int i=0;i<n;i++)
		arr[i] = random()%(n*2);
		
		
	start = clock();
	sort(arr, n);
	end = clock();
	
	printf("The time taken is: %lfms\n",(double)(end-start)/(double)(CLOCKS_PER_SEC)*1000);
	
	return 0;
}
