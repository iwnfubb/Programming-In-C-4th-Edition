#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exec_2()
{
    printf("Exec 2 ########\n");
    int number1, number2;
    printf("Please enter 1. number: \n");
    scanf("%i", &number1);
    printf("Please enter 2. number: \n");
    scanf("%i", &number2);
    if (number1 % number2 == 0)
    {
        printf("Number %i is evenly divisible by %i \n", number1, number2);
    }
    else
    {
        printf("Nope \n");
    }
}

void exec_3()
{
    int number1, number2;
    printf("Please enter 1. number: \n");
    scanf("%i", &number1);
    printf("Please enter 2. number: \n");
    scanf("%i", &number2);
    if (number2 == 0)
    {
        printf("Can not devide 0 \n");
    }
    float result = (float)number1 / (float)number2;
    int temp = (int)(result * 10000);
    int rest = temp % 10;
    if (rest >= 5)
        temp = temp + (10 - rest);
    else
        temp = temp - rest;

    printf("Result %i devide %i is %.3f \n ", number1, number2, (float)temp / 10000.f);
}

void exec_5()
{
    printf("Exec 5 ########\n");
    int number, right_digit;
    printf("Enter your number.\n");
    scanf("%i", &number);
    _Bool is_negative = 0;
    if (number < 0)
        is_negative = 1;
    number = abs(number);

    do
    {
        right_digit = number % 10;
        printf("%i", right_digit);
        number = number / 10;
    } while (number > 0);

    if (is_negative)
    {
        printf("-");
    }
    while (number != 0)
        ;
    printf("\n");
}

const char *read_digit(int number)
{
    if (number > 9 || number < 0)
        return "Invalid";
    switch (number)
    {
    case 0:
        return "zero";
    case 1:
        return "one";
    case 2:
        return "two";
    case 3:
        return "three";
    case 4:
        return "four";
    case 5:
        return "five";
    case 6:
        return "six";
    case 7:
        return "seven";
    case 8:
        return "eight";
    case 9:
        return "nine";
    default:
        return "Nope!";
    }
}

char *concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

const char *read_number(int number)
{
    if (number < 0)
        return "Invalid";

    if (number < 9)
    {
        return read_digit(number);
    }
    else
    {

        return concat(read_number(number / 10), concat(" ", read_digit(number % 10)));
    }
}

void exec_6()
{
    printf("Exec 6 ########\n");
    printf("Enter a positive number \n");
    int num;
    scanf("%i", &num);
    printf("%s", read_number(num));
}

void exec_7()
{
    printf("Exec 7 ########\n");
    printf("Enter a number: \n");
    int p, d;

    for (p = 2; p <= 50; ++p)
    {
        _Bool isPrime = 1;
        int rest = p % 2;
        if (p > 2 && rest == 0)
        {
            isPrime = 0;
            continue;
        }

        for (d = 2; d < p && isPrime != 0; ++d)
        {

            if (d > 2 && d % 2 == 0)
                continue;

            if (p % d == 0)
            {
                isPrime = 0;
                continue;
            }
        }
        if (isPrime != 0)
            printf("%i ", p);
    }
    printf("\n");
}

void intepreter(char *string)
{
    char *sub_string = strtok(string, " ");
    while (sub_string != NULL)
    {
        printf(" %s\n", sub_string); // printing each token
        sub_string = strtok(NULL, " ");
    }
}

void exec_4()
{
    printf("Exec 4 ########\n");
    printf("Begin Calculations \n");
    float number, accumulator;
    char operator;
    char string[20];
    _Bool is_running = 1;

    while (is_running)
    {
        fgets(string, sizeof(string), stdin);

        char *sub_string = strtok(string, " ");
        int index = 0;
        while (sub_string != NULL)
        {
            if (index == 0)
                number = atof(sub_string);
            if (index == 1)
                switch (sub_string[0])
                {
                case 'S':
                    accumulator = number;
                    printf("= %f \n", accumulator);
                    break;
                case '+':
                    accumulator = accumulator + number;
                    printf("= %f \n", accumulator);
                    break;
                case '-':
                    accumulator = accumulator - number;
                    printf("= %f \n", accumulator);
                    break;
                case '*':
                    accumulator = accumulator * number;
                    printf("= %f \n", accumulator);
                    break;
                case '/':
                    accumulator = accumulator / number;
                    printf("= %f \n", accumulator);
                    break;
                case 'E':
                    printf("= %f \n", accumulator);
                    is_running = 0;
                    break;
                default:
                    printf("Invalid Opration. Please use only + - * / S E \n");
                    sub_string = NULL;
                }

            if (index > 1)
            {
                printf("Invalide input \n");
                continue;
            }
            index++;
            sub_string = strtok(NULL, " ");
        }
    }
    printf("End of calculators \n");
}

void test()
{
    char str[] = "Geeks-for-Geeks";

    // Returns first token
    char *token = strtok(str, "-");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }
}

int main(void)
{
    exec_2();
    exec_3();
    exec_4();
    exec_5();
    exec_6();
    exec_7();
}
