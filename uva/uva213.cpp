#include <cstdio>
#include <cstdlib>

char data[300];
char tmpstore[10];

void readn(int n){
	int tmpsp=0;
	char tmp;
	while(tmpsp<n && (tmp=getchar()) ){
		if (tmp!='\n')
		{
			tmpstore[tmpsp++]=tmp;
		}
	}
	tmpstore[tmpsp]=0;
}

int main(){
	int tmp;
	while(1){
		int datap=0;
		while(tmp=getchar()){
			if (tmp==EOF)
			{
				return 0;
			}
			else if(tmp!='\n')
			{
				data[datap++]=tmp;
			}
			else{
				break;
			}
		}
		data[datap]=0;
		while(1){
			readn(3);
			int codelen=strtol(tmpstore,NULL,2);
			if (!codelen)
			{
				break;
			}
			while(1){
				readn(codelen);
				int code=strtol(tmpstore,NULL,2);
				if (code==(1<<codelen)-1)
				{
					break;
				}
				putchar(data[(1<<codelen)-codelen-1+code]);
			}
		}
		putchar('\n');
		getchar();
	}
	return 0;
}
