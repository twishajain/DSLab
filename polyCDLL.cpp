#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class node{
public:
    int coeff;
    int expon;
    node *link;
node *prev;
};

node* attach(int coeff, int expon, node* head)
{
            node *temp, *cur;
            temp = new node();
            temp->coeff = coeff;
            temp->expon = expon;
            cur=head->link;
            while(cur->link != head)
            {
                        cur = cur->link;
            }
            cur->link = temp;
		temp->prev=cur;
            temp->link = head;
		head->prev=temp;
            return head;
}
node*  read_poly(node* head)
{
            int i = 1, coeff, expon;
            cout<<"\nEnter the coefficient as -999 to end the polynomial \n";
            while(1)
            {
                        cout<<"Enter the "<<i++<<"term";
                        cout<<"\nCoeff = ";
                        cin>>coeff;
                        if(coeff == -999)
                                    break;
                        cout<<"\nPow x = ";
                        cin>>expon;
                        head = attach(coeff, expon, head);
            }
              return head;
}
node* poly_add(node* head1, node* head2, node* head3)
{
            node *a,*b;
            int coeff;
            a = head1->link;
            b=head2->link;
            while(a!= head1 && b!= head2)
            {
                        if(a->expon == b->expon)
                        {
                                    coeff = a->coeff + b->coeff;
                                    if(coeff != 0)
                                                head3 = attach(coeff, a->expon, head3);
                                    a = a->link;
                                    b = b->link;
                        }
                        else if(a->expon > b->expon)
                        {
                                     head3 = attach(a->coeff, a->expon, head3);
                                    a = a->link;
                        }
                        else
                        {
                                    head3 = attach(b->coeff, b->expon, head3);
                                    b = b->link;
                        }
            }
            while(a != head1)
            {
                        head3 = attach(a->coeff, a->expon, head3);
                        a = a->link;
            }
            while(b != head2)
            {
                        head3 = attach(b->coeff, b->expon, head3);
                        b = b->link;
            }
            return head3;
}
node *poly_mult(node *head1, node *head2, node *head4)
{
            node *cur1, *cur2;
            if(head1->link == head1 || head2->link == head2)
            {
                        printf("\nMultiplied polynomial is zero polynomial");
                        return NULL;
            }
            cur1 = head1->link;
            while(cur1 != head1)
            {
                        cur2 = head2->link;
                        while(cur2!=head2)
                        {
                                    head4 =attach(cur1->coeff*cur2->coeff, cur1->expon+cur2->expon, head4);
                                   cur2=cur2->link;
                        }
                        cur1=cur1->link;
            }
            return head4;
}
void display(node* head)
{
            node* temp;
            if(head->link == head)
            {
                         cout<<"\nPolynomial does not exist";
                         return;
            }
            temp = head->link;
            while(temp != head)
            {
                         cout<<temp->coeff<<"x^"<<temp->expon;
                         temp = temp->link;
                         if(temp != head)
                                    cout<<" + ";
            }
}
int main()
{
            node *head1, *head2, *head3, *head4;
            head1 = new node();
            head2 = new node();
		head4=new node();
            head3 = new node();
head4->link=head4;head4->prev=head4;
            head1->link=head1;
		head1->prev=head1;
            head2->link=head2;
head2->prev=head2;
            head3->link=head3;
head3->prev=head3;

            cout<<"\nEnter the first polynomial \n";
            head1 = read_poly(head1);
            cout<<"\nEnter the second polynomial \n";
            head2 = read_poly(head2);

            head3 = poly_add(head1, head2, head3);
head4 = poly_mult(head1, head2, head4);
            cout<<"\nPolynomial 1:\t";
            display(head1);
            cout<<"\nPolynomial 2:\t";
            display(head2);
            cout<<"\nPolynomial Result:\t";
            display(head3);
cout<<"Multiplication result";
display(head4);
}
