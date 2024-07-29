#include "TopKElement.h"
#include <string_view>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int TopKElement::findKthLargest(vector<int>& nums, int k){

    make_heap(nums.begin(), nums.end());

    int counter = k;
    int result;

    while(counter > 0){
        pop_heap(nums.begin(), nums.end());
        if (!nums.empty()) {
            result = nums.back();
            nums.pop_back();
            counter--;
        } else {
            // Handle the case when nums is empty
            break;
        }
    }
    return result;
}

void RunTopKElement(){


    vector<int> t1 = {3,2,1,5,6,4};

     TopKElement* sln = new TopKElement();

     int result = sln->findKthLargest(t1, 2);

     cout << "result: " << result;
}