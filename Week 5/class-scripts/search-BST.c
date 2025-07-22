#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

bool search(node *tree, int number);

int main(void){
}

bool search(node *tree, int number)
{
  if (NULL == tree)
  {
    return false;
  }
  else if (number < tree->number)
  {
    return search(tree->left, number);
  }
  else
  {
    return search(tree->right, number);
  }
}
