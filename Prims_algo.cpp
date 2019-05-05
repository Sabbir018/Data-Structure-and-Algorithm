#include<bits/stdc++.h>
using  namespace  std;

vector<int>node[100];
int value[100][100],par[100];

struct edge{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w > p.w;
    }
};

int find(int i)
{
    return (par[i]==i) ? i : find(par[i]);
}

int Prims(int n,int src)
{
    priority_queue<edge>q;
    edge get;
    for(int i=0;i<node[src].size();i++)
    {
        get.u=src; get.v=node[src][i]; get.w=value[src][node[src][i]];
        q.push(get);
    }
    int c=1,s=0;
    for(int i=1;i<=n;i++) par[i]=i;
    while(!q.empty())
    {
        edge e=q.top();

        q.pop();
        int u=find(e.u);
        int v=find(e.v);
        if(u!=v)
        {
            par[u]=v;
            c++;
            s+=e.w;
            for(int i=0;i<node[e.v].size();i++)
            {
                int a=find(e.v);
                int b=find(node[e.v][i]);
                if(a!=b){
                    get.u=e.v; get.v=node[e.v][i]; get.w=value[e.v][node[e.v][i]];
                    q.push(get);
                }
            }
        }
    }
    return s;
}

int main()
{
    int i,j,a,b,n,m,u,v,w;
    while(cin>>n>>m)
    {
        for(i=1;i<=m;i++)
        {
            cin>>u>>v>>w;
            node[u].push_back(v);
            node[v].push_back(u);
            value[u][v]=w;
            value[v][u]=w;
        }
        cout<<"Enter the source node : "; cin>>a;
        b=Prims(n,a);
        cout<<"Minimum Cost : "<<b<<endl;
    }
    return 0;
}
/*
9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
8 9 7
8 7 1
9 7 6
7 6 2
6 4 14
4 5 9
6 5 10
Enter the source node : 1
Minimum Cost : 37
*/
