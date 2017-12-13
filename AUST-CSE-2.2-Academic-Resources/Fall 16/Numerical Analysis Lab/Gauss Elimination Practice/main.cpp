#include <bits/stdc++.h>

using namespace std;

double a[100][100];
int n;

int main()
{
    ifstream infile;
    infile.open("input.txt");

    double x[100], b[100], temp;

    infile >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            infile >> a[i][j];
        }
        infile >> b[i];
    }


    for(int k=0; k<n; k++)
    {
        for(int j=k+1; j<n; j++)
        {
            temp = a[j][k]/a[k][k];
            for(int i=k; i<n; i++)
            {
                a[j][i]-=(a[k][i]*temp);
            }
            b[j]-=(b[k]*temp);
        }
    }

    for(int i=n-1; i>=0; i--){
        temp = b[i];
        for(int j=i+1; j<n; j++){
            temp-=(x[j]*a[i][j]);
        }
        x[i]=temp/a[i][i];
    }

    for(int i=0; i<n; i++){
        cout << x[i] << "\t";
    }

    return 0;
}
