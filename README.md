#include <stdio.h>
#include <string.h>

#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 3

char categories[NUM_CATEGORIES][50] = {
    "Animals",
    "Movies",
    "Famous People"
};

char questions[NUM_CATEGORIES][NUM_QUESTIONS][200] = {
    {
        "This animal is known for its black and white stripes.",
        "This animal is the fastest on land.",
        "This animal has the longest neck of any animal."
    },
    {
        "This movie is about a clown terrorizing a town.",
        "This movie won Best Picture in 2020.",
        "This is the first movie directed by Quentin Tarantino."
    },
    {
        "This person was the first president of the United States.",
        "This person was a famous physicist who came up with the theory of relativity.",
        "This person is known for painting the Mona Lisa."
    }
};

char answers[NUM_CATEGORIES][NUM_QUESTIONS][200] = {
    {"Zeebra", "Cheetah", "Giraffe"},
    {"It", "Parasite", "Reservoir Dogs\n"},
    {"George Washington\n", "Albert Einstein\n", "Vincent van Gogh\n"}
};

int scores[NUM_CATEGORIES][NUM_QUESTIONS] = {
    {100, 200, 300},
    {100, 200, 300},
    {100, 200, 300}
};

int main() {
    int category, question, answer, score = 0;
    char user_answer[200];

    printf("Welcome to Jeopardy!\n\n");

    while (1) {
        printf("Categories:\n");
        for (int i = 0; i < NUM_CATEGORIES; i++) {
            printf("%d. %s\n", i + 1, categories[i]);
        }

        printf("\nEnter a category number (1-%d): ", NUM_CATEGORIES);
        scanf("%d", &category);
        category--;

        printf("\n%s:\n", categories[category]);
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            printf("%d. %s\n", i + 1, questions[category][i]);
        }

        printf("\nEnter a question number (1-%d): ", NUM_QUESTIONS);
        scanf("%d%*c", &question);
        question--;

        printf("\n%s\nEnter your answer: ", questions[category][question]);
        fgets(user_answer,20, stdin);
        
        answer = answers[category][question];
        if (strcmp(user_answer, answers[category][question]) == 0) {
            score += scores[category][question];
            printf("\nCorrect! Your score is now %d.\n\n", score);
        } else {
            score -= scores[category][question];
            printf("\nIncorrect. The correct answer is %s. Your score is now %d\n",answers[category][question], score);
        }
    }

    return 0;
}
