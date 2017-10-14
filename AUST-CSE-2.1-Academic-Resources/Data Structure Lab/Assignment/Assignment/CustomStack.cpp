#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

void printList(node* header);
void push(node* p, int data);
void pop(node* head);

int main()
{
    int siz, n, value;
    struct node* header;
    header = (node*) malloc(sizeof(node));
    if(header==NULL)
    {
        cout << "Header not available!!";
        return -1;
    }
    header->data=-99999;
    header->link=NULL;

    cout << "Enter Size of Stack : ";
    cin >> siz;

    for(int i=0; i<siz; i++)
    {
        push(header, rand()%100);
    }
    printList(header);

    do
    {
        cout << "\n\nOptions :\n 1.Push\n 2.Pop\n 3.Exit\n";
        cout << "\n\nChoose Option : ";
        cin >> n;
        switch(n)
        {
        case 1:
            cout << "\tEnter Value : ";
            cin >> value;
            push(header, value);
            break;
        case 2:
            pop(header);
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Wrong Option. Enter Again!";
            break;
        }
        printList(header);
    }
    while(n!=3);

    return 1;
}

void push(node* head, int data)
{
    node* ptr = head;
    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }

    node* newNode = (node*) malloc(sizeof(node));
    if(newNode==NULL)
    {
        cout << "Node not available!!";
        return;
    }
    newNode->data= data;
    newNode->link= ptr->link;
    ptr->link= newNode;
}

void pop(node* head)
{
    if(head->link==NULL)
    {
        cout << "Nothing in the Linked List!!";
        return;
    }
    node* ptr1 = head;
    while(ptr1->link->link!=NULL)
    {
        ptr1 = ptr1->link;
    }

    node* ptr2 = ptr1->link->link;
    free(ptr1->link);
    ptr1->link=ptr2;
}

void printList(node* header)
{
    node* ptr = header->link;
    cout << "\nCurrent List:\n";
    while(ptr!=NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->link;
    }
}

