#include <stdio.h>
#include <stdlib.h>
#include "cs50.h"

typedef struct node
{
  int number;
  struct node *next;
} node;

int main(void)
{
  node *list = NULL; // It will affter points to the first element;

  // singly linked list, it is in one direction
  for (int i = 0; i < 3; i++)
  {
    node *n = malloc(sizeof(node));
    if (NULL == n)
    {
      return 1;
    }
    //(*n).number = get_int("Number: ");
    n->number = get_int("Number: ");
    //(*n).next = NULL;
    //n->next = NULL;

    /* Esse código guarda a lista numa LIFO
    n->next = list;
    printf("adress of n is: %p\n", n);
    list = n;
    printf("adress of list is: %p\n", list);
    */

    // if list is empty, what occurs for the first element
    if (NULL == list)
    {
      list = n;
    }
    else // if list already has a value
    {
      for (node *ptr = list; ptr != NULL; ptr = ptr->next)
      {
        // if at end of list
        if (NULL == ptr->next)
        {
          ptr->next = n;
          break;
        }
      }
    }

  }
  
  printf("Elements of my linked list\n");
  /*
  node *ptr = list;
  while(NULL != ptr)
  {
    printf("%i ", ptr->number);
    ptr = ptr->next; // following the arrow to the next element
  }
  printf("\n");
  */

  for (node *ptr = list; ptr != NULL; ptr = ptr->next)
  {
    printf("%i\n", ptr->number);
  }

  node *ptr = list;
  while (NULL != ptr)
  {
    node *next = ptr->next;
    free(ptr);
    ptr = next;
  }
  return 0;
}
