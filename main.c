#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define ROWS 9
#define COLS 20
int points = 0;


void HistoryQuestions(){
    
}
void AnimalsQuestions(){
    
}
    
void GeographyQuestions(){
    
}

void TelevisionQuestions(){
    
}

void categories(char catstring[]){
    if (strcmp(catstring, "History\n")==0)
        HistoryQuestions();
    else if (strcmp(catstring, "Animals\n")==0)
        AnimalsQuestions();
    else if (strcmp(catstring, "Geography\n")==0)
        GeographyQuestions();
    else if (strcmp(catstring, "Television\n")==0)
        TelevisionQuestions();
    else{
        printf("Invalid Category! It is case sensitive\n");
        printf("PICK A CATEGORY!");
        fgets(catstring, 50, stdin);
        categories(catstring);
        
    }
}

void clearScreen(){
  sleep(.1);
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
    selectionScreen();
    char catstring[50];
    printf("PICK A CATEGORY!");
    fgets(catstring, 50,stdin);
    categories(catstring);
   
    
  
  return 0; 
}
