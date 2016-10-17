#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef SHIP_H
#define SHIP_H

/*

  LINKED LIST OF SHIPS

  */

struct node
{
    int health;
    string name; // WILL NEED TO BE Q STRINGS ***
    bool status;
    struct node *next;
}*start;


class llist
{
    public:
        node* create_node(int,string,bool);
        void insert_begin(int,string,bool);
        void insert_last(int, string, bool);
        void delete_pos();
        void search();
        void display();
        llist()
        {
            start = NULL;
        }
};

node *llist::create_node(int value, string n, bool st) {
    struct node *temp, *s;
    temp = new(struct node);
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->health = value;
        temp->name = n;
        temp->status = st;
        temp->next = NULL;
        return temp;
    }
}
 void llist::insert_last(int value, string n, bool st) {

    struct node *temp, *s;
    temp = create_node(value,n,st);
    s = start;
    while (s->next != NULL)
    {
        s = s->next;
    }
    temp->next = NULL;
    s->next = temp;

}


void llist::delete_pos() {
    int pos, i, counter = 0;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element Deleted"<<endl;
    }
}


void llist::insert_begin(int value, string n, bool st) {

    struct node *temp, *p;
    temp = create_node(value,n,st);
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



void llist::search() {
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->health == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;
}


void llist::display() {
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
        cout<<temp->health<<endl;
        cout <<temp->name<<endl;
        if(temp->status == false) {
        cout <<"afloat ->" << endl;
        cout << endl;
        }
        else {
         cout << "sunk ->" << endl;
         cout << endl;
        }
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
#endif // SHIP_H
