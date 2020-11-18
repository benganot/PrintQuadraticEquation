#include <stdio.h>

float mysqrt(int n);

int main()
{
    int a, b, c, d;
    double root1, root2;
    int isPrintBeforeMe = 0;

    printf("Enter a, b and c where a*x*x + b*x + c = 0\n");
    int return_code = scanf_s("%d%d%d", &a, &b, &c);

    // Print the equation
    if (a != 0)
    {
        isPrintBeforeMe = 1;
        // Print A
        if (a < 0)
        {
            printf("-");
        }

        int const mask = a >> sizeof(int) * 8 - 1;
        a = (a + mask) ^ mask;

        if (a != 1)
        {
            printf("%d", a);
        }

        printf("x**2");

    }

    if (b != 0)
    {
        // Print B
        if (b < 0)
        {
            printf(" - ");
        }
        else if ((b > 0) && (isPrintBeforeMe == 1))
        {
            printf(" + ");
        }
        isPrintBeforeMe = 1;

        int const mask = b >> sizeof(int) * 8 - 1;
        b = (b + mask) ^ mask;

        if (b != 1)
        {
            printf("%d", b);
        }

        printf("x");
    }

    if (c != 0)
    {
        // Print C
        if (c < 0)
        {
            printf(" - ");
        }
        else if ((c > 0) && (isPrintBeforeMe == 1))
        {
            printf(" + ");
        }

        int const mask = c >> sizeof(int) * 8 - 1;
        c = (c + mask) ^ mask;
        printf("%d", c);

    }

    printf("\n");

    // Calc the equation
    d = b * b - 4 * a * c;

    if (d < 0)
    {	
        // complex roots
        printf("first sol = %.2lf + i%.2lf\n", -b / ((double)(a)*2), mysqrt(-d) / (2 * a));
        printf("second sol = %.2lf - i%.2lf\n", -b / ((double)(a)*2), mysqrt(-d) / (2 * a));
    }
    else
    {	// real roots
        root1 = (-b + mysqrt(d)) / (2 * a);
        root2 = (-b - mysqrt(d)) / (2 * a);

        printf("first sol = %.2lf\n", root1);
        printf("second sol = %.2lf\n", root2);
    }

    return 0;
}

float mysqrt(int n)
{
    float temp, sqrt;

    // store the half of the given number e.g from 256 => 128
    sqrt = n / 2;
    temp = 0;

    // Iterate until sqrt is different of temp, that is updated on the loop
    while (sqrt != temp) {
        // initially 0, is updated with the initial value of 128
        // (on second iteration = 65)
        // and so on
        temp = sqrt;

        // Then, replace values (256 / 128 + 128 ) / 2 = 65
        // (on second iteration 34.46923076923077)
        // and so on
        sqrt = (n / temp + temp) / 2;
    }

    return sqrt;
}