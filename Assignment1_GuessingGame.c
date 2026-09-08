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



#include <stdio.h> //standard input/output library for the printf and scanf functions

int main(void) { //entry point into the program
    const int SECRET_NUMBER = 7; //defines the secret number to guess as a constant int
    const int MAX_ATTEMPTS = 3; // defines the maximum allowed attempts that the user gets to guess
    int guess = 0; //creates a variable to store the user's guess
    int won = 0; //flag to track if the user has won. (0 = lose, 1 = win)

    printf("Guess a number between 1 and 10.\n"); //initial instruction for the first guess

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) { //loops from the first attempt to the MAX_ATTEMPTS(3)
        printf("Attempt %d/%d. Enter your guess: ", attempt, MAX_ATTEMPTS); //prompts the user for a guess showing the current attempt and max guessing attempt
        if (scanf("%d", &guess) != 1) //reads the user input and checks if its valid 1=int, 0=otherwise like a string
        {
            printf("Invalid input, please enter a number.\n");//the input flagged a 0, asking the user for another attempt
            while (getchar() != '\n'); //removes the user input until it reaches the \n
            attempt--; //removes the previous attempt that resulted in a string
            continue; //skips the rest and restarts the loop
        }


        if (guess == SECRET_NUMBER) { //checks if the guess equals the secret number
            printf("Correct! You win!\n"); //prints the winning message
            won = 1; //sets the flag for the win to 1
            break;//breaks the loop and exits it
        } else if (guess < SECRET_NUMBER) { //checks if the guess is smaller than the secret number
            if (attempt < MAX_ATTEMPTS) { //checks if there is any guesses left
                printf("Too low! Try again.\n"); //if theres guesses left, then prints that the guess was too small.
            }//ends the attempt check for the low guess
        } else {//handles the case where the guess is larger than the secret number
            if (attempt < MAX_ATTEMPTS) {//once again checks if there is any attempts left
                printf("Too high! Try again.\n");//prints a message telling the user that its too large
            }//end for the limit check of the too high guess
        }//end of the guess comparison block itself
    }//indicates the end of the for loop

    if (!won) {//checks if the user failed to guess
        printf("You ran out of tries! You lose. The secret number was %d.\n", SECRET_NUMBER);//tells the user they lost and reveals the secret number
    }//end of the loss check

    return 0;//returns 0 for a succesful program run
}//end of the main function