


#include <string>
#include <map>
#include <iostream>
#include "MinimumWindowSubstring.hpp"


using namespace std;

string MinumumWindowSubstring::MinWindow(string s, string t){
    string s1 = RemoveDuplicateCharacter(s);
    return s1;
}

string MinumumWindowSubstring::RemoveDuplicateCharacter(string s){
    map<char, int>* mapTable = new map<char, int>();
    string result;

    for(int i=0;i<s.length();i++){
        auto existed = mapTable->find(s[i]);
        if(existed == mapTable->end()){
            mapTable->insert(pair<char,int>(s[i],100));
        }
        else{
            existed->second = existed->second + 1;
        }
    }

    for(auto item = mapTable->begin();item != mapTable->end();item++){
        result.insert(result.end(),item->first);
    }

    return result;
}

void RunMinumumWindowSubstring(){
    auto* sln = new MinumumWindowSubstring();
    auto s = sln->MinWindow("ADOBECODEBANC", "asdasd");
    std::cout << s;
}

 