#include <cstdio>
#include <cstring>
#include <cmath>

inline double log2(double x){
	return log(x)/log(2);
}

char buf[100];
int main(){
	while(1) {
	    scanf("%s",buf);
	    if (strcmp(buf,"0e0")==0)
	    {
	    	return 0;
	    }
	    for (int i = 0; buf[i]; ++i)
	    {
	    	if (buf[i]=='e')
	    	{
	    		buf[i]=' ';
	    	}
	    }
	    double decm,dece;
	    int e;
	    sscanf(buf,"%lf%lf",&decm,&dece);
	    e=(int)(log2(log2(decm)+dece*log2(10)+2));
	    printf("%d %d\n", (int)( -log2(1 - pow( 2, log2(decm) + dece*log2(10) + 1 - pow(2,e) ) ) - 0.5 ) , e);
	}
}