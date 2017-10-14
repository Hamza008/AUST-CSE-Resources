#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int num[100];
    int n, l=0, r=-1, siz, value;
    cout << "Enter Size : ";
    cin >> siz;
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
            //enqueue(header, value);
            r++;
            r=r%siz;
            if(abs(l-r)<0){
                cout << "List is FULL!\n";
                break;
            }
            num[r]=value;
            break;
        case 2:
            //dequeue(header);

            cout << "\nThe Number from Dequeue: " << num[l] << "\n";
            l++;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Wrong Option. Enter Again!";
            break;
        }

        //printList(header);
        cout << "\nCurrent List: \n";
        for(int i=l; i<=r; i++)
        {
            cout << num[i] << "\t";
        }
    }
    while(n!=3);

    return 1;
}

