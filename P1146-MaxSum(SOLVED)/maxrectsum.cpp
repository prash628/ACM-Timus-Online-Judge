#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("rect.in");
ofstream fout("rect.out");

int N;
int A[101][101];
int res[101][101][101][101];
int chk[101][101][101][101];
void readA();
int compute();
int findarea(int i1,int j1,int i2,int j2);
int main()
{
	int total;
	fin>>N;
    readA();
	//fout<<compute();

	return(0);
}

void readA()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{fout<<"hmm";
			fin>>A[i][j];
		}
	}
}

int compute()
{
	int i1,j1,i2,j2;
	int val;
	int temp;
	for(i1=0;i1<N;i1++)
	{
		for(j1=0;j1<N;j1++)
		{
			for(i2=0;i2<N;i2++)
			{
				for(j2=0;j2<N;j2++)
				{

					if(i1==0&&j1==0&&i2==0&&j2==0){val=A[0][0];}
					else
					{
						if(chk[i1][j1][i2][j2]==1){temp=res[i1][j1][i2][j2];}
						else{temp=findarea(i1,j1,i2,j2);}
						if(temp>val){val=temp;}
					}
				}
			}
		}
	}
	return(val);
}

int findarea(int i1,int j1,int i2,int j2)
{
	int p,q,r,s;
	int tot=0;
	if(i1<i2)
	{
		if(j1<j2)
		{		
		  p=i1;
		  q=i2;
		  r=j1;
		  s=j2;
		}
		else
		{
		  p=i1;
		  q=i2;
		  r=j2;
		  s=j1;
		}
	}
	else
	{
        if(j1<j2)
		{		
		  p=i2;
		  q=i1;
		  r=j1;
		  s=j2;
		}
		else
		{
		  p=i2;
		  q=i1;
		  r=j2;
		  s=j1;
		}
	}
    for(;p<=q;p++)
	{
		for(;r<=s;r++)
		{
			tot=tot+A[p][r];
		}
	}
    res[i1][j1][i2][j2]=tot;
	chk[i1][j1][i2][j2]=1;
	res[i2][j2][i1][j1]=tot;
	chk[i2][j2][i1][j1]=1;
	return(res[i1][j1][i2][j2]);
}
