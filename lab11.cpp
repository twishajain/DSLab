#include<iostream>
using namespace std;
class bst
{public:
	bst *lchild;int data;bst *rchild;
	bst(int ele=0)
{
lchild=NULL;rchild=NULL;data=ele;}
void insert(int);void search(bst*,int);void display(bst *root);bst* del();bst* min(bst*);};
bst *root=NULL;
bst* bst::min(bst *p)
{bst* t;
	for (t=p;t->lchild;t=t->lchild);return t;}
bst* bst::del()
{
bst *c, *p, *s,*q;
cout<<"Enter the key value to be deleted ";int ele;
cin>>ele;
if(root==NULL)
return root;
p=NULL;
c=root;
while(c!=NULL)
{
if(ele==c->data)
break;
p=c;
if(ele<c->data)
c=c->lchild;
else
c=c->rchild;
}
if(c==NULL)
return root;
if(c->lchild==NULL)
q=c->rchild;
else if(c->rchild==NULL)
q=c->lchild;
else
{
s=c->rchild;
while(s->lchild)
s=s->lchild;
s->lchild=c->lchild;
q=c->rchild;
}
if(!p)
{
delete c;
return q;
}
if(c==p->lchild)
p->lchild=q;
else
p->rchild=q;
delete(c);
return(root);
}



void bst::insert(int ele)
{
bst *temp=new bst(ele);
if (root==NULL)
{root=temp;return;}
else
{
bst *curr=root,*prev=NULL;
while (curr)
{
prev=curr;
if (temp->data<curr->data)
curr=curr->lchild;
else if(curr->data<temp->data)curr=curr->rchild;
else
{
cout<<"Insertion not possible";return;}}
if (temp->data>prev->data)
prev->rchild=temp;
else if (temp->data<prev->data)
prev->lchild=temp;
}return;}
void bst::display(bst *ptr)
{
	if (ptr){display(ptr->lchild);cout<<""<<ptr->data;display(ptr->rchild);}}

void bst:: search(bst *root,int ele)
{
if (root==NULL)return;
bst *curr=root;int flag=0;
while(curr!=NULL)
{
if (curr->data==ele)
{cout<<ele<<"found";flag=1;return;
}if (ele>curr->data)curr=curr->rchild;else curr=curr->lchild;}
cout<<"Not found";
return;}


int main()
{int ch;char c='y';bst g;
while(c=='y')
{
	cout<<"1.insert 2.display 3.Search 4.Delete";
	cin>>ch;
switch (ch)
{	case 1:int ele; cin>>ele;g.insert(ele);break;
	case 2:g.display(root);break;
case 3:cout<<"ele:";cin>>ele;g.search(root,ele);break;
case 4:root=g.del();break;
}
cout<<"continue?";
cin>>c;
}}
