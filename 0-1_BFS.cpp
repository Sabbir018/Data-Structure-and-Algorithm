#include<bits/stdc++.h>
using  namespace  std;

typedef pair<int,int>pii;


#define pub              push_back
#define pob              pop_back

int level[1005][1005];
char grid[1005][1005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int m, n;

int BFS()
{
    int ans = 0;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) level[i][j] = INT_MAX;
    deque<pii>q;
    q.push_front(pii(0,0));
    level[0][0] = 1;

    while(!q.empty())
    {
        pii top = q.front();

        q.pop_front();
        if(top.first==m-1 && top.second==n-1) break;

        for(int i=0; i<4; i++)
        {
            int u = top.first + dx[i];
            int v = top.second + dy[i];

            if(u>=0 && v>=0 && u<m && v<n)
            {
                if(grid[u][v]==grid[top.first][top.second] && level[u][v]>level[top.first][top.second])
                {

                    level[u][v] = level[top.first][top.second];
                    q.push_front(pii(u,v));
                }
                else if(level[u][v]>level[top.first][top.second]+1)
                {
                    level[u][v] = level[top.first][top.second] + 1;
                    q.push_back(pii(u,v));
                }
            }
        }
    }
    ans = level[m-1][n-1] - 1;

    return ans;
}

int main()
{
    int x;
    scanf("%d", &x);
    for(int cn=1; cn<=x; cn++)
    {
        scanf("%d %d", &m, &n);
        for(int i=0; i<m; i++)
        {
            scanf("%s", grid[i]);
        }
        printf("%d\n", BFS());
    }
}
