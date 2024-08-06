#include "ChoseTest.h"

#include <vector>
#include <string>
#include <iostream>



using namespace std;

vector<string> StringSplit(string s, string delimiter)
{
    vector<string> result;

    int pos = 0;

    while ((pos = s.find(delimiter) != string::npos))
    {
        string token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    result.push_back(s);

    return result;
}

void RunChoseTest()
{
    int n;
	
	cin >> n;
	
	string listHardLevel;
	
	getline(cin, listHardLevel);
	
	cout << listHardLevel;
}