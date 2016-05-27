#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int main(){
	map<ull,ull> m;
	set<ull> s;
	ull c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		ull t;
		cin >> t;
		if (m.count(t))
		{
			m[t]++;
		}
		else
		{
			m[t]=1;
		}
		s.insert(t);
	}
	for (auto &i: s)
	{
		cout << i << " " << m[i] << endl;
	}
	return 0;
}