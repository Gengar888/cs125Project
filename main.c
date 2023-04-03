//Make I/O File to output high scores at the end

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define ROWS 9
#define COLS 20

int points = 0;
char InpAns[100];
int AnimalsToken100 = 0;    //All token variables are used to ensure a user can't pick a question twice.
int GeographyToken100 = 0;
int HistoryToken100 = 0;
int MoviesToken100 = 0;

int AnimalsToken200 = 0;
int GeographyToken200 = 0;
int HistoryToken200 = 0;
int MoviesToken200 = 0;


int AnimalsToken300 = 0;
int GeographyToken300 = 0;
int HistoryToken300 = 0;
int MoviesToken300 = 0;

int AnimalsToken400 = 0;
int GeographyToken400 = 0;
int HistoryToken400 = 0;
int MoviesToken400 = 0;

int price100 = 100;
int price200 = 200;
int price300 = 300;
int price400 = 400;

void catselectionScreen();
void catselectionScreen();
void categories();
int menu();
int HistoryQuestions();
int GeographyQuestions();
int AnimalsQuestions();
int MoviesQuestions();

//Function that makes the menu flash in different colors 
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
  sleep(1);
  printf("\e[2J\e[H");
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
    while(y=1 && y< (ROWS-1));
   
}

//Function with all the Geography questions & error checking inside to account for any user errors.
int GeographyQuestions(){  
    int price;
    
    priceselectionscreen();
    
    scanf("%d%*c",&price); // "%*c" This makes the fgets work because it makes fgets read a character and not save it  // meaning when we hit "Enter" after picking the price, the fgets will now work.
    if(price==price100 && GeographyToken100 == 0 ){   //Token makes sure you havent chosen this problem before
        GeographyToken100++;
        printf("This is the smallest state in the United States. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is Rhode Island?\n")==0 ){
            printf("Correct! +100 points!\n");
            while( getchar() != '\n' );
            points+=100;
            menu();
        }
        
        else{
        printf("Incorrect! -100 points!\nPress Enter to continue");
        points-=100;
        while( getchar() != '\n' );
        menu();
        }
}
    else if(price==price200 && GeographyToken200 == 0){
        GeographyToken200++;
        printf("This is the smallest country in the world. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is Vatican City?\n")==0 ){
            printf("Correct! +200 points!\nPress Enter to continue");
            while( getchar() != '\n' );
            points+=200;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=200;
        while( getchar() != '\n' );
        menu();
    }
}
    else if(price==price300 && GeographyToken300 == 0){
        GeographyToken300++;
        printf("This capital city is the most populous in the Western Hemisphere. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is Sao Paulo?\n")==0 ){
            printf("Correct! +300 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=300;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=300;
        while( getchar() != '\n' );
        menu();
    }
}
    else if(price==price400 && GeographyToken400 == 0){
        GeographyToken400++;
        printf("This sea is the only sea on the planet to not have a coastline. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is the Sargasso Sea?\n")==0 ){
            printf("Correct! +400 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=400;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=400;
        while( getchar() != '\n' );
        menu();
    }
}
    else{
        printf("You have already chosen this price & category!\nPress Enter to continue");
        while( getchar() != '\n' );
        menu();
    }
    
}

