#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool alphabetic_and_number(const char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'')
        return true;
    else if (c >= 48 && c <= 57) // ANSI table for 0-9
        return true;
    else
        return false;
}

void readLine(char buffer[])
{
    char character;
    int i = 0;
    do
    {
        character = (char)getchar();
        buffer[i] = character;
        ++i;
    } while (character != '\n');
    buffer[i - 1] = '\0';
}

/* Function to count the number of words in a string */
int countWords(const char string[])
{
    int i, wordCount = 0;
    bool lookingForWord = true, alphabetic_and_number(const char c);
    for (i = 0; string[i] != '\0'; ++i)
        if (alphabetic_and_number(string[i]))
        {
            if (lookingForWord)
            {
                ++wordCount;
                lookingForWord = false;
            }
        }
        else
            lookingForWord = true;
    return wordCount;
}

void exec_3(void)
{
    printf("####### exec 3 ######## \n");
    printf("Enter number and char to count \n");
    char buffer[81];
    readLine(buffer);
    printf("Words and number count %d \n", countWords(buffer));
}

int char_array_length(char string[])
{
    int i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}

void substring(char source[], int start, int count, char result[])
{
    if (start < 0)
    {
        printf("Start index can not be negative");
        return;
    }
    if (start + count > char_array_length(source))
    {
        printf("Start index + count is greater than length of source");
        return;
    }
    int index = 0;
    for (int i = start; i < start + count; i++)
    {
        result[index] = source[i];
        index++;
    }
}

void exec_4(void)
{
    printf("######## exec 4 #######\n");
    char *string = "This is a string";
    char result[81];
    substring(string, 2, 4, result);
    printf("substring from 2 with count 4 of string \"%s\" is \"%s\" ", string, result);
}

int findString(char string[], char sub_string[])
{
    int index = 0;

    while (string[index] != '\0')
    {
        int sub_index = 0;
        bool stop = false;
        int start_index = index;
        while (sub_string[sub_index] != '\0' && !stop)
        {
            if (sub_string[sub_index] == string[index])
            {
                sub_index++;
                index++;
            }
            else
                stop = true;
            if (sub_string[sub_index] == '\0')
                return start_index;
        }
        index++;
    }
    return -1;
}

void exec_5_6(void)
{
    printf("########## exec 5 ######### \n");
    char *string = "This is a test string";
    char *sub_string = "test";
    char *not_sub_string = "not";
    printf("Index from \"%s\" in \"%s\" is %d\n", sub_string, string, findString(string, sub_string));
    printf("Index from \"%s\" in \"%s\" is %d\n", not_sub_string, string, findString(string, not_sub_string));
}

int lengthString(char string[])
{
    int index = 0;
    ;
    while (string[index] != '\0')
        index++;
    return index;
}

char *removeString(char *string, int start, int length)
{
    char *new_string = malloc(80);
    int string_length = lengthString(string);
    if (start + length > string_length)
    {
        for (int i = 0; i < start; i++)
            new_string[i] = string[i];

        new_string[start] = '\0';
        return new_string;
    }
    for (int i = 0; i < start; i++)
    {
        new_string[i] = string[i];
    }

    while (string[start + length - 1] != '\0')
    {
        new_string[start] = string[start + length];
        start++;
    }
    new_string[start - 1] = '\0';
    return new_string;
}

void exec_6(void)
{
    printf("########## exec 6 ######### \n");
    char *string = "The wrong son";
    printf("This is the result: %s", removeString(string, 4, 6));
}

char *insertString(char *string, char *text, int position)
{
    char *new_string = malloc(80);
    int index = 0, source_string_index = 0;
    for (index = 0; index < position; index++)
    {
        new_string[index] = string[index];
        source_string_index++;
    }

    int text_index = 0;
    while (text[text_index] != '\0')
    {
        new_string[index] = text[text_index];
        index++;
        text_index++;
    }
    while (string[source_string_index] != '\0')
    {
        new_string[index] = string[source_string_index];
        index++;
        source_string_index++;
    }
    new_string[index + 1] = '\0';
    return new_string;
}

void exec_7(void)
{
    printf("########## exec 7 ######### \n");
    char *string = "The son";
    printf("This is the result: %s", insertString(string, " correct", 3));
}

char *replaceString(char *string, char *s1, char *s2)
{
    int index = findString(string, s1);
    if (index == -1)
    {
        printf("String %s not found", s1);
        return "\0";
    }
    else
    {
        string = removeString(string, index, lengthString(s1));
        string = insertString(string, s2, index);
    }
    return string;
}

char *replaceAllString(char *string, char *s1, char *s2)
{
    int index = findString(string, s1);
    if (index == -1)
    {
        printf("String %s not found", s1);
        return "\0";
    }
    else
    {
        while (findString(string, s1) != -1)
        {
            index = findString(string, s1);
            string = removeString(string, index, lengthString(s1));
            string = insertString(string, s2, index);
        }
    }
    return string;
}

