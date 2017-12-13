#include <bits/stdc++.h>
using namespace std;

int F(int x)
{
    return x*x + 3*x + 2;
}

int main()
{
    double x1, x2, e, f1, f2, x0, f0;
    cout << "Enter x1, x2, e : \n";
    cin >> x1 >> x2 >> e;

    do
    {
        f1 = F(x1);
        f2 = F(x2);

        //x0 = x1-f1*(x1-x2)/(f1-f2);
        //x0 = (x1*f2-f1*x2)/(f2-f1);
        x0 = (x1+x2)/2;
        f0 = F(x0);

        if(f0*f1<0)
        {
            x2=x0;
        }
        else
        {
            x1=x0;
        }
    }
    while((x2-x1)/x2 > e);

    cout << "\nRoot: " << x0;

    return 0;
}

