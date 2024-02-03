#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct linkedListEntry
{
    int value;
    struct linkedListEntry *next;
};

struct doubleLinkedListEntry
{
    int value;
    struct doubleLinkedListEntry *previous;
    struct doubleLinkedListEntry *next;
};

struct doubleLinkedListEntry *createNewDoubleLinkList(void)
{
    struct doubleLinkedListEntry *n1 = (struct doubleLinkedListEntry *)malloc(sizeof(struct doubleLinkedListEntry));
    struct doubleLinkedListEntry *n2 = (struct doubleLinkedListEntry *)malloc(sizeof(struct doubleLinkedListEntry));
    struct doubleLinkedListEntry *n3 = (struct doubleLinkedListEntry *)malloc(sizeof(struct doubleLinkedListEntry));

    n1->value = 100;
    n1->previous = NULL;
    n1->next = n2;

    n2->value = 200;
    n2->previous = n1;
    n2->next = n3;

    n3->value = 300;
    n3->previous = n2;
    n3->next = NULL;
    return n1;
}

struct doubleLinkedListEntry *inserDoubleLinkedListEntry(int value, struct doubleLinkedListEntry **double_linked_list)
{
    struct doubleLinkedListEntry *new_entry = (struct doubleLinkedListEntry *)malloc(sizeof(struct doubleLinkedListEntry));
    new_entry->value = value;
    new_entry->previous = NULL;
    new_entry->next = NULL;
    // Go to the last element
    struct doubleLinkedListEntry *current = *double_linked_list;
    if (current == NULL)
    {
        *double_linked_list = new_entry;
        return new_entry;
    }

    while (current->next != NULL)
        current = current->next;
    current->next = new_entry;
    new_entry->previous = current;
    return new_entry;
}

void print_double_linked_list(struct doubleLinkedListEntry *double_linked_list)
{
    struct doubleLinkedListEntry *current = double_linked_list;
    printf("[");
    while (current != NULL)
    {
        printf("  %d  ", current->value);
        current = current->next;
    }
    printf("]\n");
}

struct doubleLinkedListEntry *removeDoubleEntry(int value, struct doubleLinkedListEntry **double_linked_list)
{
    struct doubleLinkedListEntry *current = *double_linked_list;
    bool found = false;

    if (current == NULL)
    {
        // List is empty
        return *double_linked_list;
    }

    while (current != NULL)
    {
        if (current->value == value)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found)
    {
        if (current->previous == NULL)
        {
            // First element need to removed
            if (current->next != NULL)
                current->next->previous = NULL;
            *double_linked_list = current->next;
            return *double_linked_list;
        }
        else if (current->next == NULL)
        {
            current->previous->next = NULL;
            return *double_linked_list;
        }
        else
        {
            current->previous->next = current->next;
            current->next->previous = current->previous;
            return *double_linked_list;
        }
    }
    else
    {
        // Element not found.
        printf("No element fonud \n");
        return *double_linked_list;
    }
}

struct linkedListEntry *createNewLinkList(void)
{
    struct linkedListEntry *n1 = (struct linkedListEntry *)malloc(sizeof(struct linkedListEntry));
    struct linkedListEntry *n2 = (struct linkedListEntry *)malloc(sizeof(struct linkedListEntry));
    struct linkedListEntry *n3 = (struct linkedListEntry *)malloc(sizeof(struct linkedListEntry));

    n1->value = 100;
    n1->next = n2;

    n2->value = 200;
    n2->next = n3;

    n3->value = 300;
    n3->next = NULL;
    return n1;
}

struct linkedListEntry *insertEntry(int value, struct linkedListEntry **linked_list)
{
    struct linkedListEntry *new_entry = (struct linkedListEntry *)malloc(sizeof(struct linkedListEntry));
    new_entry->value = value;
    new_entry->next = NULL;
    // Go to the last element
    struct linkedListEntry *current = *linked_list;
    if (current == NULL)
    {
        *linked_list = new_entry;
        return new_entry;
    }

    while (current->next != NULL)
        current = current->next;
    current->next = new_entry;
    return new_entry;
}

