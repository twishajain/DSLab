#include<iostream>

using namespace std;
class node
{
	int exp;
	int coe;
	node *next;

    public:
	node *create(node *,int,int);
	void display(node *);
	node *add(node *,node *);
	node *mul(node *,node *);
	node *sortin(node *);
};
node *first1=NULL,*first2=NULL,*first3=NULL,*first4=NULL,*first6=NULL;

node * node::mul(node *f1,node *f2)
{
	node *res=NULL;
	for(node *i=f1;i!=NULL;i=i->next)
		for(node *j=f2;j!=NULL;j=j->next)
			res=create(res,i->coe*j->coe,i->exp+j->exp);
	return(res);
}



node * node::create(node *f,int c,int e)
{
		node *temp;
	temp=new node;

	temp->coe=c;
	temp->exp=e;
	temp->next=NULL;

	if(f==NULL)	f=temp;
	else
	{
		   node *curr;
		   for(curr=f;curr->next!=NULL;curr=curr->next);
		   curr->next=temp;
	}
	return(f);
 }
node* node::sortin(node *f)
{
    int max=0;
    node *curr;
    for (curr=f;curr;curr=curr->next)
        {if (curr->exp>max)
        max=curr->exp;}
    int n=max;
    int arr[n];node *res=NULL; node a;
    for (int i=0;i<n+1;i++)
    {
        arr[i]=0;
    }
    for (curr=f;curr!=NULL;curr=curr->next)
    {
        arr[curr->exp]=arr[curr->exp]+curr->coe;
    }

    for(int i=0;i<n+1;i++)
	{
		res=a.create(res,arr[i],i);
	}
    return (res);
}
    void node::display(node *f)
    {

	for(node *curr=f;curr!=NULL;curr=curr->next)
	{
	    cout<<curr->coe<<"x^"<<curr->exp;
	    if(curr->next!=NULL)
	      cout<<"+";
	}
	cout<<"\n";
    }

node* node::add(node *f1,node *f2)
{
	node *res=NULL;
	node *a=f1,*b=f2;

	while((a!=NULL)&&(b!=NULL))
	{
		if (a->exp>b->exp)
		{
			res=create(res,a->coe,a->exp);
			a=a->next;
		}
		else if(a->exp==b->exp)
		{
			res=create(res,a->coe+b->coe,a->exp);
			a=a->next;
			b=b->next;
		}
		else //b->exp<a->exp
		{
			res=create(res,b->coe,b->exp);
			b=b->next;
		}
	}
	while(a!=NULL)
	{
		res=create(res,a->coe,a->exp);
		a=a->next;
	}
	while(b!=NULL)
	{
		res=create(res,b->coe,b->exp);
		b=b->next;
	}
	return(res);
}

int main()
{
	int n,i,e,c;
	node a;

	cout<<"how many terms in 1 polynomial\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter coe: ";
		cin>>c;
		cout<<"Enter exp: ";	cin>>e;
		first1=a.create(first1,c,e);
	}
	a.display(first1);

	cout<<"how many terms in 2 polynomial\n";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"\nEnter coe: ";
		cin>>c;
		cout<<"Enter exp: ";	cin>>e;
		first2=a.create(first2,c,e);
	}
	a.display(first2);
	first3=a.add(first1,first2);
	first4=a.mul(first1,first2);
	first6=a.sortin(first4);
	cout<<"Result of sorting"; a.display(first6);cout<<endl;
	cout<<"Result of addition: ";		a.display(first3);	cout<<endl;
	cout<<"Result of multiplication: ";	a.display(first4);	cout<<endl;
}

