#include <stdio.h>
char a[1000],b[1000],c[1000],*ap=a,*bp=b,*cp=c;
int main(void)
{
	scanf("%s%s",a,b);
	while(*ap || *bp){
		if (*ap)
		{
			*(cp++)=*(ap++);
		}
		if (*bp)
		{
			*(cp++)=*(bp++);
		}
	}
	printf("%s\n", c);
	return 0;
}