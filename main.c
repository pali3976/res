
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

void readFile(char buffer[]){
  int comma = 0;
  int buss;
  char station1[1024];
  char station2[1024];
  char temp[1024];
  int timeBetween;
  int i = 0;

  while(comma == 0){
    if (buffer[i] == ','){
      memcpy(temp, buffer, i);
      temp[i] = '\0';
      buss = atoi(temp);
      removeChars(i+2, buffer);
      comma = 1;
    }
    else ++i;
  }
  while(comma == 1){
    if (buffer[i] == ','){
      memcpy(station1, buffer, i);
      station1[i] = '\0';
      removeChars(i+2, buffer);
      i = 0;
      comma = 2;
    }
    else ++i;
  }
  while(comma == 2){
    if (buffer[i] == ','){
      memcpy(station2, buffer, i);
      station2[i] = '\0';
      removeChars(i+2, buffer);
      i = 0;
      comma = 3;
    }
    else ++i;
  }
  while(comma == 3){
    if (buffer[i] == '\0'){
      memcpy(temp, buffer, i);
      temp[i] = '\0';
      timeBetween = atoi(temp);
      comma = 4;
      removeChars(i, buffer);
    }
    else ++i;
  } 
  printf("Busslinje: %d\n", buss);
  printf("Busstation 1: %s\n", station1);
  printf("Busstation 2: %s\n", station2);
  printf("Timebetween %d\n", timeBetween);
}


void readRowStart(){
}

void readFile(char *net, char *start){
  printf("Loading textfile\n\n");
  char buffer[1024];
  FILE *netFile = fopen(net, "r");
  FILE *startFile = fopen(start, "r");
 
 
 
  while(!(feof(netFile))){
    //Om bussnummer !=, k�r datatypen tillbaka
    readline(buffer, 128, netFile);
    readRowNetwork(buffer);
    }
  fclose(netFile);
  

  while(!(feof(startFile))){
    readline(buffer, 128, startFile);
    readRowStart(buffer);
  }
  fclose(startFile);
}


int main (int argc,char *argv[]){
  readFile("natverk.txt","start.txt");

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
    default: puts("Kunde inte hitta n�got alternativ");
    }   
    */
  }
  return 0;
}







