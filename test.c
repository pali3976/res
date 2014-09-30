#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void removeChars(int number, char *buffer){
  memmove(buffer, buffer+number, strlen(buffer));  
}

int main(void){

  int comma = 0;
  char buffer[] = "1321, HRAJSFNKSANFASFNA, 33";
  char buss[10];
  char stat[128];
  int i = 0;
  int x;
 
  while(comma == 0 || comma == '\0'){
    if (buffer[i] == ','){
      memcpy(buss, buffer, i);
      buss[i] = '\0';
      removeChars(i+2, buffer);
      comma = 1;
      i = 0;
    }
    else ++i;
  } 
  
  while(comma == 1){
    if (buffer[i] == ','){
      memcpy(stat, buffer, i);
      stat[i] = '\0';
      removeChars(i+2, buffer);
      i = 0;
      comma = 2;
    }
    
    else  ++i;
  } 

  x = atoi(buffer);
  printf("%d\n", x);
  printf("%s\n", buss);
  printf("%s\n", stat);
  printf("%s\n", buffer);
  return 0;
}
