#include<iostream>
using namespace std;
int main()
{
    int a[50],i,j,n,l,h,key,flag=0,low,high;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter elements";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter key:";
    cin>>key;
    low=0;
    high=n-1;
    while (low<=high)
    {
        h=(low+high)/2;
        if (a[h]==key)
        {
            flag=1;
            break;
        }
        else if (key>h)
        {
            low=h+1;
        }
        else
            high=h-1;
    }
    if (flag==1)
    {
        cout<<h+1;

    }
    else
        cout<<"Key not found";
    return 0;
}


