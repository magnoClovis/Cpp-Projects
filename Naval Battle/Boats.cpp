#include "Boats.h"
#include <string>

using namespace std;
Boats::Boats()
{
    //ctor
}

void  Boats::boats(string type) {
    this->type = type;
}

/*
Each boat has different sizes.
Here it is decided the size of each boat according to the name informed as a parameter
*/

int Boats::setLength(string type) {
    if (type == "submarine") {
        return length = 1;
    }
    else if (type == "tug ship") {
        return length = 2;
    }

    else if (type == "destroyer") {
        return length = 3;
    }

    else if (type == "cruiser") {
        return length = 4;
    }

    else if (type == "aircraft carrier") {
        return length = 5;
    }
    else { return length = 0; }
}

int Boats::setQtt(int length) {
    switch (length) {
    case 1:
        return quantity = 3;
        break;
    case 2:
        return quantity = 2;
        break;
    case 3:
        return quantity = 1;
        break;
    case 4:
        return quantity = 1;
        break;
    case 5:
        return quantity = 1;
        break;
    default:
        return quantity = 0;
        break;
    }
}


Boats::~Boats()
{
    //dtor
}

