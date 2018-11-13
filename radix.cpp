#include<iostream>
using namespace std;

void radix(int a[],int a1[],int n)
{
    int t,min1,temp;
    int max1=a[0];
    int u=0;
    for(int j=0;j<n;j++)
    {
        if(a[j]>max1)
        {
            max1=a[j];
            u=j;
        }
    }
    int o;
    int e=0;
    o=max1;
    while(o!=0)
    {
        o=o/10;
        e++;
    }
    for(int l=0;l<e;l++)
    {
        for(int i=0;i<n;i++)
        {
            min1=a[i]%10;
            t=i;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]%10<min1)
                {
                    min1=a[j]%10;
                    t=j;
                }
            }
            temp=a1[i];
            a1[i]=a1[t];
            a1[t]=temp;
            temp=a[t];
            a[t]=a[i];
            a[i]=temp;
        }
        for(int k=0;k<n;k++)
        {
            a[k]=a[k]/10;
        }
    }
    for(int y=0;y<n;y++)
    {
        cout<<a1[y]<<" ";
    }
}

int main(){
    int a[100],a1[100];
    cout<<"enter n";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a1[i]=a[i];
    }
    radix(a,a1,n);
}
