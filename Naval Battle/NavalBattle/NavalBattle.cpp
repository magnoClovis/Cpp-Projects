#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#include "variables.h"
#include "boats.h"
#include "player.h"
#include "computer_game.h"


char g_squares[10][10][2];
char g_set_boat = 'S';
char g_boat = 'O';
char g_water = '.';
char g_fire = 'X';


using namespace std;

int main()
{
    srand(time(0));
    char against; // agains a person or the computer
    matrix(2); // starting a 3D matrix full of zeros
    playerBoard(0); // shows the player one's board on the screen
    against = randomOrNot(0);
    if (against == 'A' || against == 'a') { // if playing agains a person, then...
        playerBoard(1); // shows the player two's board on the screen
        randomOrNot(1); // set the position of the player two's boats on the board
        game(randomValues() % 2); // start the game and decides who goes first
        return 0;
    }
    else if (against == 'B' || against == 'b') {
        cout << "----------------------------GENERATING POSITIONS FOR THE COMPUTER----------------------------\n\n";
        randomSet(1);
        computerGame();
    }

    return 0;
}