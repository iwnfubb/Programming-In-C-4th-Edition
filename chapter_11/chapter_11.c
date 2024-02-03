#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int int_size(void)
{
    int count = 0;
    unsigned number = ~0;
    do
    {
        count++;
        number = number >> 1;
    } while (number != 0);
    return count;
}

void exec_2(void)
{
    /**
     * Idea: we create a random number which starts with digit 1. Then shift the number to 1 digits to the right .
     * If the result is a positive number then 0 is replaced to most left digit, therefore that is a logical shift.
     * Otherwise it is a arithmetic shift.
     */
    int number = 0xFFFFFFFFu;
    printf("####### exec 2 #######\n");
    printf("Size of int : %i\n", int_size());
    int result = number >> 1;
    printf("Int 0x%08x \n", result);
    if (result > 0)
    {
        printf("Logical shift.\n");
    }
    else
    {
        printf("Arithmetic shift.\n");
    }
    printf("\n\n");
}

void exec_3(void)
{
    printf("####### exec 3 #######\n");
    printf("int_size() %i Bytes\n", int_size() / 8);
    printf("\n\n");
}

unsigned int rotate(unsigned int value, int n)
{
    unsigned int result, bits;
    int size_of_int = int_size();
    // scale down the shift count to a defined range
    if (n > 0)
        n = n % size_of_int;
    else
        n = -(-n % size_of_int);
    if (n == 0)
        result = value;
    else if (n > 0)
    { // leftrotate
        bits = value >> (size_of_int - n);
        result = value << n | bits;
    }
    else
    { // right rotate
        n = -n;
        bits = value << (size_of_int - n);
        result = value >> n | bits;
    }
    return result;
}

void exec_4(void)
{
    printf("####### exec 4 #######\n");
    unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;
    unsigned int rotate(unsigned int value, int n);
    printf("Rotation of 0x%x with 8 bits to the right is 0x%x\n", w1, rotate(w1, 8));
    printf("Rotation of 0x%x with 16 bits to the left is 0x%x\n", w1, rotate(w1, -16));
    printf("Rotation of 0x%x with 4 bits to the right is 0x%x\n", w2, rotate(w2, 4));
    printf("Rotation of 0x%x with 2 bits to the left is 0x%x\n", w2, rotate(w2, -2));
    printf("Rotation of 0x%x with 0 bits is 0x%x\n", w1, rotate(w1, 0));
    printf("Rotation of 0x%x with 44 bits to the right is 0x%x\n", w1, rotate(w1, 44));
    printf("\n\n");
}

bool bit_test(unsigned int number, int n)
{
    /**
     * Idea: first we need to get the size of n
     * Then we just need to shift the number to the right and merge with the number with the pattern n
     * until we can get a merged number is equal n
     *
     * 0x12345678
     * 0x00000056
     * Merge
     * 0x00000050 not equal 0x00000056
     *
     * shift the number 0x12345678 until we got
     * 0x00123456
     * 0x00000056
     * Merge
     * 0x00000056 is equal 56 then the pattern 0x00000056 is found
     */
    int size_of_n = 0;
    int bits_of_int = int_size();
    int temp = n;

    do
    {
        size_of_n++;
        temp = temp >> 1;
    } while (temp != 0);

    for (int i = 0; i < bits_of_int - size_of_n + 1; i++)
    {
        int merge_int = number & n;
        if (merge_int == n)
        {
            return true;
        }
        else
        {
            number = number >> 1;
        }
    }
    return false;
}

void exec_5(void)
{
    unsigned int number = 0xabcdef00u;
    printf("####### exec 5 #######\n");
    printf("%x contains pattern %x :  %x \n", number, 0xf00, bit_test(number, 0xf00));
    printf("%x contains pattern %x :  %x \n", number, 0xabc, bit_test(number, 0xabc));
    printf("%x contains pattern %x :  %x \n", number, 0xdef, bit_test(number, 0xdef));
    printf("%x contains pattern %x :  %x \n", number, 0xabf, bit_test(number, 0xabf));
    printf("\n\n");
}