void exec_8(void)
{
    printf("########## exec 8 ######### \n");
    char *string = "The son is numer 1 and always numer 1";
    printf("This is the result: %s\n", replaceString(string, "1", "one"));
    printf("This is the result: %s\n", replaceString(string, "1", ""));
}

void exec_9(void)
{
    printf("########## exec 9 ######### \n");
    char *string = "The son is numer 1 and always numer 1";
    printf("This is the result: %s\n", replaceAllString(string, "1", "one"));
    printf("This is the result: %s\n", replaceAllString(string, "1", ""));
}

struct linkedListEntry
{
    char word[15];
    char definition[50];
};

int compareStrings(const char s1[], const char s2[])
{
    int i = 0, result = 0;

    while (s1[i] == s2[i] && s1[i] != '\0')
        ++i;
    if (s1[i] == '\0' && s2[i] == '\0')
        result = 0;
    else
        result = s1[i] - s2[i];
    return result;
}

void sort(struct linkedListEntry dictionary[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (compareStrings(dictionary[i].word, dictionary[j].word) < 0)
            {
                struct linkedListEntry temp = dictionary[i];
                dictionary[i] = dictionary[j];
                dictionary[j] = temp;
            }
        }
    }
}

void exec_10(void)
{
    printf("########## exec 10 ######### \n");
    struct linkedListEntry dictionary[100] = {
        {"aardvark", "a burrowing African mammal"},
        {"abyss", "a bottomless pit"},
        {"addle", "to become confused"},
        {"acumen", "mentally sharp; keen"},
        {"ahoy", "a nautical call of greeting"},
        {"aerie", "a high nest"},
        {"aigrette", "an ornamental cluster of feathers"},
        {"affix", "to append; attach"},
        {"ajar", "partially opened"},
        {"agar", "a jelly made from seaweed"},
    };
    int length = 10;
    sort(dictionary, length);
    for (int i = 0; i < length; i++)
    {
        printf("%s : %s \n", dictionary[i].word, dictionary[i].definition);
    }
}

int strToInt(const char string[])
{
    int i, startIndex = 0, intValue, result = 0;
    bool isNegative = false;
    if (string[0] == '-')
    {
        isNegative = true;
        startIndex = 1;
    }

    for (i = startIndex; string[i] >= '0' && string[i] <= '9'; ++i)
    {
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }
    if (isNegative)
        return -result;
    else
        return result;
}

void exec_11(void)
{
    printf("########## exec 11 ######### \n");
    printf("%d", strToInt("-112") + 12);
}

double strToFloat(const char string[])
{
    double result = 0, floatValue;
    int i, startIndex = 0, intValue;
    bool isNegative = false;
    if (string[0] == '-')
    {
        isNegative = true;
        startIndex = 1;
    }

    for (i = startIndex; string[i] >= '0' && string[i] <= '9'; ++i)
    {
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }

    startIndex = i + 1;

    for (i = startIndex; string[i] >= '0' && string[i] <= '9'; ++i)
    {
        floatValue = string[i] - '0';
        double temp = floatValue / (pow(10, i - startIndex + 1));
        result = result + temp;
    }
    if (isNegative)
        return -result;
    else
        return result;
}

void exec_12(void)
{
    printf("########## exec 12 ######### \n");
    printf("%f", strToFloat("-12.345"));
}

char *uppercase(char *text)
{
    char *result = malloc(80);
    int index = 0;
    while (text[index] != '\0')
    {
        result[index] = text[index] - 'a' + 'A';
        index++;
    }
    return result;
}

void exec_13(void)
{
    printf("########## exec 13 ######### \n");
    printf("%s", uppercase("qweasdqweasdqwe"));
}

char *concat(char *s1, char *s2)
{
    char *result = malloc(80);
    int index = 0, temp = 0;
    while (s1[temp] != '\0')
    {
        result[index] = s1[temp];
        temp++;
        index++;
    }
    temp = 0;
    while (s2[temp] != '\0')
    {
        result[index] = s2[temp];
        temp++;
        index++;
    }
    result[index] = '\0';
    return result;
}

char *intToStr(int number)
{
    if (number < 10)
    {
        switch (number)
        {
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 0:
            return "0";

        default:
            break;
        }
    }
    else{
        char* temp1 = intToStr(number / 10);
        char* temp2 = intToStr(number % 10);
        return concat(intToStr(number / 10), intToStr(number % 10));
    }
}

void exec_14(void)
{
    printf("########## exec 14 ######### \n");
    printf("%s", intToStr(12345));
}

int main(void)
{
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
    // exec_13();
    exec_14();
}
