#include "HouseRobber.h"

#include <vector>
#include <algorithm>

using namespace std;

//nums = [1,2,3,1]
// 1 3
// 2 1

//[2,7,9,3,1]
// 2 9 1
// 2 3
// 2 1
// 7 3
// 7 1
// 9 1
// 3
// 1



int HouseRobber::Robber(vector<int>& nums){

    int max = nums[0];

    if(nums.size() <= 2){

        auto maxResult = max_element(nums.begin(), nums.end(), [](int a, int b){return a < b;});
        int maxIndex = distance(nums.begin(), maxResult);
        max = nums[maxIndex];
        return max;
    }

    for(int i=0;i<nums.size();i++){
        int index = i;
        int step = 0;
        int sum = 0;

        while (index + step < nums.size())
        {
            while (index < nums.size())
            {
                sum += nums[index];
                index += step;
            }
            if(max < sum) max =sum;
            step++;
            
        }
    }

    return max;
}


void RunHouseRobber(){
    auto sln = new HouseRobber();

    vector<int> t1 = {1,3,1};

    auto result = sln->Robber(t1);
    
}