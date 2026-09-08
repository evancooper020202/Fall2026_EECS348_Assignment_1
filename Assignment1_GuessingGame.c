/*
Program:
    EECS 348 Assignment 1
Description: 
    C program that picks a secret number between 1 and 10.
    The user gets up to 3 tries to guess the number.
Inputs:
    Integer guesses provided by the user
Output:
    terminal text displaying the attempt count.
    Feedback on guesses (too high/too low)
    Win or lose messages
Collaborators
    None
Other Sources
    Gemini 
Author’s full name
    Evan Cooper
Creation date:
    September 8th, 2026
Revision date: 
    September 8th, 2026
Revisions: 
    Adding code for bad input like strings.
*/



#include <stdio.h>

int main(void) {
    const int SECRET_NUMBER = 7;
    const int MAX_ATTEMPTS = 3;
    int guess = 0;
    int won = 0;

    printf("Guess a number between 1 and 10.\n");

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        printf("Attempt %d/%d. Enter your guess: ", attempt, MAX_ATTEMPTS);
        scanf("%d", &guess);

        if (guess == SECRET_NUMBER) {
            printf("Correct! You win!\n");
            won = 1;
            break;
        } else if (guess < SECRET_NUMBER) {
            if (attempt < MAX_ATTEMPTS) {
                printf("Too low! Try again.\n");
            }
        } else {
            if (attempt < MAX_ATTEMPTS) {
                printf("Too high! Try again.\n");
            }
        }
    }

    if (!won) {
        printf("You ran out of tries! You lose. The secret number was %d.\n", SECRET_NUMBER);
    }

    return 0;
}