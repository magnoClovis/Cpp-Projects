#include <iostream>
#include <string>
#include "Boats.h"

using namespace std;

char spaces[10][10][2];

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
                    spaces[i][j][c] = 48; // 48 == 0(zero) in ASCII table
                    if(spaces[i][j][c] == 48){
                    cout << spaces[i][j][c] << " ";
                    }
                    else{
                        cout<< spaces[i][j][c] << " ";
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
                The differences between them are just the number of spaces used on each "cout<<"
                statement, so everything on the display will be symmetrical.*/
                if (j==0&&i<=9&&spaces[i][j][c]=='O'){
                    cout<< i << " | " << spaces[i][j][c] << " |";
                }
                else if(j==0&&i<=9){
                    cout<< " " << i <<" |___|";
                }
                else{
                    if(spaces[i][j][c]=='O'){
                        cout<< " " << spaces[i][j][c] << " |";
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

void board(int a, int b, int c)
{
    // This function changes an element on the matrix "spaces" and show what the changes did on the board
    int i,j; // Again, 'i' represents the rows and 'j' the columns

    spaces[b][a][c] = 'O'; // 'b' represents the rows and 'a' the columns
    gameBoard(c);
}

int main()
{
    gameBoard(0);
    cout << "Player 1, please follow the instructions to set the position for each boat." << endl;

    Boats submarine, tug_ship, destroyer, cruiser, aircraft, none;
    submarine.setSpaces("submarine");
    tug_ship.setSpaces("tug ship");
    destroyer.setSpaces("destroyer");
    cruiser.setSpaces("cruiser");
    aircraft.setSpaces("aircraft carrier");
    none.setSpaces("none boat");

    cout << "submarine spaces: " << submarine.spaces << endl;
    cout << "tug ship spaces: " << tug_ship.spaces << endl;
    cout << "destroyer spaces: " << destroyer.spaces << endl;
    cout << "cruiser spaces: " << cruiser.spaces << endl;
    cout << "aircraft carrier spaces: " << aircraft.spaces << endl;
    cout << "none boat spaces: " << none.spaces << endl;

    return 0;
}
