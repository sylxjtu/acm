#include <cstdio>

char keys[]="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

int main(){
	char c;
	while((c=getchar())!=EOF) {
	    for (int i = 0; keys[i]; ++i)
	    {
	    	if (keys[i]==c)
	    	{
	    		printf("%c", keys[i-1]);
	    		goto found;
	    	}
	    }
	    printf("%c", c);
	    found:;
	}
}