void print_linked_list(struct linkedListEntry *linked_list)
{
    struct linkedListEntry *current = linked_list;
    printf("[");
    while (current != NULL)
    {
        printf("  %d  ", current->value);
        current = current->next;
    }
    printf("]\n");
}

struct linkedListEntry *removeEntry(int value, struct linkedListEntry **linkedlist)
{
    struct linkedListEntry *current = *linkedlist;
    struct linkedListEntry *previous = *linkedlist;
    bool found = false;

    if (current == NULL)
    {
        // List is empty
        return *linkedlist;
    }

    while (current != NULL)
    {
        if (current->value == value)
        {
            found = true;
            break;
        }
        previous = current;
        current = current->next;
    }
    if (found)
    {
        if (current == previous)
        {
            // First element need to removed
            *linkedlist = current->next;
            return *linkedlist;
        }
        else
        {
            previous->next = current->next;
            return *linkedlist;
        }
    }
    else
    {
        // Element not found.
        printf("No element fonud \n");
        return *linkedlist;
    }
}

void exec_2(void)
{
    printf("######## exec 2 ########\n");
    struct linkedListEntry *linked_list = createNewLinkList();
    printf("Original list \n");
    print_linked_list(linked_list);
    printf("Add new element  \n");
    struct linkedListEntry *current_pointer = insertEntry(400, &linked_list);
    print_linked_list(linked_list);
    printf("Add new element \n");
    current_pointer = insertEntry(500, &current_pointer);
    print_linked_list(linked_list);
}

void exec_3(void)
{
    printf("######## exec 3 ########\n");
    struct linkedListEntry *linked_list = NULL;
    printf("Original list \n");
    print_linked_list(linked_list);
    printf("Add new element  \n");
    struct linkedListEntry *current_pointer = insertEntry(400, &linked_list);
    print_linked_list(linked_list);
    printf("Add new element \n");
    current_pointer = insertEntry(500, &current_pointer);
    print_linked_list(linked_list);
}

void exec_4(void)
{
    printf("######## exec 4 ########\n");
    struct linkedListEntry *linkedList = createNewLinkList();
    printf("Original list : \n");
    print_linked_list(linkedList);
    printf("Remove first Element\n");
    linkedList = removeEntry(100, &linkedList);
    print_linked_list(linkedList);

    printf("Restore list\n");
    linkedList = createNewLinkList();
    printf("Original list : \n");
    print_linked_list(linkedList);
    printf("Remove 2. Element\n");
    linkedList = removeEntry(200, &linkedList);
    print_linked_list(linkedList);

    printf("Restore list\n");
    linkedList = createNewLinkList();
    printf("Original list : \n");
    print_linked_list(linkedList);
    printf("Remove last Element\n");
    linkedList = removeEntry(300, &linkedList);
    print_linked_list(linkedList);

    printf("Restore list\n");
    linkedList = createNewLinkList();
    printf("Original list : \n");
    print_linked_list(linkedList);
    printf("Remove 1. Element\n");
    linkedList = removeEntry(100, &linkedList);
    print_linked_list(linkedList);
    printf("Remove 1. Element\n");
    linkedList = removeEntry(200, &linkedList);
    print_linked_list(linkedList);
    printf("Remove 1. Element\n");
    linkedList = removeEntry(300, &linkedList);
    print_linked_list(linkedList);
    printf("Remove Element from emplty list \n");
    linkedList = removeEntry(0, &linkedList);
    print_linked_list(linkedList);

    printf("Restore list\n");
    linkedList = createNewLinkList();
    printf("Original list : \n");
    print_linked_list(linkedList);
    printf("Remove last Element\n");
    linkedList = removeEntry(300, &linkedList);
    print_linked_list(linkedList);
    printf("Remove last Element\n");
    linkedList = removeEntry(200, &linkedList);
    print_linked_list(linkedList);
    printf("Remove last Element\n");
    linkedList = removeEntry(100, &linkedList);
    print_linked_list(linkedList);
    printf("Remove Element from emplty list \n");
    linkedList = removeEntry(0, &linkedList);
    print_linked_list(linkedList);
}

