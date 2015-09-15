#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("mirrors.in");
ofstream fout("mirrors.out");

int N;
int find(int balcony[21],int prev);
int findmask(int balcony[21]);
int memo[20971520];

int main()
{
    int k;
    for(k=0;k<2097152;k++)
    {
                          memo[k]=-1;
    }
    int prev=0;
	int balcony[21];
	fin>>N;
	int i;
	for(i=0;i<N;i++)
	{
       fin>>balcony[i];
       prev=prev+balcony[i];
	}
	
	fout<<find(balcony,prev);
    return(0);
}

int find(int balcony[21],int prev)
{
	//Base case
	int i;
	int chk=0;
	int bitmask=findmask(balcony);
	if(memo[bitmask]!=-1){return(memo[bitmask]);}

	int stepdamage;
	int totaldamage;
	int max=100000;
	int temp1,temp2,temp3;
	for(i=0;i<N;i++)
	{
        
		if(balcony[i]!=0)
		{
            chk++;
			temp1=balcony[i];
			balcony[i]=0;

			temp2=balcony[(i+1)%(N)];
			balcony[(i+1)%(N)]=0;

			temp3=balcony[(i+2)%(N)];
			balcony[(i+2)%(N)]=0;

			stepdamage=prev-temp1-temp2-temp3;
			totaldamage=stepdamage+find(balcony,stepdamage);
			if(totaldamage<max){max=totaldamage;}

			//restore
			balcony[i]=temp1;
			balcony[(i+1)%(N)]=temp2;
            balcony[(i+2)%(N)]=temp3;
		}
	}
	
	if(chk==0){memo[bitmask]=0;return(0);}
	memo[bitmask]=max;
	return(max);

}

int findmask(int balcony[21])
{
    int i;
    int res=0;
    int val;
    for(i=0;i<N;i++)
    {
        res=res*2;
        if(balcony[i]==0){val=0;}
        else{val=1;}
        res=res+val;
    }
    return(res);
}
                      
