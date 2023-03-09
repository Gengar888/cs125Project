#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


#define ROWS 9
#define COLS 20

void categories(char catstring[]){
    if (strcmp(catstring, "History")==0)
        
    else if (strcmp(catstring, "Animals")==0)
    
    else if (strcmp(catstring, "History")==0)
    
    else if (strcmp(catstring, "History")==0)
    
    else{
        printf("Invalid Category! It is case sensitive ")
        printf("PICK A CATEGORY!");
        fgets(catstring, 50,stdin);
        categories(catstring[]);
    }
}
void clearScreen(){
  sleep(0.5);
  printf("\e[2J\e[H");
}

void changeColor(int color){
  if(color==1){
    printf(" \e[1;31m");  //bold red font
  }
  else if(color==2){
    printf(" \e[1;34m");  //bold blue font
  }
  else if(color==3){
    printf(" \e[1;32m");  //bold green font
  }
  else{
    printf("\e[0m\n");
  }
}

int stringcompare(char QuestionAnswer[],char InputAnswer[]){

    if(strcmp(QuestionAnswer, InputAnswer)==0)
        return 1;
    else
        return 0;

}

void print_array(char lines[ROWS][COLS]){

  int x;
  for (x=0; x< ROWS; x++){
    printf("%s\n", lines[x]);
  }

}


int selectionScreen(){
    char intro[ROWS][COLS]={
    "***************",
    "*   History   *",
    "*   Animals   *",
    "*             *",
    "*  JEOPARDY!  *",
    "*             *",
    "*  Geography  *",
    "*  Television *",
    "***************"};
  int y;

  clearScreen();
  print_array(intro);
  for(y=1; y< (ROWS-1); y++){
    clearScreen();
    print_array(intro);
    changeColor((y%3)+1);
   
  }
   
}
   
int main(){
    int points = 0;
    char catstring[50];
    selectionScreen();
    printf("PICK A CATEGORY!");
    fgets(catstring, 50,stdin);
    
   
    
  
  return 0; 
}








