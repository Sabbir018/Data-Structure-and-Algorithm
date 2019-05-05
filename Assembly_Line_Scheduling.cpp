#include<bits/stdc++.h>
using  namespace  std;

int f[100][100],a[100][100],t[100][100],l[100][100];
int main()
{
    int i,j,s1,s2,e1,e2,p,q,n,m,line,b,c;
    cout<<"Enter of starting value of line 1 and 2 : ";
    cin>>s1>>s2;
    cout<<"Enter the value of 6 station of line 1 : ";
    for(i=1;i<=6;i++) cin>>a[1][i];
    cout<<"Enter the value of 6 station of line 2 : ";
    for(i=1;i<=6;i++) cin>>a[2][i];
    cout<<"Enter the value of 5 station to transfer line 1 to 2 : ";
    for(i=1;i<6;i++) cin>>t[1][i];
    cout<<"Enter the value of 5 station to transfer line 2 to 1 : ";
    for(i=1;i<6;i++) cin>>t[2][i];
    cout<<"Enter the finishing value of line 1 and 2 : ";
    cin>>e1>>e2;
    f[1][1]=s1+a[1][1];
    f[2][1]=s2+a[1][1];
    for(i=2;i<=6;i++)
    {
        if(f[1][i-1]+a[1][i]<=f[2][i-1]+t[2][i-1]+a[1][i])
        {
            f[1][i]=f[1][i-1]+a[1][i];
            l[1][i]=1;
        }
        else{
            f[1][i]=f[2][i-1]+t[2][i-1]+a[1][i];
            l[1][i]=2;
        }
        if(f[2][i-1]+a[2][i]<=f[1][i-1]+t[1][i-1]+a[2][i])
        {
            f[2][i]=f[2][i-1]+a[2][i];
            l[2][i]=2;
        }
        else{
            f[2][i]=f[1][i-1]+t[1][i-1]+a[2][i];
            l[2][i]=1;
        }
    }
    if(f[1][6]+e1<=f[2][6]+e2)
    {
        b=f[1][6]+e1;
        c=1;
    }
    else{
        b=f[2][6]+e2;
        c=2;
    }
    cout<<"Minimum cost: "<<b<<endl;
    cout<<" line "<<c<<" Station 6"<<endl;
    for(j=6;j>=2;j--)
    {
        c=l[c][j];
        cout<<" line "<<c<<" Station "<<j-1<<endl;
    }
    return 0;
}
/*
Enter of starting value of line 1 and 2 : 10 12
Enter the value of 6 station of line 1 : 4 5 3 2 6 1
Enter the value of 6 station of line 2 : 2 3 4 5 1 6
Enter the value of 5 station to transfer line 1 to 2 : 3 4 6 1 5
Enter the value of 5 station to transfer line 2 to 1 : 2 1 6 4 3
Enter the finishing value of line 1 and 2 : 18 7
minimum cost is : 39
 line 2 Station 6
 line 2 Station 5
 line 1 Station 4
 line 1 Station 3
 line 1 Station 2
 line 1 Station 1
*/
