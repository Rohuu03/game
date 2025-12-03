#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main() {
    int userChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    char playAgain;

    // Seed random number generator
    srand(time(0));

    printf("===== ROCK PAPER SCISSORS GAME =====\n\n");

    while (1) {
        printf("Player Score: %d | Computer Score: %d\n\n", playerScore, computerScore);
        printf("Enter your choice:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &userChoice);

        // Generate computer choice (1 to 3)
        computerChoice = (rand() % 3) + 1;

        // Show choices
        printf("\n--- ROUND RESULT ---\n");
        printf("You chose: ");
        if(userChoice == 1) printf("Rock\n");
        else if(userChoice == 2) printf("Paper\n");
        else if(userChoice == 3) printf("Scissors\n");
        else {
            printf("Invalid choice!\n\n");
            continue;
        }

        printf("Computer chose: ");
        if(computerChoice == 1) printf("Rock\n");
        else if(computerChoice == 2) printf("Paper\n");
        else printf("Scissors\n");

        // Decide winner
        if(userChoice == computerChoice) {
            printf("It's a draw!\n\n");
        } else if((userChoice == 1 && computerChoice == 3) ||
                  (userChoice == 2 && computerChoice == 1) ||
                  (userChoice == 3 && computerChoice == 2)) {
            printf("You win!\n\n");
            playerScore++;
        } else {
            printf("Computer wins!\n\n");
            computerScore++;
        }

        // Ask to play again
        printf("Play again? (y/n): ");
        fflush(stdin);
        playAgain = getch();
        
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
        printf("\n");
    }

    // Final score
    printf("\n===== FINAL SCORE =====\n");
    printf("Player: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);
    
    if (playerScore > computerScore) {
        printf("YOU WON THE GAME!\n");
    } else if (computerScore > playerScore) {
        printf("COMPUTER WON THE GAME!\n");
    } else {
        printf("THE GAME WAS A TIE!\n");
    }
    printf("=======================\n");

    return 0;
}

