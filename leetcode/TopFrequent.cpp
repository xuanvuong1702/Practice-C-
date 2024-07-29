#include "TopFrequent.h"
#include <map>
#include  <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void print(std::string_view text, std::vector<int> const& v = {}) {
    std::cout << text << ": ";
    for (const auto& e : v) std::cout << e << ' ';
    std::cout << '\n';
}

vector<int> TopFrequent::topKFrequent(vector<int>& nums, int k){
    map<int, int>* mapTable = new map<int, int>();

    int max = 0;
    for(auto i = 0;i<  nums.size();i++){

        auto item = mapTable->find(nums[i]);

        if(item != mapTable->end()){
            item->second = item->second + 1;
        }
        else{
            mapTable->insert(pair<int, int>(nums[i], 1));
        }
    }

    //convert to vector
    vector<pair<int, int>> vt;

    for(auto item  = mapTable->begin();item != mapTable->end();item++){
        vt.push_back(make_pair(item->first, item->second));
    }

    make_heap(vt.begin(), vt.end(), PairCompare());

    int counter = k;

    vector<int> result;

    while(counter > 0){

        pop_heap(vt.begin(), vt.end(), PairCompare());
        result.push_back(vt.back().first);
        vt.pop_back();
        counter--;
    }

    return result;

}

bool TopFrequent::compare(const pair<int, int >& a, const pair<int, int>& b){
    return a.second > b.second;
}

void RunTopFrequent(){
    TopFrequent* sln = new TopFrequent();

    vector<int> t1 = {1,1,1,2,2,3};
    int k = 2;

    auto result = sln->topKFrequent(t1,2);

    print("result: ",result);

}