#include <stdio.h>
#include <stdlib.h>
int board[20], n,count;

int place(int row, int col){
    for(int i =0;i<row;i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return 0;
    }
    return 1;
}

void print(){
    printf("\nSolution %d: ", ++count);
    for(int i =0;i<n;i++)
        printf("%d ", board[i]);
    printf("\n");

    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%s ", board[i]==j ? "Q": ".");
        }
        printf("\n");
    }
}

void queen(int row){
    for(int col = 0;col<n;col++){
        if(place(row,col)){
            board[row] = col;
            if(row==n-1)
                print();
            else
                queen(row+1);
        }
    }
}

void main(){
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    queen(0);

    printf("Total Solution: %d", count);
}
