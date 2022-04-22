#include <string>
#pragma once
#include <string>
#ifndef BOATS_H
#define BOATS_H
#include <string>

using namespace std;
class Boats
{
public:
    Boats();
    virtual ~Boats();
    void boats(string type);
    void setType(string type);
    int getLength();
    string getType();
    int getQtt();
    

private:
    string type;
    int length; int quantity;
    void setLength(string type);
    void setQtt(int length);


};

#endif // BOATS_H
