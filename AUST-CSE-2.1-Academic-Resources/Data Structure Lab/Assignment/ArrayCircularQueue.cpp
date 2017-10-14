#include <iostream>
using namespace std;
#include <stdlib.h>

void printList(int num[], int siz, int l, int r);
void enqueue(int num[], int siz, int data);
int dequeue(int num[], int siz);

int r=-1, l=-1;

int main()
{
    int num[100], siz, n, value, x;
    cout << "Enter Size of List: ";
    cin >> siz;
    siz++;
    do
    {
        cout << "\nOptions:\n 1. Enqueue.\n 2. Dequeue.\n 3. Exit.\n";
        cout << "\nChoose Options: ";
        cin >> n;
        switch(n)
        {
        case 1:
            cout << "The number for enqueue: ";
            cin >> value;
            enqueue(num, siz, value);
            break;
        case 2:
            if((x=dequeue(num, siz))!=INT_MIN)
            {
                cout << "\tThe number from dequeue: "<< x;
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "\nWrong Option!\n";
            break;
        }
        printList(num, siz, l, r);
    }
    while(n!=3);
    return 0;
}

void enqueue(int num[], int siz, int data)
{
    r++;
    r=r%siz;
    num[r]=data;
    if(abs(l-r)>=siz)
    {
        cout << "\tList is Full!!";
        return;
    }
}

int dequeue(int num[], int siz)
{
    if(abs(l-r)==0)
    {
        cout << "\tList is Empty!!";
        return INT_MIN;
    }
    l++;
    l=l%siz;
    return num[l];
}

void printList(int num[], int siz, int l, int r)
{
    cout << "\nCurrent List: \n";
    int x=(siz-(l-r))%siz;
    for(int i=0; i<x ; i++)
    {
        cout << num[(i+l+1)%siz] << "\t";
    }
}
