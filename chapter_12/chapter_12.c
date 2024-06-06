#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MIN3(a, b, c) ((MIN(a, b) < (c)) ? MIN(a, b) : (c))
#define SHIFT(a, n) ((n > 0) ? (a << n) : (a >> -n))
#define IS_UPPER_CASE(x) (((x) >= 'A') && ((x) <= 'Z'))
#define IS_LOWER_CASE(x) (((x) >= 'a') && ((x) <= 'z'))
#define IS_ALPHABETIC(a) ((IS_LOWER_CASE(a)) || (IS_UPPER_CASE(a)))
#define IS_DIGIT(x) (((x) >= '0') && ((x) <= '9'))
#define IS_SPECIAL(a) (!((IS_LOWER_CASE(a)) || (IS_LOWER_CASE(a)) || (IS_DIGIT(a))))
#define ABSOLUTE_VALUE(a) ((a < 0) ? -a : a)

#define PRINT_EXEC(x) printf("-----------Exec %s ---------- \n", x)

void exec_3(void)
{
    PRINT_EXEC("3");
    printf("Min of %i and %i is %i \n", 5, 10, MIN(5, 10));
    printf("Min of %i and %i is %i \n", 5, 5, MIN(5, 5));
}

void exec_4(void)
{
    PRINT_EXEC("4");
    printf("Min of %i, %i and %i is %i \n", 5, 10, 15, MIN3(5, 10, 15));
    printf("Min of %i, %i and %i is %i \n", 15, 10, 5, MIN3(15, 10, 5));
    printf("Min of %i, %i and %i is %i \n", 5, 5, 5, MIN3(5, 5, 5));
}

void exec_5(void)
{
    PRINT_EXEC("5");
    unsigned int w1 = 0177777u, w2 = 0444u;
    printf("%o\t%o\n", SHIFT(w1, 5), w1 << 5);
    printf("%o\t%o\n", SHIFT(w1, -6), w1 >> 6);
    printf("%o\t%o\n", SHIFT(w2, 0), w2 >> 0);
    printf("%o\n", SHIFT(SHIFT(w1, -3), 3));
}

void exec_6(void)
{
    PRINT_EXEC("6");
    printf("%c is upper case %d\n", 'A', IS_UPPER_CASE('A'));
    printf("%c is upper case %d\n", 'a', IS_UPPER_CASE('a'));
}

void exec_7(void)
{
    PRINT_EXEC("7");
    printf("%c is alphabetic %d\n", 'A', IS_ALPHABETIC('A'));
    printf("%c is alphabetic %d\n", 'a', IS_ALPHABETIC('a'));
    printf("%c is alphabetic %d\n", '1', IS_ALPHABETIC('1'));
    printf("%c is alphabetic %d\n", ':', IS_ALPHABETIC(':'));
}

void exec_8(void)
{
    PRINT_EXEC("8");
    printf("%c is digit %d\n", 'A', IS_DIGIT('A'));
    printf("%c is digit %d\n", '1', IS_DIGIT('1'));
    printf("%c is special  %d\n", 'a', IS_SPECIAL('a'));
    printf("%c is special  %d\n", '1', IS_SPECIAL('1'));
    printf("%c is special  %d\n", ':', IS_SPECIAL(':'));
}

void exec_9(void)
{
    PRINT_EXEC("9");
    printf("%d is absolute value %d\n", ABSOLUTE_VALUE(10), 10);
    printf("%d is absolute value %d\n", ABSOLUTE_VALUE(-10), -10);
}

void exec_10(void)
{
    PRINT_EXEC("10");
    printf("Does not work \n");
}

void exec_11(void){
    PRINT_EXEC("11");
    printf("%c is alpha %d\n", 'a', isalpha('a'));
    printf("%c is digit %d\n", '1', isdigit('1'));
    printf("%c is upper %d\n", 'A', isupper('A'));
}

int main(void)
{
    exec_3();
    exec_4();
    exec_5();
    exec_6();
    exec_7();
    exec_8();
    exec_9();
    exec_10();
    exec_11();
}
