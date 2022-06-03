#include <string>
#include <vector>
#ifndef BOATS_H
#define BOATS_H

using namespace std;
class Boats
{
public:
    Boats();
    Boats(std::string type);
    virtual ~Boats();
    int*** address;
    void boats(string type);
    int getLength();
    string getType();
    int getQtt();
    void setAddress(int row, int column);
    void showAddress();
    void setCountQtt(int count_quantity);
    void setCountLen(int count_len);
    bool getAdress(int row, int column);
    
private:
    int length; int quantity;  int count_quantity; int count_len;
    string type;
    void setType(string type);
    int setLength(string type);
    int setQtt(int length);
};

#endif // BOATS_H
