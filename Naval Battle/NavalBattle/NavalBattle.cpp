#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <vector>

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
/*void foo(Boats* boats[]) {
    for (int i = 0; i < 5; i++)
    {
        cout << "TYPE  " << boats[i]->getType() << endl;
        cout << "LENGTH  " << boats[i]->getLength() << endl;
        cout << "QUANTITY  " << boats[i]->getQtt() << endl << endl << endl;
    }

    boats[4]->setType("submarine");

}*/

int main()
{
    std::string types[5] = { "submarine", "tug ship", "destroyer", "cruiser", "aircraft carrier" };

    vector<Boats> boats;

    for (int i = 0; i < 5; i++) {
        boats.push_back(Boats(types[i])); // filling a vector with boats objects, this way the characteristis of each boat dont get lost during the execution of the program
    }

    boats[0].setAddress(0, 1);
    boats[0].setAddress(5, 7);
    boats[0].setAddress(4, 8);

    boats[1].setAddress(0, 0);
    boats[1].setAddress(5, 9);
    boats[1].setAddress(3, 2);
    boats[1].setAddress(7, 6);

    boats[0].getAddress();
    
    boats[1].getAddress();

    /*
    srand(time(0));
    char against; // agains a person or the computer
    matrix(2); // starting a 3D matrix full of zeros
    playerBoard(0); // shows the player one's board on the screen m
    against = randomOrNot(0, boats);
    if (against == 'A' || against == 'a') { // if playing agains a person, then...
        playerBoard(1); // shows the player two's board on the screen
        randomOrNot(1, boats); // set the position of the player two's boats on the board
        game(randomValues() % 2); // start the game and decides who goes first
        return 0;
    }
    else if (against == 'B' || against == 'b') {
        cout << "----------------------------GENERATING POSITIONS FOR THE COMPUTER----------------------------\n\n";
        randomSet(1, boats);
        computerGame();
    }
    */
    return 0;
}


/*
    int*** cu = new int**[2];
    for (int i = 0; i < 2; i++) {
        cu[i] = new int*[3];
        for (int j = 0; j < 3; j++) {
            cu[i][j] = new int[1];
        }
    }

    int l = 10;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 1; k++) {
                cu[i][j][k] = ++l;
            }
        }
    }


    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 1; k++) {
                std::cout << cu[i][j][k] << " ";
            } std::cout << std::endl;
        }std::cout << std::endl << std::endl;
    }
*/