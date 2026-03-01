#include <stdio.h>
#include <stdlib.h>
int *ht, m;
int count = 0;

void insert(int key){
  int idx = key%m;
  while(ht[idx]!=-1)
    idx = (idx+1)%m;
  ht[idx] = key;
  count++;
}

void display(){
  if(count==0){
    printf("The Hash Table is empty");
    return;
  }
  printf("Hash Table Contents: \n");
  for(int i=0;i<m;i++)
    printf("\nht[%d] -> %d",i,ht[i]);
}

void search(int key){
    int idx = key % m;
    int start = idx;

    while(ht[idx] != -1){
        if(ht[idx] == key){
            printf("Key found at index %d\n", idx);
            return;
        }
        idx = (idx+1)%m;
        if(idx == start)
            break;
    }

    printf("Key not found\n");
}

int main(){
    FILE *fp;
    int key, n, choice;

    printf("Enter the number of records: ");
    scanf("%d", &n);

    printf("Enter the memory size for hash table: ");
    scanf("%d", &m);

    ht = (int*)malloc(m * sizeof(int));

    for(int i = 0; i < m; i++)
        ht[i] = -1;

    fp = fopen("a.txt", "r");

    if(fp == NULL){
        printf("Error opening file\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        if(count == m){
            printf("Hash Table is full\n");
            break;
        }
        fscanf(fp, "%d", &key);
        insert(key);
    }
    fclose(fp);
    while(1){
        printf("\n\nHASH TABLE MENU\n");
        printf("1. Display\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                display();
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                free(ht);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
