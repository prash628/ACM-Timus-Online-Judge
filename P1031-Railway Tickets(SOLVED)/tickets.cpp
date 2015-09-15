#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
ifstream fin("tickets.in");
ofstream fout("tickets.out");

long long L1,L2,L3;
long long C1,C2,C3;
int N;
long long dist[10001];

long long memo[10001];
int maxstn[10001][3];

int boardingpt;
int destination;


long long oo=1000000000;


long long func(int init);
void readB();

int main()
{
    int u,v;
    for(u=0;u<10001;u++)
    {
                        for(v=0;v<3;v++)
                        {
                                        maxstn[u][v]=0;
                        }
    }
	fin>>L1;
	fin>>L2;
	fin>>L3;
	fin>>C1;
	fin>>C2;
	fin>>C3;
	fin>>N;
	fin>>boardingpt;
	boardingpt--;
	fin>>destination;
	destination--;
	int temp;
	if(boardingpt>destination)
	{
                              temp=boardingpt;
                              boardingpt=destination;
                              destination=temp;
                              
   }

	int p;
	dist[0]=0;
	for(p=1;p<(N);p++)
	{
		fin>>dist[p];
	}
	fout<<func(boardingpt);
	 
	return(0);
}

long long func(int init)
{
     
	//Base case
	if(init==destination){return(0);}
	if(memo[init]!=0){return(memo[init]);}

	long long disttogo=dist[destination]-dist[init];
	//If da distance between init and destination(disttogo) is<= L1,return that
	if(disttogo<=L1){return(C1);}
	long long res=oo;
	long long val;
	
	if(disttogo<=L2)
	{
	   val=C2;
	   if(val<res){res=val;}
	}
	else
	{
        if(disttogo<=L3)
        {
		val=C3;
		if(val<res){res=val;}
        }
	}

	//Max station from init by L1
	int x=init;
	int nextstn;
	
	if(maxstn[init][0]==0)
	{             
		while((dist[x+1]-dist[init])<=L1)//while the dist betn init and x && x==destinationis ...dist[x]-dist[init]
		{
                                                 
			x++;
			if(x==destination){break;}
		}
		nextstn=x;
		maxstn[init][0]=nextstn;
	}
	else
	{
		nextstn=maxstn[init][0];
	}
	

    if(nextstn!=init)
    {          
	val=C1+func(nextstn);
	 
	if(val<res){res=val;}
    }
    
	//Max stn from init by L2
	x=init;
	if(maxstn[init][1]==0)
	{
		x=init;
		while((dist[x+1]-dist[init])<=L2)
		{
			x++;
			if(x==destination){break;}
		}
		nextstn=x;
		maxstn[init][1]=nextstn;
	}
	else
	{
		nextstn=maxstn[init][1];
	}
	if(nextstn!=init)
    {         
	val=C2+func(nextstn);
	 
	if(val<res){res=val;}
    }

	//Max stn from init by L3
	x=init;
	if(maxstn[init][2]==0)
	{
                           
		x=init;
		while((dist[x+1]-dist[init])<=L3)
		{
			x++;
			if(x==destination){break;}
		}
		nextstn=x;
		maxstn[init][2]=nextstn;
	}
	else
	{
		nextstn=maxstn[init][2];
	}
	    
	val=C3+func(nextstn);
	 
	if(val<res){res=val;}


	memo[init]=res;
	 
	return(res);
}
	
