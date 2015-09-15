#include <iostream>
//#include <fstream>
using namespace std;
#define oo -1000000
/*ifstream fin("rect.in");
ofstream fout("rect.out");
*/
int N;
int A[100][100];
int res[25][25][25][25];
int compute();
int findarea(int i1,int j1,int i2,int j2);
void readA();
int main()
{
	int total;
	cin>>N;
    readA();
	cout<<compute();
	 

	return(0);
}

void readA()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{ 
			cin>>A[i][j];
		}
	}
}


int compute()
{
	int i1,j1,i2,j2;
	int val;
	int temp;
	for(i1=0;i1<25;i1++)
	{
		for(j1=0;j1<25;j1++)
		{
			for(i2=0;i2<25;i2++)
			{
				for(j2=0;j2<25;j2++)
				{
                    res[i1][j1][i2][j2]=oo;
				}
			}
		}
	}
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
						if(i2<25 && j2<25 && i1<25 &&j1<25 &&(res[i1][j1][i2][j2]!=oo)){temp=res[i1][j1][i2][j2];}
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
	  p=i1;
	  q=i2;
	}
	else
	{
        p=i2;
        q=i1;
    } 
	
   if(j1<j2)
	{		
		  r=j1;
		  s=j2;
	}
	else
	{
		  r=j2;
		  s=j1;
	}
	int x=r;
	 
    for(;p<=q;p++)
	{
        
		for(r=x;r<=s;r++)
		{
             
			tot=tot+A[p][r];
		}
		 
	}
    if(i1<25 && j1<25 &&i2<25 && j2<25)
    {res[i1][j1][i2][j2]=tot;
	res[i2][j2][i1][j1]=tot;
    }
	return(tot);
}
