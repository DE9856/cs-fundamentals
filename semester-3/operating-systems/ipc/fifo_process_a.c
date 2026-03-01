#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
  mkfifo("AtoB",0666);
  mkfifo("BtoA",0666);
  int fd_write = open("AtoB",O_WRONLY);
  int fd_read = open("BtoA",O_RDONLY);
  char send[100],recv[100];
  while(1){
    printf("A: ");
    fgets(send,100,stdin);
    write(fd_write,send,100);
    read(fd_read,recv,100);
    printf("B: %s",recv);
  }
  close(fd_read);
  close(fd_write);
  return 0;
}
