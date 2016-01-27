#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char sec1[300],sec2[300];

int main(){
	while(scanf(" %s %s",sec1,sec2)==2) {
		int curMin=300;
		int sec1l=strlen(sec1);
		int sec2l=strlen(sec2);
	    for (int i = 0; i < sec1l+1; ++i)
	    {
	    	int ok=1;
	    	for (int j = i; j < sec1l && j-i < sec2l; ++j)
	    	{
	    		if (sec1[j]=='2' && sec2[j-i]=='2')
	    		{
	    			ok=0;
	    			break;
	    		}
	    	}
	    	if (ok)
	    	{
	    		curMin=max(sec2l+i,sec1l);
	    		break;
	    	}
	    }
	    for (int i = 0; i < sec2l+1; ++i)
	    {
	    	int ok=1;
	    	for (int j = i; j < sec2l && j-i < sec1l; ++j)
	    	{
	    		if (sec2[j]=='2' && sec1[j-i]=='2')
	    		{
	    			ok=0;
	    			break;
	    		}
	    	}
	    	if (ok)
	    	{
	    		curMin=min(curMin,max(sec1l+i,sec2l));
	    		break;
	    	}
	    }
	    printf("%d\n", curMin);
	    memset(sec1,0,sizeof(sec1));
	    memset(sec2,0,sizeof(sec2));
	}
	return 0;
}