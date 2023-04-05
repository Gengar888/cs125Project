//CS125 Group Project
//Jeopardy! game program made by Raymond Siebert, Theodore Feldman, and Ruslan Gabdulin

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "catstringselection.h"
#include "screen.h"
#include "constants.h"

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
void menu();
void HistoryQuestions();
void GeographyQuestions();
void AnimalsQuestions();
void MoviesQuestions();




//Function with all the Geography questions & error checking inside to account for any user errors.
void GeographyQuestions(){  
    int price;
    
    priceselectionscreen();
//George helped with this section by suggesting we use the "%*c" to make the fgets work correctly     
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
//Error checking to catch incorrect user inputs and return them to the start of the price selection screen in their chosen category
    if(price!=price100 && price!=price200 && price!=price300 && price!=price400){
        printf("Invalid Selection!\nPress Enter to continue");
        while( getchar() != '\n' );
        GeographyQuestions();
}
//Error checking to make sure a user knows they cannot choose the same price more than once in a category
    else{
        printf("You have already chosen this price & category!\nPress Enter to continue");
        while( getchar() != '\n' );
        menu();
    }
    
}

//Function with all the History questions & error checking inside to account for any user errors. Function follows same format as Geography Questions format.
void HistoryQuestions(){
    int price;
    
    priceselectionscreen();
    
    scanf("%d%*c",&price); 
    if(price==price100 && HistoryToken100 == 0 ){   
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
        printf("This city became the first in history to have a nuclear warhead dropped on it. \n");
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
//Error checking to catch incorrect user inputs and return them to the start of the price selection screen in their chosen category
    if(price!=price100 && price!=price200 && price!=price300 && price!=price400){
        printf("Invalid Selection!\nPress Enter to continue");
        while( getchar() != '\n' );
        HistoryQuestions();
}
//Error checking to make sure a user knows they cannot choose the same price more than once in a category
    else{
        printf("You have already chosen this price & category!\nPress Enter to continue");
        while( getchar() != '\n' );
        menu();
    }

}

//Function with all the Animals questions & error checking inside to account for any user errors. Function follows same format as Geography Questions format.
void AnimalsQuestions(){
    int price;
    
    priceselectionscreen();
    
    scanf("%d%*c",&price); 
    if(price==price100 && AnimalsToken100 == 0 ){   
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
//Error checking to catch incorrect user inputs and return them to the start of the price selection screen in their chosen category
    if(price!=price100 && price!=price200 && price!=price300 && price!=price400){
        printf("Invalid Selection!\nPress Enter to continue");
        while( getchar() != '\n' );
        AnimalsQuestions();
}
//Error checking to make sure a user knows they cannot choose the same price more than once in a category
    else{
        printf("You have already chosen this price & category!\nPress Enter to continue");
        while( getchar() != '\n' );
        menu();
}

}

//Function with all the Movies questions & error checking inside to account for any user errors. Function follows same format as Geography Questions format.
void MoviesQuestions(){
    int price;
    
    priceselectionscreen();

    scanf("%d%*c",&price); 
    if(price==price100 && MoviesToken100 == 0 ){   
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
//Error checking to catch incorrect user inputs and return them to the start of the price selection screen in their chosen category
    if(price!=price100 && price!=price200 && price!=price300 && price!=price400){
        printf("Invalid Selection!\nPress Enter to continue");
        while( getchar() != '\n' );
        MoviesQuestions();
}
//Error checking to make sure a user knows they cannot choose the same price more than once in a category
    else{
        printf("You have already chosen this price & category!\nPress Enter to continue");
        while( getchar() != '\n' );
        menu();
    }
    
}



//Function that navigates a user to their selected category menu.
void categories(char catstring[]){
//defines date and time
time_t t;   
    if (strcmp(catstring, "History\n")==0)
        HistoryQuestions();
    else if (strcmp(catstring, "Animals\n")==0)
        AnimalsQuestions();
    else if (strcmp(catstring, "Geography\n")==0)
        GeographyQuestions();
    else if (strcmp(catstring, "Movies\n")==0)
        MoviesQuestions();
    else if (strcmp(catstring, "x\n")==0){
        time(&t);
//Creates a file "highscores.txt" that saves the timestamp when the user exited the game and the user's score.
        FILE *ptr = fopen("highscores.txt", "a");
        fprintf(ptr, "\n**************************\n%s\n**************************\nHIGH SCORE:", ctime(&t));
        fprintf(ptr, "%d\n", points);
        fclose(ptr);
        exit(1);
    }
    else{
        printf("Invalid Category! It is case sensitive\n");
        printf("PICK A CATEGORY! ");
        fgets(catstring, 50, stdin);
        categories(catstring);
    }  
    
}

//This function returns the user to the categories menu & is called at the end of all the question category functions
void menu(){
    catselectionScreen();
    char catstring[50];
    printf("Total points: %d\n", points);
    printf("\nRULES: All answers should be in the format of question sentences. Use 'Who is' when answers relate to people & 'What is' for everything else. \nDon't forget to include a question mark at the end of your answer!\n\n(Type 'x' to exit program)\nPICK A CATEGORY! ");
    fgets(catstring, 50 ,stdin);
    categories(catstring);
}


int main(){
    menu();
   
return 0; 
}
