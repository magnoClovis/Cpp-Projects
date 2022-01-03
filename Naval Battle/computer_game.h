#include <string>
#include "player.h"
#include "variables.h"
#pragma once
#ifndef COMPUTER_GAME_H
#define COMPUTER_GAME_H

using namespace std;


int boardPC(int column, int row, int layer);
void computerMatrix();
int setComputerBoard(int layer, string type);
void lockBoat(int layer);

#endif

