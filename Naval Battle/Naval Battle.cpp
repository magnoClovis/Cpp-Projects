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

char g_water = '.';
char g_fire = 'X';
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

void playerBoard(int layer) // This function is responsible to print the board on the screen during the game, allowing the player to visualize the game board
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
            if (j == 0 && i <= 9 && g_squares[i][j][layer] == 'O') {
                cout << " " << i << " | " << g_squares[i][j][layer] << " |";
            }
            else if (j == 0 && i <= 9) {
                cout << " " << i << " |___|";
            }
            else {
                if (g_squares[i][j][layer] == 'O') {
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

void board(int column, int row, int layer)
{
    // This function changes an element on the matrix "squares" and show what the changes did on the board
    int i, j; // Again, 'i' represents the rows and 'j' the columns

    g_squares[row][column][layer] = 'O';
    playerBoard(layer);
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
        playerBoard(layer);
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

void setBoat(int layer, string type) { // Sets the destroyer on the board
    Boats boat;

    int i, j, column, row, quantity, length;
    int* pcolumn = &column, * prow = &row;
    bool repeated, horiz, vert;
    bool* prepeated = &repeated;

    boat.setLength(type);
    boat.setQtt(boat.length);

    quantity = boat.quantity;
    length = boat.length;

    j = 0;
    horiz = 0, vert = 0, repeated = 1; // 0 for false and 1 for true

    while (j < quantity) {
        for (i = 0; i < length; i++) {

            cout << "Total of " << type << " on the board: " << j << endl << endl;
            cout << type << ": You have " << quantity << " " << type << "! Each " << type << " occupies " << length << " squares on the board.\n";

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

                    while (horiz == 0 && vert == 0) { // while both horiz and vert are equal to 0, it indicates that the boat isn't either in horizontal or vertical...
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

char SetPlayer(int layer) // This functions stands for letting the players set all the boats on the board
{
    char a;
    string types[] = { "submarine", "tug ship", "destroyer", "cruiser", "aircraft carrier" };
    cout << "Player " << layer+1 << ", please follow the instructions to set the position for each boat." << endl;
  
    for (int i = 0; i < 1; i++) {
        setBoat(layer, types[i]);
    }
    
    cout << "Perfect! All boats have been set!\n\n";
    system("pause");
    system("cls");

    if (layer == 0) {
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
}

void gameBoard(int layer)
{
    int i, j;
    cout << "     A   B   C   D   E   F   G   H   I   J" << endl;
    for (i = 0; i < 10; i++) {
        j = 0;
        while (j < 10) {
            if (j == 0 && i <= 9 && (g_squares[i][j][layer] == g_fire || g_squares[i][j][layer] == g_water)) {
                cout << " " << i << " | " << g_squares[i][j][layer] << " |";
            }
            else if (j == 0 && i <= 9) {
                cout << " " << i << " |___|";
            }
            else {
                if (g_squares[i][j][layer] == g_fire || g_squares[i][j][layer] == g_water) {
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

unsigned int random()
{
    int r;
    srand((unsigned)time(NULL));
    r = rand();
    return r;
}

int winner(int layer)
{
    int i, j;
    bool  O;
    O = false;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (g_squares[i][j][layer] == 'O') {
                return 0;
            }
        }
    }
    return 1;
}

int boardAttack(int *column, int *row, int layer)
{
    // This function changes an element on the matrix "g_squares" and show what the changes did on the table
    int i, j, attack; // 'i' represents teh lines and 'j' the columns
    attack = 0;
    if (g_squares[*row][*column][layer] == 'O'){
        system("cls");
        g_squares[*row][*column][layer] = g_fire;
        gameBoard(layer);
        printf("YOU HIT A BOAT!!\n");
        system("pause");
        system("cls");
        attack = 1;
    }
    else if (g_squares[*row][*column][layer] == g_fire) {
        system("cls");
        gameBoard(layer);
        printf("YOU DIDN'T HIT ANY BOAT!!\n");
        system("pause");
        system("cls");
        attack = 0;
    }
    else {
        system("cls");
        g_squares[*row][*column][layer] = g_water;
        gameBoard(layer);
        printf("YOU DIDN'T HIT ANY BOAT!!\n");
        system("pause");
        system("cls");
        attack = 0;
    }

    return attack;
}

void gameOver(int layer)
{
    int i, j;
    for (i = 0; i < 10; i++) {
        j = 0;
        while (j < 10)
        {
            if (j == 0 && i <= 9 && (g_squares[i][j][layer] == g_fire || g_squares[i][j][layer] == 'O' || g_squares[i][j][layer] == '   ')) {
                cout << i << " " << " | " << g_squares[i][j][layer] << " | ";
            }
            else if (j == 0 && i <= 9) {
                cout << " " << i << " |___| ";
            }
            else {
                if (g_squares[i][j][layer] == g_fire || g_squares[i][j][layer] == 'O' || g_squares[i][j][layer] == '   ') {
                    cout << " " << g_squares[i][j][layer] << " | ";
                }
                else {
                    cout << "___|";
                }
            }
            j++;
        }
        cout << endl << endl;
    }
}

void playerOneAttack(int layer, int* attack, int* win) {
    int column, row;
    int* pcolumn = &column, * prow = &row;
    cout << "It's Player 1's turn!\n";
    gameBoard(layer);
    cout << "Choose the square to attack on Player 2's board. \n";
    positions(pcolumn, prow);
    *attack = boardAttack(pcolumn, prow, layer);
    *win = winner(layer);
    if (*win == 1)
    {
        system("cls");
        cout << "---------PLAYER 1 WON THE GAME!!!---------\n";
        cout << "PLAYER 2'S BOARD\n\n";
        gameOver(1);
        cout << endl;
        system("pause");
        cout << "PLAYER 1'S BOARD\n\n";
        gameOver(0);
        system("pause");
    }
}

void playerTwoAttack(int layer, int* attack, int* win) {
    int column, row;
    int* pcolumn = &column, * prow = &row;
    cout << "It's Player 2's turn!\n";
    gameBoard(layer);
    cout << "Choose the square to attack on Player 1's board. \n";
    positions(pcolumn, prow);
    *attack = boardAttack(pcolumn, prow, layer);
    *win = winner(layer);
    if (*win == 1)
    {
        system("cls");
        cout << "---------PLAYER 2 WON THE GAME!!!---------\n";
        cout << "PLAYER 1'S BOARD\n\n";
        gameOver(1);
        cout << endl;
        system("pause");
        cout << "PLAYER 2'S BOARD\n\n";
        gameOver(0);
        system("pause");
    }
}

void game(unsigned int r)
{
    int layer, win, attack;
    int *pwin = &win, *pattack = &attack;
    win = 0;
    attack = 1;
    cout << "Let's begin the game\n";
    if (r == 0) {
        cout << "Player 1 is the first one to play." << endl;
        system("pause");
        system("cls");
        while (win == 0)
        {
            attack = 1;
            while (attack == 1)
            {
                layer = 1;
                playerOneAttack(layer, pattack, pwin);
                if (win == 1) {
                    return;
                }
            }
            attack = 1;
            while (attack == 1)
            {
                layer = 0;
                playerTwoAttack(layer, pattack, pwin);
                if (win == 1) {
                    return;
                }
            }

        }

    }
    else if (r == 1) {
        cout << "Player 2 is the first one to play." << endl;
        system("pause");
        system("cls");
        while (win == 0)
        {
            attack = 1;
            while (attack == 1)
            {
                layer = 0;
                playerTwoAttack(layer, pattack, pwin);
                if (win == 1) {
                    return;
                }
            }

            attack = 1;
            attack = 1;
            while (attack == 1)
            {
                layer = 1;
                playerOneAttack(layer, pattack, pwin);
                if (win == 1) {
                    return;
                }
            }
        }
    }
}


int main()
{   
    srand((unsigned)time(NULL));
    char against;
    matrix();
    playerBoard(0);
   
    against = SetPlayer(0);
    if (against == 'A' || against == 'a') {
        playerBoard(1);
        SetPlayer(1);
        game(random()%2);
    }
    

    return 0;
}