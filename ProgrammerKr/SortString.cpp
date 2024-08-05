#include "SortString.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct SortStringCompare{
    static bool operator()(char a, char b){
        return a > b;
    }
};


string SolutionSortString(string s) {
    sort(s.begin(), s.end(), SortStringCompare());

    return s;
}

void RunSolutionSortString(){
    string s1 = "Zbcdefg";
    string rs = SolutionSortString(s1);
}