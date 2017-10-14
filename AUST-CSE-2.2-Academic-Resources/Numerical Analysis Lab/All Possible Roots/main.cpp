#include <bits/stdc++.h>

using namespace std;

double e, iteration;

double f(double x)
{
    return x*x + x -2;
}

void bisection(double x1, double x2)
{
    double f1, f2;
    f1 = f(x1);
    f2 = f(x2);
    if(iteration <= 0 || f1*f2>0)
    {
        return;
    }
    double x3, f3, Err, i=0;
    do
    {
        x3 = (x1+x2)/2;
        f3 = f(x3);
        if(f1*f3<0)
        {
            x2=x3;
        }
        else
        {
            x1=x3;
        }
        Err = fabs((x2-x1)/x2);
        i++;
    }
    while(i<=iteration && e<Err);
    cout << "\nRoot: " << x2;
}

int main()
{
    double a, b, inc;
    cin >> a >> b >> e >> iteration;
    inc = fabs((a-b)/1000);
    do
    {
        bisection(a, a+inc);
        a+=inc;
    }
    while(a<b);
    return 0;
}
