#include<iostream>
using namespace std;
int main()
{
    int a[50],i,j,n,c,min;
    cout<<"Enter no of elements";
    cin>>n;
    cout<<"Enter elements";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if (a[j]<a[min])
            {
                min=j;
            }
        }
        c=a[i];
        a[i]=a[min];
        a[min]=c;
    }
    cout<<"Sorted"<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i];
        cout<<"\t";
    }
    return 0;
}

