#include "MinimumWindow.h"  
#include <string>
#include <iostream>
#include <map>

using namespace std;

void MinimumWindow::RunMinimumWindow(){
    string s = "a";
    string t = "aa";
    string removed = MinWindow(s, t);
    cout << removed << "\n" << endl;
}

string MinimumWindow::MinWindow(string s, string t){

    if(s.length() < t.length()) return "";

    string tRemoved = RemoveDuplicate(t);

    map<int, int>* result = new map<int, int>();

    for(int i=0;i< s.length(); i++){

        int minLength = tRemoved.length();
        while(i + minLength < s.length()){
            string subString = s.substr(i, minLength);
            string removeDuplicated = RemoveDuplicate(subString);

            int isContaintAll = true;

            for(int j=0;j<tRemoved.length();j++){
                int index = removeDuplicated.find(tRemoved[j]);
                if(index < 0){
                    isContaintAll =  false;
                    break;
                }
            }

            if(isContaintAll){
                result->insert(pair<int, int>(i, minLength));
            }

            minLength++;
        }
    }

    int minLength = 0;
    int leftIndex = -1;

    for(auto i=result->begin();i != result->end();i++){
        if(i->second < minLength || leftIndex == -1){
            minLength = i->second;
            leftIndex = i->first;
        }
    }

    return s.substr(leftIndex, minLength);
}

string MinimumWindow::RemoveDuplicate(string s){

    map<char, int>* mapTable = new std::map<char, int>();
    string result;
    
    for(int i=0;i<s.length();i++){
        
        auto  item = mapTable->find(s[i]);
        
        if(item == mapTable->end()){
            mapTable->insert({{s[i], 1}});
        }
        else{
            item->second = item->second + 1;
        }
    }

    for(auto i = mapTable->begin();i != mapTable->end();i++){

        result.insert( result.end(), i->first);


    }

    return result;

}