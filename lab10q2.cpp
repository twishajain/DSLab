#include<iostream>
using namespace std;

class node
{
    int info;
    node* rcl;
    node* lcl;

public:
    node()
    {
        lcl=NULL;
        rcl=NULL;
    }

    node* create_bt()
    {
        node* root;
        int x;
        cout<<"\nEnter data (-1 for NULL)";
        cin>>x;
        if(x==-1)
            return NULL;
        node* temp=new node();
        temp->info=x;
        root=temp;
        cout<<"\nEnter left child of "<<root->info;
        root->lcl=create_bt();
        cout<<"\nEnter right child of "<<root->info;
        root->rcl=create_bt();
        return root;
    }

    void display(node* root)
    {
        if(root){
        display(root->lcl);
        cout<<root->info;
        display(root->rcl);}
    }




};

int main()
{
    node n;
    node* root=n.create_bt();
    cout<<"The tree is: \n\n";
    n.display(root);
}
