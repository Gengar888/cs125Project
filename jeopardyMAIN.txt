#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


#define ROWS 9
#define COLS 20

void categories();
void clearScreen(){
  sleep(1);
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


void print_array(char lines[ROWS][COLS]){

  int x;
  for (x=0; x< ROWS; x++){
    printf("%s\n", lines[x]);
  }

}


int selectionScreen(){
    char intro[ROWS][COLS]={
    "***************",
    "*  Category1  *",
    "*  Category2  *",
    "*             *",
    "*  JEOPARDY!  *",
    "*             *",
    "*  Category3  *",
    "*  Category4  *",
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
    char catstring[50];
    selectionScreen();
    printf("PICK A CATEGORY!");
    fgets(catstring, 50,stdin);
    //if(strcmp(catstring, "back")!=0)
    //selectionScreen();
    //else
    //categories(catstring);
   
   
}