void exec_5_6(void)
{
    printf("######## exec 5 ########\n");
    struct doubleLinkedListEntry *doubleLinkedList = createNewDoubleLinkList();
    printf("Original list : \n");
    print_double_linked_list(doubleLinkedList);
    printf("Remove first Element\n");
    doubleLinkedList = removeDoubleEntry(100, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);

    printf("Restore list\n");
    doubleLinkedList = createNewDoubleLinkList();
    printf("Original list : \n");
    print_double_linked_list(doubleLinkedList);
    printf("Remove 2. Element\n");
    doubleLinkedList = removeDoubleEntry(200, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);

    printf("Restore list\n");
    doubleLinkedList = createNewDoubleLinkList();
    printf("Original list : \n");
    print_double_linked_list(doubleLinkedList);
    printf("Remove last Element\n");
    doubleLinkedList = removeDoubleEntry(300, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);

    printf("Restore list\n");
    doubleLinkedList = createNewDoubleLinkList();
    printf("Original list : \n");
    print_double_linked_list(doubleLinkedList);
    printf("Remove 1. Element\n");
    doubleLinkedList = removeDoubleEntry(100, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);
    printf("Remove 1. Element\n");
    doubleLinkedList = removeDoubleEntry(200, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);
    printf("Remove 1. Element\n");
    doubleLinkedList = removeDoubleEntry(300, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);
    printf("Remove Element from emplty list \n");
    doubleLinkedList = removeDoubleEntry(0, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);

    printf("Restore list\n");
    doubleLinkedList = createNewDoubleLinkList();
    printf("Original list : \n");
    print_double_linked_list(doubleLinkedList);
    printf("Remove last Element\n");
    doubleLinkedList = removeDoubleEntry(300, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);
    printf("Remove last Element\n");
    doubleLinkedList = removeDoubleEntry(200, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);
    printf("Remove last Element\n");
    doubleLinkedList = removeDoubleEntry(100, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);
    printf("Remove Element from emplty list \n");
    doubleLinkedList = removeDoubleEntry(0, &doubleLinkedList);
    print_double_linked_list(doubleLinkedList);
}

void swap(int *array, int i, int j)
{
    int temp = *(array + i);
    *(array + i) = *(array + j);
    *(array + j) = temp;
}

int exec_13_array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                         44, -3, -9, 12, 17, 22, 6, 11};
bool exec13_ascending = true;

