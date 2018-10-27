#include<iostream>
#include<string.h>
using namespace std;
class treenode
{public:
	treenode *lchild;treenode *rchild;int data;

		treenode(int element=0)
		{data=element;lchild=NULL;rchild=NULL;}
		void inorder(treenode *);
		treenode* insert(int,treenode*);
		void preorder(treenode *);
		void postorder(treenode*);
		treenode* parent(treenode*,int,treenode*);
		int depth(treenode*);
void leafnode(treenode*);
		int Ancestors(treenode*,int);
};
treenode *root=NULL;
void treenode::postorder(treenode *root)
{int top=-1;	if (root==NULL) return;
treenode* stack[10];
do{
while(root)
{
if (root->rchild) stack[++top]=root->rchild;
stack[++top]=root;root=root->lchild;
}
root=stack[top--];
if (root->rchild && stack[top]==root->rchild)
{
stack[top--];
stack[++top]=root;
root=root->rchild;
}
else
{cout<<root->data;root=NULL;}}while(top!=-1);}
	
treenode* treenode::parent(treenode* curr,int ele,treenode* prev)
{
	if(curr!=NULL)
{
	parent(curr->lchild,ele,curr);
	if(ele==curr->data)
{
cout<<"\n parent"<<prev->data;return prev;}parent(curr->rchild,ele,curr);}}

int treenode::Ancestors(treenode *root,int target)
{
	if (root==NULL) return 0;
	if (root->data==target) return 1;
	if (Ancestors(root->lchild,target) || Ancestors(root->rchild,target))
{cout<<root->data<<"";return 1;}return 0;}



int treenode::depth(treenode* ptr)
{
int ldepth=0,rdepth=0;
if (ptr==NULL)return 0;
else
{
	ldepth=depth(ptr->lchild);
	rdepth=depth(ptr->rchild);
	if (ldepth>rdepth) return (ldepth+1);else return (rdepth+1);}}

void treenode::leafnode(treenode *ptr)
{
int top=-1;int count=0;
treenode *stack[10];
do {
for (;ptr;ptr=ptr->lchild)
stack[++top]=ptr;
if (top>=0)
ptr=stack[top--];
else
break;
if (ptr->lchild==NULL && ptr->rchild==NULL)
count++;
ptr=ptr->rchild;

}while(1);
cout<<count;
}


treenode* treenode::insert(int item,treenode *root)
{
	treenode *temp=new treenode();
	temp->data=item;
	if (root==NULL)
	{root=temp;return root;}
	else
	{
		char direction[20];
		cout<<"Enter direction in uppercase";
		cin>>direction;
		treenode *current,*prev;
		prev=NULL;
		current=root;
		int i;
		for (i=0;i<strlen(direction)&&current!=NULL;i++)
		{
prev=current;
if (direction[i]=='L')
current=current->lchild;
else current=current->rchild;
}
if (current!=NULL || i!=strlen(direction))
{
cout<<"Insertion not possible";
delete temp;return root;}
if (direction[i-1]=='L')
prev->lchild=temp;
else
prev->rchild=temp;
}
return root;}
void treenode::inorder(treenode *ptr)
{
int top=-1;
treenode *stack[10];
do {
for (;ptr;ptr=ptr->lchild)
stack[++top]=ptr;
if (top>=0)
ptr=stack[top--];
else
break;
cout<<ptr->data;
ptr=ptr->rchild;

}while(1);}
void treenode:: preorder(treenode *ptr)
{
	int top=-1;treenode* stack[10];do{
for(;ptr;ptr=ptr->lchild){cout<<ptr->data;
stack[++top]=ptr;}
if(top>=0) ptr=stack[top--];
else break;
ptr=ptr->rchild;}while(1);}




int main()
{int ch,item;treenode g;char c;c='y';
while(c=='y')
{
cout<<"1.insert 2.inorder 3.preorder 4.postorder 5.parent 6.depth 7.Ancestors 8.Leafnodes";
cin>>ch;
switch(ch)
{
case 1: cout<<"Enter ele to be inserted";
cin>>item;
root=g.insert(item,root);
break;
case 2:
g.inorder(root);
break;
case 3:g.preorder(root);break;
case 4:g.postorder(root);break;
case 5:cout<<"Enter ele:";
int d;cin>>d;g.parent(root,d,NULL);break;
case 6: cout<<g.depth(root);break;
case 7:cout<<"Enter ele:";int t; cin>>t;g.Ancestors(root,t);break;
case 8:g.leafnode(root);break;
}
cout<<"continue?";
cin>>c;
}
}
