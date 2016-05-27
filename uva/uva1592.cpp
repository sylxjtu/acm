#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
char buffer[100];

int main(){
	int r,c;
	while(cin >> r >> c){
		getchar();

		vector< map<string,int> > vm(c);
		set< pair<int,int> > dups;
		map< pair<int,int> , int > dupsc;
		int flag = 0;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				char ch;
				int ind=0;
				while((ch = getchar())!=',' && ch!='\n'){
					buffer[ind++]=ch;
				}
				if (!flag){
					buffer[ind] = 0;
					string s(buffer);
					if (vm[j].count(s))
					{
						if(dups.count(pair<int,int>(vm[j][s],i))){
							cout << "NO" << endl;
							cout << vm[j][s]+1 << " " << i+1 << endl;
							cout << dupsc[pair<int,int>(vm[j][s],i)]+1 << " " << j+1 << endl;
							flag = 1;
						}
						dups.insert(pair<int,int>(vm[j][s],i));
						dupsc[pair<int,int>(vm[j][s],i)] = j;
					}
					else
						vm[j][s] = i;
				}
			}
		}

		if (!flag)
		{
			cout << "YES" << endl;
		}
	}
}