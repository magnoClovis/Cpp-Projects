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
    // This function changes an element on the matrix "squares" when the player is setting the boats on the board, 
    // and show what the changes did on the board
    g_squares[row][column][layer] = 'O';
    playerBoard(layer);
}

int _getch() {// This function is responsible to get the inputs from the players, everytime something need to be inputed, this function is called
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
    while (*column < 65 || *column>74 && (*column < 97 || *column>106)) // Checks if the input is a letter between A and J
    {
        cout << "Input a valid option!!\n";;
        *column = _getch();
    }
    cout << "Now, input the ROW using numbers from '0' to '9'.\n";
    *row = _getch() - 48; // Converts 'char' numbers to their values in 'int' using ASCII
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

bool vertical(int* column, int* row, int layer) { // Here it is verified if the input of the boat on the board is in vertical
    bool vert = 0;
    if (g_squares[*row - 1][*column][layer] == 79 || g_squares[*row + 1][*column][layer] == 79) { // This condition verifies the continuity in the vertical axis
        vert = true;
        return vert;
    }
    else { return false;  }
}

bool horizontal(int* column, int* row, int layer) { // Here it is verified if the input of the boat on the board is in horizontal
    bool horiz = 0;
    if (g_squares[*row][*column - 1][layer] == 79 || g_squares[*row][*column + 1][layer] == 79) { // This condition verifies the continuity in the horizontal axis
        horiz = true;
        return horiz;
    }
    else { return false; }
}

void clearBoard(int column, int row, int layer) { // This function is responsible for cleaning a specific space of the board by setting its value to zero if the player
                                                  // inputs an invalid value while setting the boats on the board

    int i, j;

    g_squares[row][column][layer] = 0; // clear the space by setting its value to zero

    cout << "     A   B   C   D   E   F   G   H   I   J" << endl;

    for (i = 0; i < 10; i++) { // shows the board with no changes 
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

void setBoat(int layer, string type) { // Here the boats are set in the board, for that it is used some of the functions above and, in order to help, objects from the 'Boats' class are created
    Boats boat; // Creating object
    int i, j, column, row, quantity, length;
    int* pcolumn = &column, * prow = &row; // pointers so the value of these variables can be changed and used in more than one function
    bool repeated, horiz, vert; // bools for checking continuity and repetition of choosen squares while the player is setting the boats on the board
    bool* prepeated = &repeated; // pointer so the value of the boolean variable 'repeated' can be changed and used in more than one function

    boat.setLength(type); // setting length characteristic for the object from the boat class
    boat.setQtt(boat.length); // after setting the length, it is then set the quantity of that boat on the board

    quantity = boat.quantity; // savig the quantity of boats in a variable
    length = boat.length;// saving the lenght of the boats in another variable

    j = 0;
    horiz = 0, vert = 0, repeated = 1; // 0 for false and 1 for true

    while (j < quantity) { // this first while loop stands for setting the correct quantity of each boat on the board
        for (i = 0; i < length; i++) { // this for loop is used for setting the correct amount of spaces that each boat has

            cout << "Total of " << type << " on the board: " << j << endl << endl;
            cout << type << ": You have " << quantity << " " << type << "! Each " << type << " occupies " << length << " squares on the board.\n";

            positions(pcolumn, prow); // gets the choosen space from the player
            if (i == 0) { /// if its the first iteration, then.....
                repeated = repeat(pcolumn, prow, layer); // checks only for repetition of spaces, no need to check continuity in the first iteration
            }
           
            else if (i == 1) { // if it is the second iteration, then...
                repeated = repeat(pcolumn, prow, layer); // first, check for repetition as before in the first iteration
                if (repeated == 0) { // then check continuity and identify the axis (vertical or horizontal)
                    horiz = horizontal(pcolumn, prow, layer); // horiz will be equal to 1 if the boat is horizontal on the board
                    vert = vertical(pcolumn, prow, layer); // vert will be equal to 1 if the boat is vertical on the board

                    while (horiz == 0 && vert == 0) { // while both horiz and vert are equal to 0, it shows that the boat isn't either in horizontal or vertical...
                        system("cls");               // ...in other words, there's no continuity   
                        clearBoard(column, row, layer); // erase the last square informed, since this position is invalid
                        cout << "---------INVALID POSITION---------\nInput a position close to the last one.\n";
                        positions(pcolumn, prow); // gets another position
                        repeated = repeat(pcolumn, prow, layer); // checks again for repetition of spaces
                        horiz = horizontal(pcolumn, prow, layer); // checks continuity on horizontal again
                        vert = vertical(pcolumn, prow, layer); // checks continuity on vertical again
                    }
                    system("cls");
                    board(column, row, layer); // if everything is ok, then set the position on the board and then show it on the screen.
                }
            }

            else { // after the second loop
                repeated = repeat(pcolumn, prow, layer); // again, first set for repetitions
                // after getting the 2 later squares on the board, we already know whether the boat is on the horizontal or vertical axis and the user must finish input the boat on the same axis
                if (horiz == 1) { // if the horizontal axis is the axis choosed for the player, then this if block will be executed and it looks for horizontal continuity
                    horiz = horizontal(pcolumn, prow, layer); // checks for horizontal continuity
                    while (horiz == 0) { // while the user keeps on inputing invalid positions, either because its far from the last ones, either bcz it's not on the same axis, this loop runs
                        system("cls");
                        clearBoard(column, row, layer); // clear the last invalid position informed
                        cout << "---------INVALID POSITION---------\nInput a position close to the last one and in the same row.\n";
                        positions(pcolumn, prow); // asks for other values
                        repeated = repeat(pcolumn, prow, layer); // checks for repetitions
                        horiz = horizontal(pcolumn, prow, layer); // checks for horizontal continuity again (note that for this if block the value of horizontal can be changed, but the vertical can't)
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
                        vert = vertical(pcolumn, prow, layer); // again, here the value of vertical can be changed, but the horizontal can't
                    }
                }
            }
        }
        j++;
    }
}

char SetPlayer(int layer) // This functions stands for letting both players set all the boats on the board
{
    char a;
    string types[] = { "submarine", "tug ship", "destroyer", "cruiser", "aircraft carrier" }; //listing all the existing boats so then it can be used in the 'setBoat' function
    cout << "Player " << layer+1 << ", please follow the instructions to set the position for each boat." << endl;
  
    for (int i = 0; i < 1; i++) {
        setBoat(layer, types[i]); // setting the different boats on the board, by using the values on the 'types' array, the objects are created and each one has its characterists of length and quantity
    }
    
    cout << "Perfect! All boats have been set!\n\n";
    system("pause");
    system("cls");

    if (layer == 0) {
        cout << "The game will be:\nA. Against a person\nB. Against the computer\n"; // choose if the game will be played against a person or a computer
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

void gameBoard(int layer) // This functions shows the changes on the board during the game
{
    int i, j;
    cout << "     A   B   C   D   E   F   G   H   I   J" << endl;
    for (i = 0; i < 10; i++) {
        j = 0;
        while (j < 10) {
            if (j == 0 && i <= 9 && (g_squares[i][j][layer] == g_fire || g_squares[i][j][layer] == g_water)) { // whether the player hits a boat or not, it shows on the screen what happened
                cout << " " << i << " | " << g_squares[i][j][layer] << " |";                                   // if a boat is hit, a 'X' is shown on the board, if nothing is hit, then a '.' is shown 
            }
            else if (j == 0 && i <= 9) {
                cout << " " << i << " |___|";
            }
            else {
                if (g_squares[i][j][layer] == g_fire || g_squares[i][j][layer] == g_water) { // same as above
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

unsigned int random() { // getting positive random values for both: choosing who starts and also automatically setting the positions for the computer in case the player plays agains the computer 
    int r;
    srand((unsigned)time(NULL));
    r = rand();
    return r;
}

int winner(int layer) { // checks if someone have won the game
    int i, j;
    bool  O;
    O = false;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (g_squares[i][j][layer] == 'O') { // a player wins if its opponent board has no "O"s, which indicates the player has found all the boats of their opponent
                return 0; // if an 'O' is found, then theres no win, then, return 0
            }
        }
    }
    return 1; // if no 'O' in found, it shows that all the boats have been found and so there's a win, then, the code will end here in this line and '1' will be returned
}

int boardAttack(int *column, int *row, int layer) {
    // This function changes an element on the matrix "g_squares" and show what the changes did on the table
    int attack = 0;
    if (g_squares[*row][*column][layer] == 'O'){ // hit a boat
        system("cls");
        g_squares[*row][*column][layer] = g_fire;
        gameBoard(layer);
        printf("YOU HIT A BOAT!!\n");
        system("pause");
        system("cls");
        attack = 1;
    }
    else if (g_squares[*row][*column][layer] == g_fire) { // if the player attacks a square where there is a boat but it has already been attacked, then it counts as if the player did not hit anything
        system("cls");
        gameBoard(layer);
        printf("YOU DIDN'T HIT ANY BOAT!!\n");
        system("pause");
        system("cls");
        attack = 0;
    }
    else { // else, if the position does not have a non hit boat or an already hit boat, so it's water and the player didn't hit anything
        system("cls");
        g_squares[*row][*column][layer] = g_water;
        gameBoard(layer);
        printf("YOU DIDN'T HIT ANY BOAT!!\n");
        system("pause");
        system("cls");
        attack = 0;
    }
    return attack; // returns 1 if hits a boat, 0 if did not hit any
}

void gameOver(int layer) { // screens the boards after a win showing all the hit and non hit boats
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

void playerOneAttack(int layer, int* attack, int* win) { // fuctions played when player one attacks
    int column, row;
    int* pcolumn = &column, * prow = &row; 
    cout << "It's Player 1's turn!\n";
    gameBoard(layer); // shows player 2's board on the screen
    cout << "Choose the square to attack on Player 2's board. \n";
    positions(pcolumn, prow); // gets the position to attack
    *attack = boardAttack(pcolumn, prow, layer); // attacks
    *win = winner(layer); // checks for wins
    if (*win == 1) // if there's a win, then...
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

void playerTwoAttack(int layer, int* attack, int* win) { // fuctions played when player two attacks, the same used in the lest function is used here, but for the player 2
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

void game(unsigned int r) // this function is where the game starts after the players set all the boats on the board
{
    int layer, win, attack;
    int *pwin = &win, *pattack = &attack;
    win = 0;
    attack = 1; // starts in 1 so some of the loops can start and keep running if the player hits a boat
    cout << "Let's begin the game\n";
    if (r == 0) {
        cout << "Player 1 is the first one to play." << endl;
        system("pause");
        system("cls");
        while (win == 0)
        {
            attack = 1;
            while (attack == 1) // while the player one hits a boat, then this loop keep on running
            {
                layer = 1;
                playerOneAttack(layer, pattack, pwin);
                if (win == 1) {
                    return;
                }
            }
            attack = 1;
            while (attack == 1) // same for player two
            {
                layer = 0;
                playerTwoAttack(layer, pattack, pwin);
                if (win == 1) {
                    return;
                }
            }

        }

    }
    else if (r == 1) { // the same happens here when player 2 is the first one to play
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