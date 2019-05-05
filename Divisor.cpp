#include<bits/stdc++.h>
using  namespace  std;

const int mx = 1e7;

int divs[mx+5];
bool chk[mx+5];
int anti[mx+5];

void gen(void)
{
    int i,j,maxi;
    for(i=1; i<=mx; i++)
    {
        for(j=i; j<=mx; j+=i) divs[j]++;
    }
    maxi=0;
    for(i=1; i<=mx; i++)
    {
        if(divs[i]>maxi)
        {
            maxi=divs[i];
            chk[i]=1;
        }
    }
    maxi=10810800;
    for(i=mx; i>0; i--)
    {
        if(chk[i]) maxi=i;
        anti[i]=maxi;
    }
    return;
}

int main()
{
    int q,a;
    gen();
    int k;
    scanf("%d", &k);
    while(k--)
    {
        int n;
        cin>>n;
        printf("%d\n", divs[n]);
    }
    return 0;
}
