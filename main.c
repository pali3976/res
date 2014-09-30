#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct station {
  int lTime;
  int lStart[];
  int rTime;
  int rStart[];


  struct station *left;
  struct station *right
}*Station;


void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
}


void readRowNetwork(char bufer[]){ //M�ste l�gga till i datatypen
  int comma = 0;
  char buss[10];
  char station1[128];
  char station2[128];
  int timeBetween[10]; 
  

  while(comma == 0 || comma == NULL ){
    if (buffer[i] == ','){
      memcpy(buss, buffer, i);
      buss[i+1] = '\0';
      comma = 1;
    }
    else ++i;
  }

  
  while(comma == 1 || comma == NULL){
    if (buffer[i] == ','){
      memcpy(station1, buffer, i);
      station1[i] = '\0';
      removeChars(i+2, buffer);
      i = 0;
      comma = 2;
    }
    else ++i;
  } 
  while(comma == 2 || comma == NULL){
    if (buffer[i] == ','){
      memcpy(station2, buffer, i);
      station2[i] = '\0';
      removeChars(i+2, buffer);
      i = 0;
      comma = 3;
    }
    else ++i;
  } 
  while(comma == 3 || comma == NULL){
    if (buffer[i] == ','){
      memcpy(timeBetween, buffer, i);
      timeBetween[i] = '\0';
      i = 0;
      
      comma = 4;
    }
    else ++i;
    timeBetween = atoi(buffer);
}


void readFile(char *natverk, char *start){
  
  printf("Loading textfiles\n\n");
  
  FILE *natverk = fopen("n�tverk.txt", "r");
  FILE *start = fopen("start.txt","r");
  char buffer[128];
 
  readRowNetwork(buffer) // F�R VARJE RAD
  readline(buffer, 128, natverk);

  fclose();	      
}



int main (int argc,char *argv[]){
  Station end = NULL;
  readFile("n�tverk.txt", "start.txt");
    
  int choise = -1;
  
  while (choise != 0){
    //printa busstationer etc.
    char startDest[128];
    char endDest[128];
    printf("V�lj alternativ\n");
    printf("1. �ka fr�n X till Y  kl. Z\n");
    printf("2. �ka fr�n X till Y och vara framme senaste kl. Z\n");
    printf("0. F�r att avsluta\n");
    scanf("%d", &choice);
    
    switch(choise){
    case 1: break; 
    case 2:break;
    case 0: puts("Bajbaj"); break; //Exit
    default: puts("Kunde inte hitta n�got alternativ");
    }   
  }
  return 0;
}
