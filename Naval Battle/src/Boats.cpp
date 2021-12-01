#include "Boats.h"
#include <string>

using namespace std;
Boats::Boats()
{
    //ctor
}

Boats::boats(string type) {
    this->type = type;
}

/*
Each boat occupies different spaces on the board.
Here it is decided how many spaces each boat will occupy according to the name informed as a parameter
*/

int Boats::setSpaces(string type){
    if(type == "submarine"){
        return spaces = 1;
    }
    else if(type == "tug ship"){
         return spaces = 2;
    }

    else if(type == "destroyer"){
           return spaces = 3;
    }

    else if (type == "cruiser"){
        return spaces = 4;
    }

    else if (type == "aircraft carrier"){
        return spaces = 5;
    }

    else {return spaces = 0;}
}

Boats::~Boats()
{
    //dtor
}
