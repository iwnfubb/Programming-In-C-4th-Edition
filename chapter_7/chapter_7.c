//
//  chapter_7.c
//  C_Programming
//
//  Created by Duc Nguyen on 20.10.23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculateTriangularNumber(int n)
{
    int i, triangularNumber = 0;
    for (i = 1; i <= n; ++i)
        triangularNumber += i;
    return triangularNumber;
}

void exec_2(void)
{
    printf("Exec 2 ########\n");
    int number, triangularNumber, counter;
    for (counter = 1; counter <= 5; ++counter)
    {
        printf("What triangular number do you want? ");
        scanf("%i", &number);
        triangularNumber = calculateTriangularNumber(number);
        printf("Triangular number %i is %i\n\n", number, triangularNumber);
    }
}

float absoluteValue(float x)
{
    if (x < 0)
        x = -x;
    return x;
}

float squareRoot_3(float x, float epsilon)
{
    float guess = 1.0;

    while (absoluteValue(guess * guess - x) >= epsilon)
        guess = (x / guess + guess) / 2.0f;
    return guess;
}

void exec_3(void)
{
    printf("Exec 3 ########\n");
    float number = 10.;
    printf("Epsilon %f square root of %f is %f \n", 0.00001f, number, squareRoot_3(number, 0.00001f));
    printf("Epsilon %f square root of %f is %f \n", 0.0001f, number, squareRoot_3(number, 0.0001f));
    printf("Epsilon %f square root of %f is %f \n", 0.001f, number, squareRoot_3(number, 0.001f));
    printf("Epsilon %f square root of %f is %f \n", 0.01f, number, squareRoot_3(number, 0.01f));
    printf("Epsilon %f square root of %f is %f \n", 0.1f, number, squareRoot_3(number, 0.1f));
}

float squareRoot_4(float x, float epsilon)
{
    float guess = 1.0;

    while (absoluteValue(guess * guess - x) >= epsilon)
    {
        guess = (x / guess + guess) / 2.0f;
        printf("%f \n", guess);
    }
    return guess;
}

void exec_4(void)
{
    printf("Exec 4 ########\n");
    float number = 10.;
    printf("Epsilon %f square root of %f is %f \n", 0.00001f, number, squareRoot_4(number, .00001f));
    printf("Epsilon %f square root of %f is %f \n", 0.0001f, number, squareRoot_4(number, .0001f));
    printf("Epsilon %f square root of %f is %f \n", 0.001f, number, squareRoot_4(number, .001f));
    printf("Epsilon %f square root of %f is %f \n", 0.01f, number, squareRoot_4(number, .01f));
    printf("Epsilon %f square root of %f is %f \n", 0.1f, number, squareRoot_4(number, .1f));
}

float squareRoot_5(float x, float epsilon)
{
    float guess = 1.0;

    while (absoluteValue((guess * guess / x) - 1.f) >= epsilon)
    {
        guess = (x / guess + guess) / 2.0f;
        printf("%f \n", guess);
    }
    return guess;
}

void exec_5_6(void)
{
    printf("Exec 5 ########\n");
    float number = 10.;
    printf("Epsilon %f square root of %f is %f \n", 0.00001f, number, squareRoot_5(number, .00001f));
    printf("Epsilon %f square root of %f is %f \n", 0.0001f, number, squareRoot_5(number, .0001f));
    printf("Epsilon %f square root of %f is %f \n", 0.001f, number, squareRoot_5(number, .001f));
    printf("Epsilon %f square root of %f is %f \n", 0.01f, number, squareRoot_5(number, .01f));
    printf("Epsilon %f square root of %f is %f \n", 0.1f, number, squareRoot_5(number, .1f));
}

double absoluteValue_6(double x)
{
    if (x < 0)
        x = -x;
    return x;
}

double squareRoot_6(double x, double epsilon)
{
    double guess = 1.0;

    while (absoluteValue_6(guess * guess - x) >= epsilon)
    {
        guess = (x / guess + guess) / 2.0f;
        printf("%f \n", guess);
    }
    return guess;
}

void exec_6(void)
{
    printf("Exec 6 ########\n");
    double number = 10.;
    printf("Epsilon %f square root of %f is %f \n", 0.00001f, number, squareRoot_6(number, .00001f));
    printf("Epsilon %f square root of %f is %f \n", 0.0001f, number, squareRoot_6(number, .0001f));
    printf("Epsilon %f square root of %f is %f \n", 0.001f, number, squareRoot_6(number, .001f));
    printf("Epsilon %f square root of %f is %f \n", 0.01f, number, squareRoot_6(number, .01f));
    printf("Epsilon %f square root of %f is %f \n", 0.1f, number, squareRoot_6(number, .1f));
}

