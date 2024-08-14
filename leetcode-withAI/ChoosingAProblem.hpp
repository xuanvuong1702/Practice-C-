#ifndef CHOOSING_A_PROBLEM
#define CHOOSING_A_PROBLEM

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

namespace ChoosingAProblem
{
    struct InputValue
    {
        int n;
        vector<int> items;

        InputValue(int n, vector<int> items)
        {
            this->n = n;
            this->items = items;
        }
    };

    void ReadInput();
    
    void Run();
}

#endif