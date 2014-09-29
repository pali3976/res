#include <stdio.h>
#include <stdlib.h>
int main(void){

  int comma = 0;
  char buffer[] = "11, HRAJSFNKSANFASFNA";
  char buss[10];
  int i = 0;
  while(comma == 0, i++){
    if (buffer[i] == ','){
      comma = 1;
      fgets(buss, i, buffer);
    }
  }
  printf("Swag %d", buss);
  return 0;
}
