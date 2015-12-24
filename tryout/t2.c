#include <stdio.h>
int x1[25],x2[25],result[50];
int minus;
void product(){
	for (int i = 24; i >= 0; --i)
	{
		for (int j = 24; j >= 0; --j)
		{
			result[i+j+1]+=x1[i]*x2[j];
		}
	}
	for (int i = 49; i >= 1; --i)
	{
		result[i-1]+=result[i]/10;
		result[i]%=10;
	}
}
void inp(int* x){
	char nothing[2];
	if (scanf(" %[-]",nothing))
	{
		minus=!minus;
	}
	scanf(" 0.");
	for (int i = 0; i < 25; ++i)
	{
		x[i]=getchar()-'0';
	}
}
int main(int argc, char const *argv[])
{
	int end;
	inp(x1);
	inp(x2);
	product();
	printf("%s", minus?"-":"");
	printf("0.");
	for (end = 49; end >= 0; --end)
	{
		if(result[end]){
			break;
		}
	}
	for (int i = 0; i <= end; ++i)
	{
		printf("%d", result[i]);
	}
	printf("\n");
	return 0;
}