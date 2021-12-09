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
//#include "source.h"

using namespace std;

char g_squares[10][10][2];

void matrix()
{
    // This function is responsible to generate and print a matrix full of zeros.
    // This matrix will be used to record the boats and ships positions for the game.
    int i, j, c; // 'i' represents the lines and 'j' the columns.
    for (c = 0; c < 2; c++) {
        if (c == 1) { cout << ("\n"); }

        for (i = 0; i < 10; i++) {
            j = 0;
            while (j < 10) {
                g_squares[i][j][c] = 48; // 48 == 0(zero) in ASCII table
                //cout << g_squares[i][j][c] << " "; // if for some reason it's necessary to take a look at the matrix of zeros, then uncomment this line and the othes cout below
                j++;
            }
            //cout << endl;
        }
    }
   //cout << endl;
}

void showBoard()
{
    int i, j;
    cout << "Welcome to Naval Battle!! First we are setting the position for each boat on the board!" << endl << endl;
    // The lines below print on the screen the table for showing what is happening on the matrix in a better dynamic way
    cout << "     A   B   C   D   E   F   G   H   I   J" << endl;
    for (i = 0; i < 10; i++) {
        j = 0;
        while (j < 10) {
            if (j == 0 && i <= 9) {
                cout << " " << i << " |___|";
            }
            else {
                cout << "___|";
            }
            j++;
        }
        cout << endl << endl;
    }

}

