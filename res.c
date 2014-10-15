#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "res.h"


typedef struct node {
  char *name;
  struct eList *eLista;

}*Station;

typedef struct edge {
  int buss;
  int time;
  
  struct node *left;
  struct node *right;
}*Edge;
  

typedef struct nList {
  
  struct nList *nLista;
  char *name;
}*NList;

typedef struct eList{
  struct eList *eLista;
  struct edge *nEdge;

}*EList;

void removeChars(int number, char *buffer){
  memmove(buffer, buffer+number, strlen(buffer));
}


int nodeExist(NList nodeList, char *str){
  if(nodeList == NULL){
    return 0;
  }
  else if(strcmp(nodeList->name, str) == 0){
    return 1;
  }
  return nodeExist(nodeList->nLista, str);
}

void makeNodeList(NList *nodeList, char *str){
  NList nameTemp = NULL;
  nameTemp = malloc(sizeof(struct nList));
	
  nameTemp->name = malloc(strlen(str)+1);
  strcpy(nameTemp->name, str);
  nameTemp->nLista = NULL;
	
  *nodeList = nameTemp;
}

//FÅR EJ VARA TOM
void appendNodeList(NList nodeList, char *str){
  while(nodeList->nLista != NULL){
    nodeList = nodeList->nLista;
  }
    
  NList nameTemp = NULL;
  nameTemp = malloc(sizeof(struct nList));
  
  nameTemp->name = malloc(strlen(str)+1);
  strcpy(nameTemp->name, str);
  nameTemp->nLista = NULL;
  
  nodeList->nLista = nameTemp;
}

void makeNode(char *str){
  Station nTemp = NULL;
  nTemp = malloc(sizeof(struct node));

  nTemp->name = malloc(strlen(str)+1);
  strcpy(nTemp->name, str);

  nTemp->eLista = NULL;
}

void addEdgeNode(Station node1, Station node2, int buss, int time){

}


void readFile(char buffer[], NList *nodeList){
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

      //Om den är tom
      if (*nodeList == NULL){
	makeNodeList(nodeList, station1);
      }
      //Append
      else if (!nodeExist(*nodeList, station1)){
	appendNodeList(*nodeList,station1);
      }
      //Annars finns den redan
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

      //Append
      if (!nodeExist(*nodeList, station2)){
	appendNodeList(*nodeList,station2);
      }
      //Annars finns den redan
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



int main(void){
  FILE *net = fopen("natverk.txt", "r");
  char buffer[1024];
  NList nodeList = NULL;

  while(fgets(buffer, sizeof(buffer), net) != NULL){
    readFile(buffer,&nodeList);
  }
  fclose(net);


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
    
   
    switch(choice){
    case 1: break; 
    case 2:break;
    case 0: puts("Bajbaj"); break; //Exit
    default: puts("Kunde inte hitta något alternativ");
    }   
    
  }
  return 0;
}

