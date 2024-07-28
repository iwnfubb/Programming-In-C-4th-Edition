#include <stdlib.h>
#include <stdio.h>
#define NUM 1000 * sizeof(char)
#define WORD_LEN 15
#define DEFINITION_LEN 50

int DICT_LEN = 0;

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
    DICT_LEN = dictionary_index;
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

int lookup(const struct entry *dictionary, const char search[])
{
    for (int i = 0; i < DICT_LEN; i++)
    {
        if (compareStrings(search, dictionary[i].word) == 0)
            return i;
    }
    return -1;
}
void add_new_word_to_dictionary(char *new_word, char *dict_path)
{
    printf("Sorry, %s is not in my dictionary.\n", new_word);
    printf("Do you wan to add \"%s\" to dictionary? YES, no [Y/n]\n", new_word);
    char input;
    scanf("%c", &input);
    while (getchar() != '\n')
        ;
    if (input == 'y' || input == 'Y')
    {
        FILE *in = open_file(dict_path, "a");
        size_t size;
        fputs(new_word, in);
        printf("Please enter a definition for %s \n", new_word);
        char *definition = NULL;
        getline(&definition, &size, stdin);
        fputs(":", in);
        fputs(definition, in);
        fputs("\n", in);
        printf("Updated definition %s for word \"%s\" \n", definition, new_word);
    }
    else
    {
        printf("No Update.");
    }
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
    entryNumber = lookup(dictionary, argv[1]);
    if (entryNumber != -1)
        printf("Found ! %s is %s\n", argv[1], dictionary[entryNumber].definition);
    else
        add_new_word_to_dictionary(argv[1], argv[2]);

    free(dictionary);
    return EXIT_SUCCESS;
}
