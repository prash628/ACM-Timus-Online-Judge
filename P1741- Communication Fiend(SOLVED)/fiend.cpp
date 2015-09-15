#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
ifstream fin("fiend.in");
ofstream fout("fiend.out");

typedef long long I;
#define oo I(10000000000000000LL)

int N,M;

long long memo[10001][3];

struct myarray
{
	int init;
	int final;
	int data;
	int type;
}software[10001];

void readM();
bool mybool(const struct myarray &a1,const struct myarray &a2)
{
	return(a1.init<a2.init);
}
long long findres(int initial,int type);

int main()
{
	int j;
	int k;
	for(j=0;j<10001;j++)
    {  
       for(k=0;k<3;k++)
       {
                        memo[j][k]=-1;
       }
    }
    fin>>N;
	fin>>M;
	readM();
	sort(&software[0],&software[M],mybool);
	int initial=1;
	int type=0;//Licensed
	long long ans;
	ans=findres(initial,type);
	if(ans>=oo){fout<<"Offline";}
	else{fout<<"Online"<<"\n"<<ans;}
    return(0);
}

void readM()
{
	int i;
	string temp;
	for(i=0;i<M;i++)
	{
		fin>>software[i].init;
		fin>>software[i].final;
		fin>>software[i].data;
		fin>>temp;
		if(temp[0]=='L'){software[i].type=0;}
		if(temp[0]=='C'){software[i].type=1;}
		if(temp[0]=='P'){software[i].type=2;}
	}
}

long long findres(int initial,int type)
{
	//Base case
	if(initial==N){return(0);}

	if(memo[initial][type]!=-1){return(memo[initial][type]);}
	int i;
	int chk=1;
	long long val;
	long long finalres=oo;
	for(i=0;i<M && (chk==1);i++)
	{
		val=oo;
		if(software[i].init>initial){chk=0;}
		if(software[i].init==initial)
		{
			if(type==0)
			{
				if(software[i].type==2){val=software[i].data+findres(software[i].final,2);}
				else{val=software[i].data+findres(software[i].final,0);}
			}
			else
			{
				if(software[i].type==0){}
				else
				{val=software[i].data+findres(software[i].final,2);}
			}
			if(val<finalres){finalres=val;}
		}
	}
	memo[initial][type]=finalres;
	return(finalres);
}


		


