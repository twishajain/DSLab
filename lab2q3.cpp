#include<iostream>
using namespace std;
class timer{
    int hour;
    int min;
    int sec;
    public:
    timer add(timer a,timer b);
    timer diff(timer a,timer b);
    timer read(timer a);
    void display(timer a);
};

timer timer::read(timer a)
{
    cout<<"Enter the hours:";
    cin>>a.hour;
    cout<<"Enter the mins:";
    cin>>a.min;
    cout<<"Enter the sec:";
    cin>>a.sec;
    return a;
}
void timer::display(timer a)
{
    cout<<"hours:";
    cout<<a.hour;
    cout<<"mins:";
    cout<<a.min;
    cout<<"sec:";
    cout<<a.sec;
    
}
timer timer::add(timer a,timer b)
{
    int found=0;
    timer c;
    c.sec=a.sec+b.sec;
    if (c.sec>=60)
        {c.sec=(c.sec%60);
        found=1;}
    if (found==1)
        c.min=a.min+b.min+1;
    else 
        c.min=a.min+b.min;
    found=0;
    if (c.min>=60)
    {
        c.min=(c.min%60);
        found=1;
    }
    if (found==1)
        c.hour=a.hour+b.hour+1;
    else
        c.hour=a.hour+b.hour;
    return c;
}
timer timer::diff(timer a,timer b)
{
    timer c;
    c.sec=a.sec-b.sec;
    if (c.sec<0)
    {
        a.min--;
        a.sec=a.sec+60;
        c.sec=a.sec-b.sec;
    }
    c.min=a.min-b.min;
    if (c.min<0)
    {
        a.hour--;
        a.min=a.min+60;
        c.min=a.min-b.min;
    }
    c.hour=a.hour-b.hour;
    return c;
}
    

int main()
{
    timer a,b,c,d,e,f,j;
    d=a.read(a);
    e=b.read(b);
    c=a.add(d,e);
    cout<<"Addition"<<"\n";
    c.display(c);
    j=a.diff(d,e);
    cout<<"\n"<<"Difference"<<"\n";
    j.display(j);
}
