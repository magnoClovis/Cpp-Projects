// algorithms.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

#include "algorithms.h"

using namespace std;

QLearning::QLearning(const int& s, const int& r, const int& a):
c_state_size(s), c_range(r), c_action_size(a + 1) //setting the private variables with the values from user
{
    try {
        if (c_state_size > 0 && c_action_size > 0) {
            cout << "Constructor call successful" << endl;
            QtableLogic(c_range, c_state_size, c_action_size);
            cout << "QTable generated successfully." << endl;
            init = true;
        }
        else {
            throw - 1;
        }
    }
    catch (...) {
        std::cerr << "State or action size is 0";
    }
}

std::vector<int> QLearning::indexFromMulti(int one_dimensional_index, int nn, int depth) { // this function allocates the values in the matrix
    std::vector<int> index(depth, 0);
    for (int i = 0; i < depth; i++) {
        index[i] = (one_dimensional_index % nn);
        one_dimensional_index /= nn;
    }
    return index; 
}

void QLearning::QtableLogic(int nn, int depth, int breadth) {
    if (nn == 0) {
        std::cerr << "size cannot be 0" << endl;
    }

    float size = nn / 2;

    int max_index = pow(nn, depth);

    for (int i = 0; i < max_index; i++) {
        std::vector<int> key = indexFromMulti(i, nn, depth);
        for (int j = 0; j < depth; j++) {
            key[j] -= size;
            std::vector<float> value(breadth, 0);
            for (int j = 0; j < breadth; j++) {
                value[j] = (rand()%5)+1;
                this->c_q_table[key] = value;
            }
        }
    }
}

void QLearning::show() const {
    if (init) {
        cout << "qtable populated with: " << endl;
        for (auto iter = this->c_q_table.begin(); iter != this->c_q_table.end(); ++iter) {
            cout << "qtable[{";
            for (size_t i = 0; i < iter->first.size(); i++) {
                cout << iter->first[i];
                if (i != iter->first.size() - 1) {
                    cout << ",";
                }
            }
            cout << "}]=[";
            for (size_t i = 0; i < iter->second.size(); i++) {
                cout << iter->second[i];
                if (i != iter->second.size() - 1) {
                    cout << ",";
                }
            }
            cout << "];" << endl;
        }
    }
    else {
        cerr << "Qtable not initialized" << endl;
    }
}

float QLearning::getEpsilon() const {
    return epsilon;
}

void QLearning::setEpsilon(float e){
    this->epsilon = e;
    cout << "EPSILON set to " << this->epsilon << endl;
}

double QLearning::s_discount = 0.9;
float QLearning::s_eps_decay = 0.99;
double QLearning::s_learning_rate = 0.01;

// #include "algorithms.h"

int main()
{
    QLearning q(2, 10, 4);
    q.show();
}

