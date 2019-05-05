#include<bits/stdc++.h>
using  namespace  std;

long long MOD = 1000003;
long long fact[1000005];

long long Fermat(long long a, long long b, long long MOD)
{
    long long x = 1;
    long long y = a;
    while(b)
    {
        if(b%2==1)
        {
            x = x * y;
            if(x>MOD)
                x = x % MOD;
        }
        y = y * y;
        if(y>MOD)
            y = y % MOD;
        b = b/2;
    }
    return x;
}

void solve()
{
    fact[0] = fact[1] = 1;
    for(int i=2; i<1000001; i++)
        fact[i] = ((fact[i-1]%MOD)*(i%MOD))%MOD;
}

int main()
{
    solve();
    long long n, r, test;
    scanf("%lld",&test);
    for(int cn = 1; cn<=test; cn++)
    {
        scanf("%lld %lld", &n, &r);
        long long A = ((fact[r]%MOD)*(fact[n-r]%MOD))%MOD;
        long long res = ((Fermat(A, MOD-2, MOD)%MOD) * (fact[n]%MOD))%MOD;
        printf("Case %d: %lld\n",cn, res);
    }
    return 0;
}