long int x_to_the_n(long int x, long int n)
{
    if (n == 1)
        return x;
    else
        return x * x_to_the_n(x, n - 1);
}

void exec_7(void)
{
    printf("Exec 7 ########\n");
    long int x = 2l;
    long int n = 50l;
    printf("%ld to the %ld is %ld \n", x, n, x_to_the_n(x, n));
}

void exec_8(void)
{
    printf("Exec 8 ########\n");
    int a, b, c;
    printf("Enter a: \n");
    scanf("%d", &a);
    printf("Enter b: \n");
    scanf("%d", &b);
    printf("Enter c: \n");
    scanf("%d", &c);
    double discriminant = squareRoot_3(b * b - 4 * a * c, .0001f);
    if (discriminant < 0)
        printf("Discriminal is less than 0. Roots os the equation are imaginary numbers.");

    double x1 = (-b + discriminant) / (2 * a);
    double x2 = (-b - discriminant) / (2 * a);
    printf("x1 = %f  x2 = %f", x1, x2);
}

int gcd(int u, int v)
{
    int temp;
    while (v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }
    return u;
}

void exec_9(void)
{
    printf("Exec 9 ########\n");
    int u, v;
    printf("Enter u: \n");
    scanf("%d", &u);
    printf("Enter v: \n");
    scanf("%d", &v);
    int lcm_result = u * v / gcd(u, v);
    printf("lcm of %d and %d is %d \n", u, v, lcm_result);
}

_Bool prime(int p)
{
    _Bool isPrime = 1;
    int rest = p % 2;
    if (p == 0 || p == 1)
        return 1;

    if (p > 2 && rest == 0)
        return 0;

    for (int d = 2; d < p && isPrime != 0; ++d)
    {

        if (d > 2 && d % 2 == 0)
            continue;

        if (p % d == 0)
            return 0;
    }
    return isPrime;
}

void exec_10(void)
{
    printf("Exec 10 ########\n");
    printf("Enter a number: \n");
    int p;
    scanf("%d", &p);
    if (prime(p) == 1)
        printf("%d is a prime number \n", p);
    else
        printf("%d is not a prime number \n", p);
}