void sort(int *a, int n, bool ascending)
{
    int i, j;
    for (i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
        {
            if (ascending && *(a + i) > *(a + j))
                swap(a, i, j);
            if (!ascending && (*(a + i) < *(a + j)))
                swap(a, i, j);
        }
}

void exec_7(void)
{

    printf("The array before the sort:\n");
    for (int i = 0; i < 16; ++i)
        printf("%i ", exec_13_array[i]);

    sort(exec_13_array, 16, exec13_ascending);
    printf("\n\nThe array after the sort ascending:\n");

    for (int i = 0; i < 16; ++i)
        printf("%i ", exec_13_array[i]);
    printf("\n");

    exec13_ascending = !exec13_ascending;
    sort(exec_13_array, 16, exec13_ascending);
    printf("\n\nThe array after the sort descending:\n");

    for (int i = 0; i < 16; ++i)
        printf("%i ", exec_13_array[i]);
    printf("\n");
}

void swap_ascending(int *num1, int *num2)
{
    int temp;
    if (*num1 > *num2)
    {
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
}

void sort3(int *num1, int *num2, int *num3)
{
    swap_ascending(num1, num2);
    swap_ascending(num2, num3);
    swap_ascending(num1, num2);
}

void exec_8(void)
{
    int num1 = 3;
    int num2 = 2;
    int num3 = 1;
    sort3(&num1, &num2, &num3);

    printf("Num1: %d Num2: %d Num3: %d", num1, num2, num3);
}

void str_append(char **s, char ch)
{
    size_t s_len = strlen(*s);
    size_t size = s_len + 2;
    // Allocate memory for the size of the str + char and '\0'
    char *new_str = (char *)malloc(size);
    strcpy(new_str, *s); // Copy old str to newly allocated space
    new_str[size - 2] = ch;
    new_str[size - 1] = '\0';
    free(*s);     // Free old str
    *s = new_str; // Replace value of old pointer to point to new str
}

void readLine(char **buffer)
{
    char character;
    do
    {
        character = (char)getchar();
        str_append(buffer, character);
    } while (character != '\n');
}

bool alphabetic_and_number(const char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'')
        return true;
    else if (c >= 48 && c <= 57) // ANSI table for 0-9
        return true;
    else
        return false;
}

int countWords(const char *string)
{
    int i, wordCount = 0;
    for (i = 0; *(string + i) != '\n'; ++i)
    {
        if (alphabetic_and_number(*(string + i)))
        {
            ++wordCount;
        }
    }
    return wordCount;
}

void exec_9(void)
{
    printf("####### exec 9 ######## \n");
    printf("Enter number and char to count \n");
    char *buffer = (char *)malloc(1);
    strcpy(buffer, "");
    readLine(&buffer);
    printf("Words and number count %d \n", countWords(buffer));
}

int compareStrings(const char *s1, const char *s2)
{
    int i = 0, result = 0;
    char s1_i, s2_i;

    do
    {
        s1_i = *(s1 + i);
        s2_i = *(s2 + i);
        if (s1[i] == '\0' && s2[i] == '\0')
            result = 0;
        else
            result = s1[i] - s2[i];

        ++i;
    } while (s1_i == s2_i && s1_i != '\0');
    return result;
}

void exec_10(void)
{
    printf("######## exec 10 #########\n");
    char *str1 = "abc";
    char *str2 = "abc";
    char *str3 = "abd";
    printf("Comapre string %s and %s = %d \n", str1, str2, compareStrings(str1, str2));
    printf("Comapre string %s and %s = %d \n", str1, str2, compareStrings(str1, str3));
    printf("Comapre string %s and %s = %d \n", str1, str2, compareStrings(str3, str1));
}

struct date
{
    int month;
    int day;
    int year;
};
bool isLeapYear(struct date d)
{
    bool leapYearFlag;
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        leapYearFlag = true; // It's a leap year else
    leapYearFlag = false;    // Not a leap year
    return leapYearFlag;
}

int numberOfDays(struct date d)
{
    int days;
    bool isLeapYear(struct date d);
    const int daysPerMonth[12] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(d) && d.month == 2)
        days = 29;
    else
        days = daysPerMonth[d.month - 1];
    return days;
}

void dateUpdate(struct date *today)
{
    if (today->day != numberOfDays(*today))
        today->day = today->day + 1;
    else if (today->month == 12)
    {
        today->day = 1;
        today->month = 1;
        today->year = today->year + 1;
    }
    else
    {
        today->day = 1;
        today->month = today->month + 1;
    }
}

void exec_11(void)
{
    struct date today = {12, 31, 2021};
    struct date *date_pointe = &today;
    printf("Today: %d/%d/%d \n", date_pointe->month, date_pointe->day, date_pointe->year);
    dateUpdate(date_pointe);
    printf("Today: %d/%d/%d \n", date_pointe->month, date_pointe->day, date_pointe->year);
}

void exec_12(void)
{
    char *message = "Programming in C is fun\n";
    char message2[] = "You said it\n";
    char *format = "x = %i\n";
    int x = 100;
    /*** set 1 ***/
    printf("Programming in C is fun\n");
    printf("%s", "Programming in C is fun\n");
    printf("%s", message);
    printf(message);
    /*** set 2 ***/
    printf("You said it\n");
    printf("%s", message2);
    printf(message2);
    printf("%s", &message2[0]);
    /*** set 3 ***/
    printf("said it\n");
    printf(message2 + 4);
    printf("%s", message2 + 4);
    printf("%s", &message2[4]);
    /*** set 4 ***/
    printf("x = %i\n", x);
    printf(format, x);
}

int main(void)
{
    // exec_2();
    // exec_3();
    // exec_4();
    // exec_5_6();
    // exec_7();
    // exec_8();
    // exec_9();
    // exec_10();
    // exec_11();
    exec_12();
}
