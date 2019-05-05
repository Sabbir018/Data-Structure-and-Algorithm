#include<bits/stdc++.h>
using  namespace  std;

int main()
{
    int i,j,a[100],b,n,m;
    cout<<"Enter the number of element : "; cin>>n;
    cout<<"Enter elements : ";
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++)
    {
        m=i;
        for(j=i+1;j<=n;j++)
        {
            if(a[j]<a[m])
                m=j;
        }
        swap(a[i],a[m]);
    }
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}
/*
Enter the number of element : 5
Enter elements : 3 6 4 1 2
1 2 3 4 6
*/
