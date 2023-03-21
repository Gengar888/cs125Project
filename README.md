#include <stdio.h>
#include <string.h>

int main() {
    char category1[50] = "cat1";
    char category2[50] = "cat2";
    char category3[50] = "cat3";
    char q1[200] = "q1";
    char q2[200] = "q2";
    char q3[200] = "q3";
    char a1[50] = "a1";
    char a2[50] = "a2";
    char a3[50] = "a3";
    int score = 0;
    int category_choice;
    printf("Categories:\n");
    printf("1. %s\n", category1);
    printf("2. %s\n", category2);
    printf("3. %s\n\n", category3);
    printf("Choose a category (1-3): ");
    scanf("%d", &category_choice);
    
    char question[200];
    char answer[50];
    
    switch (category_choice) {
        case 1:
            strcpy(question, q1);
            strcpy(answer, a1);
            break;
        case 2:
            strcpy(question, q2);
            strcpy(answer, a2);
            break;
        case 3:
            strcpy(question, q3);
            strcpy(answer, a3);
            break;
        default:
            printf("Invalid category choice.");
            return 1;
    }
    
    printf("\n%s\n", question);
    
    printf("\nWhat is your answer? ");
    char user_answer[50];
    scanf("%s", user_answer);
    
    if (strcmp(user_answer, answer) == 0) {
        printf("\nCorrect!");
        score += 100;
    } else {
        printf("\nIncorrect");
    }
    
    printf("\n\nFinal score: %d", score);
    
    return 0;
}
