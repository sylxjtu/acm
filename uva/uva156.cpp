#include <vector>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
vector<string> v;
map<string,int> m;

string repr(const string& s){
	string stds=s;
	for(auto &i: stds){
		i=tolower(i);
	}
	sort(stds.begin(), stds.end());

	return stds;
}

int main(){
	string s;
	while(cin >> s && s!="#"){
		string stds=repr(s);
		v.push_back(s);
		if (!m.count(stds))
		{
			m[stds] = 0;
		}
		m[stds]++;
	}
	vector<string> ans;
	for(auto &i:v){
		if (m[repr(i)] == 1)
		{
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for(auto &i:ans){
		cout << i << endl;
	}
	return 0;
}