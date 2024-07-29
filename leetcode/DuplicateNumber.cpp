#include "DuplicateNumber.h"
#include <map>
#include <iostream>


using namespace std;

int DuplicateNumber::findDuplicate(vector<int>& nums)
{
    map<int, int>* mapTable = new map<int, int>();

    for (int n : nums) {

        auto existed = mapTable->find(n);

        if(existed == mapTable->end()){
            mapTable->insert(pair<int, int>(n,1));
        }
        else{
            existed->second = existed->second + 1;
        }
    }

    for(auto item = mapTable->begin();item != mapTable->end();item++){
        if(item->second > 1){
            return item->first;
        }
    }

    return NULL;
}


void RunDuplicateNumber(){

    vector<int> t1 = {1,3,4,2,2};

    auto sln = new DuplicateNumber();

    auto result = sln->findDuplicate(t1);

    cout << "result: " << result << endl;

}