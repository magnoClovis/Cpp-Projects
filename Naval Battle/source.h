#include <string>
#pragma once
#ifndef SOURCE_H
#define SOURCE_H

using namespace std;

extern char g_squares[10][10][2];
extern char g_water;
extern char g_fire;

void matrix();
void showBoard();
void playerBoard(int layer);
void board(int column, int row, int layer);
int _getch();
void positions(int* column, int* row);
int repeat(int* column, int* row, int layer);
bool vertical(int* column, int* row, int layer);
bool horizontal(int* column, int* row, int layer);
void clearBoard(int column, int row, int layer);
void setBoat(int layer, string type);
char SetPlayer(int layer);
void gameBoard(int layer);
unsigned int random();
int winner(int layer);
int boardAttack(int* column, int* row, int layer);
void gameOver(int layer);
void playerOneAttack(int layer, int* attack, int* win);
void playerTwoAttack(int layer, int* attack, int* win);
void game(unsigned int r);

#endif
