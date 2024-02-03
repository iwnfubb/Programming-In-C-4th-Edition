#include <stdio.h>
#include <math.h>

void exe_2(void)
{
  printf("Exe 2 ######## \n");
  for (int i = 1; i <= 10; i++)
  {
    printf("%d \t %d  \n", i, i * i);
  }
}

void exe_3(void)
{
  printf("Exe 3 ######## \n");
  for (int n = 5; n <= 50; n = n + 5)
  {
    printf("Triangular number iof %d is %d  \n", n, n * (n + 1) / 2);
  }
}

void exe_4(void)
{
  printf("Exe 4 ########\n");
  for (int number = 1; number <= 10; number++)
  {
    int result = 1;
    for (int i = 1; i <= number; i++)
    {
      result = result * i;
    }
    printf("Facatorial of %d is %d  \n", number, result);
  }
}

void exe_5(void)
{
  printf("Exe 5 ########\n");
  int n, two_to_the_n;
  printf("TABLE OF POWERS OF TWO\n\n");
  printf(" n 2 to the n\n");
  printf("--- ---------------\n");
  two_to_the_n = 1;
  for (n = 0; n <= 10; ++n)
  {
    printf("%2i %i\n", n, two_to_the_n);
    two_to_the_n *= 2;
  }
}

void exe_6(void)
{
  printf("Exe 6 ########\n");
  int n, triangularNumber;
  triangularNumber = 0;
  for (n = 1; n <= 200; n = n + 1)
    triangularNumber = triangularNumber + n;
  printf("The 200th triangular number is %-2i\n", triangularNumber);
}

void exe_7(void)
{
  printf("Exe 7 ########\n");
  int dollars, cents;
  for (int count = 1; count <= 2; ++count)
  {
    printf("Enter dollars: ");
    scanf("%i", &dollars);
    printf("Enter cents: ");
    scanf("%i", &cents);
    printf("$%i.%.2i\n\n", dollars, cents);
  }
}

void exe_8(void)
{
  printf("Exe 8 ########\n");
  int n, number, triangularNumber, counter, counter_max;
  printf("Enter how many number you want to calculate:");
  scanf("%i", &counter_max);

  for (counter = 1; counter <= counter_max; ++counter)
  {
    printf("What triangular number do you want? ");
    scanf("%i", &number);
    triangularNumber = 0;
    for (n = 1; n <= number; ++n)
      triangularNumber += n;
    printf("Triangular number %i is %i\n\n", number, triangularNumber);
  }
}

void exe_9(void)
{
  printf("Exe 9 ########\n");
  int n, number, triangularNumber, counter, counter_max;
  printf("Enter how many number you want to calculate:");
  scanf("%i", &counter_max);

  counter = 1;
  while (counter <= counter_max)
  {
    printf("What triangular number do you want? ");
    scanf("%i", &number);
    triangularNumber = 0;
    n = 1;
    while (n <= number)
    {
      triangularNumber += n;
      ++n;
    }
    printf("Triangular number %i is %i\n\n", number, triangularNumber);
    counter++;
  }
}

void exe_10(void)
{
  printf("Exe 10 ########\n");
  int number, right_digit;
  printf("Enter your number.\n");
  scanf("%i", &number);
  while (number != 0)
  {
    right_digit = number % 10;
    printf("%i", right_digit);
    number = number / 10;
  }
  printf("\n");
}

void exe_11(void)
{
  printf("Exe 11 ########\n");
  int number;
  printf("Enter your number.\n");
  scanf("%i", &number);
  int sum = 0;
  while (number != 0)
  {
    sum = sum + number % 10;
    number = number / 10;
  }
  printf("Sum: %d \n", sum);
}

int main(void)
{
  exe_2();
  exe_3();
  exe_4();
  exe_5();
  exe_6();
  exe_7();
  exe_8();
  exe_9();
  exe_10();
  exe_11();
  return 0;
}
