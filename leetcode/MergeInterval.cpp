#include "MergeInterval.h"

OverlapResult MergeInterval::CheckOverlap(vector<int> &a, vector<int> &b)
{
    int leftA = a[0];
    int leftB = b[0];

    int rightA = a[1];
    int rightB = b[1];

    OverlapResult CheckResult = {};

    vector<int> result = a;

    bool isOverlap = false;

    if (leftB < leftA)
    {
        isOverlap = true;
        result[0] = leftB;
    }

    if (rightB > rightA)
    {
        isOverlap = true;
        result[1] = rightB;
    }

    CheckResult.IsOverlap = isOverlap;
    CheckResult.Result = result;

    return CheckResult;
}

vector<vector<int>> MergeInterval::merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    vector<int> *last;

    for (int i = 0; i < intervals.size(); i++)
    {
        vector<int> *current = &intervals[i];

        if (result.empty())
        {
            result.push_back(*current);
            last = current;
            continue;
        }

        auto checkResult = CheckOverlap(*last, *current);

        if(checkResult.IsOverlap){
            result.pop_back();
            result.push_back(checkResult.Result);
            last = &checkResult.Result;
        }
        else
        {
            result.push_back(*current);
            last = current;
        }
    }

    return result;
}

void RunMergeInterval()
{
    MergeInterval *sln = new MergeInterval();

    vector<vector<int>> t1 = {{1,3},{2,6},{8,10},{15,18}};

    auto result = sln->merge(t1);
}