#include <vector>
#include <cstdio>

std::vector<int> modv;

int main(){
	int u,d,init=1;
	while(scanf("%d%d",&u,&d)==2) {
		if(init) {
			init=0;
		}
		else{
			printf("\n");
		}
		printf("%d/%d = %d.", u, d, u/d);
		int rps;
		while(1) {
			for (int i = 0; i < modv.size(); i++)
			{
				if(u%d==modv[i]) {
					rps=i;
					goto outerbreak;
				}
			}
		    modv.push_back(u%d);
		    u=(u%d)*10;
		}
		outerbreak:;
		for (int i = 0; i < rps; ++i)
		{
			printf("%d", modv[i]*10/d);
		}
		printf("(");
		int totlen=modv.size()-rps;
		if(modv.size()>50) {
			for (int i = rps; i < 50; ++i)
			{
				printf("%d", modv[i]*10/d);
			}
			printf("...)\n");
		}
		else{
			for (int i = rps; i < modv.size(); ++i)
			{
				printf("%d", modv[i]*10/d);
			}
			printf(")\n");
		}
		printf("   %d = number of digits in repeating cycle\n", totlen);
		modv.clear();
	}
	printf("\n");
}
