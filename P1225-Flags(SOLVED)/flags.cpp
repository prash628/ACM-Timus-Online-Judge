#include <iostream>
#include <conio.h>
using namespace std;

int N;
long long rec(int i,int prev,int pprev);
long long memo[50][50][50];

int main()
{
	long long total;
	cin>>N;
	int i,j,k;
	for(i=0;i<=N;i++)
	{
                     for(j=0;j<=N;j++)
                     {
                                      for(k=0;k<=N;k++)
                                      {
                                                       memo[i][j][k]=-1;
                                      }
                     }
    }
                                                       
	total=rec(0,0,0);
	cout<<total;
    getch();
	return(0);
}

long long rec(int i,int prev,int pprev)
{
	long long tot;
	//Base
	if(i==N-1)
	{
		return(1);
	}
	if(memo[i][prev][pprev]!=-1){return(memo[i][prev][pprev]);}
	if(i==0)
	{
		tot=rec(i+1,1,prev)+rec(i+1,3,prev);
	}
	else
	{
	  if(prev==1)
	  {
		  tot=rec(i+1,2,prev)+rec(i+1,3,prev);
	  }
	  if(prev==2)
	  {
		  if(pprev==1)
		  {
		     tot=rec(i+1,3,prev);
		  }
		  if(pprev==3)
		  {
			  tot=rec(i+1,1,prev);
		  }
	  }
	  if(prev==3)
      {
		  tot=rec(i+1,2,prev)+rec(i+1,1,prev);
	  }
	 
	}
	memo[i][prev][pprev]=tot;
	return(tot);
}
