#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

void insertAfter(node* oldNode, int data);
void printList(node* header);
void insertOption(node* p);
void insertLast(node* p, int data);
void insertAtIndex(node* p, int data, int index);
void insertAfterValue(node* oldNode, int data, int value);
void updateOption(node* p);
void updateAfter(node* oldNode, int data);
void updateLast(node* oldNode, int data);
void updateAtIndex(node* oldNode, int data, int index);
void updateAtValue(node* oldNode, int data, int index);
void deleteOption(node* p);
void deleteAfter(node* oldNode);
void deleteLast(node* oldNode);
void deleteAtIndex(node* oldNode, int index);
void deleteAtValue(node* oldNode, int value);
void searchOption(node* oldNode, int value);

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

    cout << "Enter Size of Linked List : ";
    cin >> siz;

    for(int i=0; i<siz; i++)
    {
        insertAfter(header, rand()%100);
    }
    printList(header);

    do
    {
        cout << "\n\nOptions :\n 1.Insert\n 2.Update\n 3.Delete\n 4.Search\n 5.Exit\n";
        cout << "\n\nChoose Option : ";
        cin >> n;
        switch(n)
        {
        case 1:
            insertOption(header);
            break;
        case 2:
            updateOption(header);
            break;
        case 3:
            deleteOption(header);
            break;
        case 4:
            cout << "\tEnter Value : ";
            cin >> value;
            searchOption(header, value);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Wrong Option. Enter Again!";
            break;
        }
        printList(header);
    }
    while(n!=5);

    return 1;
}

void insertOption(node* p)
{
    int n, data, index, value;
    cout << "\n\n\tInsert Options :\n\t 1.First\n\t 2.Last\n\t 3.At Index\n\t 4.After Value\n";
    cout << "\n\n\tChoose Option : ";
    cin >> n;
    cout << "\tEnter Value: ";
    cin >> data;
    switch(n)
    {
    case 1:
        insertAfter(p, data);
        break;
    case 2:
        insertLast(p, data);
        break;
    case 3:
        cout << "\tEnter Index: ";
        cin >> index;
        insertAtIndex(p, data, index);
        break;
    case 4:
        cout << "\tThe After Value: ";
        cin >> value;
        insertAfterValue(p, data, value);
        break;
    default:
        cout << "Wrong Option. Enter Again!";
        break;
    }
}

void insertAfter(node* oldNode, int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    if(newNode==NULL)
    {
        cout << "Node not available!!";
        return;
    }
    newNode->data= data;
    newNode->link= oldNode->link;
    oldNode->link= newNode;
}

void insertLast(node* oldNode, int data)
{
    node* ptr = oldNode->link;
    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }

    insertAfter(ptr, data);
}

void insertAtIndex(node* oldNode, int data, int index)
{
    node* ptr = oldNode;
    for(int i=1; i<index; i++)
    {
        ptr = ptr->link;
        if(ptr==NULL)
        {
            cout << "Index bigger than Linked List!!";
            return;
        }
    }

    insertAfter(ptr, data);
}

void insertAfterValue(node* oldNode, int data, int value)
{
    node* ptr = oldNode->link;
    while(ptr->data!=value)
    {
        ptr= ptr->link;
        if(ptr==NULL)
        {
            cout << "Value Not Found!!";
            return;
        }
    }

    insertAfter(ptr, data);
}

void updateOption(node* p)
{
    int n, data, index, value;
    cout << "\n\n\tUpdate Options :\n\t 1.First\n\t 2.Last\n\t 3.At Index\n\t 4.At Value\n";
    cout << "\n\n\tChoose Option : ";
    cin >> n;
    cout << "\tEnter Value: ";
    cin >> data;
    switch(n)
    {
    case 1:
        updateAfter(p, data);
        break;
    case 2:
        updateLast(p, data);
        break;
    case 3:
        cout << "\tEnter Index: ";
        cin >> index;
        updateAtIndex(p, data, index);
        break;
    case 4:
        cout << "\tAt Value: ";
        cin >> value;
        updateAtValue(p, data, value);
        break;
    default:
        cout << "Wrong Option. Enter Again!";
        break;
    }
}

void updateAfter(node* oldNode, int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    if(newNode==NULL)
    {
        cout << "Node not available!!";
        return;
    }
    newNode->data= data;
    newNode->link= oldNode->link->link;
    oldNode->link= newNode;
}

void updateLast(node* oldNode, int data)
{
    node* ptr = oldNode->link;
    while(ptr->link->link!=NULL)
    {
        ptr = ptr->link;
    }

    updateAfter(ptr, data);
}

void updateAtIndex(node* oldNode, int data, int index)
{
    node* ptr = oldNode;
    for(int i=1; i<index; i++)
    {
        ptr = ptr->link;
        if(ptr==NULL)
        {
            cout << "Index bigger than Linked List!!";
            return;
        }
    }

    updateAfter(ptr, data);
}

void updateAtValue(node* oldNode, int data, int value)
{
    node* ptr = oldNode;
    while(ptr->link->data!=value)
    {
        ptr= ptr->link;
        if(ptr->link==NULL)
        {
            cout << "Value Not Found!!";
            return;
        }
    }

    updateAfter(ptr, data);
}

void deleteOption(node* p)
{
    int n, index, value;
    cout << "\n\n\tDelete Options :\n\t 1.First\n\t 2.Last\n\t 3.At Index\n\t 4.At Value\n";
    cout << "\n\n\tChoose Option : ";
    cin >> n;
    switch(n)
    {
    case 1:
        deleteAfter(p);
        break;
    case 2:
        deleteLast(p);
        break;
    case 3:
        cout << "\tEnter Index: ";
        cin >> index;
        deleteAtIndex(p, index);
        break;
    case 4:
        cout << "\tAt Value: ";
        cin >> value;
        deleteAtValue(p, value);
        break;
    default:
        cout << "Wrong Option. Enter Again!";
        break;
    }
}

void deleteAfter(node* oldNode)
{
    if(oldNode->link==NULL)
    {
        cout << "Nothing in the Linked List!!";
        return;
    }
    node* ptr = oldNode->link->link;
    free(oldNode->link);
    oldNode->link=ptr;
}

void deleteLast(node* oldNode)
{
    if(oldNode->link==NULL)
    {
        cout << "Nothing in the Linked List!!";
        return;
    }
    node* ptr = oldNode;
    while(ptr->link->link!=NULL)
    {
        ptr = ptr->link;
    }

    deleteAfter(ptr);
}

void deleteAtIndex(node* oldNode, int index)
{
    node* ptr = oldNode;
    for(int i=1; i<index; i++)
    {
        ptr = ptr->link;
        if(ptr==NULL)
        {
            cout << "Index bigger than Linked List!!";
            return;
        }
    }

    deleteAfter(ptr);
}

void deleteAtValue(node* oldNode, int value)
{
    node* ptr = oldNode;
    while(ptr->link->data!=value)
    {
        ptr= ptr->link;
        if(ptr->link==NULL)
        {
            cout << "Value Not Found!!";
            return;
        }
    }

    deleteAfter(ptr);
}

void searchOption(node* oldNode, int value)
{
    node* ptr = oldNode->link;
    int i=1;
    while(ptr->data!=value)
    {
        ptr= ptr->link;
        i++;
        if(ptr==NULL)
        {
            cout << "\tValue Not Found!!";
            return;
        }
    }
    cout << "\tIndex of Value : " << i;
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
