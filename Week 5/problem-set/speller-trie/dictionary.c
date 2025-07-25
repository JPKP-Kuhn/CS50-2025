// Impl

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

#define ALPHABET_LENGTH 27 // +1 beacuse of the '
// Represents a node in a trie
typedef struct trie_node
{
  bool is_word;
  struct trie_node *children[ALPHABET_LENGTH];
} trie_node;

trie_node *root = NULL;

// coutn the total nuumber of words
unsigned int tot_words = 0;

bool loaded = false;

// It will return the index for a trie
int get_trie_index(char c)
{
  return (c == '\'') ? 26 : tolower(c) - 'a';
}
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
  // TODO
  trie_node *cursor = root;

  for (int i = 0; word[i] != '\0'; i++)
  {
    int index = get_trie_index(word[i]);

    if (cursor->children[index] == NULL)
    {
      return false;
    }
    cursor = cursor->children[index];
  }
  return cursor->is_word;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
  // TODO: Improve this hash function
  return toupper(word[0]) - 'A';
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

  // Aloca nó raiz à trie e já inicializa os ponteiros e o is_word com 0/NULL
  root = calloc(1, sizeof(trie_node));
  if (NULL == root)
  {
    fclose(dict);
    return false;
  }

  char word[LENGTH+1];

  while(fscanf(dict, "%s", word) != EOF)
  {
    trie_node *cursor = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
      int index = get_trie_index(word[i]);
      // Se o caminho ainda não existe, então cria o nó.
      if (cursor->children[index] == NULL)
      {
        cursor->children[index] = calloc(1, sizeof(trie_node));
        if (NULL == cursor->children[index])
        {
          fclose(dict);
          unload();
          return false;
        }
      }
      // Anda para o próximo nó
      cursor = cursor->children[index];
    }
    // Marca o fim da palavra
    cursor->is_word = true;
    tot_words++;
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
  return loaded ? tot_words : 0;
}

void free_trie(trie_node *node)
{
  if (NULL == node)
  {
    return;
  }

  for (int i = 0; i < ALPHABET_LENGTH; i++)
  {
    free_trie(node->children[i]);
  }
  free(node);
}
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
  // TODO
  free_trie(root);
  root = NULL;
  loaded = false;
  return true;
}
