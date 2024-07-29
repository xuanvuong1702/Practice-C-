//
// Created by 63200320 on 7/25/2024.
//

#ifndef LEETCODE_MINMUMWINDOWSUBSTRING_H
#define LEETCODE_MINMUMWINDOWSUBSTRING_H

#include <string>
#include <map>

using namespace  std;

class MinimumWindowSubstring {
public:
    string MinWindow(string s, string t);
    map<char, int>* ToUniqueHashMap(string s, int left, int right);
    bool IsHashTableAContaintAllB(const map<char, int>* a,const map<char, int>* b);
};

void RunMinimumWindowSubstring();

#endif //LEETCODE_MINMUMWINDOWSUBSTRING_H
