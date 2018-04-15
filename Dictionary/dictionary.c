




//* code written by: Mohammad Alsalkini





// Implements a dictionary's functionality


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define HASHTABLE_SIZE 143100

typedef struct node
    {
        char word[LENGTH + 1];
        struct node *next;
    }
    node;

    node* hashtable [HASHTABLE_SIZE] = {NULL};
    int counter = 0;
unsigned hash(char *s)
{
     // Hash function from:
     // https://stackoverflow.com/questions/7700400/whats-a-good-hash-function-for-english-words
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
         hashval = *s + 31*hashval;

    return hashval % HASHTABLE_SIZE;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char word1[LENGTH + 1];
    int length = strlen(word);
    for(int i = 0; i < length; i++)
    {
        word1[i] = tolower(word[i]);

    }
    word1[length] = '\0';
    node* cursor = hashtable[hash(word1)];
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, word1) == 0)
        {
            return true;

        }
        cursor = cursor->next;

    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word [LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open .\n");
        return false;
    }
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        strcpy(new_node->word, word);
        counter ++;
        int hash1 = hash(word);
        if(hashtable[hash1] == NULL)
        {
            hashtable [hash1] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = hashtable[hash1];
            hashtable[hash1] = new_node;
        }

    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if ( counter > 0)
    {
        return counter;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);

        }

    }
    return true;
}
