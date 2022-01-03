#include <string>
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;



void matrix();
void showBoard();
void playerBoard(int layer);
void board(int column, int row, int layer);
int _getch();
void positions(int* column, int* row);
int repeat(int* column, int* row, int layer);
int vertical(int* column, int* row, int layer);
int horizontal(int* column, int* row, int layer);
void clearBoard(int column, int row, int layer);
void setBoat(int layer, string type);
char SetPlayer(int layer);
void gameBoard(int layer);
unsigned int randomValues();
int winner(int layer);
int boardAttack(int* column, int* row, int layer);
void gameOver(int layer);
void playerOneAttack(int layer, int* attack, int* win);
void playerTwoAttack(int layer, int* attack, int* win);
void game(unsigned int r);

#endif
