
#include <stdio.h>
#include <math.h>

void exe_4(void)
{
  printf("Exe 4 ########\n");
  printf("Convert 27 F to C \n");
  int F = 27;
  float C = (F - 32) / 1.8f;
  printf("27F = %f \n", C);
}

void exe_6(void)
{
  printf("Exe 6 ########\n");
  float x = 2.55;
  float result = 3 * pow(x, 3) - 5 * pow(x, 2) + 6;
  printf("Evaluate: 3x^3 - 5x^2 + 6 = %f \n", result);
}

void exe_7(void)
{
  printf("Exe 7 ########\n");
  double result = 3.31e-8 * 2.01e-7 / (7.16e-6 + 2.01e-8);
  printf("Evaluate: 3x^3 - 5x^2 + 6 = %lf \n", result);
}

void exe_8(int number1, int number2)
{
  printf("Exe 8 ########\n");
  printf("next largest even multiple of %d from %d is %d \n", number1, number2, number1 + number2 - number1 % number2);
}

int main(void)
{
  exe_4();
  exe_6();
  exe_7();
  exe_8(256, 7);
  exe_8(356, 7);
  exe_8(12258, 23);
  exe_8(996, 4);
  return 0;
}
