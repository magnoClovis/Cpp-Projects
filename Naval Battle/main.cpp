#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

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

int getch()
{
    char ch;
    ch = '\n';
    while(ch=='\n')
    {
      ch = getchar();
      if(ch=='\n')
      {
          printf("Type a valid value!");
          ch = getchar();
      }
    }
    while(getchar()!='\n');
    return ch;
}

int positions(int *column, int *row) {
        cout << "Type a COLUMN using a letter from A to J.\n";
        *column = getch();
        while(column<65||column>74&&(column<97||column>106))
        {
            cout << "Digite um valor válido!\n";
            *column = getch();
        }
        cout << "Agora, digite a linha com números de '0' a '9'.\n";
        *row = getch()-48;
        if(column<97){
            *column = column-65;
        }else {
            *column = column-97;
        }


        system("cls");
}

/*int repeat(a,b,c) // This function repeats the code if the user input some position that is not valid
{
      while(casas[b][a][c] == 'O')
    {
        printTab(c);
        cout << "Choose a position that has not been choosen yet!!\n";
        cout << "Type a COLUMN using a letter from A to J.\n";
        a = getch();
        while(a<65||a>74&&(a<97||a>106))
        {
            printf("Digite um valor válido!\n");
            a = getch();
        }
        printf("Agora, digite a linha com números de '0' a '9'.\n");
        b = getch()-48;
        if(a<97){
            a = a-65;
        }else {
            a = a-97;
        }
        system("cls");
    }
    tabuleiro(a,b,c);
    return 0;
}*/

void submarino(int c) //This function is responsible to set the positions for the submarines
{
    int i, column, row;
    int *pcolumn = &column, *prow = &row;
    for(i=0;i<3;i++){
        cout << "Total of submarines on the board: " << i << endl << endl;
        cout << "SUBMARINES: You have three submarines! Each submarine occupies one space on the board.\n";
        positions(pcolumn, prow);
        //repeat(a,b,c);
        cout << column << " " << row;
    }

}

char SetPlayer1()
{
    int c;
    char a;
    c = 0;
    submarino(c);
    //rebocador(c);
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
    SetPlayer1();

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
