#include<bits/stdc++.h>
using  namespace  std;

int main()
{
    long long int i,j,a[100],n,item;
    cout<<"Enter the number of element : "; cin>>n;
    cout<<"Enter elements : ";
    for(i=1;i<=n;i++)
        cin>>a[i];
    cout<<"Enter the Item to find : "; cin>>item;
    j=-1;
    for(i=1;i<=n;i++)
    {
        if(a[i]==item){
            j=i;
            break;
        }
    }
    if(j==-1) cout<<"Item not found!!!!"<<endl;
    else cout<<"Item found in a["<<j<<"]"<<endl;
    return 0;
}
/*
Enter the number of element : 5
Enter elements : 5 4 8 9 1
Enter the Item to find : 9
Item found in a[4]
*/
