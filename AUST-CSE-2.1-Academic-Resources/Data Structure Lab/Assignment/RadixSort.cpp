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
int dequeue(node* head);

int main()
{
    int siz, n, value;
    struct node* header[12];
    for(int i=0; i<12; i++)
    {
        header[i] = (node*) malloc(sizeof(node));
        if(header[i]==NULL)
        {
            cout << "Header not available!!";
            return -1;
        }
        header[i]->data=-99999;
        header[i]->link=NULL;
    }

    cout << "Enter List Size : ";
    cin >> siz;

    for(int i=0; i<siz; i++)
    {
        enqueue(header[10], rand()%10000);
    }
    printList(header[10]);

    int maxDigit, m=1;
    do{
        maxDigit=0;
        for(int i=0; i<siz; i++)
        {
            int x=dequeue(header[10]);
            int div=x/m;
            if(maxDigit<div){
                maxDigit=div;
            }
            enqueue(header[div%10], x);
        }

        for(int i=0; i<10; i++)
        {
            int x;
            while((x=dequeue(header[i]))!=-1)
            {
                enqueue(header[10], x);
            }

        }
        m*=10;
    }while(maxDigit>0);
    cout << "\n\n\nAfter Sorting: \n";
    printList(header[10]);


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

int dequeue(node* head)
{
    if(head->link==NULL)
    {
        return -1;
    }
    node* ptr1 = head;
    int info= head->link->data;

    node* ptr2 = ptr1->link->link;
    free(ptr1->link);
    ptr1->link=ptr2;
    return info;
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

