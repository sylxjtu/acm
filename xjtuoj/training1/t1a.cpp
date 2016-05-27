#include <iostream>
using namespace std;

int f(int m, int n, int lst){
	if (n == 1 && m>=lst)
	{
		return 1;
	}
	if (n == 1 && m<lst)
	{
		return 0;
	}
	else
	{
		int ret = 0;
		for (int i = lst; i < m-lst+1; ++i)
		{
			ret += f(m-i, n-1, i);
		}
		return ret;
	}
}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int m,n;
		cin >> m >> n;
		cout << f(m,n,0) << endl;
	}
	return 0;
}