#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class student{
    char name[20];
    int rollno;
    char grade;
    public:
        void read(student students[],int n);
        void display(student students[],int n);
        void sort(student students[],int n);
};
void student::read(student students[],int n)
{
    for(int j=0;j<n;j++){
        cout<<"Enter name:";
        cin>>(students[j].name);
        cout<<"Enter rollno:";
        cin>>students[j].rollno;
        cout<<"Enter grade:";
        cin>>students[j].grade;
    }
}
void student::display(student students[],int n)
{
     for(int j=0;j<n;j++){
        cout<<"Name:";
        cout<<(students[j].name)<<"\n";
        cout<<"Rollno:";
        cout<<students[j].rollno<<"\n";
        cout<<"grade:";
        cout<<students[j].grade<<"\n";
    }
}
void student::sort(student students[],int n)
{
    student j;
    for (int pass=0;pass<n-1;pass++)
    {
        for (int h=0;h<n-pass-1;h++)
        {
            if (students[h].rollno>students[h+1].rollno)
            {
                j=students[h];
                students[h]=students[h+1];
                students[h+1]=j;
                
            }
            
        }
        
    }
    cout<<"Sorted"<<"\n";
    j.display(students,n);
}

    

int main()
{
    int n;
    cout<<"How many students do you want to enter: ?";
    cin>>n;
    student a;
    student students[n];
    a.read(students,n);
    cout<<"Displaying"<<"\n";
    a.display(students,n);
    a.sort(students,n);
}
