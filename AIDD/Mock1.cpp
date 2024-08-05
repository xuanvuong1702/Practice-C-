#include "Mock1.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> SplitString(string s, string delimiter){
    int index = 0;
    vector<string> result;

    while((index = s.find(delimiter)) != string::npos){
        string token = s.substr(0, index);
        result.push_back(token);
        s.erase(0, index + delimiter.length());
    }

    result.push_back(s);

    return result;
}

int CalculateGroup(int n, int k, vector<int> vt){
	
    int counter = 0;
    int step = vt.size() / 3;
    int index = 0;

    while (index + step <= vt.size())
    {
        int sum = 0;
        for(int i=index;i<index + step;i++){
            sum += vt[i];
        }
        if(sum >= k) counter++;

        index += step;
    }
    
    return counter;

}



void RunCalculateGroup(){
    string input1;

    cout << "enter input: " << endl;
    getline(cin, input1);

    vector<string> i1 = SplitString(input1, " ");

    int n = stoi(i1[0]);
    int k = stoi(i1[1]);

    string input2;

    cout << "enter input2: " << endl;

    getline(cin, input2);

    vector<int> kv;

    vector<string> i2 = SplitString(input2, " ");

    for(int i=0;i<i2.size();i++){
        int value  = stoi(i2[i]);

        kv.push_back(value);

    }

    int result = CalculateGroup(n,k,kv);


}
