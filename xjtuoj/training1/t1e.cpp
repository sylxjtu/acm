#include <iostream>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const double maxdouble = 1e+100;

double station[2][100000];
double agent[2][100000];
int n;

inline double dis(int j, int k){
	//cout << "dis(" << j << "," << k << ")" << endl;
	return sqrt((station[0][j]-agent[0][k])*(station[0][j]-agent[0][k])+(station[1][j]-agent[1][k])*(station[1][j]-agent[1][k]));
}


inline double mymin(double r, int j, int k){
	if((station[1][j]-agent[1][k])>r || (station[1][j]-agent[1][k])>r)
		return r;
	else
		return min(r,dis(j,k));
}

double min_dis(int start, int end, double startpos, double endpos){
	//cout << start << " " << end << " " << startpos << " " << endpos << endl;
	double ret = maxdouble;
	if (end - start == 1)
	{
		double *low = lower_bound(agent[0],agent[0]+n,startpos);
		double *up = upper_bound(low,agent[0]+n,endpos);
		for (double* i = low; i != up; ++i)
		{
			ret = mymin(ret,start,i-agent[0]);
		}
		return ret;
	}
	double centre = (station[0][(start+end)/2-1]+station[0][(start+end)/2])/2;
	double min_dis_mlr = min(min_dis(start,(start+end)/2,startpos,centre),
							min_dis((start+end)/2,end,centre,endpos));
	double *low_stat = lower_bound(station[0]+start,station[0]+end,centre-min_dis_mlr);
	double *up_stat = upper_bound(low_stat,station[0]+end,centre+min_dis_mlr);
	double *centre_stat_l = lower_bound(low_stat,up_stat,centre);
	double *centre_stat_u = upper_bound(centre_stat_l,up_stat,centre);
	double *low_agent = lower_bound(agent[0],agent[0]+n,centre-min_dis_mlr);
	double *up_agent = upper_bound(low_agent,agent[0]+n,centre+min_dis_mlr);
	double *centre_agent_l = lower_bound(low_agent,up_agent,centre);
	double *centre_agent_u = upper_bound(centre_agent_l,up_agent,centre);

	ret = min_dis_mlr;
	for (double* i = low_stat; i < centre_stat_u; ++i)
	{
		for (double* j = centre_agent_l; j < up_agent; ++j)
		{
			ret = mymin(ret, i-station[0], j-agent[0]);
		}
	}
	for (double* i = centre_stat_l; i < up_stat; ++i)
	{
		for (double* j = low_agent; j < centre_agent_u; ++j)
		{
			ret = mymin(ret, i-station[0], j-agent[0]);
		}
	}

	return ret;
}

int main(){
	//freopen("Desktop\\t1eex.txt","r",stdin);
	int kase;
	cin >> kase;
	for (int i = 0; i < kase; ++i)
	{
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> station[0][j] >> station[1][j];
		}
		for (int j = 0; j < n; ++j)
		{
			cin >> agent[0][j] >> agent[1][j];
		}
		sort(station[0],station[0]+n);
		sort(agent[0],agent[0]+n);
		printf("%.3lf\n", min_dis(0,n,-1,maxdouble));
	}
}