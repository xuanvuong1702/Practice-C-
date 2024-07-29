#include <vector>
#ifndef GREATER_ELEMENT_H
#define GREATER_ELEMENT_H

using namespace std;

class MonotonicStack {
public:
    vector<int> ConvertArrayToIncrease(vector<int>& temperatures);
    vector<int> GreaterNumber(vector<int> nums);
    void printNGE(vector<int>& arr);
    vector<int> dailyTemperatures(vector<int>& temperatures);
};


void RunMonotonicStack();

#endif~