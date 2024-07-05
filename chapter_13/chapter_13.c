#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define PRINT_EXEC(x) printf("-----------Exec %s ---------- \n", x)

#define typename(x) _Generic((x),        /* Get the name of a type */             \
                                                                                  \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")




typedef  int (*FunctionPtr) ( void);

int test (void){
  return 1;
}

enum month { January, February, March, April, May, June, July, August, September, October, November, December };

char *monthName( enum month aMonth)
{
  char *string[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
  return string[aMonth];
}

void exec_1(void){
  PRINT_EXEC("1");
  FunctionPtr test_function = &test;
  printf("%d \n", test_function());
}

void exec_2(void)
{
    PRINT_EXEC("2");
    enum month aMonth = May;
    printf("%s \n", monthName (aMonth) );
    aMonth = January;
    printf("%s \n", monthName (aMonth) );
}

void exec_3(void){
  PRINT_EXEC("3");
  float f = 1.00;
  short int i = 100;
  long int l = 500L;
  double d = 15.00;
  printf ("Type of f + i is %s\n", typename( f + i ));
  printf ("Type of l / d is %s \n", typename( l / d  ));
  printf ("Type of i / l + f  is %s \n", typename( i / l + f ));
  printf ("Type of l * i  is %s \n", typename( l * i ));
  printf ("Type of f / 2  is %s \n", typename( f / 2 ));
  printf ("Type of i / ( d + f )  is %s \n", typename( i / ( d +f ) ));
  printf ("Type of l / ( i * 2.0 ) is %s \n", typename( l / (i * 2.0) ));
  printf ("Type of l + i / (double) l  is %s \n", typename( l + i / (double) l));
}


int main(void)
{
    exec_1();
    exec_2();
    exec_3();
}
