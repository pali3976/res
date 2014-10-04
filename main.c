
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct station {
  int lTime;
  int lStart[10];
  int rTime;
  int rStart[10];


  struct station *left;
  struct station *right;
}*Station;

void removeChars(int number, char *buffer){
  memmove(buffer, buffer+number, strlen(buffer));  
}

void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
}


void readRowNetwork(char buffer[]){ 
  int comma = 0;
  char buss[10];
  char station1[128];
  char station2[128];
  int timeBetween[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  int i = 0;

  while(comma == 0 || comma == '\0'){
    if (buffer[i] == ','){
      memcpy(buss, buffer, i);
      buss[i+1] = '\0';
      comma = 1;
    }
    else ++i;
  }

   while(comma == 1 || comma == '\0'){
    if (buffer[i] == ','){
      memcpy(station1, buffer, i);
      station1[i] = '\0';
      removeChars(i+2, buffer);
      i = 0;
      comma = 2;
    }
    else ++i;
   } 
   while(comma == 2 || comma == '\0'){
     if (buffer[i] == ','){
       memcpy(station2, buffer, i);
       station2[i] = '\0';
       removeChars(i+2, buffer);
       i = 0;
       comma = 3;
     }
     else ++i;
   } 
   while(comma == 3 || comma == '\0'){
     if (buffer[i] == ','){
       memcpy(timeBetween, buffer, i);
       removeChars(i+2, buffer);
       timeBetween[i] = '\0';
      
       i = 0;
      
       comma = 4;
     }
     else ++i;
    
     timeBetween = atoi(buffer);
   }

}

void readFile(char *natverk, char *start){
  
  printf("Loading textfiles\n\n");
  
  
  char buffer[128];

  FILE *natverk = fopen("natverk.txt", "r");
  FILE *start = fopen("start.txt", "r");
  readRowNetwork(buffer); // FOR VARJE RAD
  readline(buffer, 128, natverk);

  fclose("natverk.txt");
  fclose("start.txt");
}

int main (int argc,char *argv[]){
  //Station end = NULL;
  readFile("natverk.txt", "start.txt");
    
  int choice = -1;
  
  while (choice != 0){
    //printa busstationer etc.
    //char startDest[128];
    //char endDest[128];
    printf("Choose Option\n");
    printf("1.  FROM X TO Y  kl. Z\n");
    printf("2.  FROM X TO Y AND BE HOME LATEST kl. Z\n");
    printf("0.  CLOSE\n");
    scanf("%d", &choice);

    /*
    switch(choise){
    case 1: break; 
    case 2:break;
    case 0: puts("Bajbaj"); break; //Exit
    default: puts("Kunde inte hitta något alternativ");
    }   
    */
  }
  return 0;
}







