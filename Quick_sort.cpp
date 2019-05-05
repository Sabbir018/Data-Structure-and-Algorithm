#include<bits/stdc++.h>
using  namespace  std;

int a[1000];

int Q_sort(int low, int high)
{
    int i=low,j=low,r=a[high];
    while(j<high)
    {
        if(a[j]<r)
        {
            swap(a[i],a[j]);
            i++;j++;
        }
        else j++;
    }
    swap(a[i],a[high]);
    return i;
}

void quicksort(int low,int high)
{
    if(low<high)
    {
        int q=Q_sort(low, high);
        quicksort(low,q-1);
        quicksort(q+1,high);
    }
}

int main()
{
    int i,j,n;
    cout<<"Enter the no. of element : "; cin>>n;
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++) cin>>a[i];
    quicksort(0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
/*
Enter the no. of element : 5
Enter the elements : 5 4 2 1 3
1 2 3 4 5
*/
