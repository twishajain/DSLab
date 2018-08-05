#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    //string len
char s[50],c[50];
cout<<"Enter first string";
cin.getline(s,50);
int i=0;
while (s[i]!='\0')
{
    i++;
}
cout<<"length of string:"<<i<<"\n";
//string concatenation
cout<<"enter 2nd string";
cin.getline(c,50);
char d[50];
int j=0;
while (c[j]!='\0')
{
    j++;
}
int t=i+j;
int k=0,a=0;
for(k=0;k<i;k++)
{
    d[k]=s[a];
    a++;
}
int h=0,b=0;
for (h=i;h<t;h++)
{
    d[h]=c[b];
    b++;
}
d[h]='\0';
cout<<"Concatenation:"<<d<<"\n";
//string comparison
cout<<"Comparing first and second string by code now:";
int flag=0;
int u;
if (i>j)
    u=i;
else
    u=j;
for (a=0;a<u;a++)
{
    if (s[a]>c[a])
    {   flag=1;
        cout<<1;
        break;
    }
    else if (s[a]<c[a])
       {cout<<-1;
        flag=1;
        break;}
    else if (s[a]==c[a])
        continue;

}
if (flag==0)
{
    cout<<0;
}
//Substring addition
cout<<"\n"<<"at what position due you want to add substring to string?";
int n;
cin>>n;
char str[50];
u=0;
while (u<n-1)
{
    str[u]=s[u];
    u++;}
a=u;
b=0;
for (k=u;k<(a+j);k++)
    {str[k]=c[b];
    b++;}
for (k=(a+j);k<(i+j);k++)
{
    str[k]=s[a];
    a++;
}
str[i+j]='\0';
cout<<"New string:"<<str;
cout<<"\n";
return 0;}

