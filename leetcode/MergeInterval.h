
#ifndef MERGE_INTERVAL_H
#define MERGE_INTERVAL_H

#include <vector>

using namespace std;

struct OverlapResult{
    bool IsOverlap;
    vector<int> Result;

    OverlapResult(bool isOverlap, vector<int> result){
        this->IsOverlap = isOverlap;
        this->Result = result;
    }

    OverlapResult(){

    }

};

class MergeInterval {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals);
    static OverlapResult CheckOverlap(vector<int>& a, vector<int>& b);
};


void RunMergeInterval();

#endif