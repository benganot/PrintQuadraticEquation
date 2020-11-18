#include <stdio.h>
#include <math.h>

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
        printf("first sol = %.2lf + i%.2lf\n", -b / (double)(2 * a), sqrt(-d) / (2 * a));
        printf("second sol = %.2lf - i%.2lf\n", -b / (double)(2 * a),sqrt(-d) / (2 * a));
    }
    else
    {	// real roots
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);

        printf("first sol = %.2lf\n", root1);
        printf("second sol = %.2lf\n", root2);
    }

    return 0;
}

