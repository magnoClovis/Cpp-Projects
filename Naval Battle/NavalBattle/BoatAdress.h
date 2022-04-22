#pragma once
#include "Boats.h"

class Node {
private:
    Node* next;
    int v;
public:
    Node(int v);
    int getValue();
    Node* getNext();
    void setNetx(Node* n);
};
class BoatAdress :
    private Boats
{
private:
    Node* head;
    Node* tail;

public:
    BoatAdress();
    BoatAdress(int v);
    virtual ~BoatAdress();
    bool empt();
    void input_beginning(int v);
    void input_ending(int v);
    int len();
    bool is_there(int v);
    void del();
};

