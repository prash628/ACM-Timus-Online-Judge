#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream fin("metro.in");
ofstream fout("metro.out");


int N,M,K;
int diag[101][101];
double A[1001][1001];
double findpath(int i,int j);
int available(int a,int b);
double ddist;


int main()
{
	ddist=sqrt(2)*100;
	double res;
	fin>>N; 
	fin>>M;
	fin>>K;
	int i,j;
	for(i=0;i<K;i++)
	{
		for(j=0;j<2;j++)
		{
			fin>>diag[i][j];
		}
	}
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=M;j++)
		{
			A[i][j]=-1;
		}
	}
	res=findpath(0,0);
	int ires=(int)(res+.5);
	fout<<ires;
	return(0);
}

double findpath(int i,int j)
{
       fout<<i<<j<<"\n";
	double res1,res2,res3;
	double min=-2;
	if(i==N && j==M){return(0);}
	if(A[i][j]>=0){fout<<"Memo"<<"\n";return(A[i][j]);}

	//Choice 1:to da right
	if(i+1<=N){res1=100+findpath(i+1,j);min=res1;}
	
	//Choice 2:goin up
	if(j+1<=M)
	{res2=100+findpath(i,j+1);
	if(min<0){min=res2;}
	else{if(res2<min){min=res2;}}
	}

	//Goin diagonally
	if(i+1<=N && j+1<=M)
	{
	if(available(i,j))
	{
		res3=ddist+findpath(i+1,j+1);
		if(res3<min){min=res3;}
	}
    }

	A[i][j]=min;
   fout<<"A["<<i<<"]["<<j<<"]"<<"="<<min<<"\n";
	return(min);
}

int available(int a,int b)
{
	a++;b++;
	int i,j;
	int xi,xj;
	for(i=0;i<K;i++)
	{
            xi=diag[i][0];
            xj=diag[i][1];
			if(a==xi && b==xj){return(1);}
	}
	return(0);
}




	
