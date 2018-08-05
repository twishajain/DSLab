#include<iostream>
using namespace std;
int main()
{
    int a[50],i,j,k,pass,n;
    cout<<"Enter no of elements";
    cin>>n;
    cout<<"Enter elements";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
    cout<<"Sorted";
    for(i=0;i<n;i++)
    {
        cout<<a[i];
    }
}

