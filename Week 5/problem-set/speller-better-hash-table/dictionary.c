// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
// I am following the hash function DJB2, a big prime number is better
const unsigned int N = 9991; // it is almost 1e5

// Count the total number of words
unsigned int tot_words = 0;

// Hash table
node *table[N];

// Check if the dictionary was successfuly loaded into my table
bool loaded = false;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);
    
    for (node *n = table[index]; n != NULL; n = n->next)
    {
      if (strcasecmp(n->word, word) == 0)
      {
        return true;
      }
    }
    return false;
}

// Hashes word to a number
// hash function DJB2
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash = 5381;
    int c;
    while((c = *word++))
    {
      hash = ((hash << 5) + hash) + tolower(c); // hash * 32 + c
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (NULL == dict)
    {
      return false;
    }

    // buffer for words
    char word[LENGTH+1];
    // Read each word in the file and add them to the hash table
    while (fscanf(dict, "%s", word) != EOF)
    {
      tot_words++;
      node *n = malloc(sizeof(node));
      if (NULL == n)
      {
        fclose(dict);
        return false;
      }
      strcpy(n->word, word);
      int index = hash(word);

      n->next = table[index];
      table[index] = n;
    }
    
    // close the file
    fclose(dict);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return (loaded ? tot_words : 0);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
      node *ptr = table[i];
      while (NULL != ptr)
      {
        node *n = ptr->next;
        free(ptr);
        ptr = n;
      }
      table[i] = NULL;
    }
    return true;
}
