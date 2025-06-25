#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    /**
     * Write a program that:
     * - Inputs two integers `a` and `b`.
     * - Uses a pointer-based function to swap the values of `a` and `b`.
     * - Prints the values after swapping
     */

    // Input a, b;
    int a, b;
    printf("Enter a = ");
    scanf("%d", &a);
    printf("Enter b = ");
    scanf("%d", &b);
    printf("You enter\n(a,b) = (%d, %d)\n", a, b);

    // Swap a, b values
    swap(&a, &b);
    printf("After swaping\n(a,b) = (%d, %d)\n", a, b);
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
};
