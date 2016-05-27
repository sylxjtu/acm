#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main(){
	int kase=1;
	while(1){
		int n;
		cin >> n;
		if (n==0)
		{
			cout << endl;
			return 0;
		}
		if (kase!=1)
		{
			cout << endl;
		}
		cout << "Scenario #" << kase << endl;
		kase++;

		map<int,int> teamByPerson;
		for (int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			for (int j = 0; j < t; ++j)
			{
				int t2;
				cin >> t2;
				teamByPerson[t2] = i;
			}
		}
		queue<int> qt;
		vector< queue<int> > qpv(n);
		while(1){
			string s;
			cin >> s;
			if (s == "ENQUEUE")
			{
				int t;
				cin >> t;
				if (qpv[teamByPerson[t]].empty())
				{
					qt.push(teamByPerson[t]);
				}
				qpv[teamByPerson[t]].push(t);
			}
			else if (s == "DEQUEUE")
			{
				cout << qpv[qt.front()].front() << endl;
				qpv[qt.front()].pop();
				if (qpv[qt.front()].empty())
				{
					qt.pop();
				}
			}
			else
			{
				break;
			}
		}
	}
}