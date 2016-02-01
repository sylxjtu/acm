#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int orifreq[26];
int cipfreq[26];

int main(){
	string s1,s2;
	while(cin >> s1 >> s2){
		memset(orifreq,0,sizeof(orifreq));
		memset(cipfreq,0,sizeof(cipfreq));
		for(auto i: s1){
			orifreq[i-'A']++;
		}
		for(auto i: s2){
			cipfreq[i-'A']++;
		}
		sort(orifreq,orifreq+26);
		sort(cipfreq,cipfreq+26);
		for (int i = 0; i < 26; ++i)
		{
			if (orifreq[i]!=cipfreq[i])
			{
				goto nogood;
			}
		}
		printf("YES\n");
		continue;
		nogood:
		printf("NO\n");
	}
	return 0;
}