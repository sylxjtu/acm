//AC Time: 40 min
//Algorithm: None
#include <cstdio>
#include <cmath>
double t,d,h;
int p;

int inp(){
	t=0,d=0,h=0,p=0;
	char tmpc[2];
	double tmpi[2];
	scanf(" %c",tmpc);
	if (*tmpc=='E')
	{
		return 0;
	}
	scanf(" %lf %c %lf",tmpi,tmpc+1,tmpi+1);
	switch(tmpc[0]){
		case 'T':
		p|=1<<2;
		t=tmpi[0];
		break;
		case 'D':
		p|=1<<1;
		d=tmpi[0];
		break;
		case 'H':
		p|=1;
		h=tmpi[0];
	}
	switch(tmpc[1]){
		case 'T':
		p|=1<<2;
		t=tmpi[1];
		break;
		case 'D':
		p|=1<<1;
		d=tmpi[1];
		break;
		case 'H':
		p|=1;
		h=tmpi[1];
	}
	return 1;
}

void outp(){
	printf("T %.1f D %.1f H %.1f\n", t, d, h);
}

void process(){
	switch(p){
		case 3:
		t=h-(0.5555)*(6.11 * exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10);
		break;
		case 5:
		d=1/( (1/273.16)-log(((h-t)/0.5555+10)/6.11)/5417.7530 )-273.16;
		break;
		case 6:
		h=t+(0.5555)*(6.11 * exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10);
	}
}

int main()
{
	while(inp()){
		process();
		outp();
	}
	return 0;
}