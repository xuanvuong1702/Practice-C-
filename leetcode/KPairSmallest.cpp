#include "KPairSmallest.h"

#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> KPairSmallest::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
    
    vector<PairElement> stack;

    vector<vector<int>> result;

    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            vector<int> elements;
            elements.push_back(i);
            elements.push_back(j);

            PairElement item = {(nums1[i] + nums2[j]), elements};

            stack.push_back(item);
        }
    }

    make_heap(stack.begin(), stack.end(), KPairSmallestCompare());

    int counter = k;

    while(counter > 0){
        pop_heap(stack.begin(), stack.end(), KPairSmallestCompare());

        result.push_back(stack.back().items);

        stack.pop_back();

        counter--;
    }



}