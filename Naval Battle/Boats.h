#pragma once
#ifndef BOATS_H
#define BOATS_H
#include <string>

using namespace std;
class Boats
{
public:
    Boats();
    int length; int quantity;
    void boats(string type);
    int setLength(string type);
    virtual ~Boats();
    int setQtt(int length);
protected:

private:
    string type;


};

#endif // BOATS_H
