#include <iostream>
#include <algorithm>
using namespace std;

int arr[30000];
int main(){
	int w,n,cnt=0;
	cin >> w >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	for (int fp=0, bp=n-1; fp <= bp; --bp)
	{
		if (arr[fp]+arr[bp]<=w)
		{
			fp++;
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}