#include<bits/stdc++.h>
using  namespace  std;

#define MAX 1000000000

int status[(MAX/32)+10];
vector<int>primelist;

bool check(int n, int pos)
{
    return (bool)(n & (1<<pos));
}
int SET(int n, int pos)
{
    return n=n|(1<<pos);
}

void sieve()
{
    int sqrtN=int (sqrt(MAX));

    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAX; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
    primelist.push_back(2);
    for(int i=3; i<=MAX; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            primelist.push_back(i);
        }
    }
    cout<<primelist.size()<<endl;
}

int main()
{
    sieve();
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        printf("%d,",primelist[i]);
    }

    return 0;
}
