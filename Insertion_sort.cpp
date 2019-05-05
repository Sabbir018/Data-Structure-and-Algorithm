#include<bits/stdc++.h>
using  namespace  std;

int main()
{
    int i,j,a[100],b,n,m;
    cout<<"Enter the number of element : ";
    cin>>n;
    cout<<"Enter elements : ";
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=2;i<=n;i++)
    {
        j=i-1;
        m=a[i];
        while(j>0 and a[j]>m)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=m;
    }
    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
/*
Enter the number of element : 5
Enter elements : 3 6 4 1 2
1 2 3 4 6
*/
