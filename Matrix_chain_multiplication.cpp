#include<bits/stdc++.h>
using  namespace  std;

int p[100],m[100][100],s[100][100];

void print(int i,int j)
{
    if(i==j)
        cout<<"A"<<i;
    else{
        cout<<"{";
        print(i,s[i][j]);
        print(s[i][j]+1,j);
        cout<<"}";
    }
}

void Matrix_Chain_order(int n)
{
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=2147483647;

            for(int k=i;k<=j-1;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }

        }
    }
    cout<<"Minimum Step = "<<m[1][6]<<endl;
}

int main()
{
    int i,j,a,b,n;
    char c;
    cout<<"Enter the number of matrix : "; cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"A"<<i<<"=";
        cin>>a>>c>>b;
        p[i]=a;
    }
    p[n]=b;
    Matrix_Chain_order(n);
    print(1,n);
}
/*
Enter the number of matrix : 3
A0=1 2 3
A1=4 5 6
A2=7 8 9
Minimum Step = 0
{{A1A2}A3}
*/
