
#include "SearchNumber.h"
#include <vector>
#include <iostream>

using namespace std;

int SearchNumber::searchInsert(vector<int>& nums, int target) {
    
        int left = 0;
        int right = nums.size() -1;
        int step = 1;

        // 1 5 8 9 -> 4
        while(step <= nums.size()){
            
            if(nums[left] == target) return left;
            
            if(nums[left] < target){
                left++;
                step++;
            }

            if(left == right) break;

            if(nums[right] == target) return right;

            if(nums[right] > target){
                right--;
                step++;
            }
        }

        if(step > nums.size() || nums[left] >= target) return left;
        else return left+1;
}


void RunSearchNumber(){
    SearchNumber* sln = new SearchNumber();

    vector<int> t1 = {1};
    
    int result = sln->searchInsert(t1, 2);

    cout << "result: " << result << endl;
}