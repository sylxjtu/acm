//AC Time: 0MS
//Algorithm: recursion
#include <cstdio>
#include <cstring>
struct Bintree{
	Bintree* left;
	Bintree* right;
	char val;
	Bintree(){
		left=NULL;
		right=NULL;
		val=0;
	}
};
Bintree* construct(char* s1,char* s2,int slen);

char buf1[30],buf2[30];

int inp(){
	return scanf("%s %s",buf1,buf2)==2;
}

Bintree* process(){
	return (construct(buf1,buf2,strlen(buf1)));
}

Bintree* construct(char* s1,char* s2,int slen){
	if (slen==0)
	{
		return 0;
	}
	Bintree* r=new Bintree;
	if (slen==1)
	{
		r->val=s1[0];
		return r;
	}
	for (int i = 0; i < slen; ++i)
	{
		if (s2[i]==s1[0])
		{
			r->left=construct(s1+1,s2,i);
			r->right=construct(s1+i+1,s2+i+1,slen-i-1);
			r->val=s1[0];
			break;
		}
	}
	return r;
}

void outp_r(Bintree* b){
	if (b->left)
	{
		outp_r(b->left);
	}
	if (b->right)
	{
		outp_r(b->right);
	}
	putchar(b->val);
	delete b;
}

void outp(Bintree* b){
	outp_r(b);
	printf("\n");
}

int main(void){
	while(inp()){
		outp(process());
	}
	return 0;
}