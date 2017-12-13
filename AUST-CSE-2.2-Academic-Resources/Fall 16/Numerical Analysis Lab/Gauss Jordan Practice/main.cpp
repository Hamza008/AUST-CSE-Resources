#include <bits/stdc++.h>

using namespace std;

double a[100][100];
int n;

void print_A()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

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

    print_A();


    for(int k=0; k<n; k++)
    {
        temp=a[k][k];
        for(int i=k; i<n; i++)
        {
            a[k][i]/=temp;
        }
        b[k]/=temp;
        for(int j=0; j<n; j++)
        {
            if(j!=k)
            {
                temp=a[j][k];
                for(int i=k; i<n; i++)
                {
                    a[j][i]-=(a[k][i]*temp);
                }
                b[j]-=(b[k]*temp);
            }
        }
    }

    print_A();

    for(int i=0; i<n; i++)
    {
        cout << b[i] << "\t";
    }

    return 0;
}
