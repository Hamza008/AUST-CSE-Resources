#include <bits/stdc++.h>

using namespace std;

double F(double x)
{
    return x*x - 5*x + 6;
}

int main()
{
    double x1, x2, x3, f1, f2, f3, Err, e=0.001;
    cin >> x1 >> x2;

    do
    {
        f1 = F(x1);
        f2 = F(x2);

        x3 = x2 - (f2*(x2-x1)/(f2-f1));
        f3 = F(x3);

        if((f1*f3)<0)
        {
            x2 = x3;
        }
        else
        {
            x1 = x3;
        }
        Err = ((x2-x1)/x2);
        cout << "\n" << x1 << "\t" << x2 << "\t" << Err;
    }
    while(Err>e && f3>e);
    return 0;
}
