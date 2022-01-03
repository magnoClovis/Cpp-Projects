#include <iostream>
#include <string>
#include<windows.h>
#include <random>
#include <time.h>

#include "variables.h"
#include"computer_game.h"
#include"player.h"
#include "boats.h"

using namespace std;


int computerBoard(int column, int row, int layer)
{
    // This function changes an element on the matrix "g_squares" and shows what the changes did on the table
    if (g_squares[row][column][layer] == g_set_boat)
    {
        return 1;
    }
    g_squares[row][column][layer] = g_set_boat;
    return 0;
}

void lockBoat(int layer) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (g_squares[j][i][layer] == g_set_boat) {
                g_squares[j][i][layer] = g_boat;
            }
        }
    }
}

void clearComputerBoard(int column, int row, int layer)
{
    g_squares[row][column][layer] = 0;
}


void computerPositions(int* column, int* row, int axis) { // In this function it is used pointers to modify the values of rows and columns
    switch (axis) {
    case 0:
        *column = randomValues();
        break;
    case 1:
        *row = randomValues();
        break;
    default:
        *row = randomValues();
        *column = randomValues();
    }

}

void cPlayerBoard(int layer) // This function is responsible to print the board on the screen during the game, allowing the player to visualize the game board
{
    int i, j;
    cout << "Welcome to Naval Battle!! First we are setting the position for each boat on the board!" << endl << endl;
    cout << ("     A   B   C   D   E   F   G   H   I   J");
    cout << endl;
    for (i = 0; i < 10; i++) {
        j = 0;
        while (j < 10) {
            /* The conditions below are used for a better visual representation.
            The differences between them are just the number of squares used on each "cout<<"
            statement, so everything on the display will be symmetrical.*/
            if (j == 0 && i <= 9 && (g_squares[i][j][layer] == g_boat || g_squares[i][j][layer] == g_set_boat)) {
                cout << " " << i << " | " << g_squares[i][j][layer] << " |";
            }
            else if (j == 0 && i <= 9) {
                cout << " " << i << " |___|";
            }
            else {
                if ((g_squares[i][j][layer] == g_boat || g_squares[i][j][layer] == g_set_boat)) {
                    cout << " " << g_squares[i][j][layer] << " |";
                }
                else {
                    cout << ("___|");
                }
            }
            j++;
        }
        cout << endl << endl;
    }
}

int computerRepeat(int* column, int* row, int layer, int axis, int* repeated, int square, int* fit) { // This function repeats the code if the user input some position that is not valid

    if (axis == 0) {
        if (((*column + square) <= 9) && *repeated == 0) {
            switch (g_squares[*row][*column + square][layer]) {
            case 83:
                *repeated = 1;
                *column += (square - 1);
                break;
            case 79:
                *repeated = 1;
                *column += (square - 1);
                break;
            default:
                computerBoard(*column + square, *row, layer);
                *repeated = 0;
                return *repeated;
            }
        }

        else if(*fit == 0) {
            *fit = 1;
            *column += (square - 1);
        }


        if ((*column - square) >= 0) {
            
            switch (g_squares[*row][*column - square][layer]) {
            case 83:
                *repeated = 1;
                break;
            case 79:
                *repeated = 1;
                break;
            default:
                computerBoard(*column - square, *row, layer);
                *repeated = 1;
                return *repeated;
            }
            
            if (*repeated == 1) {
                *repeated = 2;
                return *repeated;
            }
        }

        else {
            *repeated = 2;
            return *repeated;
        }
        
    }

    else if (axis == 1) {
        if ((*row + square) <= 9 && *repeated == 0) {
            switch (g_squares[*row + square][*column][layer]) {
            case 83:
                *repeated = 1;
                *row += (square - 1);
                break;
            case 79:
                *repeated = 1;
                *row += (square - 1);
                break;
            default:
                computerBoard(*column, *row + square, layer);
                *repeated = 0;
                return *repeated;
            }
        }

        else if (*fit == 0) {
            *fit = 1;
            *row += (square - 1);
        }

        if ((*row - square) >= 0) {
            
            switch (g_squares[*row - square][*column][layer]) {
            case 83:
                *repeated = 1;
                break;
            case 79:
                *repeated = 1;
                break;
            default:
                computerBoard(*column, *row - square, layer);
                *repeated = 1;
                return *repeated;
            }

            if (*repeated == 1) {
                *repeated = 2;
                return *repeated;
            }
        }

        else {
            *repeated = 2;
            return *repeated;
        }
    } 
}

int setComputerBoard(int layer, string type)
{
    Boats boat; // Creating object
    //system("cls");
    int i, j, column, row, axis, quantity, length, repeated, fit;
    int* pcolumn = &column, * prow = &row, *prepeated = &repeated, *pfit =&fit; // pointers so the value of these variables can be changed and used in more than one function
  
    boat.setLength(type); // setting length characteristic for the object from the boat class
    boat.setQtt(boat.length); // after setting the length, it is then set the quantity of that boat on the board

    quantity = boat.quantity; // savig the quantity of boats in a variable
    length = boat.length; // saving the lenght of the boats in another variable

    axis = randomValues() % 2; // axis = 0, horizontal  ######   axis = 1, vertical

    j = 0;
    
    while (j < quantity) { // this first while loop stands for setting the correct quantity of each boat on the board
        repeated = 0;
        fit = 0;
        for (i = 0; i < length; i++) { // this for loop is used for setting the correct amount of spaces that each boat has
            if (i == 0) { /// if its the first iteration, then.....
                computerPositions(pcolumn, prow, -1); // gets the choosen space from the player
                computerRepeat(pcolumn, prow, layer, axis, prepeated, i, pfit); // checks only for repetition of spaces, no need to check continuity in the first iteration
                cPlayerBoard(1);
                if (repeated == 2){
                    return repeated;
                } 
            }
            else { 
                computerRepeat(pcolumn, prow, layer, axis, prepeated, i, pfit);
                cPlayerBoard(1);
                if (repeated == 2) {
                    return repeated;
                }
            }
        }
        axis = randomValues() % 2; // new axis for new boat
        j++;
    }
    return 0;
}

void computerMatrix()
{
    cout << "----------------------------GENERATING POSITIONS FOR THE COMPUTER----------------------------\n\n";
    string types[] = { "submarine", "tug ship", "destroyer", "cruiser", "aircraft carrier"};
    int layer, set_computer, i;
    layer = 1;
    for (i = 0; i < 5; i++) {
        lockBoat(1);
        set_computer = setComputerBoard(layer, types[i]); // setting the different boats on the board, by using the values on the 'types' array, the objects are created and each one has its characterists of length and quantity
        //system("pause");
        if (set_computer == 2) {
            i = -1;
            matrix();
        }cPlayerBoard(1);
    } lockBoat(1); 
     
}

/*
write a function to lock the older boats by turning their values to another thing different from 'O', then, if a new boat finds it, it is unable to recognize that part as a part of
itself. After all boats are set, the values are again converted to 'O'.
Anothar way of doing that is, instead of turning the boats to something differente from 'O', set the positions first to something already different and then set everything to 'O'.
*/