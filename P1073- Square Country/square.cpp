
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream fin("square.in");
ofstream fout("square.out");

int rectimes=0;

int perfectsq(int x);
int func(int x);
int memo[60001];

int main()
{
	int N;
	fin>>N;

	int i;
	for(i=0;i<=N;i++)
	{
		memo[i]=-1;
	}

	fout<<func(N);
	fout<<"\n"<<rectimes;

	return(0);

}

int func(int x)
{
    rectimes++;
	double temp;
	//Base Case
	if(x==1){return(1);}

	if(memo[x]!=-1){return(memo[x]);}

	if(perfectsq(x))
	{
		temp=x;
		memo[x]=1;
		fout<<"Memo["<<x<<"]:"<<memo[x]<<"\n";
		return(memo[x]);
	}

	int i;
	int min=600000;
	int res;
	for(i=1;i<(x);i++)
	{
		res=func((x-i))+func(i);
		if(res<min){min=res;}
	}
	memo[x]=min;
	fout<<"Memo["<<x<<"]:"<<memo[x]<<"\n";
    return(min);
}

int perfectsq(int x)
{
	double temp=x;
	int ans=sqrt(temp);
	if((ans*ans)==x){return(1);}
	else{return(0);}
}
