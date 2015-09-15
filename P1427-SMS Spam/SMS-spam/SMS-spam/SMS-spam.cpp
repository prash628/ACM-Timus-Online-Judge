#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("sms.in");
ofstream fout("sms.out");

void readip();
int func(int ipos);
void initmemo();
int findlatinend(int ipos);
int findnonlatinend(int ipos);

int N,M;
string sms;
int smslen;
int memo[100002];
int main()
{
	readip();
	initmemo();
	fout<<func(0);
}
int func(int ipos)
{
	if(ipos=smslen)
	{
		return(0);
	}
	else
	{
		if(memo[ipos]!=-1){return(memo[ipos]);}
		else
		{
			int latincount=0,nonlatincount=0;
			int latinend=findlatinend(ipos);
			int nonlatinend=findnonlatinend(ipos);
			int latinfunc=func(latinend+1);
			int nonlatinfunc;
			memo[latinend+1]=latinfunc;
			if(latinend==nonlatinend)
			{
				nonlatinfunc=latinfunc;
			}
			else
			{
				nonlatinfunc=func(nonlatinend+1);
			}
			latincount=latinfunc;
			nonlatincount=nonlatinfunc;
			if(latinend!=ipos){latincount++;}
			if(nonlatinend!=ipos){nonlatincount++;}
			if(latincount<nonlatincount)
			{
				memo[ipos]=latincount;
				return(latincount);
			}
			else
			{
				memo[ipos]=nonlatincount;
				return(nonlatincount);
			}
			
		}

	}
}

void readip()
{
	fin>>N;
	fin>>M;
	fin>>sms;
	smslen=sms.length();
}
void initmemo()
{
	int i=0;
	for(;i<100002;i++)
	{
		memo[i]=-1;
	}
}
int findlatinend(int ipos)
{
	int i=ipos;
	int count=0;
	while(i<smslen && ((sms[i]>=65 && sms[i]<=90) || (sms[i]>=97 && sms[i]<=122) || (sms[i]==' ')) &&(count<N))
	{
		i++;
		count++;
	}
	return(i-1);
}
int findnonlatinend(int ipos)
{
	int i=ipos;
	int count=0;
	while(i<smslen &&(count<N))
	{
		i++;
		count++;
	}
	return(i-1);
}