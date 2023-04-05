//Authors: Raymond Siebert, Theodore Feldman, & Ruslan Gabdulin

#include <stdio.h>
#include "constants.h"
#include "screen.h"

//Function that allows users to pick what category of question they would like.
void catselectionScreen(){
    char intro[ROWS][COLS]={
    "***************",
    "*   History   *",
    "*   Animals   *",
    "*             *",
    "*  JEOPARDY!  *",
    "*             *",
    "*  Geography  *",
    "*   Movies    *",
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

//Function that allows a user to pick the price of the question they want.
void priceselectionscreen(){  
    int price100 = 100;
    int price200 = 200;
    int price300 = 300;
    int price400 = 400;

    char price[ROWS][COLS]={
            "***************",
            "*      %d  *",
            "*      %d  *",
            "*             *",
            "*  JEOPARDY!  *",
            "*             *",
            "*      %d  *",
            "*      %d      *",
            "***************"};
//George helped us by suggesting we use "sprintf" as we had issues early on with our matrix not printing the int values			
    sprintf((char*)&price[1],"*     %d     *",price100);   
    sprintf((char*)&price[2],"*     %d     *",price200);
    sprintf((char*)&price[6],"*     %d     *",price300);
    sprintf((char*)&price[7],"*     %d     *",price400);

    int y;
    clearScreen();
    print_array(price);
        do{
        y++;
        clearScreen();
        print_array(price);
        changeColor((y%3)+1);
        printf("\nChoose a price! ");
    }
    while((y==1) && (y< (ROWS-1)));
   
}


