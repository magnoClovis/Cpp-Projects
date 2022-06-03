#include <string>
#include <vector>
#include "Boats.h"
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

void matrix(int layer);
void playerBoard(int layer);
char randomOrNot(int layer, vector<Boats> boats);
void SetPlayer(int layer, vector<Boats> boats);
unsigned int randomValues();
void lockBoat(int layer);
void game(unsigned int r);
void gameBoard(int layer);
int playerOneAttack(int layer, int* attack, int computer);
int winner(int layer);
void gameOver(int layer);
void showingAddresses(vector<Boats> boats);
#endif
