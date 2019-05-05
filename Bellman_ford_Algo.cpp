#include<bits/stdc++.h>
using  namespace  std;

int main()
{
    int i,j,a,b,n,m,edge_u[100],edge_v[100],cost[100],d[100];
    while(cin>>n>>m)
    {
        for(i=1;i<=n;i++) d[i]=1000000000;
        d[1]=0;
        for(i=1;i<=m;i++)
        {
            cin>>edge_u[i]>>edge_v[i]>>cost[i];
        }

        bool negative=false;

        for(i=1;i<=n;i++)
        {
            bool update=false;
            for(j=1;j<=m;j++)
            {
                int u=edge_u[j]; int v=edge_v[j];
                if(d[u]+cost[j]<d[v])
                {
                    update=true;
                    if(i==n) negative=true;
                    d[v]=d[u]+cost[j];
                }
            }
            if(!update) break;
        }
        if(negative)
        {
            cout<<"There is a negative Cycle"<<endl;
        }
        else
        {
            cout<<d[i]<<"\n";
        }
    }
    return 0;
}
/*
5 7
3 4 2
4 3 1
2 4 4
0 2 5
1 2 3
0 3 8
0 1 4
*/
