#ifndef K_PAIR_SMALLEST_H
#define K_PAIR_SMALLEST_H

#include <vector>

using namespace std;

struct PairElement{
    vector<int> items;
    int sum;

    PairElement(int s, vector<int> is){
        items = is;
        sum = s;
    }
};

struct KPairSmallestCompare{
    static bool operator()(PairElement a, PairElement b){
        return a.sum > b.sum;
    }
};



class KPairSmallest {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);
};


void RunKPairSmallest();

#endif