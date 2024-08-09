#include "ClimbingStair.h"
#include <vector>

using namespace std;

int ClimbingStair::climbStairs(int n){
    int ways[46];
    ways[0] = 0;
    ways[1] = 1;
    ways[2] = 2;

    if(n <= 2){
        return ways[n];
    }
    
    int sum = 0;
    for(int i=3;i<=n;i++){
        ways[i] = ways[i-1] + ways[i-2];
    }

    return ways[n];
}

void RunClimbingStair(){
    ClimbingStair* sln = new ClimbingStair();

    int result2 = sln->climbStairs(5);
}