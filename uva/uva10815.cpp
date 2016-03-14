#include <set>
#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;

int main(){
	string s;
	set<string> st;
	while(cin >> s){
		for (int i = 0; i < s.length(); ++i)
		{
			if (isalpha(s[i]))
			{
				s[i] = tolower(s[i]);
			}
			else
			{
				s[i] = ' ';
			}
		}
		stringstream ss(s);
		string buf;
		while(ss >> buf){
			st.insert(buf);
		}
	}
	for(auto &i: st){
		cout << i << endl;
	}
	return 0;
}