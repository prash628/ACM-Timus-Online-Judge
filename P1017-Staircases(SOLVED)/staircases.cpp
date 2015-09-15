#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("staircases.in");
ofstream fout("staircases.out");

long long A[501][501];


long long func(int leftover,int prev);

int main()
{
	int N;
	fin>>N;
	
	int i,j;long long total=0;
	
	for(i=0;i<N;i++)
	{
                    for(j=0;j<N;j++)
                    {
                                    A[i][j]=-1;
                    }
    }
	
	for(i=2;i<N;i++)
	{
                    
	total=total+func(N-i,i);
	  //fout<<"func("<<N-i<<","<<i<<")"<<func(N-i,i)<<"\n";
	}
	fout<<total;
	return(0);

}

long long func(int leftover,int prev)
{
    //fout<<"func("<<leftover<<","<<prev<<")"<<"\n";
	if(leftover==0)
    {
      return(1);
      
    }

    int x=prev;
    
                  if(A[leftover][x]!=-1){return(A[leftover][x]);}

	int N=leftover;

	int i;
	long long total=0;
	for(i=1;i<prev &&(N-i>=0);i++)
	{                  
		total=total+func(N-i,i);
	}
	 
    
    A[leftover][prev]=total;
	return(total);
	
}


