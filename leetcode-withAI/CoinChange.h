
#ifndef COIN_CHANGE_H
#define COIN_CHANGE_H
#include <vector>

using namespace std;

class CoinChange{ 
    public: 
        int coinChange(vector<int>& coins, int amount);
};


void RunCoinChange();

#endif