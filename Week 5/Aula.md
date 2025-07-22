# Data Structures
Uma forma de estruturar seus dados num computador, arrays são formas muito simples
Abstrair tipos de dados.
queues - filas, FIFO.
#### Structure of a queue
```C
const int CAPACITY = 50;
typedef struct 
{
    person people[CAPACITY];
    int size;
} queue;
```

stack - pilhas, LIFO

ALgumas palavras para operações com essas estruturas são push, colocar na estrutura, e pop, remover da estrutura. Na stack, push é colocar no topo da stack e pop remove do topo
Na queue só coloca no finaç e remove do início.
#### Structure of a stack
```C
const int CAPACITY = 50;

typedef struct
{
    person people[CAPACITY];
    int size;
} stack;
```

Um porblema que poderíamos encarar é por exemplo, uma array que tem seu tamanho limitado, porque se ela crescer, irá sobrescrever o espaço de outra variável que estou usando. É possível mover essa array para outro lugar, mas ficar movendo demais pode se tornar uma problema de performance. Talvez eu possa então criar essa arrya com espaço o suficiente para poder aumentar se eu quiser, mas estarei gastando mais memória.
A resposta para resolver isso é usando struct, . e *, sendo que veremos agora o operador ->, que une o operador . e o * num só.

Para poder realocar um espaço a mais, além do malloc que é memory allocation, posso usar o realloc, para realocation

linked list, usa ponteiros para ligar as coisas. Os dados não precisam estar lado a lado na memória, podem estar em outros lugaresm desde que junto com o dado eu garde um ponteiro para o próximo elemento, sendo que o último será um ponteiro NULL. Além disso, só é necessário o primeiro ponteiro que marca o início da lista lincada. fragmentation da estrutura de dados, mas hoje me dia não é um problema com os atuais sistemas operacionais. Com linked list você pode acabar gastando mais do que o dobro de memória da lista original, mas agora tem a flexibilidade de poder usar toda a memória livre que tem, para poder aumentar a lista se quiser.
#### Structure of a linked list
```C
typedef struct node
{
    int number;
    struct node *next;
} node;
```
Cada elemento aponta para o próximo. Há singly linked list, que só tem uma direção, e doubly linked list, que consegue retornar.
Uma linked list, para fazer um search por cada elemento usa O(n), mas para inserir um elemento novo é O(1), porque sempre será o próximo elemento. Assim é uma estrutura LIFO.
Não é possível fazer uma busca binária numa lista lincada, pois não tem como simplesmente pular para o meio, para isso eu teria que percorrer tudo, para saber o meio e então percorrer até o meio.

### Trees
Como por exemplo a estrutura de uma árvore genealógica.
Binary search trees, é possível realizar uma busca binária nelas.
Como uma simples array, com elementos numerados de 1 a 7. O primeiro meio é 4, o meio do meio é 2 e 6. Posso montar essa busca binária como se fosse uma árvore.
#### Structure of a binary search tree
```C
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;
```
Nessa BST (Binary Search Tree), o valor a esqurda precisa ser menor do que o pai e o da direita maior.
O principal problema é construir essa BST, mantendo os valores organizados, pode ser que não seja inserido um número menor do que o que é o pai, ou não um maior, assim simplesmente a árvore acaba tendendo apenas para um lado.

### Dictionaries
have a word and a definition; a key with values.
A key geralemente é uma stirng e associa com algum outro valor.
É possível implementar um dicionário para guardar o nome e o número de uma pessoa

### Hash function
Decidir para onde uma coisa via na memória. Buckterization, pegar um valor grande, como ordenar as 52 cartas de baralho, mas separar em problemas menores, ao invés de ordenar as 52, primeiro classifica pelos naipes e agora terá que ordenar 4 baralhos de 13 cartas, o que é um problema mais fácil de resolver, ordenar 13 cartas é mais fácil do que 52 de uma vez.
Uma hash table é uma array e uma lista lincada juntas. Pois, posso usar o arrya, como se fosse um dicionário de 26 de tamanho, para guardar nomes, mas se tiver pessoas com a mesma letra inicial? Vou precisar de uma lista lincada.
#### Structure of a hash table
```C
typedef struct node
{
    char *name;
    char *number;
    struct node *next;
} node;

node *table[26];
```
Mas ao invés de apenas analisar a primeira letra, se for para remover o tempo O(n), por causa das colisões, posso analisar as 3 primeiras letras, se eu quiser.

Para a primeira letra:
```C
#include <ctype.h>

// Pequena otimização, pois sempre retorna positivo o índice de uma array
unsigned int hash(char *word)
{
    return toupper(word[0]) - 'A';
}
```
No entanto, mesmo com três letras iniciais, não há garantia de que não haverá colisões. Mas uma coisa importante dessa estrutura, em separar em 26 letras, ou 17000, com as 3 primeiras letras, ou qualquer k, na verdade será O(n/k). Hash tables são O(n), mas se você for esperto, uma função hash ideal terá 0 colisões e será praticamente O(1).

### Trie
É uma árvore de arrays.
Por exemplo, para guardar um nome, posso guardar cada letra em uma array diferente. Para Toad, a array da primeira camada tem todas as letras do alfabeto, todas as arrays; Primeiro guardo T, cujo elemento será um ponteiro para a próxima array com a próxima letra do nome, O, que terá um ponteiro para outra array, mas agora apontando para o A, por fim, este aponta para outra arrya a letra D, que marca o fim de uma palavra. Para adicionar um novo nome, ele não depende da estrutura já pronta. Para inserir, deletar, procurar, só depende do comprimento do nome da pessoa.
```C
typedef struct node
{ // Guardar o número de telefone das pessoas.
    struct node *children[26];
    char *number;
} node
```
