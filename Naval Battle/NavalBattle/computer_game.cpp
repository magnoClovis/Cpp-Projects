#include <iostream>
#include <string>
#include<windows.h>
#include <random>
#include <time.h>
#include <windows.data.json.h>


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

void computerPositions(int* column, int* row, int axis) { // In this function it is used pointers to modify the values of rows and columns according to the axis
    switch (axis) {
    case 0:
        *column = randomValues(); // if horizontal, change only the value of the column and keep the row
        break;
    case 1:
        *row = randomValues(); // if vertical, change only the row and keep the column the same
        break;
    default:   // if the axis is not stablished yet, then set both, column and row 
        *row = randomValues();
        *column = randomValues();
    }

}

void cPlayerBoard(int layer) // This function is just used for testing the generation of random positions, during the game this function is not used. It displays the board on the screen showing the positions generated for the computer
{
    int i, j;
    cout << endl;
    for (i = 0; i < 10; i++) {
        j = 0;
        while (j < 10) {
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

int computerRepeat(int* column, int* row, int layer, int axis, int* repeated, int square, int* fit) { // This function checks if the positions chosed randomly are valid or not.
                                                                                                     // This function also choose the next postions for the boat after the first one is choosed, after it,
                                                                                                    // it checks if this square is valid or not before setting it on the board.
    if (axis == 0) { // if horizontal, then....
        if (((*column + square) <= 9) && *repeated == 0) { // checks if the value of the column + the next possible value is something smaller than 9
            switch (g_squares[*row][*column + square][layer]) { // if so, verifies if the position is already filled
            case 83: // if it's filled with and 'S' (83 in ASCII), it's invalid, then, 'repeated' is set to 1, showing this position is already filled
                *repeated = 1;
                *column += (square - 1); // column set to column + square - 1, which means the starting point is now the last position informed and the next squares will be placed following this starting point
                break;
            case 79: // if the square is filled with an 'O' (79 in ASCII), it's also invalid, then 'repeated' is set to 1, also showing this square is filled already and the same stuff as the ones done before are done in the lines below
                *repeated = 1;
                *column += (square - 1);
                break;
            default: // if the value at the square isn't either 83 or 79, then the position is free to use 
                computerBoard(*column + square, *row, layer); // calls the function responsible for setting the boats on the board
                *repeated = 0; // the position is obviously not repeated
                return *repeated; // returns
            }
        }

        else if (*fit == 0) { // if the condition below is false, it means the value informed either greater than 9, then this block of code runs
            *fit = 1; // the variable fit is set to 1, indicating the value is greater then the maximum allowed
            *column += (square - 1); // samething done in the lines above
        }


        if ((*column - square) >= 0) { // so, if it's a value greater then 9 or repeated, the program tries to fill and set the boat in the opposite direction as before 

            switch (g_squares[*row][*column - square][layer]) { // the exact same thing done above is done here, the only difference is that now we're checking for positions in another direction
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

            if (*repeated == 1) {// if up there we find another repetition of positions, then the boat can't be placed in de space it was suposed to be..
                *repeated = 2; //... so the value of repeated is set to 2 ...
                return *repeated; //... then it's returned, when the functions returns 2, all the board is reseted and new attempt to set all the boats will be made
            }
        }

        else { // if the condition above is false, then the possible next position for the boat would be some value below 0, that's impossible...
            *repeated = 2; // then, as the other if statement inside the last condition, it shows that the boat can't be placed in the space randomly chosed, so all the boats will be reseted
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

        else if (*fit == 0) { // same as before
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

int setRandomBoard(int layer, string type) // set each boat in the board
{
    Boats boat; // Creating object
    int i, j, column, row, axis, quantity, length, repeated, fit;
    int* pcolumn = &column, * prow = &row, * prepeated = &repeated, * pfit = &fit; // pointers so the value of these variables can be changed and used in more than one function

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
                computerPositions(pcolumn, prow, -1); // generates random values for row and column
                computerRepeat(pcolumn, prow, layer, axis, prepeated, i, pfit); // checks for repetitions and sets the boats on the boeard if everything is correct
                //cPlayerBoard(1); // shows the board (only used while programming to check if everything is fine, during the game this function is not called)
                if (repeated == 2) {
                    return repeated;
                }
            }
            else {
                computerRepeat(pcolumn, prow, layer, axis, prepeated, i, pfit);
                //cPlayerBoard(1);
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

int attackPC(int* hit_or_miss)
{
    int column, row, win, layer;
    layer = 0;
    win = winner(0);
    while (*hit_or_miss == 1)
    {
        column = randomValues();
        row = randomValues();
        if (g_squares[row][column][layer] == g_boat)// 'b' represents the lines and 'a' the columns
        {
            system("cls");
            g_squares[row][column][layer] = g_fire;
            gameBoard(0);
            cout << "\nCOMPUTER HIT A BOAT!!";
            printf("\nBOAT ATTACKED ON POSITION: %c%d\n", column + 65, row);
            win = winner(0);
            cout << endl << "REMAINING PARTS: " << win << endl;
            system("pause");
            system("cls");
            win = winner(0);
            if (win == 0) {
                system("cls");
                cout << "---------COMPUTER WON THE GAME!!!---------\n";
                cout << "COMPUTER'S BOARD\n\n";
                gameOver(1);
                cout << endl;
                system("pause");
                cout << "PLAYER 1'S BOARD\n\n";
                gameOver(0);
                system("pause");
                return win;
            }
        }
        else if (g_squares[row][column][layer] == g_fire || g_squares[row][column][layer] == g_water) {
            *hit_or_miss = 1;
        }
        else {
            system("cls");
            g_squares[row][column][layer] = g_water;
            gameBoard(0);
            cout << "\nCOMPUTER DIDN'T HIT ANY BOAT!!";
            printf("\nATTACKED POSITION: %c%d\n", column + 65, row);
            win = winner(0);
            cout << endl << "REMAINING PARTS: " << win << endl;
            system("pause");
            system("cls");
            *hit_or_miss = 0;
        }
    }
    return win;
}

void randomSet(int layer)
{
    string types[] = { "submarine", "tug ship", "destroyer", "cruiser", "aircraft carrier" };
    int set_computer, i;
    i = 0;
    matrix(layer);
    for (i; i < 5; i++) {
        lockBoat(layer); // lock the boats as explained before
        set_computer = setRandomBoard(layer, types[i]); // setting the different boats on the board, by using the values on the 'types' array, the objects are created and each one has its characterists of length and quantity
        if (set_computer == 2) {
            i = -1;
            matrix(layer);
        }//cPlayerBoard(layer);
    } lockBoat(layer); //cPlayerBoard(layer);
}

void computerGame() {
    int layer, win, attack;
    int* pattack = &attack;
    win = 1;
    attack = 1; // starts in 1 so some of the loops can start and keep running if the player hits a boat
    cout << "Let's begin the game\n";
    cout << "Player 1 is the first one to play." << endl;
    system("pause");
    system("cls");
    layer = 1;
    while (win != 0)
    {
        attack = 1;
        while (attack == 1) // while the player one hits a boat, then this loop keep on running
        {
            win = playerOneAttack(layer, pattack, 1);
            if (win == 0) {
                return;
            }
        }
        attack = 1;
        while (attack == 1) // same for the computer
        {
            win = attackPC(pattack);
            if (win == 0) {
                return;
            }
        }

    }
}