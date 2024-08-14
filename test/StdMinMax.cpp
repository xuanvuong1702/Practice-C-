
#include <vector>
#include <algorithm>
#include <string_view>
#include <list>
using namespace std;

void RunStdMinMax(){
    
    vector<int> items = {1,2,5,7,8,3,5,6,2};
    list<int> list = {1,2,3};

    auto item = max_element(list.begin(), list.end(), [](int a, int b){
        return a > b;
    });

    auto x = std::max({ "foo", "bar", "hello" },
                          [](const std::string_view s1, const std::string_view s2) {
                              return s1.size() < s2.size();
                          });


}