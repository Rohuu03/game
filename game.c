#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int x = 1;              // player position (0 to 2)
    int step = 0;           // obstacle vertical movement
    int obstaclePos = rand() % 3;   // 0,1,2 lane
    int score = 0;          // player's score
    int lives = 3;          // player's lives (displayed as hearts)

    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();

            if (ch == 65 && x > 0)        // LEFT arrow
                x--;

            if (ch == 68 && x < 2)       // RIGHT arrow
                x++;
        }

        // ---- DRAW ----
        system("cls");
        printf("Score: %d  Lives: %d\n", score, lives-1);
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {
            if (i == step) {

                if (obstaclePos == 0)
                    printf("| %c        |\n", 168);

                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 168);

                else if (obstaclePos == 2)
                    printf("|        %c |\n", 168);

            } else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)
            printf("| %c        |\n", 94);
        else if (x == 1)
            printf("|     %c    |\n", 94);
        else if (x == 2)
            printf("|        %c |\n", 94);
        // ---- COLLISION ----
        if (step == 10 && x == obstaclePos) {
            lives--;
            if (lives <= 0) {
                printf("\nGAME OVER!\n");
                printf("Final score: %d\n", score);
                break;
            } else {
                printf("\nHit! Lives left: %d\n", lives);
                Sleep(700);
                /* reset obstacle so player gets a fresh attempt */
                step = 0;
                obstaclePos = rand() % 3;
                continue;
            }
        }

        // Increase speed with score: start at 120ms, decrease by 2ms per point, min 40ms
        int delay = 120 - (score * 2);
        if (delay < 40) delay = 40;
        Sleep(delay);

        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3; // new lane
            score++; // obstacle passed safely
        }
    }

    return 0;
}