#include<bits/stdc++.h>
using namespace std;

long long arr[20];

void fff()
{
    arr[0] = 1;
    for(int i=1; i<=20; i++)
        arr[i] = arr[i-1] * i;
}

long long cool(long long m, long long temp, long long sz)
{
    //cout<<m<<' '<<temp<<endl;
    long long c;
    for(long long i=1; i<=sz; i++)
    {
        if(m*i>=temp)
        {
            c = i - 1;
            break;
        }
    }
    return c;
}

int main()
{
    fff();
    string str, temp = "";
    long long n, to, test;
    scanf("%lld", &test);
    while(test--)
    {
        cin>>str>>n;
        int sz = str.size();
        sort(str.begin(), str.end());
        temp ="";
        to = n + 1;
        for(long long i=1; i<=sz; i++)
        {
            long long id = cool(arr[sz-i], to, sz);
            to = to - (arr[sz-i]*id);
            temp = temp + str[id];
            str.erase(id,1);
        }
        cout<<temp<<endl;
    }
    return 0;
}
