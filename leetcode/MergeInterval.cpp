#include "MergeInterval.h"
#include <algorithm>


vector<vector<int>> MergeInterval::merge(vector<vector<int>> &intervals)
{
    
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end(), MergeIntervalCompare());

    for (int i = 0; i < intervals.size(); i++)
    {
        vector<int> current = intervals[i];

        if (result.empty())
        {
            result.push_back(current);
            continue;
        }
       
        vector<int>& last = result.back();

        if(current[0] <= last[1]){
            if(current[0]< last[0]){
                last[0] = current[0];
            }

            if(current[1] > last[1]){
                last[1] = current[1];
            }

        }
        else{
            result.push_back(current);
        }
    }

    return result;
}

vector<vector<int>> MergeInterval::insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    intervals.push_back(newInterval);

    return merge(intervals);    
}


int MergeInterval::eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end(), MergeIntervalCompare());

    for (int i = 0; i < intervals.size(); i++)
    {
        vector<int> current = intervals[i];

        if (result.empty())
        {
            result.push_back(current);
            continue;
        }
       
        vector<int>& last = result.back();

        if(current[0] < last[1]){
            continue;
        }
        else{
            result.push_back(current);
        }
    }

    return intervals.size() - result.size();
}

void RunMergeInterval()
{
    MergeInterval *sln = new MergeInterval();

    vector<vector<int>> t1 = {{1,2},{2,3},{3,4},{1,3}};

    auto result = sln->eraseOverlapIntervals(t1);


}