#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int kase = 1;
	while(1){
		vector<int> regions;
		int m,n;
		int volume;
		cin >> m >> n;
		if (!m || !n)
		{
			printf("\n");
			return 0;
		}
		for (int i = 0; i < m*n; ++i)
		{
			int tmp;
			cin >> tmp;
			regions.push_back(tmp);
		}
		cin >> volume;
		sort(regions.begin(), regions.end());
		double finalHeight,coverPercent;
		if (regions.size()==1)
		{
			finalHeight = regions[0] + double(volume)/100;
			coverPercent = 1;
		}
		for (int i = 1; i < regions.size(); ++i)
		{
			if (volume >= i * 100 * (regions[i] - regions[i-1]))
			{
				volume -= i * 100 * (regions[i] - regions[i-1]);
				//printf("%d volume=%d regions[%d]-regions[%d]=%d\n", i, volume, i, i-1, (regions[i] - regions[i-1]));
			}
			else{
				finalHeight = regions[i-1] + double(volume)/(i*100);
				coverPercent = double(i)/(m*n);
				goto cont;
			}
		}
		finalHeight = regions[regions.size()-1] + double(volume)/(regions.size()*100);
		coverPercent = 1;
		cont:;
		if (kase!=1)
		{
			printf("\n");
		}
		printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n", kase, finalHeight, coverPercent*100);
		kase++;
	}
}