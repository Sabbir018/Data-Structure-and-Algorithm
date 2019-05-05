#include<bits/stdc++.h>
using  namespace  std;

int a[1000];
void marge(int low,int mid,int high)
{
    int i=low; int j=mid+1; int k=0;
    int b[1000];
    while(i<=mid and j<=high)
    {
        if(a[i]<=a[j]) b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=high) b[k++]=a[j++];
    k--;
    while(k>=0)
    {
        a[low+k]=b[k];
        k--;
    }
}
void margesort(int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        margesort(low,mid);
        margesort(mid+1,high);
        marge(low,mid,high);
    }
}
int main()
{
    int i,j,n;
    cout<<"Enter the no. of element : "; cin>>n;
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++) cin>>a[i];
    margesort(0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
/*
Enter the no. of element : 5
Enter the elements : 5 4 2 1 3
1 2 3 4 5
*/
