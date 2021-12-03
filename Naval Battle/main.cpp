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

using namespace std;

char squares[10][10][2];

void matrix()
{
    // This function is responsible to generate and print a matrix full of zeros.
    // This matrix will be used to record the boats and ships positions for the game.
    int i,j,c; // 'i' represents the lines and 'j' the columns.

    for(c=0;c<2;c++){
            if (c==1){cout<<("\n");}

            for(i=0;i<10;i++){
            j=0;
               while(j<10) {
                    squares[i][j][c] = 48; // 48 == 0(zero) in ASCII table
                    if(squares[i][j][c] == 48){
                    cout << squares[i][j][c] << " ";
                    }
                    else{
                        cout<< squares[i][j][c] << " ";
                    }
                    j++;
               }
               cout<< endl;
            }
    }
    cout<< endl;
}

void showBoard()
{
    int i, j;
    cout << "Welcome to Naval Battle!! First we are setting the position for each boat on the board!" << endl << endl;
    // The lines below print on the screen the table for showing what is happening on the matrix in a better dynamic way
    cout << "     A   B   C   D   E   F   G   H   I   J" << endl;
    for(i=0;i<10;i++){
        j=0;
        while(j<10) {
            if (j==0&&i<=9){
                cout << " " << i << " |___|";
            }
            else{
                cout << "___|";
            }
            j++;
       }
       cout << endl << endl;
    }

}

void gameBoard(int c) // This function is responsible to print the board on the screen during the game, allowing the player to visualize the game board
{
    int i,j;
    cout << "Welcome to Naval Battle!! First we are setting the position for each boat on the board!" << endl << endl;
    cout<<("     A   B   C   D   E   F   G   H   I   J");
    cout<<endl;
    for(i=0;i<10;i++){
            j=0;
            while(j<10) {
                /* The conditions below are used for a better visual representation.
                The differences between them are just the number of squares used on each "cout<<"
                statement, so everything on the display will be symmetrical.*/
                if (j==0&&i<=9&&squares[i][j][c]=='O'){
                    cout<< i << " | " << squares[i][j][c] << " |";
                }
                else if(j==0&&i<=9){
                    cout<< " " << i <<" |___|";
                }
                else{
                    if(squares[i][j][c]=='O'){
                        cout<< " " << squares[i][j][c] << " |";
                    }
                else{
                    cout<<("___|");
                }
                }
                j++;
            }
            cout<<endl<<endl;
    }
}

void board(int column, int row, int layer)
{
    // This function changes an element on the matrix "squares" and show what the changes did on the board
    int i,j; // Again, 'i' represents the rows and 'j' the columns

    squares[row][column][layer] = 'O';
    gameBoard(layer);
}

int getch()
{
    char ch;
    ch = '\n';
    while(ch=='\n')
    {
      ch = getchar();
      if(ch=='\n')
      {
          cout << "Type a valid value!";
          ch = getchar();
      }
    }
    while(getchar()!='\n');
    return ch;
}

void positions(int *column, int *row) { // In this function it is used pointers to modify the values of rows and columns
        cout << "Type a COLUMN using a letter from A to J.\n";
        *column = getch();
        while(*column<65||*column>74&&(*column<97||*column>106)) // Verifies if the input is a letter between A and J
        {
            cout << "Input a valid option!!\n";;
            *column = getch();
        }
        cout << "Now, input the ROW using numbers from '0' to '9'.\n";
        *row = getch()-48;
        if(*column<97){
            *column = *column-65;
        }else {
            *column = *column-97;
        }
        system("cls");
}


int repeat(int *column, int *row, int layer){ // This function repeats the code if the user input some position that is not valid

    while(squares[*row][*column][layer] == 'O')
    {
        gameBoard(layer);
        cout << "Choose a position that has not been choosen yet!!\n";
        positions(column, row); //Here in this function, column and row are already pointers, thats why it's not being passed pcolumn/ prow as arguments to "positions".
        system("cls");
    }
    board(*column,*row,layer);
    return 0;
}

bool together(int *column, int *row, int layer){
    bool horiz, vert;
    if(squares[*row-1][*column][layer]==79||squares[*row+1][*column][layer]==79){
        system("cls");
        repeat(column,row,layer);
        return horiz = true;
    } else if(squares[*row][*column+1][layer]==79||squares[*row][*column-1][layer]==79){
        system("cls");
        repeat(column,row,layer);
        return vert = true;
    } else {return false;}
}

void clearBoard(int column, int row, int layer) {

    int i, j;

    squares[row][column][layer] = 0;

    printf("     A   B   C   D   E   F   G   H   I   J");

    printf("\n");
    for(i=0;i<10;i++){
        j=0;
        while(j<10) {
        if (j==0&&i<=9&&squares[i][j][layer]==79){
        printf(" %d | %c |",i,squares[i][j][layer]);
        }
        else if(j==0&&i<=9){
            printf(" %d |___|",i);
        }
        else{
                if(squares[i][j][layer]==79){
                   printf(" %c |",squares[i][j][layer]);
                }
        else{
            printf("___|");
        }
        }
        j++;
       }
       printf("\n\n");
    }
}


void submarine(int layer, int quantity, int length) //This function is responsible to set the positions for the submarines
{
    int i, column, row;
    int *pcolumn = &column, *prow = &row;
    for(i=0;i<quantity;i++){
        cout << "Total of submarines on the board: " << i << endl << endl;
        cout << "SUBMARINES: You have " << quantity << " submarines! Each submarine occupies " << length << " square on the board.\n";
        positions(pcolumn, prow);
        repeat(pcolumn,prow,layer);
    }

}

void tugShip(int layer, int quantity, int length)
{
    int i, j, column, row;
    int *pcolumn = &column, *prow = &row;
    bool verif;
    j=0;
    while(j<quantity){
            for(i=0;i<length;i++){
                cout << "Total of Tug Ships on the board: " << j << endl << endl;
                cout << "Tug Ship: You have " << quantity << " tug ships! Each tug ship occupies " << length << " squares on the board.\n";

                positions(pcolumn, prow);
                repeat(pcolumn,prow,layer);

                if(i!=0){
                    verif = together(pcolumn,prow,layer);
                }
                while(verif == 0) {
                    system("cls");
                    clearBoard(column,row,layer);
                    cout << "---------INVALID POSITION---------\nInput a position close to the last one.\n";
                    positions(pcolumn, prow);
                    verif = together(pcolumn,prow,layer);
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
    //contra(c);
    //cruzado(c);
    //porta(c);
    cout << "Perfect! All boats have been set!\n\n";
    system("pause");
    system("cls");
    cout << "The game will be:\nA. Against a person\nB. Against the computer\n";
    a = getch();
    while(true)
    {
        if(a=='A'||a=='a')
        {
            return a;
        }
        if(a=='B'||a=='b')
        {
            return a;
        } else
        {
            cout << "Input a valid option!!\n";
            cout << "The game will be:\nA. Against a person\nB. Against the computer\n";
            a = getch();
        }
    }
}

int main()
{
    gameBoard(0);
    cout << "Player 1, please follow the instructions to set the position for each boat." << endl;

    Boats submarine, tug_ship, destroyer, cruiser, aircraft, none;
    submarine.setLength("submarine");
    submarine.setQtt(submarine.length);

    tug_ship.setLength("tug ship");
    tug_ship.setQtt(tug_ship.length);

    destroyer.setLength("destroyer");
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
