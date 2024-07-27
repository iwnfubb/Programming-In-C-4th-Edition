#include <stdlib.h>
#include <stdio.h>
#define NUM 1000 * sizeof(char)
#define WORD_LEN 15
#define DEFINITION_LEN 50

struct entry
{
    char *word;
    char *definition;
};

FILE *open_file(char *file_name, char *mode)
{
    FILE *in;
    if ((in = fopen(file_name, mode)) == NULL)
    {
        printf("Can't open %s for reading.\n", file_name);
        fclose(in);
    }
    return in;
}

struct entry *open_dictionary(char *path)
{
    struct entry *new_dictionary = (struct entry *)malloc(sizeof(struct entry) * 100);
    int dictionary_index = 0;
    FILE *in = open_file(path, "r");
    char *buffer = malloc(NUM);
    while (fgets(buffer, NUM, in) != NULL)
    {

        int buffer_index = 0;
        // fputs(buffer, stdout);
        while (buffer[buffer_index] != '\n')
        {
            int word_index = 0;
            new_dictionary[dictionary_index].word = malloc(sizeof(char) * WORD_LEN);
            new_dictionary[dictionary_index].definition = malloc(sizeof(char) * DEFINITION_LEN);
            while (buffer[buffer_index] != ':')
            {
                new_dictionary[dictionary_index].word[word_index] = buffer[buffer_index];
                buffer_index++;
                word_index++;
            }
            new_dictionary[dictionary_index].word[word_index] = '\0';
            word_index = 0;

            while (buffer[buffer_index] != '\n')
            {
                new_dictionary[dictionary_index].definition[word_index] = buffer[buffer_index];
                buffer_index++;
                word_index++;
            }
            new_dictionary[dictionary_index].definition[word_index] = '\0';
            dictionary_index++;
        }
    }
    free(buffer);
    fclose(in);
    return new_dictionary;
}

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

    int entries = 10;
    int entryNumber;

    if (argc != 3)
    {
        fprintf(stderr, "No word typed on the command line.\n");
        return EXIT_FAILURE;
    }
    struct entry *dictionary = open_dictionary(argv[2]);
    entryNumber = lookup(dictionary, argv[1], entries);
    if (entryNumber != -1)
        printf("Found ! %s is %s\n", argv[1], dictionary[entryNumber].definition);
    else
        printf("Sorry, %s is not in my dictionary.\n", argv[1]);

    free(dictionary);
    return EXIT_SUCCESS;
}
