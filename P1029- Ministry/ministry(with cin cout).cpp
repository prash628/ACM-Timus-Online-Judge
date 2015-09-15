#include <iostream>
 
#include <string>
#include <algorithm>
using namespace std;
 

long long oo=1000000000;
int M,N;
long long cost[101][501];
int printA[6000];
int justonce=0;


long long maintotal;
long long func(int floorno,int A[101][501]);
long long func2(int floorno,int A[101][501],long long money,int printi,int printA[6000]);

int main()
{
	cin>>M;
	cin>>N;
	

	int A[101][501];
	int p,q;
	for(p=0;p<6000;p++){printA[p]=-1;}
	for(p=0;p<101;p++)
	{
		for(q=0;q<501;q++)
		{
			A[p][q]=0;
		}
	}

	for(p=0;p<M;p++)
	{
		for(q=0;q<N;q++)
		{
			cin>>cost[p][q];
		}
	}

	
	long long max=oo;
	long long val;
	for(p=0;p<N;p++)
	{
		A[0][p]=1;
		val=cost[0][p]+func(1,A);
		if(val<max){max=val;}
	    A[0][p]=0;
	}
	maintotal=max;
	
	//Repeat
	max=oo;
	int printi=0;
	for(p=0;p<N;p++)
	{
		A[0][p]=1;
		printA[printi]=p;
		printi++;
		val=cost[0][p]+func2(1,A,cost[0][p],printi,printA);
		if(val<max){max=val;}
	    A[0][p]=0;
	    printi--;
	    printA[printi]=-1;
	}
	
	return(0);
}

long long func2(int floorno,int A[101][501],long long money,int printi,int printA[6000])
{
     int first1nospace=1;
     int p,q;
	//Base case
	if(floorno==(M))
	{
        if(money==maintotal)
        {  if(justonce==0)
           {
                    for(p=0;p<printi;p++)
                    {
                               if(first1nospace){cout<<((printA[p])+1);first1nospace=0;}
                               else{cout<<" "<<((printA[p])+1);}
	                 } 
	                 justonce++;
           }       
	                 
        }
		return(0);
	}


	int i;
	long long val;
	int costtemp=0,costtempr,costtempl;
	long long res=oo;
	for(i=0;i<N;i++)
	{
		if(A[floorno-1][i]==1)
		{
			//Pick just one and send it up
			A[floorno][i]=1;
			costtemp=cost[floorno][i];
			printA[printi]=i;
			printi++;
			val=costtemp+func2(floorno+1,A,money+costtemp,printi,printA);
			
			if(val<res){res=val;}
			costtempr=costtemp;
			costtempl=costtemp;
			//To da right
			for(p=i+1;p<N;p++)
			{
				A[floorno][p]=1;
				costtempr+=cost[floorno][p];
				
				printA[printi]=p;
				printi++;
				
				val=costtempr+func2(floorno+1,A,money+costtempr,printi,printA);
				if(val<res){res=val;}
			}

			for(p=i+1;p<N;p++)
			{
				A[floorno][p]=0;
				printi--;
				printA[printi]=-1;
			}
			//To da left
			
			for(p=i-1;p>=0;p--)
			{
				A[floorno][p]=1;
				costtempl+=cost[floorno][p];
				printA[printi]=p;
				printi++;
				val=costtempl+func2(floorno+1,A,money+costtempl,printi,printA);
				if(val<res){res=val;}
			}
			for(p=i-1;p>=0;p--)
			{
				A[floorno][p]=0;
				printi--;
				printA[printi]=-1;
			}
			A[floorno][i]=0;
			printi--;
			printA[printi]=-1;
		}
	}
	return(res);
}


long long func(int floorno,int A[101][501])
{
	//Base case
	if(floorno==(M))
	{
		return(0);
	}


	int i,p,q;
	long long val;
	int costtemp=0,costtempr,costtempl;
	long long res=oo;
	for(i=0;i<N;i++)
	{
		if(A[floorno-1][i]==1)
		{
			//Pick just one and send it up
			A[floorno][i]=1;
			costtemp=cost[floorno][i];
			val=costtemp+func(floorno+1,A);
			if(val<res){res=val;}
			costtempr=costtemp;
			costtempl=costtemp;
			//To da right
			for(p=i+1;p<N;p++)
			{
				A[floorno][p]=1;
				costtempr+=cost[floorno][p];
				val=costtempr+func(floorno+1,A);
				if(val<res){res=val;}
			}

			for(p=i+1;p<N;p++)
			{
				A[floorno][p]=0;
			}
			//To da left
			
			for(p=i-1;p>=0;p--)
			{
				A[floorno][p]=1;
				costtempl+=cost[floorno][p];
				val=costtempl+func(floorno+1,A);
				if(val<res){res=val;}
			}
			for(p=i-1;p>=0;p--)
			{
				A[floorno][p]=0;
			}
			A[floorno][i]=0;
		}
	}
	return(res);
}
