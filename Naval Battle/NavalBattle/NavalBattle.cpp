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
void foo(Boats* boats[]) {
    for (int i = 0; i < 5; i++)
    {
        cout << "TYPE  " << boats[i]->getType() << endl;
        cout << "LENGTH  " << boats[i]->getLength() << endl;
        cout << "QUANTITY  " << boats[i]->getQtt() << endl << endl << endl;
    }

    boats[4]->setType("submarine");

}

int main()
{
    Boats submarine, tug_ship, destroyer, cruiser, aircraft;
    Boats *psubmarine, *ptug_ship, *pdestroyer, *pcruiser, *paircraft;
    psubmarine = &submarine;
    ptug_ship = &tug_ship;
    pdestroyer = &destroyer;
    pcruiser = &cruiser;
    paircraft = &aircraft;

    submarine.setType("submarine");
    tug_ship.setType("tug ship");
    destroyer.setType("destroyer");
    cruiser.setType("cruiser");
    aircraft.setType("aircraft carrier");

    Boats* boats[5];
    boats[0] = psubmarine;
    boats[1] = ptug_ship;
    boats[2] = pdestroyer;
    boats[3] = pcruiser;
    boats[4] = paircraft;
    
    /*foo(boats);
    cout << "TYPE  " << boats[4]->getType() << endl;
    cout << "LENGTH  " << boats[4]->getLength() << endl;
    cout << "QUANTITY  " << boats[4]->getQtt() << endl << endl << endl;*/

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
    
    return 0;
}