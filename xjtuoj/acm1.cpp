#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

ll m,s,t,curs=0;

map< pair<ll, ll>, ll> dp_s;

int dp(ll m, ll s, ll t, ll curs){
	if (!dp_s.count(pair<ll,ll>(m,t)))
	{
		dp_s[pair<ll,ll>(m,t)] = curs;
	}
	else{
		dp_s[pair<ll,ll>(m,t)] = max(curs;
	}

}

int main(){
	cin >> m >> s >> t;
	if (t < m/10)
	{
		if (s > t*60)
		{
			cout << "No" << endl << t*60 << endl;
		}
		else
		{
			cout << "Yes" << endl << s/t << endl;
		}
		return 0;
	}
	curs += m/10 * 60;
	t-=m/10;
	m%=10;
	dp()
}