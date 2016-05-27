#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

char chrs[][4] = {"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
char s[300];
int r[7];

map < int , int > mp;
set< int > nums;

int hash(){
	int sum = 0;
	for (int i = 0; i < 7; ++i)
	{
		sum*=10;
		sum+=r[i];
	}
	return sum;
}

int main(){
	//freopen ("a.txt","r",stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",s);
		int rp = 0;
		int hr;
		for(int i = 0; s[i]; i++){
			if (s[i] == '-')
			{
				continue;
			}
			else if (isalpha(s[i]))
			{
				for (int j = 0; j < 8; ++j)
				{
					for (int k = 0; k < 3; ++k)
					{
						if (s[i] == chrs[j][k])
						{
							r[rp++] = j+2;
						}
					}
				}
			}
			else
			{
				r[rp++] = (s[i] - '0');
			}
			hr = hash();
		}
		if (mp.count(hr))
		{
			mp[hr]++;
		}
		else{
			mp[hr] = 1;
		}
		nums.insert(hr);
	}
	int flag = 0;
	for (set<int>::iterator j = nums.begin(); j != nums.end(); ++j){
		if (mp[*j] != 1)
		{
			printf("%d%d%d-%d%d%d%d %d\n", (*j)/1000000, ((*j)/100000)%10, ((*j)/10000)%10, ((*j)/1000)%10, ((*j)/100)%10, ((*j)/10)%10, (*j)%10, mp[(*j)]);
			flag = 1;
		}
	}
	if (!flag)
	{
		printf("No duplicates.\n");
	}
	return 0;
}