
#ifndef MERGE_INTERVAL_H
#define MERGE_INTERVAL_H

#include <vector>

using namespace std;

struct MergeIntervalCompare{
    static bool operator()(const vector<int> a, const vector<int> b){
        return a[0] < b[0];
    }
};



class MergeInterval {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals);
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
};


void RunMergeInterval();

#endif