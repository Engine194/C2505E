#include <stdio.h>

int main()
{
    /**
     * Write a C program that:
     * - Inputs an integer `n` (1 ≤ n ≤ 100) and an array of `n` integers.
     * - Prints the input array.
     * - Calculates and prints how many elements are greater than the average value of the array.
     */

    int n = 0;
    // Input n
    do
    {
        printf("Enter n = ");
        scanf("%d", &n);
        if (n < 1 || n > 100)
        {
            printf("Invalid input! 1 <= n <= 100, try again: \n");
        }
    } while (n < 1 || n > 100);

    // Declare array numbers and input all elements
    int numbers[n];
    int i = 0;
    int *ptr = numbers;
    int sum = 0;
    while (i < n)
    {
        int value;
        printf("#%d, Enter element [%d]: ", i + 1, i + 1);
        scanf("%d", &value);
        *(ptr + i) = value;
        sum += value;
        i++;
    }

    // Print numbers in a for loop
    printf("You enter values: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    // Calculate the average value of the array
    float avg = 1.0 * sum / n;

    // Count and print number of elements are greater than the average value of the array;
    int aboveAvgNumbers[n];
    int *abovePtr = aboveAvgNumbers;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int element = *(ptr + i);
        if (element > avg)
        {
            *(abovePtr + count) = element;
            count++;
        }
    }
    printf("\nAverage value = %.2f\n", avg);
    printf("There a %d elements those are greater than the average value of the array:\n", count);
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            printf("%d ", *(abovePtr + i));
        }
    }

    return 0;
}
