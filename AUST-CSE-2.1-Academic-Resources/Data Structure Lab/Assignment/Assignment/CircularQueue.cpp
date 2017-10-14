#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

void printList(node* header);
void enqueue(node* p, int data);
void dequeue(node* head);

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

    cout << "Enter Size of Queue : ";
    cin >> siz;

    for(int i=0; i<siz; i++)
    {
        enqueue(header, rand()%100);
    }
    printList(header);

    do
    {
        cout << "\n\nOptions :\n 1.Enqueue\n 2.Dequeue\n 3.Exit\n";
        cout << "\n\nChoose Option : ";
        cin >> n;
        switch(n)
        {
        case 1:
            cout << "\tEnter Value : ";
            cin >> value;
            enqueue(header, value);
            break;
        case 2:
            dequeue(header);
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

void enqueue(node* head, int data)
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

void dequeue(node* head)
{
    if(head->link==NULL)
    {
        cout << "Nothing in the Linked List!!";
        return;
    }
    node* ptr1 = head;

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

