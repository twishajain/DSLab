#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char str[30],subs[20],newstr[30];
    cout<<"Enter A String: ";
    cin.getline(str,30);
    cout<<"Enter A Substring: ";
    cin.getline(subs,20);
    int lens = strlen(str);
    int sub = strlen(subs); 
    int matchstart;
    int matchend;
    int i;
    for(i=0;i<lens;i++)
    {
        if(str[i] == subs[0])
        {
            int j=0;
            int k=i;
            int count=0;
            for(j=0;j<sub;j++)
            {
                if(str[k] == subs[j])
                {
                    count++;
                }
                k++;
            }
            if(sub == count)
            {
                cout<<"Match Found: ";
                matchstart = i;
                matchend = i+sub;
                break;
            }
        }
    }
    for (i=0;i<matchstart;i++)
    {
        newstr[i]=str[i];
    }
    int y=i;
    for (i=matchend;i<lens;i++)
    {
        newstr[y]=str[i];
        y++;
    }
    newstr[y]='\0';
    cout<<newstr;
}
