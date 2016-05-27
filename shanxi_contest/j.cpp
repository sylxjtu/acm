#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int limits[220];

int m7table[6][10] = {
	{0, 1, 2, 3, 4, 5, 6, 0, 1, 2},
	{0, 3, 6, 2, 5, 1, 4, 0, 3, 6},
	{0, 2, 4, 6, 1, 3, 5, 0, 2, 4},
	{0, 6, 5, 4, 3 ,2, 1, 0, 6, 5},
	{0, 4, 1, 5, 2, 6, 3, 0, 4, 1},
	{0, 5, 3, 1, 6, 4, 2, 0, 5, 3},
};

int dparr[220][10][7][2];

int dp(int x, int pre, int mod7, int bo, int limit){
	if(x<0){
		return (bo&&(mod7==0))?1:0;
	}
	else{
		if(limit==-1){
			int& ans = dparr[x][pre][mod7][bo];
			if(ans != -1){
				return ans;
			}
			else{
				ans=0;
				for(int i=0; i<10; i++){
					if(pre == 1 && i == 8) continue;
					ans+=dp(x-1, i, (mod7+m7table[x%6][i]) % 7, bo?1:(i==2||i==3||i==5), -1);
					ans%=1000000007;
				}
				return ans;
			}
		}
		else{
			if(x == 0){
				int ans=0;
				for(int i=0; i<=limit; i++){
					if(pre == 1 && i == 8) continue;
					ans+=dp(x-1, i, (mod7+m7table[x%6][i]) % 7, bo?1:(i==2||i==3||i==5), -1);
					ans%=1000000007;
				}
				return ans;
			}
			else{
				int ans=0;
				for(int i=0; i<limit; i++){
					if(pre == 1 && i == 8) continue;
					ans+=dp(x-1, i, (mod7+m7table[x%6][i]) % 7, bo?1:(i==2||i==3||i==5), -1);
					ans%=1000000007;
				}
				int i=limit;
				if(!(pre == 1 && i == 8)){
					ans+=dp(x-1, i, (mod7+m7table[x%6][i]) % 7, bo?1:(i==2||i==3||i==5), limits[x-1]);
					ans%=1000000007;
				}
				return ans;
			}
		}
	}
}

int solve(const string& maxlimit){
	for(int i = maxlimit.size(); i>0; i--){
		limits[i-1] = maxlimit[maxlimit.size() - i] - '0';
	}
	return dp(maxlimit.size()-1, 0, 0, 0, limits[maxlimit.size() - 1]);
}

int solveopen(const string& maxlimit){
	for(int i = maxlimit.size(); i>0; i--){
		limits[i-1] = maxlimit[maxlimit.size() - i] - '0';
	}
	for(int i = 0; i<maxlimit.size(); i++){
		if(limits[i]!=0){
			for(int j=0; j<i; j++){
				limits[j] = 9;
			}
			limits[i]--;
			break;
		}
	}
	return dp(maxlimit.size()-1, 0, 0, 0, limits[maxlimit.size() - 1]);
}

int main(){
	int kase;
	cin >> kase;
	memset(dparr, -1, sizeof(dparr));
	for(int i=0; i<kase; i++){
		string a,b;
		cin >> a >> b;
		if(a!=string("1"))
			cout << (solve(b) - solveopen(a))%1000000007 << endl;
		else
			cout << solve(b) << endl;
	}
	/*for (int i = 10000; i < 100000; ++i)
	{
		stringstream ss;
		ss << i;
		string s = ss.str();
		if(solve(s) - solveopen(s) == 1)
			cout << i << endl;
	}*/
	return 0;
}