void gameBoard(int c) // This function is responsible to print the board on the screen during the game, allowing the player to visualize the game board
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
            if (j == 0 && i <= 9 && g_squares[i][j][c] == 'O') {
                cout << i << " | " << g_squares[i][j][c] << " |";
            }
            else if (j == 0 && i <= 9) {
                cout << " " << i << " |___|";
            }
            else {
                if (g_squares[i][j][c] == 'O') {
                    cout << " " << g_squares[i][j][c] << " |";
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

void board(int column, int row, int layer)
{
    // This function changes an element on the matrix "squares" and show what the changes did on the board
    int i, j; // Again, 'i' represents the rows and 'j' the columns

    g_squares[row][column][layer] = 'O';
    gameBoard(layer);
}

int _getch()
{
    char ch;
    ch = '\n';
    while (ch == '\n')
    {
        ch = getchar();
        if (ch == '\n')
        {
            cout << "Type a valid value!";
            ch = getchar();
        }
    }
    while (getchar() != '\n');
    return ch;
}

void positions(int* column, int* row) { // In this function it is used pointers to modify the values of rows and columns
    cout << "Type a COLUMN using a letter from A to J.\n";
    *column = _getch();
    while (*column < 65 || *column>74 && (*column < 97 || *column>106)) // Verifies if the input is a letter between A and J
    {
        cout << "Input a valid option!!\n";;
        *column = _getch();
    }
    cout << "Now, input the ROW using numbers from '0' to '9'.\n";
    *row = _getch() - 48;
    if (*column < 97) { // Converts capital and lower case letters in numbers from 0 to 9
        *column = *column - 65;
    }
    else {
        *column = *column - 97;
    }
    system("cls");
}

int repeat(int* column, int* row, int layer) { // This function repeats the code if the user input some position that is not valid

    bool repeated;
    repeated = false;
    while (g_squares[*row][*column][layer] == 79) // Verifies if the space is already filled with the letter 'O' (79 in ASCII)
    {
        gameBoard(layer);
        cout << "Choose a position that has not been choosen yet!!\n";
        positions(column, row); //Here in this function, column and row are already pointers, thats why it's not being passed pcolumn/ prow as arguments to "positions".
        system("cls");
    }
    board(*column, *row, layer);
    return repeated;
}


bool vertical(int* column, int* row, int layer) {
    bool vert = 0;
    if (g_squares[*row - 1][*column][layer] == 79 || g_squares[*row + 1][*column][layer] == 79) { // verifies continuity in vertica
        vert = true;
        return vert;
    }
    else { return false;  }
}

bool horizontal(int* column, int* row, int layer) {
    bool horiz = 0;
    if (g_squares[*row][*column - 1][layer] == 79 || g_squares[*row][*column + 1][layer] == 79) { // verifies continuity in horizontal
        horiz = true;
        return horiz;
    }
    else { return false; }
}

void clearBoard(int column, int row, int layer) {

    int i, j;

    g_squares[row][column][layer] = 0; // clear the space by setting its value to zero

    cout << "     A   B   C   D   E   F   G   H   I   J" << endl;

    for (i = 0; i < 10; i++) { // shows the board
        j = 0;
        while (j < 10) {
            if (j == 0 && i <= 9 && g_squares[i][j][layer] == 79) {
                cout << " " << i << " | " << g_squares[i][j][layer] << " |";
            }
            else if (j == 0 && i <= 9) {
                cout << " " << i << " |___|";
            }
            else {
                if (g_squares[i][j][layer] == 79) {
                    cout << " " << g_squares[i][j][layer] << " |";
                }
                else {
                    cout << "___|";
                }
            }
            j++;
        }
        cout << "\n\n";
    }
}

void submarine(int layer, int quantity, int length) //This function is responsible to set the positions for the submarines
{
    int i, column, row;
    int* pcolumn = &column, * prow = &row;
    for (i = 0; i < quantity; i++) {
        cout << "Total of submarines on the board: " << i << endl << endl;
        cout << "SUBMARINES: You have " << quantity << " submarines! Each submarine occupies " << length << " square on the board.\n";
        positions(pcolumn, prow);
        repeat(pcolumn, prow, layer);
    }

}

void tugShip(int layer, int quantity, int length)
{
    int i, j, column, row;
    int* pcolumn = &column, * prow = &row;
    bool repeated, horiz, vert;
    bool* prepeated = &repeated;
    j = 0;
    horiz = 0, vert = 0, repeated = 1;
    while (j < quantity) {
        for (i = 0; i < length; i++) {
            cout << "Total of Tug Ships on the board: " << j << endl << endl;
            cout << "TUG SHIP: You have " << quantity << " tug ships! Each tug ship occupies " << length << " squares on the board.\n";

            positions(pcolumn, prow);
            repeated = repeat(pcolumn, prow, layer);

            if (i == 1) {
                horiz = horizontal(pcolumn, prow, layer);
                vert = vertical(pcolumn, prow, layer);

                while (horiz == 0 && vert == 0) {
                    system("cls");
                    clearBoard(column, row, layer);
                    cout << "---------INVALID POSITION---------\nInput a position close to the last one.\n";
                    positions(pcolumn, prow);
                    repeated = repeat(pcolumn, prow, layer);
                    horiz = horizontal(pcolumn, prow, layer);
                    vert = vertical(pcolumn, prow, layer);
                }
                system("cls");
                board(column, row, layer);
            }
        }
        j++;
    }
}

void destroyer(int layer, int quantity, int length) { // Sets the destroyer on the board
    int i, j, column, row;
    int* pcolumn = &column, *prow = &row;
    bool repeated, horiz, vert;
    bool* prepeated = &repeated;
    j = 0;
    horiz = 0, vert = 0, repeated = 1; // 0 for false and 1 for true

    while (j < quantity) {
        for (i = 0; i < length; i++) {

            cout << "Total of Destroyers on the board: " << j << endl << endl;
            cout << "DESTROYER: You have " << quantity << " destroyer! The destroyer occupies " << length << " squares on the board.\n";

            positions(pcolumn, prow);
            if (i == 0) {
                repeated = repeat(pcolumn, prow, layer); // checking only repetitions, no need to check continuity at the first iteration
            }
            // this 'else if' block can be transformed into a function
            else if (i == 1) {
                repeated = repeat(pcolumn, prow, layer); // check repetition
                if (repeated == 0) { // then check continuity and identify the axis
                    horiz = horizontal(pcolumn, prow, layer); // horiz will be equal to 1 if the boat is horizontal on the board
                    vert = vertical(pcolumn, prow, layer); // vert will be equal to 1 if the boat is vertical on the board

                    while (horiz == 0 && vert == 0){ // while both horiz and vert are equal to 0, it indicates that the boat isn't either in horizontal or vertical...
                        system("cls");               // ...in other words, there's no continuity   
                        clearBoard(column, row, layer); // erase the last square informed, since this position is invalid
                        cout << "---------INVALID POSITION---------\nInput a position close to the last one.\n";
                        positions(pcolumn, prow); // gets another position
                        repeated = repeat(pcolumn, prow, layer);
                        horiz = horizontal(pcolumn, prow, layer); // checks continuity on horizontal again
                        vert = vertical(pcolumn, prow, layer); // checks continuity on vertical again
                    }
                    system("cls");
                    board(column, row, layer); // if everything is ok, then set the position on the board and then show it on the screen.
                }
            }

            // This last block can also be transformed into another function
            else { // after the second loop
                repeated = repeat(pcolumn, prow, layer);
                if (horiz == 1) { // after getting the 2 later squares on the board, we already know whether the boat is on the horizontal or vertical axis and the user must finish informing it on the same axis
                    horiz = horizontal(pcolumn, prow, layer);
                    while (horiz == 0) { // while the user keeps on inputing invalid positions, either because its far from the last ones, either bcz it's not on the same axis, this loop runs
                        system("cls");
                        clearBoard(column, row, layer);
                        cout << "---------INVALID POSITION---------\nInput a position close to the last one and in the same row.\n";
                        positions(pcolumn, prow);
                        repeated = repeat(pcolumn, prow, layer);
                        horiz = horizontal(pcolumn, prow, layer);
                    }
                }
                
                else { // same logic as before, but for the vertical axis
                    vert = vertical(pcolumn, prow, layer);
                    while (vert == 0) {
                        system("cls");
                        clearBoard(column, row, layer);
                        cout << "---------INVALID POSITION---------\nInput a position close to the last one and in the same column .\n";
                        positions(pcolumn, prow);
                        repeated = repeat(pcolumn, prow, layer);
                        vert = vertical(pcolumn, prow, layer);
                    }
                }
            }
        }
        j++;
    }
}

char SetPlayer1(int quantity, int length) // This functions stands for letting the Player 1 set all the boats on the board
{
    int layer = 0;
    char a;
    //submarine(layer, quantity, length);
    tugShip(layer, quantity, length);
    //destroyer(layer, quantity, length);
    //cruzado(c);
    //porta(c);
    cout << "Perfect! All boats have been set!\n\n";
    system("pause");
    system("cls");
    cout << "The game will be:\nA. Against a person\nB. Against the computer\n";
    a = _getch();
    while (true)
    {
        if (a == 'A' || a == 'a')
        {
            return a;
        }
        if (a == 'B' || a == 'b')
        {
            return a;
        }
        else
        {
            cout << "Input a valid option!!\n";
            cout << "The game will be:\nA. Against a person\nB. Against the computer\n";
            a = _getch();
        }
    }
}

int main()
{
    matrix();
    gameBoard(0);
    cout << "Player 1, please follow the instructions to set the position for each boat." << endl;

    Boats submarine, tug_ship, destroyer, cruiser, aircraft, none;
    submarine.setLength("submarine");
    submarine.setQtt(submarine.length);

    tug_ship.setLength("tug ship");
    tug_ship.setQtt(tug_ship.length);

    destroyer.setLength("destroyer");
    destroyer.setQtt(destroyer.length);

    cruiser.setLength("cruiser");
    aircraft.setLength("aircraft carrier");
    none.setLength("none boat");

    SetPlayer1(tug_ship.quantity, tug_ship.length);

    cout << "submarine length: " << submarine.length << endl;
    cout << "tug ship length: " << tug_ship.length << endl;
    cout << "destroyer length: " << destroyer.length << endl;
    cout << "cruiser length: " << cruiser.length << endl;
    cout << "aircraft carrier length: " << aircraft.length << endl;
    cout << "none boat length: " << none.length << endl;

    return 0;
}
