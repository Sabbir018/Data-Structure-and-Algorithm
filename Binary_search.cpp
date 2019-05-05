#include<bits/stdc++.h>
using  namespace  std;

int main()
{
    long long int i,j,a[1000],b,n,m,item;
    cout<<"Enter the number of element : "; cin>>n;
    cout<<"Enter elements : ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Item to find : "; cin>>item;
    sort(a,a+n);
    int l=0; int r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]==item){
            cout<<"Item found in "<<mid+1<<"."<<endl;
            break;
        }
        else if(item>a[mid]){
            l=mid+1;
        }
        else r=mid-1;
    }
    if(l>r) cout<<"Item not found!"<<endl;
    return 0;
}
/*
Enter the number of element : 5
Enter elements : 2 3 4 6 9
Enter the Item to find : 4
Item found in 3
*/
