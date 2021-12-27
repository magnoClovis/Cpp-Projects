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
    // This function changes an element on the matrix "casas" and show what the changes did on the table
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


int computerRepeat(int* column, int* row, int layer, int axis) { // This function repeats the code if the user input some position that is not valid

    int repeated = 0;
    while (g_squares[*row][*column][layer] == g_set_boat || g_squares[*row][*column][layer] == g_boat) // Verifies if the space is already filled with the letter 'O' (79 in ASCII)
    {
        computerPositions(column, row, axis); //Here in this function, column and row are already pointers, thats why it's not being passed pcolumn/ prow as arguments to "positions".
        repeated++;
        if (repeated > 100) {
            return repeated;
        }
    }
    computerBoard(*column, *row, layer);
    return repeated;
}

int setComputerBoard(int layer, string type)
{
    Boats boat; // Creating object
    system("cls");
    int i, j, column, row, axis, quantity, length, repeated;
    int* pcolumn = &column, * prow = &row; // pointers so the value of these variables can be changed and used in more than one function
    bool horiz, vert; // bools for checking continuity and repetition of choosen squares while the player is setting the boats on the board
    int* prepeated = &repeated; // pointer so the value of the boolean variable 'repeated' can be changed and used in more than one function

    boat.setLength(type); // setting length characteristic for the object from the boat class
    boat.setQtt(boat.length); // after setting the length, it is then set the quantity of that boat on the board

    quantity = boat.quantity; // savig the quantity of boats in a variable
    length = boat.length; // saving the lenght of the boats in another variable

    axis = randomValues() % 2; // axis = 0, horizontal  ######   axis = 1, vertical

    j = 0;
    repeated = 1; // 0 for false and 1 for true

    while (j < quantity) { // this first while loop stands for setting the correct quantity of each boat on the board
        system("cls");
        for (i = 0; i < length; i++) { // this for loop is used for setting the correct amount of spaces that each boat has
            system("cls");

            if (i == 0) { /// if its the first iteration, then.....
                computerPositions(pcolumn, prow, -1); // gets the choosen space from the player
                repeated = computerRepeat(pcolumn, prow, layer, axis); // checks only for repetition of spaces, no need to check continuity in the first iteration
                if (repeated > 100){
                    return repeated;
                }
                playerBoard(1);
                
            }
            else { // if it is the second iteration, then...    
                computerPositions(pcolumn, prow, axis);
                repeated = computerRepeat(pcolumn, prow, layer, axis); // first, check for repetition as before in the first iteration
                if (repeated > 100) {
                    return repeated;
                }
                if (repeated == 0) { // then check continuity and identify the axis (vertical or horizontal)
                    if (axis == 0) {
                        playerBoard(1);
                        horiz = horizontal(pcolumn, prow, layer);
                            while (horiz == 0) {
                                playerBoard(1);
                                clearComputerBoard(column, row, layer);
                                computerPositions(pcolumn, prow, axis);
                                repeated = computerRepeat(pcolumn, prow, layer, axis);
                                if (repeated > 100) {
                                    return repeated;
                                }
                                horiz = horizontal(pcolumn, prow, layer);
                                system("cls");
                            }  
                    }
                    else if (axis == 1) {
                        playerBoard(1);
                        vert = vertical(pcolumn, prow, layer);
                        while (vert == 0) {
                            playerBoard(1);
                            clearComputerBoard(column, row, layer);
                            computerPositions(pcolumn, prow, axis);
                            repeated = computerRepeat(pcolumn, prow, layer, axis);
                            if (repeated > 100) {
                                return repeated;
                            }
                            vert = vertical(pcolumn, prow, layer);
                            system("cls");
                        }
                    }
                }
                    //computerBoard(column, row, layer); // if everything is ok, then set the position on the board and then show it on the screen.
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
    string types[] = { "submarine", "tug ship", "destroyer", "cruiser", "aircraft carrier" };
    int layer, set_computer;
    layer = 1;
    for (int i = 0; i < 5; i++) {
        lockBoat(1);
        set_computer = setComputerBoard(layer, types[i]); // setting the different boats on the board, by using the values on the 'types' array, the objects are created and each one has its characterists of length and quantity
        //system("pause");
        if (set_computer > 100) {
            i = 0;
            matrix();
        }
    } lockBoat(1); playerBoard(1);

}

/*
write a function to lock the older boats by turning their values to another thing different from 'O', then, if a new boat finds it, it is unable to recognize that part as a part of
itself. After all boats are set, the values are again converted to 'O'.
Anothar way of doing that is, instead of turning the boats to something differente from 'O', set the positions first to something already different and then set everything to 'O'.
*/