#include <cstdio>
#include <cstring>

char orichars[]="AEHIJLMOSTUVWXYZ12358";
char revchars[]="A3HILJMO2TUVWXY51SEZ8";
char buf[100];
char alert[][30]={"is not a palindrome.","is a regular palindrome.","is a mirrored string.","is a mirrored palindrome."};

int palin();
int mirror();

int main(){
	int flag=0;
	while(scanf(" %s",buf)==1){
		flag=0;
		flag+=palin();
		flag+=mirror();
		printf("%s -- %s\n\n", buf, alert[flag]);
	}
	return 0;
}

int palin(){
	for(int i=0,j=strlen(buf)-1 ; i<j ; i++,j--){
		if (buf[i]!=buf[j])
		{
			return 0;
		}
	}
	return 1;
}

int mirror(){
	for(int i=0,j=strlen(buf)-1 ; i<=j ; i++,j--){
		for (int k = 0; orichars[k]; ++k)
		{
			if (buf[i]==orichars[k])
			{
				if (buf[j]!=revchars[k])
				{
					return 0;
				}
				goto brked;
			}
		}
		return 0;
		brked:;
	}
	return 2;
}