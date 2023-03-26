//Make I/O File to output high scores at the end

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define ROWS 9
#define COLS 20

int points = 0;
char InpAns[50];
int AnimalsToken100 = 0;
int GeographyToken100 = 0;
int HistoryToken100 = 0;
int Television100 = 0;

int AnimalsToken200 = 0;
int GeographyToken200 = 0;
int HistoryToken200 = 0;
int Television200 = 0;

int AnimalsToken300 = 0;
int GeographyToken300 = 0;
int HistoryToken300 = 0;
int Television300 = 0;

int AnimalsToken400 = 0;
int GeographyToken400 = 0;
int HistoryToken400 = 0;
int Television400 = 0;

int price100 = 100;
int price200 = 200;
int price300 = 300;
int price400 = 400;



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

void clearScreen(){
  sleep(0.1);
  printf("\e[2J\e[H");
}

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
            "*      %d  *",
            "*      %d  *",
            "*             *",
            "***************"};
    sprintf((char*)&price[1],"*    %d    *",price100);
    sprintf((char*)&price[2],"*    %d    *",price200);
    sprintf((char*)&price[5],"*    %d    *",price300);
    sprintf((char*)&price[6],"*    %d    *",price400);

    int y;
    clearScreen();
    print_array(price);
    for(y=1; y< (ROWS-1); y++){
        clearScreen();
        print_array(price);
        changeColor((y%3)+1);

    }
    printf("Choose a price! ");
}

void GeographyQuestions(){
    int price;
    
    priceselectionscreen();
    
    scanf("%d%*c",&price); // "%*c" This makes the fgets work because it makes fgets read a character and not save it  // meaning when we hit "Enter" after picking the price, the fgets will now work.
    if(price==price100 && GeographyToken100 == 0 ){   //Token makes sure you havent chosen this problem before
        GeographyToken100 + 1;
        printf("This is the smallest state in the United States. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "Rhode Island\n")==0 ){
            printf("Correct! +50 points!\n");
            while( getchar() != '\n' );
            points + 50;
            main();
        }
        
        else{
        printf("Incorrect!");
        while( getchar() != '\n' );
        main();
        
        }
    }
    else if(price==price200 && GeographyToken200 == 0){
        printf("This is the smallest country in the world. \n");
        fgets(InpAns, 50 ,stdin);
    }   
    else if(price==price300 && GeographyToken300 == 0){
            printf("This capital city is the most populous in the Western Hemisphere. \n");
            fgets(InpAns, 50 ,stdin);
    }
    else if(price==price400){
            printf("This sea is the only sea on the planet to not have a coastline. \n");
            fgets(InpAns, 50 ,stdin);
        }
    else{
        printf("You have already chosen this price & catergory!");
        while( getchar() != '\n' );
        main();
    }
    
}

void HistoryQuestions(){
    int price;
    priceselectionscreen();
    
    scanf("%d%*c",&price);
    if(price==price100){
        printf("Q1 ");
        fgets(InpAns, 50 ,stdin);
    }
    else if(price==price200){
        printf("Q2 ");
    }   
    else if(price==price300){
        printf("Q3 ");
    }
        else if(price==price400){
        printf("Q4 ");
    }
    else{
        printf(" Wrong");
    }

}
void AnimalsQuestions(){
    int price;
    
    priceselectionscreen();
    
}
    


void TelevisionQuestions(){
    priceselectionscreen();
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



void catselectionScreen(){
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
    catselectionScreen();
    char catstring[50];
    printf("PICK A CATEGORY!");
    fgets(catstring, 50 ,stdin);
    categories(catstring);
   
    
  
  return 0; 
}
