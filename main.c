#include <stdio.h>
#include <string.h>

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

void readFile(char *natverk, char *start){
  
  printf("Loading textfiles\n\n");
  
  FILE *natverk = fopen("nätverk.txt", "r");
  FILE *start = fopen("start.txt","r");

  int comma = 0;
  char buss[10];
  char station1[128];
  char station2[128];
  char timeBetween[10]; // FÅR DEN TILL EN INT
  char buffer[128];

  readline(buffer, 128, natverk);
  
  while(int i = 0; comma == 0; i++){
    if (getc(buffer) == ','){
      comma = 1;
      fgets(buss, i, buffer);
    }
  }



  else if (comma == 1){}
  else if (comma == 2){}
  else if (comma == 3){}

  
  
    
    
    
  }
  





 
  fclose();	      
}



int main (int argc,char *argv[]){
  Station end = NULL;
  readFile("nätverk.txt", "start.txt");
    
  int choise = -1;
  
  while (choise != 0){
    //printa busstationer etc.
    char startDest[128];
    char endDest[128];
    printf("Välj alternativ\n");
    printf("1. Åka från X till Y  kl. Z\n");
    printf("2. Åka från X till Y och vara framme senaste kl. Z\n");
    printf("0. För att avsluta\n");
    scanf("%d", &choice);
    
    switch(choise){
    case 1: break; 
    case 2:break;
    case 0: puts("Bajbaj"); break; //Exit
    default: puts("Kunde inte hitta något alternativ");
    }   
  }
  return 0;
}
