#include<bits/stdc++.h>
using  namespace  std;

int n, CAP;
int arr[100], cost[100];
int dp[100][10000];

int knapsack(int i, int wt)
{
    if(i==n+1) return 0;
    if(dp[i][wt]!=-1)  return dp[i][wt];
    int cost1 = 0, cost2 = 0;
    if(wt + arr[i]<=CAP)
        cost1 = cost[i] + knapsack(i+1, wt + arr[i]);
    cost2 = knapsack(i+1, wt);

    dp[i][wt] = max(cost1, cost2);
    return dp[i][wt];
}

int main()
{
    scanf("%d %d", &n, &CAP);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &arr[i], &cost[i]);
    }
    memset(dp, -1, sizeof dp);
    printf("Maximum Cost: %d\n", knapsack(1,0));
}
