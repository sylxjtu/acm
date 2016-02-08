#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int n,q,kase=1;
	vector<int> v;
	while(1){
		cin >> n >> q;
		if (!n && !q)
		{
			break;
		}
		printf("CASE# %d:\n", kase);
		for (int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			v.push_back(t);
		}
		sort(v.begin(),v.end());
		for (int i = 0; i < q; ++i)
		{
			int t;
			cin >> t;
			int lbi = lower_bound(v.begin(),v.end(),t) - v.begin();
			if (v[lbi]==t)
			{
				printf("%d found at %d\n", t, lbi+1);
			}
			else{
				printf("%d not found\n", t);
			}
		}
		kase++;
		v.clear();
	}
}