int bitpath_search(unsigned int source, unsigned int pattern, int n)
{
    /**
     * Base on
     *
     */
    int size_of_int = int_size();
    for (int i = 0; i < size_of_int - n; i++)
    {
        unsigned int double_check = source << i;
        double_check = double_check >> (size_of_int - n);
        if (double_check == pattern)
        {
            return i;
        }
    }
    return -1;
}

void exe_6(void)
{
    printf("####### exec 6 #######\n");
    printf("%x contains %x at postion %i \n", 0xe1f4, 0x5, bitpath_search(0xe1f4, 0x5, 3));
    printf("%x contains %x at position %i \n", 0xe1f4, 0xaf, bitpath_search(0xe1f4, 0xaf, 3));
    printf("%x contains %x at position %i \n", 0xe1f4, 0x4, bitpath_search(0xe1f4, 0x4, 3));
    printf("\n\n");
}

unsigned int bitpat_get(unsigned int number, int start, int count)
{
    /**
     * Idea: to get the pattern at postion "start" and with "size"
     * we just shift the number to "start" times to the left
     * and then (size of int - size) to the right
     * 0xFF34FFFF and we want to get the pattern from postion 4 with size 12 bits
     * 0xFF34FFFF shift left 4 bits -> 0xF34FFFF0
     * then (32 - 12) bits to the right -> 0x00000F34 = 0xF34
     */
    int bits_of_int = int_size();
    number = number << start;
    return number >> (bits_of_int - count);
}

void exec_7(void)
{
    printf("####### exec 7 #######\n");
    unsigned int number = 0x12345678;
    printf("Pattern from index %i with size %i from %x is %x\n", 3, 4, number, bitpat_get(number, 3, 4));
    printf("\n\n");
}

void bitpat_set(unsigned int *number, unsigned int pattern, int start_index, int size)
{
    /**
     * Idea: We spilt the number into 3 parts
     * 1.Part : from 0 to start_index
     * 2.Part : from start_index to start_index + size (This part will be replaced with the pattern)
     * 3.Part : The rest
     *
     * Ex: 0x12345678 replace at postion 8 with 8 ditgit from pattern 0x55
     * 1. Part: 0x12000000
     * 2. Part: 0x00340000 replace with 0x00550000
     * 3. Part: 0x00005678
     * Then sum of 3 parts is the result after the number 0x12345678 is replace with 0x55 at position 8 with size 8
     *
     */
    int bits_of_int = int_size();
    printf("Size of int : %d\n", bits_of_int);

    unsigned int first_part = *number;

    if (start_index == 0)
    {
        // We can only shift from 0 - 31 bits so if the start_index is 0 then we just asign the first part to 0.
        first_part = 0;
    }
    else
    {
        first_part = *number >> (bits_of_int - start_index);
        printf("first part: 0x%08x\n\n", first_part);
        first_part = first_part << (bits_of_int - start_index);
        printf("first part: 0x%08x\n\n", first_part);
    }

    unsigned int second_part = pattern << (bits_of_int - start_index - size);
    printf("second part: 0x%08x\n\n", second_part);

    unsigned int third_part = *number << (start_index + size);
    third_part = third_part >> (start_index + size);
    printf("third part: 0x%08x\n\n", third_part);

    *number = first_part + second_part + third_part;
}

void exec_8(void)
{
    printf("####### exec 8 #######\n");
    unsigned number = 0x12345678u;
    unsigned int pattern = 0x55u;
    printf("Old number: 0x%08x\n", number);
    bitpat_set(&number, pattern, 0, 8);
    printf("New number: 0x%08x\n", number);

    number = 0x12345678u;
    pattern = 0x55u;
    printf("Old number: 0x%08x\n", number);
    bitpat_set(&number, pattern, 8, 8);
    printf("New number: 0x%08x\n", number);
}

int main(void)
{
    exec_2();
    exec_3();
    exec_4();
    exec_5();
    exe_6();
    exec_7();
    exec_8();
}
