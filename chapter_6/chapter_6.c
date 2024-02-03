#include <stdio.h>

void exec_2(void)
{
    printf("Exec 2 ########\n");
    int values[10];
    int index;
    for (index = 0; index < 10; ++index)
        values[index] = 0;

    values[0] = 197;
    values[2] = 100;
    values[5] = 350;
    values[3] = values[0] + values[5];
    values[9] = values[5] / 10;
    --values[2];
    for (index = 0; index < 10; ++index)
        printf("values[%i] = %i\n", index, values[index]);
}
void exec_3(void)
{
    printf("Exec 3 ########\n");
    int ratingCounters[11], i, response;
    for (i = 1; i <= 10; ++i)
        ratingCounters[i] = 0;
    printf("Enter your responses\n");
    while (1)
    {
        scanf("%i", &response);
        if (response == 999)
            break;
        if (response < 1 || response > 10)
            printf("Bad response: %i\n", response);
        else
            ++ratingCounters[response];
    }
    printf("\n\nRating Number of Responses\n");
    printf("------ -------------------\n");
    for (i = 1; i <= 10; ++i)
        printf("%4i%14i\n", i, ratingCounters[i]);
}

void exec_4(void)
{
    printf("Exec 4 ########\n");
    double array[10] = {1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99, 10.10};
    size_t length = sizeof(array) / sizeof(array[0]);
    double sum = 0;
    for (int index = 0; index < length; index++)
        sum = sum + array[index];

    printf("Sum: %.1f", sum / length);
}

void exec_5_6(void)
{
    printf("Exec 5 ########\n");
    int numbers[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, j;
    for (j = 0; j < 10; ++j)
        for (i = 0; i < j; ++i)
            numbers[j] += numbers[i];

    for (j = 0; j < 10; ++j)
        printf("%i ", numbers[j]);
    printf("\n");
}
void exec_6(void)
{
    printf("Exec 6 ########\n");
    int fibo1 = 0, fibo2 = 1, fibo3, i;
    // Fibonacci[0] = 0; // by definition
    // Fibonacci[1] = 1; // ditto

    printf("%i\n", fibo1);
    printf("%i\n", fibo2);

    for (i = 2; i < 15; ++i)
    {
        fibo3 = fibo1 + fibo2;
        printf("%i\n", fibo3);
        fibo1 = fibo2;
        fibo2 = fibo3;
    }
}

void exec_7(void)
{
    printf("Exec 7 ########\n");
    int P[150];
    int length = sizeof(P) / sizeof(P[0]);
    for (int i = 0; i < length; i++)
        P[i] = 0;

    int index = 2;
    while (index < length)
    {
        for (int j = 2; index * j < length; j++)
        {
            P[index * j] = 1;
        }
        index++;
    }

    for (int i = 0; i < length; i++)
    {
        if (P[i] == 0)
            printf("%d ", i);
    }
}

struct f
{
    int a;
    int b[];
};

void exec_8(void)
{
    printf("Exec 8 ########\n");
    struct f fa[10]; // Error occurs if your complier does not support variable array.
}

int main(void)
{
    exec_2();
    exec_3();
    exec_4();
    exec_5_6();
    exec_6();
    exec_7();
    exec_8();
}
