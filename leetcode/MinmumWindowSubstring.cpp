//
// Created by 63200320 on 7/25/2024.
//

#include "MinmumWindowSubstring.h"
#include <map>
#include <iostream>

using namespace  std;

std::map<char, int>* MinimumWindowSubstring::ToUniqueHashMap(string s, int left, int right){

    map<char, int>* mapTable = new std::map<char, int>();

    for(int i=left;i<=right;i++){

        auto  item = mapTable->find(s[i]);

        if(item == mapTable->end()){
            mapTable->insert({{s[i], 1}});
        }
        else{
            item->second = item->second + 1;
        }
    }

    return mapTable;
}

bool MinimumWindowSubstring::IsHashTableAContaintAllB(const map<char, int>* a,const map<char, int>* b){
    for(auto item = (*b).begin();item != (*b).end();item++){
        if((*a).find(item->first) == (*a).end()){
            return false;
        }
    }
    return true;
}

string MinimumWindowSubstring::MinWindow(string s, string t){

    std::map<char, int>* mapTable = new std::map<char, int>();

    for(int i=0;i<t.length();i++){

        auto  item = mapTable->find(t[i]);

        if(item == mapTable->end()){
            mapTable->insert({{t[i], 1}});
        }
        else{
            item->second = item->second + 1;
        }
    }

    int minLength = mapTable->size();

    for(int i=0;i < s.length() - minLength ;i++){
        while(i + minLength <= s.length()){
            auto* subStringMapTable = ToUniqueHashMap(s, i, i + minLength);
            if(IsHashTableAContaintAllB(subStringMapTable, mapTable)){
                return s.substr(i, minLength);
            }
        }
        minLength = mapTable->size();
    }

    return "";

};

void RunMinimumWindowSubstring(){

    cout << "\n MinimumWindowSubstring 1111111111111111111 \n" << endl;   
}