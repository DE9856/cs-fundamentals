#include <stdio.h>
struct Directory{
  char name[20],sd[20][20],filename[20][20][20];
  int sdcount,filecount;
};

int main(){
  int n,i,j,k;
  printf("Enter the number of directories: ");
  scanf("%d", &n);
  struct Directory d[n];
  
  for(i=0;i<n;i++){
    printf("Directory %d: ",i+1);
    printf("\nEnter the directory name: ");
    scanf("%s",d[i].name);
    
    printf("\nEnter the number of subdirectories: ");
    scanf("%d", &d[i].sdcount);
    for(j=0;j<d[i].sdcount;j++){
      printf("\nSubdirectory %d: ",j+1);
      printf("\nEnter subdirectory name: ");
      scanf("%s", d[i].sd[j]);
      printf("Enter the number of files: ");
      scanf("%d", &d[i].filecount);
      printf("Enter the filenames: ");
      for(k=0;k<d[i].filecount;k++)
        scanf("%s", d[i].filename[j][k]);
    }
  }
  
  printf("\n\nDirectory\t\tSize\t\tSubdirectory\t\tSize\t\tFiles\n");
  for(i=0;i<n;i++){
    printf("\n%s\t\t%d",d[i].name, d[i].sdcount);
    for(j=0;j<d[i].sdcount;j++){
      printf("\t\t%s\t\t%d",d[i].sd[j],d[i].filecount);
      for(k=0;k<d[i].filecount;k++){
        printf("\t\t\t\t\t\t%s",d[i].filename[j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
