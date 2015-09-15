#include<iostream>
#include<conio.h>
using namespace std;
long long n, i, a, b, c;
int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<2;
        return 0;}
    if(n==2)
    {
        cout<<2;
        return 0;}
    a=1;
    b=1;
    for(i=3; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;}
    cout<<2*c;
    getch();
    return 0;
}
