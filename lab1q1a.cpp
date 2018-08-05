#include<iostream>
using namespace std;
int main()
{
    int n,arr[20],key,flag=0,i=0,h,j;
    cout<<"Enter n";
    cin>>n;
    cout<<"Enter n elements";
    for (j=0;j<n;j++)
    {
        cin>>arr[j];

    }
    cout<<"Enter the key";
    cin>>key;
    for (i=0;i<n;i++)
    {
        if (key==arr[i])
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
        cout<<"Key found at:"<<i+1;
    else
        cout<<"key not found";
    return 0;
}

