#include <string.h>
#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MIN3(a, b, c) ((MIN(a, b) < (c)) ? MIN(a, b) : (c))



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

int main(void)
{
    exec_3();
    exec_4();
}