//Function with all the History questions & error checking inside to account for any user errors.
int HistoryQuestions(){
    int price;
    
    priceselectionscreen();
    
    scanf("%d%*c",&price); // "%*c" This makes the fgets work because it makes fgets read a character and not save it  // meaning when we hit "Enter" after picking the price, the fgets will now work.
    if(price==price100 && HistoryToken100 == 0 ){   //Token makes sure you havent chosen this problem before
        HistoryToken100++;
        printf("America was founded in this year. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is 1776?\n")==0 ){
            printf("Correct! +100 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=100;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=100;
        while( getchar() != '\n' );
        menu();
        }
}
    else if(price==price200 && HistoryToken200 == 0){
        HistoryToken200++;
        printf("This Japanese city became the first in history to have a nuclear warhead dropped on it? \n");
        fgets(InpAns, 100 ,stdin);
        if (strcmp (InpAns, "What is Hiroshima?\n")==0 ){
            printf("Correct! +200 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=200;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=200;
        while( getchar() != '\n' );
        menu();
    }
}
    else if(price==price300 && HistoryToken300 == 0){
        HistoryToken300++;
        printf("Archduke Franz Ferdinand died in this month and this year. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is June 1914?\n")==0 ){
            printf("Correct! +300 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=300;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=300;
        while( getchar() != '\n' );
        menu();
    }
}
    else if(price==price400 && HistoryToken400 == 0){
        HistoryToken400++;
        printf("This king lead the largest calvary charge in recorded history. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "Who is King John III Sobieski?\n")==0 ){
            printf("Correct! +400 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=400;
            menu();
        }
        else if (strcmp (InpAns, "Who is King John 3 Sobieski?\n")==0 ){
            printf("Correct! +400 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=400;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=400;
        while( getchar() != '\n' );
        menu();
    }
}
    else{
        printf("You have already chosen this price & category!\nPress Enter to continue");
        while( getchar() != '\n' );
        menu();
    }
}

//Function with all the Animals questions & error checking inside to account for any user errors.
int AnimalsQuestions(){
    int price;
    
    priceselectionscreen();
    
    scanf("%d%*c",&price); // "%*c" This makes the fgets work because it makes fgets read a character and not save it  // meaning when we hit "Enter" after picking the price, the fgets will now work.
    if(price==price100 && AnimalsToken100 == 0 ){   //Token makes sure you havent chosen this problem before
        AnimalsToken100++;
        printf("This is animal reaches the fastest speeds on land. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is a cheetah?\n")==0 ){
            printf("Correct! +100 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=100;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points =-100;
        while( getchar() != '\n' );
        menu();
        }
}
    else if(price==price200 && AnimalsToken200 == 0){
        AnimalsToken200++;
        printf("This is the only member of the genus equus to have stripes. \n");
        fgets(InpAns, 100 ,stdin);
        if (strcmp (InpAns, "What is a zebra?\n")==0 ){
            printf("Correct! +200 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=200;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=200;
        while( getchar() != '\n' );
        menu();
    }
}
    else if(price==price300 && AnimalsToken300 == 0){
        AnimalsToken300++;
        printf("This animal has the longest neck of any animal. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is a giraffe?\n")==0 ){
            printf("Correct! +300 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=300;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=300;
        while( getchar() != '\n' );
        menu();
    }
}
    else if(price==price400 && AnimalsToken400 == 0){
        AnimalsToken400++;
        printf("This animal reaches the fastest speeds in the entire animal kingdom. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is a peregrine falcon?\n")==0 ){
            printf("Correct! +400 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=400;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=400;
        while( getchar() != '\n' );
        menu();
    }
}
    else{
        printf("You have already chosen this price & category!\n Press Enter to continue");
        while( getchar() != '\n' );
        menu();
    }
} 

//Function with all the Movies questions & error checking inside to account for any user errors.
int MoviesQuestions(){
    int price;
    
    priceselectionscreen();
    
    scanf("%d%*c",&price); // "%*c" This makes the fgets work because it makes fgets read a character and not save it  // meaning when we hit "Enter" after picking the price, the fgets will now work.
    if(price==price100 && MoviesToken100 == 0 ){   //Token makes sure you havent chosen this problem before
        MoviesToken100++;
        printf("This is the name of the Matrix's main character. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "Who is Neo?\n")==0 ){
            printf("Correct! +100 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=100;
            menu();
        }
        
        else{
        printf("Incorrect Press Enter to continue!");
        points-=100;
        while( getchar() != '\n' );
        menu();
        }
}
    else if(price==price200 && MoviesToken200 == 0){
        MoviesToken200++;
        printf("This movie won Best Picture in 2020. \n");
        fgets(InpAns, 100 ,stdin);
        if (strcmp (InpAns, "What is Parasite?\n")==0 ){
            printf("Correct! +200 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=200;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=200;
        while( getchar() != '\n' );
        menu();
    }
}
    else if(price==price300 && MoviesToken300 == 0){
        MoviesToken300++;
        printf("This is the first movie directed by Quentin Tarantino. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "What is Reservoir Dogs?\n")==0 ){
            printf("Correct! +300 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=300;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=300;
        while( getchar() != '\n' );
        menu();
    }
}
    else if(price==price400 && MoviesToken400 == 0){
        MoviesToken400++;
        printf("This the only actor to receive an Oscar nomination for acting in a Lord of the Rings movie. \n");
        fgets(InpAns, 50 ,stdin);
        if (strcmp (InpAns, "Who is Ian McKellen?\n")==0 ){
            printf("Correct! +400 points!\n Press Enter to continue");
            while( getchar() != '\n' );
            points+=400;
            menu();
        }
        
        else{
        printf("Incorrect! Press Enter to continue");
        points-=400;
        while( getchar() != '\n' );
        menu();
    }
}
    else{
        printf("You have already chosen this price & category!\n Press Enter to continue");
        while( getchar() != '\n' );
        menu();
    }
} 

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

//Function that navigates a user to their selected category menu.
void categories(char catstring[]){
    if (strcmp(catstring, "History\n")==0)
        HistoryQuestions();
    else if (strcmp(catstring, "Animals\n")==0)
        AnimalsQuestions();
    else if (strcmp(catstring, "Geography\n")==0)
        GeographyQuestions();
    else if (strcmp(catstring, "Movies\n")==0)
        MoviesQuestions();
    else{
        printf("Invalid Category! It is case sensitive\n");
        printf("PICK A CATEGORY!");
        fgets(catstring, 50, stdin);
        categories(catstring);
        
    }
}

int menu(){
    catselectionScreen();
    char catstring[50];
    printf("Total points %d\n", points);
    printf("PICK A CATEGORY! ");
    fgets(catstring, 50 ,stdin);
    categories(catstring);
}

int main(){
    menu();

//defines date and time
time_t t;
time(&t);
  
FILE *ptr = fopen("highscores.txt", "a");
fprintf(ptr, "**************************\n%s\n**************************\nHIGH SCORE: %ls", ctime(&t), &points);
fclose(ptr);
   
return 0; 
}
