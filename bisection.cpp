#include <iostream>
#include <iomanip>
using namespace std;
double f(double x)
{
    return (x * x + 3 * x + 1);
}
int main()
{
    double a, b, root, prevroot, realerror, error = 0.001;
again:
    cout << "enter initial guess\n";
    cin >> a >> b;
    prevroot = b;
    if (f(a) * f(b) > 0 || f(a) > 0)
    {
        printf("invalid initial guess");
        goto again;
    }
    realerror = b - a;
    if (realerror < 0)
    {
        realerror = -1 * realerror;
    }
    while (realerror > error)
    {
        root = (a + b) / 2;
        if (f(root) < 0)
        {
            a = root;
        }
        else
        {
            b = root;
        }

        realerror = root - prevroot;
        if (realerror < 0)
        {
            realerror = -1 * realerror;
        }
        prevroot = root;
        cout << "root=" << setw(10) << root << "    error=" << setw(10) << realerror << endl;
    }

    return 0;
}