#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#include "Boats.h"
#include "source.h"

using namespace std;

int main()
{   
    srand((unsigned)time(NULL));
    char against; // agains a person or the computer
    matrix(); // starting a 3D matrix full of zeros
    playerBoard(0); // shows the player one's board on the screen
    against = SetPlayer(0); // set the position of the boats on the player one's board
    if (against == 'A' || against == 'a') { // if playing agains a person, then...
        playerBoard(1); // shows the player two's board on the screen
        SetPlayer(1); // set the position of the player two's boats on the board
        game(random()%2); // start the game and decides who goes first
    }
    return 0;
}