#include<bits/stdc++.h>
using  namespace  std;

int main()
{
    int i,j,a,b,c,n,p,x;
    string s;
    cout<<"Enter the input : (a^b)%c"<<endl;
    cout<<"A = "; cin>>a;
    cout<<"B = "; cin>>b;
    cout<<"C = "; cin>>c;
    n=b;
    while(b)
    {
        s+=(b%2)+'0';
        b=b/2;
    }
    p=a%c;
    x=1;
    for(i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='1') x=(x*p)%c;
        p=(p*p)%c;
    }
    cout<<"a^b mod c = "<<x<<endl;
    return 0;
}
/*
Enter the input : (a^b)%c
A = 25
B = 39
C = 4
a^b mod c = 1
*/
