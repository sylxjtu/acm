#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
map<pair<int,int>,int> s_mp;
int found = 0;
int m,s,t;

int finds(int m, int rt){
	int r;
	if (s_mp.count(pair<int,int>(m,rt)))
	{
		r = s_mp[pair<int,int>(m,rt)];
	}
	else if (rt == 0)
	{
		r = 0;
	}
	else if (rt>=7 && m<=1)
	{
		r = finds(0, rt%7) + 120*(rt/7);
	}
	else if (rt>=3 && m<=3 && m>1)
	{
		r = finds(0, rt-3) + 60;
	}
	else if (rt>=6 && m<=5 && m>3)
	{
		r = finds(0, rt-6) + 120;
	}
	else if (rt>=2 && m<=7 && m>5)
	{
		r = finds(0, rt-2) + 60;
	}
	else if (rt>=5 && m<=9 && m>7)
	{
		r = finds(0, rt-5) + 120;
	}
	else if (m>=10)
	{
		if (rt > m/10)
		{
			r = finds(m%10, rt-m/10) + 60*(m/10);
		}
		else{
			r = rt * 60;
		}
	}
	else
	{
		r = max(finds(m+4, rt-1), finds(m, rt-1)+17);
	}
	if (r>=s)
	{
		found = 1;
	}
	else
	{
		found = 0;
	}
	s_mp[pair<int,int>(m,rt)] = r;
	return r;
}

int main(){
	cin >> m >> s >> t;
	int s_max = finds(m,t);
	if (!found)
	{
		cout << "No" << endl << s_max << endl;
	}
	else
	{
		for (int i = t-1; i >= 0; --i)
		{
			//cout << m << " " << s << " " << i << endl;
			found = 0;
			finds(m,i);
			if (!found)
			{
				cout << "Yes" << endl << i+1 << endl;
				return 0;
			}
		}
	}
	return 0;
}