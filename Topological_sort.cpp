#include<bits/stdc++.h>
using  namespace  std;

int one,five, ten, twenty, fifty;

vector<int>graph[10000];
int visited[10003];
int parent[10003];
vector<int>sl;

void DFS_Visit(int node)
{
    visited[node] = 1;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(visited[graph[node][i]]==0)
        {
            parent[graph[node][i]] = 1;
            DFS_Visit(graph[node][i]);
        }
        else if(visited[graph[node][i]]==1)
        {
            printf("Got a Cycle\n");
        }
    }

    visited[node] = 2;
    sl.push_back(node);

    return;
}


void DFS(int node, int edge)
{
    for(int i=1; i<=node; i++)
    {
        visited[i] = 0;
        parent[i] = i;
    }
    for(int i=1; i<=node; i++)
    {
        if(visited[i] == 0)
        {
            DFS_Visit(i);
        }
    }
    return;
}

int main()
{
    int node, edge, u, v;
    scanf("%d %d", &node, &edge);
    for(int i=0; i<edge; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        //graph[v].push_back(u);
    }
    DFS(node, edge);

    for(int i=1; i<=node; i++)
    {
        printf("Parent of %d: %d\n", i, parent[i]);
    }

    int sz = sl.size() ;
    printf("Sorted Order :\n");
    for(int i = sz - 1; i>=0; i--)
    {
        printf("%d", sl[i]);
        if(i>0) printf("->");
    }

}
