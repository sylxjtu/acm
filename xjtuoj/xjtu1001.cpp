#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

typedef unsigned long long int ull;
ull storage[10000];
ull arr[1000000];

bool isprime(ull x){
	if (x<2)
	{
		return false;
	}
	int sqrtx = int(sqrt(x))+1;
	if (sqrtx<=2)
	{
		return true;
	}
	//int* arr = new int[sqrtx-2];
	for (int i = 0; i < sqrtx-2; ++i)
	{
		arr[i] = i+2;
	}
	for (int i = 2; i <= sqrtx; ++i)
	{
		if (!arr[i-2])
		{
			continue;
		}
		else{
			if (!(x%i))
			{
				return false;
			}
			for (int j = 2; i*j <= sqrtx; ++j)
			{
				arr[i*j - 2] = 0;
			}
		}
	}
	return true;
}

int main(){
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> storage[i];
	}
	nth_element(storage,storage+k-1,storage+n);
	ull mine = *(storage+k-1);
	nth_element(storage,storage+n-k,storage+n);
	ull maxe = *(storage+n-k);
	if (maxe <= mine)
	{
		cout << "NO" << endl << (long long)maxe - (long long)mine << endl;
		return 0;
	}
	ull result = maxe - mine;
	cout << string(isprime(result)?"YES":"NO") << endl << result << endl;
	return 0;
}