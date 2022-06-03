#include "Boats.h"
#include <string>
#include <iostream>
using namespace std;

Boats::Boats() {

}

Boats::Boats(std::string type)
{
    this->count_quantity = 0;
    this->count_len = 0;
    this->type = type;
    length = setLength(type);
    quantity = setQtt(length);
    address = new int** [2]; 

    for (int i = 0; i < 2; i++) {                             
        address[i] = new int* [quantity];
        for (int j = 0; j < quantity; j++) {
            address[i][j] = new int[length];
        }
    }

    /*
     address[2][length][quantity] -- layer 0 for rows, layer 1 for columns
     [0][0][0] - [0][0][1] - [0][0][2]  .... rows infos
     [1][0][0] - [1][0][1] - [1][0][2]  .... columns infos

     Both cases above represent infos from one single boat. The middle param (length) is what defines if we're 
     getting the info from one single boat or from different boats. This only aplies when there can be more than one boat
     of same type as it happens with subarines (each player has 3 submarines) and tug ships (2 each).
     At the end, when there's only one boat of a kind, the last param (quantity) will always be zero,
     which means that there's only one boat of that specific kind.

    */

} 

int Boats::getLength() {
    return this->length;
}

int Boats::getQtt() {
    return this->quantity;
}

void Boats::setAddress(int row, int column)
{
    // tentar aplicar vectors
    //rows

    address[0][count_quantity][count_len] = row;

    //columns
    address[1][count_quantity][count_len] = column;
        
}

void Boats::setCountQtt(int count_quantity) {
    this->count_quantity = count_quantity;
}

void Boats::setCountLen(int count_len)
{
    this->count_len = count_len;
}

bool Boats::getAdress(int row, int column)
{
    for (int j = 0; j < quantity; j++) {
        for (int k = 0; k < length; k++) {
            if (address[0][j][k] == row && address[1][j][k] == column) {
                std::cout << "HEREEE\n" << address[0][j][k] << " - " << address[1][j][k] << std::endl;
                // agora preciso de algo para ir marcando quais posições foram encontradas...
                // caso o código entre nesse if, poderia alterar alguma variável que registre algo de cada barco
                return true;
            }
        } std::cout << std::endl;
    } 
    return false;
}


void Boats::showAddress() {
    for (int j = 0; j < quantity; j++) {
        std::cout << std::endl << type << " " << j + 1 << std::endl;
        for (int k = 0; k < length; k++) {
            for (int i = 0; i < 2; i++) {
                std::cout << address[i][j][k];
                if (i == 0) {
                    std::cout << "-";
                }
            } if (k != length - 1) { std::cout << "  |  "; }
        } std::cout << std::endl;
    }
}


string Boats::getType() {
    return this->type;
}

void  Boats::boats(string type) {
    this->type = type;
}

/*
Each boat have different sizes.
Here it is decided the size of each boat according to the name informed as a parameter
*/

int Boats::setLength(string type) {
    if (type == "submarine") {
        return 1;
    }
    else if (type == "tug ship") {
        return 2;
    }

    else if (type == "destroyer") {
        return 3;
    }

    else if (type == "cruiser") {
        return 4;
    }

    else if (type == "aircraft carrier") {
        return 5;
    }
    else { return 0; }
}

int Boats::setQtt(int length) {
    switch (length) {
    case 1:
        return 3;
    case 2:
        return 2;
    case 3:
        return 1;
    case 4:
        return 1;
    case 5:
        return 1;
    default:
        return 0;
    }
}

void Boats::setType(string type) { // colocando o tipo para poder usar lista encadeada e localizar onde exatamente está cada barco
    if (type == "submarine") {
        this->type = type;
        setLength(type);
    }
    else if (type == "tug ship") {
        this->type = type;
        setLength(type);
    }

    else if (type == "destroyer") {
        this->type = type;
        setLength(type);
    }

    else if (type == "cruiser") {
        this->type = type;
        setLength(type);
    }

    else if (type == "aircraft carrier") {
        this->type = type;
        setLength(type);
    }
    else {this->type = "NULL"; }
}


Boats::~Boats()
{
    //quantity;
    //length;
    //type;
}

  