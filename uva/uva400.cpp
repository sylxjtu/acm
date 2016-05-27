#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;

int main(){
	int cnt;
	while(cin >> cnt){
		vector<string> v;
		for (int i = 0; i < cnt; ++i)
		{
			string s;
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		int longetFileName = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].size() > longetFileName)
			{
				longetFileName = v[i].size();
			}
		}
		int width = longetFileName+2;
		int columns = 62/width;
		int rows = int( double(v.size()) / columns + 1 - 1e-5);
		for (int i = 0; i < 60; ++i)
		{
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				if ((i+j*rows) < v.size())
				{
					if (j == columns-1)
					{
						cout << setw(width - 2);
					}
					else{
						cout << setw(width);
					}
					cout << left << v[i+j*rows];
				}
			}
			cout << endl;
		}
	}
}