#include "DpFibonacci.h"
#include <vector>

using namespace std;


int DpFibonacci(int n){
    vector<int> f;
    f.push_back(1);
    f.push_back(1);
    
    if(n == 0) return f[0];
    if(n == 1) return f[1];

    for(int i=2;i<=n;i++){
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}