#include <vector>
#ifndef TOP_FREQUENT_H
#define TOP_FREQUENT_H

using namespace std;

class TopFrequent {
public:
    vector<int> topKFrequent(vector<int>& nums, int k);
    bool compare(const pair<int, int >& a, const pair<int, int>& b);
};


void RunTopFrequent();
#endif