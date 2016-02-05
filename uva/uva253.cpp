#include <cstdio>
#include <set>
using namespace std;
multiset<set<int>> s[2];

char cube[2][6];
int main(){
	while(1){
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if(scanf(" %c",&cube[i][j]) != 1)
					return 0;
			}
		}
		for (int i = 0; i < 2; ++i)
		{
			s[i].insert({cube[i][0],cube[i][5]});
			s[i].insert({cube[i][1],cube[i][4]});
			s[i].insert({cube[i][2],cube[i][3]});
		}
		printf("%s\n", s[0]==s[1]?"TRUE":"FALSE");
		for (int i = 0; i < 2; ++i)
		{
			s[i].clear();
		}
	}
}