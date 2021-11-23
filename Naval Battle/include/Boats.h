#ifndef BOATS_H
#define BOATS_H
#include <string>

using namespace std;
class Boats
{
    public:
        Boats();
        boats(string type);
        int setSpaces(string type);
        virtual ~Boats();
        int spaces;
    protected:

    private:
        string type;


};

#endif // BOATS_H
