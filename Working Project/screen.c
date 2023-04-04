
#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "constants.h"

//Function that makes the menu flash in different colors 
void changeColor(int color){   
  if(color==1){
    printf(" \e[1;31m");  //bold red font
  }
  else if(color==2){
    printf(" \e[1;34m");  //bold blue font
  }
  else if(color==3){
   printf(" \e[1;92m");  //bold green font
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

void clearScreen(){
  sleep(1);
  printf("\e[2J\e[H");
}
