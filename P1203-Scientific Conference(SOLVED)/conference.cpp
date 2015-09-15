#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;


ifstream fin("conference.in");
ofstream fout("conference.out");

int N;
int total;

void read();
bool mybool(const struct myarray &a1,const struct myarray &a2);
void walkem();

struct myarray
{
	int start;
	int fini;
}conf[100000];

int main()
{

	fin>>N;
	read();
	sort(&conf[0],&conf[N],mybool);
	walkem();
	fout<<total;
	return(0);
}

bool mybool(const struct myarray &a1,const struct myarray &a2)
{
	return(a1.fini<a2.fini);
}


void read()
{
	int i;
	for(i=0;i<N;i++)
	{
		fin>>conf[i].start;
		fin>>conf[i].fini;
	}
}

void walkem()
{
	int i;
	int last;
	total++;
	last=conf[0].fini;
	for(i=1;i<N;i++)
	{
		if(conf[i].start>=(last+1))
		{
			total++;
			last=conf[i].fini;
		}
	}
}


