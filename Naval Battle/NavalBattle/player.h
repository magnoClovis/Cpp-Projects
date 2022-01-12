#include <string>
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;



void matrix(int layer);
void playerBoard(int layer);
char randomOrNot(int layer);
//void SetPlayer(int layer);
unsigned int randomValues();
void lockBoat(int layer);
void game(unsigned int r);
void gameBoard(int layer);
int playerOneAttack(int layer, int* attack, int computer);
int winner(int layer);
void gameOver(int layer);
#endif
