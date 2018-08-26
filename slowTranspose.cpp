#include <iostream>

using namespace std;

class sparse
{
    int row,col,value;

public:

    sparse()
    {
        row=3;
        col=3;
        value=3;
    }

    sparse(int r,int c,int v)
    {
        row=r;
        col=c;
        value=v;
    }

    void display(sparse *);
    void fastTrans(sparse *);
    void slowTrans(sparse *);
};
void sparse::slowTrans(sparse a[])
{
    sparse b[20];
    int ctr=1,i,j;
    for(i=0;i<a[0].col;i++)
    {
        for (j=1;j<=a[0].value;j++)
        {
            if (a[j].col==i)
            {
                b[ctr].row=a[j].col;
                b[ctr].col=a[j].row;
                b[ctr++].value=a[j].value;
            }
        }
    }
    b[0].col=a[0].row;
    b[0].row=a[0].col;
    b[0].value=a[0].value;
    display(b);
}

void sparse::display(sparse s[])
{
    cout<<"row\tcol\tvalue\n";

    for(int i=0;i<=(s[0].value);i++)
        cout<<s[i].row<<"\t"<<s[i].col<<"\t"<<s[i].value<<"\n";
}

void sparse::fastTrans(sparse a[])
{

    sparse b[20];
    int rowterm[20],startpos[20],i,k,j;

    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].value=a[0].value;

    for(i=0;i<a[0].col;i++)
        rowterm[i]=0;

    for(j=1;j<=a[0].value;j++)
        rowterm[a[j].col]++;

    startpos[0]=1;

    for(k=1;k<a[0].col;k++)
        startpos[k]=startpos[k-1]+rowterm[k-1];

    for(j=1;j<=a[0].value;j++)
    {
        int x=startpos[a[j].col];
        b[x].row=a[j].col;
        b[x].col=a[j].row;
        b[x].value=a[j].value;
        startpos[a[j].col]++;
    }

    cout<<"Output:";
    display(b);
}

int main()
{
    sparse s[20],dummy;
    int r,c,val,val1;

    cout<<"Enter the number of rows:";
    cin>>r;
    cout<<"Enter the number of col:";
    cin>>c;
    cout<<"Enter the number of non-zero values:";
    cin>>val;

    s[0]=sparse(r,c,val);

    cout<<"Enter the elements of sparse matrix:";

    for(int i=1;i<=val;i++)
    {
        cout<<"\nrow: ";
        cin>>r;
        cout<<"\ncol: ";
        cin>>c;
        cout<<"\nvalue: ";
        cin>>val1;

        s[i]=sparse(r,c,val1);
    }

    dummy.display(s);
    dummy.fastTrans(s);
    cout<<"SlowTrans:";
    dummy.slowTrans(s);

    return 0;
}
