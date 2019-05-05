#include<bits/stdc++.h>
using  namespace  std;

int a[1000];

void Max_Heapify(int i,int n)
{
    int l=i*2;
    int r=l+1;
    int large=i;
    if(l<=n and a[l]>a[large])
        large=l;
    if(r<=n and a[r]>a[large])
    {
        large=r;
    }
    if(large!=i)
    {
        swap(a[i],a[large]);
        Max_Heapify(large,n);
    }
}

void Build_max_Heap(int n)
{
    for(int i=n/2;i>=1;i--)
    {
        Max_Heapify(i,n);
    }
}

void Heapsort(int n)
{
    Build_max_Heap(n);

    for(int i=n;i>=1;i--)
    {
        swap(a[1],a[i]);
        n--;
        Max_Heapify(1,n);
    }
}

int main()
{
    int i,j,n;
    cout<<"Enter the no. of element : "; cin>>n;
    cout<<"Enter the elements : ";
    for(i=1;i<=n;i++) cin>>a[i];
    Heapsort(n);
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
/*
Enter the no. of element : 5
Enter the elements : 5 4 2 1 3
1 2 3 4 5
*/
