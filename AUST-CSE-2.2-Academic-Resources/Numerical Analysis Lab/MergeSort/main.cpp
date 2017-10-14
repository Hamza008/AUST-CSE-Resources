#include <bits/stdc++.h>

using namespace std;

void showArray(int n, int num[]){
    for(int i=0; i<n; i++){
        cout << num[i] << "\t";
    }
}

int main()
{
    int n, num[100];
    cin >> n;

    for(int i=0; i<n; i++){
        num[i] = rand()%100;
    }

    showArray(n, num);
}
