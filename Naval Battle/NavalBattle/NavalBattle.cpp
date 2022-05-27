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

int main()
{
    std::string types[5] = { "submarine", "tug ship", "destroyer", "cruiser", "aircraft carrier" };

    vector<Boats> p1_boats, p2_boats;

    for (int i = 0; i < 5; i++) {
        p1_boats.push_back(Boats(types[i])); // filling a vector with boats objects, this way the characteristis of each boat dont get lost during the execution of the program
        p2_boats.push_back(Boats(types[i]));
    }
    
    srand(time(0));
    char against; // agains a person or the computer
    matrix(2); // starting a 3D matrix full of zeros
    playerBoard(0); // shows the player one's board on the screen 
    against = randomOrNot(0, p1_boats);

    for (int i = 0; i < p1_boats.size(); i++) {
        p1_boats[i].showAddress();
        std::cout << std::endl << std::endl;
    }

    system("pause");
    if (against == 'A' || against == 'a') { // if playing agains a person, then...
        playerBoard(1); // shows the player two's board on the screen
        randomOrNot(1, p2_boats); // set the position of the player two's boats on the board

        for (int i = 0; i < p2_boats.size(); i++) {
            p2_boats[i].showAddress();
            std::cout << std::endl << std::endl;
        }
        system("cls");

        std::cout << "------------------------\n\n";
        for (int i = 0; i < p1_boats.size(); i++) {
            p1_boats[i].showAddress();
            std::cout << std::endl << std::endl;
        }

        for (int i = 0; i < p2_boats.size(); i++) {
            p2_boats[i].showAddress();
            std::cout << std::endl << std::endl;
        }
        system("pause");


        //game(randomValues() % 2); // start the game and decides who goes first
        return 0;
    }
    else if (against == 'B' || against == 'b') {
        cout << "----------------------------GENERATING POSITIONS FOR THE COMPUTER----------------------------\n\n";
        randomSet(1, p2_boats);
        //computerGame();
    }

    std::cout << "------------------------\n\n";
    for (int i = 0; i < p1_boats.size(); i++) {
        p1_boats[i].showAddress();
        std::cout << std::endl << std::endl;
    }
    std::cout << "------------------------\n\n";
    for (int i = 0; i < p2_boats.size(); i++) {
        p2_boats[i].showAddress();
        std::cout << std::endl << std::endl;
    }
    system("pause");

    return 0;
}