int arraySum(int array[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += array[i];
    return sum;
}

int exec_11_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void exec_11(void)
{
    printf("Exec 11 ########\n");
    int length = 10;

    printf("Sum of array of 10 elements from 1 to 10 is %d \n", arraySum(exec_11_array, length));
}

int exe12_rows;
int exe12_cols;
void transposeMatrix(int array[exe12_rows][exe12_cols], int result[exe12_cols][exe12_rows])
{

    for (int i = 0; i < exe12_rows; i++)
        for (int j = 0; j < exe12_cols; j++)
            result[j][i] = array[i][j];
}

void exec_12(void)
{
    printf("Exec 11 ########\n");
    exe12_rows = 3;
    exe12_cols = 4;
    int array[exe12_rows][exe12_cols];
    memset(array, 0, exe12_rows * exe12_cols * sizeof(int));

    int result[exe12_cols][exe12_rows];
    memset(result, 0, exe12_rows * exe12_cols * sizeof(int));

    int counter = 0;
    for (int i = 0; i < exe12_rows; i++)
        for (int j = 0; j < exe12_cols; j++)
            array[i][j] = ++counter;

    printf("Original matrix ########\n");
    for (int i = 0; i < exe12_rows; i++)
    {
        for (int j = 0; j < exe12_cols; j++)
            printf("%d   ", array[i][j]);
        printf("\n");
    }

    transposeMatrix(array, result);

    printf("Transpose matrix ########\n");
    for (int i = 0; i < exe12_cols; i++)
    {
        for (int j = 0; j < exe12_rows; j++)
            printf("%d   ", result[i][j]);
        printf("\n");
    }
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int exec_13_array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                         44, -3, -9, 12, 17, 22, 6, 11};
_Bool exec13_ascending = 1;

void sort(int a[], int n, _Bool ascending)
{
    int i, j;
    for (i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
        {
            if (ascending && a[i] > a[j])
                swap(a, i, j);
            if (!ascending && a[i] < a[j])
                swap(a, i, j);
        }
}

void exec_13(void)
{

    printf("The array before the sort:\n");
    for (int i = 0; i < 16; ++i)
        printf("%i ", exec_13_array[i]);

    sort(exec_13_array, 16, exec13_ascending);
    printf("\n\nThe array after the sort ascending:\n");

    for (int i = 0; i < 16; ++i)
        printf("%i ", exec_13_array[i]);
    printf("\n");

    exec13_ascending = 0;
    sort(exec_13_array, 16, exec13_ascending);
    printf("\n\nThe array after the sort descending:\n");

    for (int i = 0; i < 16; ++i)
        printf("%i ", exec_13_array[i]);
    printf("\n");
}

void scalarMultiply(int nRows, int nCols,
                    int** matrix,
                    int scalar)
{
    int row, column;
    for (row = 0; row < nRows; ++row)
        for (column = 0; column < nCols; ++column)
            matrix[row][column] *= scalar;
}
void displayMatrix(int nRows, int nCols, int** matrix)
{
    int row, column;
    for (row = 0; row < nRows; ++row)
    {
        for (column = 0; column < nCols; ++column)
            printf("%5i", matrix[row][column]);
        printf("\n");
    }
}

int exec_15_16_rows, exec_15_16_cols;
int** exec_15_16_matrix = NULL;
void input_mechanism_exec_15(void)
{
    int num;
    if ( ! exec_15_16_matrix ){
        exec_15_16_matrix = (int**)malloc(exec_15_16_rows * sizeof(int*));
        for (int i = 0; i < exec_15_16_rows; i++)
            exec_15_16_matrix[i] = (int*)malloc( exec_15_16_cols* sizeof(int));
    }
    for (int row = 0; row < exec_15_16_rows; ++row)
    {
        for (int column = 0; column < exec_15_16_cols; ++column)
        {
            printf("Please enter number for matrix[%d][%d] \n", row, column);
            scanf("%d", &num);
            exec_15_16_matrix[row][column] = num;
        }
    }
}

void input_mechanism_exec_16(void)
{
    int num;
    if ( ! exec_15_16_matrix ){
        exec_15_16_matrix = (int**)malloc(exec_15_16_rows * sizeof(int*));
        for (int i = 0; i < exec_15_16_rows; i++)
            exec_15_16_matrix[i] = (int*)malloc( exec_15_16_cols* sizeof(int));
    }
    for (int row = 0; row < exec_15_16_rows; ++row)
    {
        for (int column = 0; column < exec_15_16_cols; ++column)
        {
            exec_15_16_matrix[row][column] = 0;
        }
    }
    
    for (int row = 0; row < exec_15_16_rows; ++row)
    {
        for (int column = 0; column < exec_15_16_cols; ++column)
        {
            printf("Please enter number for matrix[%d][%d] \n", row, column);
            scanf("%d", &num);
            if (num == 0 )
                break;
            exec_15_16_matrix[row][column] = num;
        }
    }

    
}

void exec_15(void)
{
    printf("Exec 15 ########\n");
    printf("Enter rows ########\n");
    scanf("%d", &exec_15_16_rows);
    printf("Enter collumn ########\n");
    scanf("%d", &exec_15_16_cols);
    input_mechanism_exec_15();
    printf("Original matrix:\n");
    displayMatrix(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix);
    scalarMultiply(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix, 2);
    printf("\nMultiplied by 2:\n");
    displayMatrix(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix);
    scalarMultiply(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix, -1);
    printf("\nThen multiplied by -1:\n");
    displayMatrix(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix);
}

void exec_16(void)
{
    printf("Exec 16 ########\n");
    printf("Enter rows ########\n");
    scanf("%d", &exec_15_16_rows);
    printf("Enter collumn ########\n");
    scanf("%d", &exec_15_16_cols);
    input_mechanism_exec_16();
    printf("Original matrix:\n");
    displayMatrix(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix);
    scalarMultiply(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix, 2);
    printf("\nMultiplied by 2:\n");
    displayMatrix(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix);
    scalarMultiply(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix, -1);
    printf("\nThen multiplied by -1:\n");
    displayMatrix(exec_15_16_rows, exec_15_16_cols, exec_15_16_matrix);
}
 


int main(void)
{
    // exec_2();
    // exec_3();
    // exec_4();
    // exec_5();
    // exec_6();
    // exec_7();
    // exec_8();
    // exec_9();
    // exec_10();
    // exec_11();
    // exec_12();
    exec_13();
    // exec_15();
    // exec_16();
}
