#ifndef TOP_FREQUENT_H
#define TOP_FREQUENT_H
#include <vector>

using namespace std;


struct PairCompare{
    static bool operator()(pair<int, int > a, pair<int, int> b){
        return a.second > b.second;
    }
};


class TopFrequent {
public:
    vector<int> topKFrequent(vector<int>& nums, int k);
    bool compare(const pair<int, int >& a, const pair<int, int>& b);
};


void RunTopFrequent();
#endif