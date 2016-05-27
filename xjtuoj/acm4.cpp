#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cctype>
using namespace std;

int arr[301][301];
int n, s;

map< pair<int,int> , pair<int,int> > md;

int min_dis(int i, int j){
	int& ans = arr[i][j];
	if (i == j)
	{
		return 0;
	}
	if (ans)
	{
		return ans;
	}
	while(!ans){
		for (int k = 1; k < n; ++k)
		{
			if (k == i)
			{
				continue;
			}
			if (arr[i][k])
			{
				for (int kk = 1; kk < n; ++kk)
				{
					if (arr[k][kk])
					{
						arr[i][kk] = min(arr[i][kk], arr[i][k]+arr[k][kk]);
					}
				}
			}
		}
	}
	return ans;
}

int max_distance(int i , int excpt){
	vector< pair<int,int> > v;
	if (md.count(pair<int,int>(i,excpt)))
	{
		return md[pair<int,int>(i,excpt)].first;
	}
	for (int j = 1; j <= n; ++j)
	{
		if (j == excpt)
		{
			continue;
		}
		if (arr[i][j])
		{
			v.push_back(pair<int,int>(max_distance(j, i)+arr[i][j], j));
		}
	}
	if (v.empty())
	{
		md[pair<int,int>(i,excpt)] = pair<int,int>(0,-1);
		return 0;
	}
	int curmax = v[0].first;
	int curm_sec = v[0].second;
	for(auto &x: v){
		if (x.first > curmax)
		{
			curm_sec = x.second;
			curmax = x.first;
		}
	}
	md[pair<int,int>(i,excpt)] = pair<int,int>(curmax,curm_sec);
	return curmax;
}

int min_ecc(int start, int s){
	int ret = 0;
	int min_ecc_n = INT_MAX;
	while(!ret){
		vector<int> v;
		pair<int,int> pr = md[pair<int,int>(start,start)];
		while(1){
			v.push_back(start);
			s -= arr[start][pr.second];
			if (s<=0)
			{
				break;
			}
			pr = md[pair<int,int>(pr.second,start)];
			if (pr.second == -1)
			{
				v.push_back(pr.second);
				ret = 1;
				break;
			}
			start = pr.second;
		}
		int max_ecc = 0;
		for (int i = 1; i < n; ++i)
		{
			int d_min = min_dis(i, v[0]);
			for (int j = 0; j < v.size(); ++j)
			{
				if (min_dis(i,v[j]) < d_min)
				{
					d_min = min_dis(i,v[j]);
				}
			}
			if (max_ecc < d_min)
			{
				max_ecc = d_min;
			}
		}
		if (max_ecc < min_ecc_n)
		{
			min_ecc_n = max_ecc;
		}
		if (ret)
		{
			break;
		}
		start = md[pair<int,int>(pr.second,start)].second;
	}
	return min_ecc_n;
}

int main(){
	cin >> n >> s;
	for (int i = 0; i < n-1; ++i)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		arr[t1][t2] = t3;
		arr[t2][t1] = t3;
	}
	int max_d_i = 1;
	int max_d = max_distance(max_d_i,max_d_i);
	for (int i = 1; i <= n; ++i)
	{
		if(max_d < max_distance(max_d_i,max_d_i)){
			max_d_i = i;
			max_d = max_distance(max_d_i,max_d_i);
		}
	}
	cout << min_ecc(max_d_i, s) << endl;
}