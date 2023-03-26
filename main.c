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
            points + 50;
            main();
        }
    
        else{
        printf("Incorrect!");
        sleep(3);
        main();
        
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
        printf(" Wrong");
    }
    }
}
