#include <cstdio>
int main(){
	int flag=0;
	char c;
	while((c=getchar()) != EOF) {
	    if (c=='"')
	    {
	    	printf("%s", flag?"''":"``");
	    	flag=!flag;
	    }
	    else
	    	printf("%c", c);
	}
	return 0;
}
