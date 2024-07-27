#include <stdlib.h>
#include <stdio.h>

struct entry
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

int lookup(const struct entry dictionary[], const char search[],
           const int entries)
{
    for (int i = 0; i < entries; i++)
    {
        if (compareStrings(search, dictionary[i].word) == 0)
            return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    const struct entry dictionary[100] =
        {{"aardvark", "a burrowing African mammal"},
         {"abyss", "a bottomless pit"},
         {"acumen", "mentally sharp; keen"},
         {"addle", "to become confused"},
         {"aerie", "a high nest"},
         {"affix", "to append; attach"},
         {"agar", "a jelly made from seaweed"},
         {"ahoy", "a nautical call of greeting"},
         {"aigrette", "an ornamental cluster of feathers"},
         {"ajar", "partially opened"}};
    int entries = 10;
    int entryNumber;

    if (argc != 2)
    {
        fprintf(stderr, "No word typed on the command line.\n");
        return EXIT_FAILURE;
    }
    entryNumber = lookup(dictionary, argv[1], entries);
    if (entryNumber != -1)
        printf("%s\n", dictionary[entryNumber].definition);
    else
        printf("Sorry, %s is not in my dictionary.\n",
               argv[1]);
    return EXIT_SUCCESS;
}