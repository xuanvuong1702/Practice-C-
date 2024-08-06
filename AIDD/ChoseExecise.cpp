#include "ChoseExecise.h"

#include <string>
#include <vector>
#include <map>

using namespace std;



vector<int> StringSplit(string s, string delimiter){
	vector<int> result;
	
	int pos = 0;
	
	while(s.find(delimiter) != string::npos){
        int pos = s.find(delimiter);
		string token = s.substr(0, pos);
		int value = stoi(token);
		result.push_back(value);
		
		s.erase(0, pos + delimiter.length());
	}
	
	int value = stoi(s);
	
	result.push_back(value);
	
	return result;
}


string ChoseExecise(int n, vector<int> items){
		
	map<int, int> mapTable;
	
	for(int i=0;i<items.size();i++){
		
		auto item = mapTable.find(items[i]);
			
		if(item != mapTable.end()){
			item->second = item->second + 1;
		}
		else{
			mapTable.insert(pair(items[i], 1));
		}
	}
	
	if(mapTable.size() >= 3) return "YES";
	else return "NO";
	
}

void RunChoseExecise(){
   int n;
	
	cout << "enter n: " << endl;
	cin >> n;
	
	cout << "n value: " << n << endl;
	
	string items;
	
	cout << "enter items: " << endl;
	
	getline(cin>>ws, items);
	
	cout << "items: " << items << endl;
	
	vector<int> splited = StringSplit(items, " ");
	
	for(int i=0;i<splited.size();i++){
		cout << splited[i] << endl;
	}
	
	string result = ChoseExecise(n, splited);
	
	cout << result;
	
}
