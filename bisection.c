#include <stdio.h>
float f(float x)
{
    return (x * x + 3 * x + 1);
}
int main()
{
    float a, b, root, prevroot, realerror, error = 0.001;
    again:
    printf("enter initial guess\n");
    scanf("%f%f", &a, &b);
    prevroot=b;
    if (f(a)*f(b) > 0||f(a)>0)
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
        printf("root=%f    error=%f\n", root,realerror);
    }
    
    return 0;
}