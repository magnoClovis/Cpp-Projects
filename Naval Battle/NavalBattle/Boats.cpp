#include "Boats.h"
#include <string>
#include <iostream>
using namespace std;
Boats::Boats()
{
    length = 0;
    quantity = 0;
} 

int Boats::getLength() {
    return this->length;
}

int Boats::getQtt() {
    return this->quantity;
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

void Boats::setLength(string type) {
    if (type == "submarine") {
        length = 1;
        setQtt(length);
    }
    else if (type == "tug ship") {
        length = 2;
        setQtt(length);
    }

    else if (type == "destroyer") {
        length = 3;
        setQtt(length);
    }

    else if (type == "cruiser") {
        length = 4;
        setQtt(length);
    }

    else if (type == "aircraft carrier") {
        length = 5;
        setQtt(length);
    }
    else { length = 0; }
}

void Boats::setQtt(int length) {
    switch (length) {
    case 1:
        quantity = 3;
        break;
    case 2:
        quantity = 2;
        break;
    case 3:
        quantity = 1;
        break;
    case 4:
        quantity = 1;
        break;
    case 5:
        quantity = 1;
        break;
    default:
        quantity = 0;
        break;
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
    quantity;
    length;
    type;
}

  