#include "CoinChange.h"
#include <vector>
#include <iostream>


using namespace std;


//Input: coins = [1,2,5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
int CoinChange::coinChange(vector<int>& coins, int amount){
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for(int i = 1; i <= amount; i++){
        for(int j = 0; j < coins.size(); j++){
            if(coins[j] <= i){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}

void RunCoinChange(){
    auto sln = new CoinChange();

    vector<int> x = {1,2,5};

    int result = sln->coinChange(x, 11);

    cout << "result: " << result << endl;
}