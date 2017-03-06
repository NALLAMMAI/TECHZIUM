#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int info;
    struct node *next;
}*start;

class single_llist
{
    public:
        node* create_node(int);
        void insert_begin();
        void insert_last();
        void display();
        void ret();
        single_llist()
        {
            start = NULL;
        }
};

int main()
{
    int  i,a;
    single_llist s1;
    start = NULL;
    cout<<"enter no of nodes to be inserted"<<endl;
    cin>>a;
    s1.insert_begin();
    for(i=1;i<a;i++)
           {
             s1.insert_last();

           }
        cout<<"Display elements of link list"<<endl;
            s1.display();
            s1.ret();
return 0;
}
 node *single_llist::create_node(int value)
{
    struct node *temp;
    temp = new(struct node);
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;
        return temp;
    }
}

void single_llist::insert_begin()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
}

void single_llist::insert_last()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *s;
    temp = create_node(value);
    s = start;
    while (s->next != NULL)
    {
        s = s->next;
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Element Inserted at last"<<endl;
}

void single_llist::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void single_llist::ret()
{
    int n;
    struct node *temp;
    cout<<"enter the position of the element to be retrieved from the last"<<endl;
    cin>>n;
    temp=start;
    for(int i=0;i<n;i++)
        temp=temp->next;
    while (temp != NULL)
    {
        start = start->next;
    temp=temp->next;

    }
    cout<<"the element present is"<<start->info<<endl;
}
