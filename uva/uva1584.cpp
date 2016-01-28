#include <cstdio>
#include <cstring>

char buf[110];

int main(){
	int kase;
	scanf("%d",&kase);
	for (int i = 0; i < kase; ++i)
	{
		scanf("%s",buf);
		int curMin=0;
		int len=strlen(buf);
		for (int j = 1; j < len; ++j)
		{
			for (int k = 0; k < len; ++k)
			{
				if (buf[(j+k)%len]<buf[(curMin+k)%len])
				{
					curMin=j;
					break;
				}
				else if(buf[(j+k)%len]>buf[(curMin+k)%len]){
					break;
				}
			}
		}
		for (int i = 0; i < len; ++i)
		{
			putchar(buf[(curMin+i)%len]);
		}
		putchar('\n');
	}
	return 0;
}