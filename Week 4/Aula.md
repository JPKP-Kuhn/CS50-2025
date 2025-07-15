# Memória
bits podem ser armazenados em hexadecimal que usa a base 16. 0xFF representa 255 em decimal.
Hexadecimal é importnate, pois os endereços de memória são guardados em hexadeciaml, fica mais fácil.

## Ponteiros
Apontam para um endereço de memória. São & e *
& --> Onde na memória está guardado um valor. O endereço de algo.
'*' --> Ver qual é a informação que está guardada no endereço de memória. Diz como conseguir algo.
%p --> para fazer o print de um pointer, que representa o endereço de algo na memória.

Um ponteiro é uma variável que armazena o endereço para alguma coisa.
```c
int n = 50;
int *p = &n;
```

n é um interio que armazena o número decimal 50. Na memória, ele ocupa 4 bytes e está representado na sua forma binária. Agora p é um ponteiro de um int, isso por causa da star, *, e recebe &n que é o endereço de memória da variável n.
Ponteiros usam 8 bytes de armazenamento.

cs50.h estava ajudando criando o tipo string, typedef char* string. Mas no C, uma string memso pode ser declarada como char s[], ou melhor como char *s; pois a string aponta para o primeiro char.

## Aritmética de Ponteiros
Já que ponteiros são apenas números que representam o endereço de memória, então é possível fazer contas com eles. somar +1 significa que estou indo para o próximo endereço.


### Segunda parte da aula
Eu preciso usar strcmp para comparar se duas string são iguais, pois, uma string é um ponteiro para o primeiro char que forma a string. Ao criar duas strings, elas terão ponteiros diferentes. strcmp consegue lidar com isso. == quando é para string, ele acaba comparando os endereços de memória, que serão diferentes.
strcmp deve conseguir ir até checar os valores de cada memória e analisar char por char, para saber se são iguais, ou tem ordem alfabética diferente.

Como string são ponteiros, se eu fizer:
```c
#include <ctype.h>

char *s = "hi!";
char *t = s;
t[0] = toupper(t[0]);
```

Ambos s e t terão o H maiúsculo, pois eles são ponteiros para o mesmo endereço de memória.
Para poder copiar, eu preciso usar malloc e free
malloc precisa incluir stdlib.h e ele armazena um número de bytes que é o argumento, na variável
malloc eu aloco memória para uma vairável, enquanto free eu libero memória.

valgrind -> Para detectar problemas como falhas de memória, uso indevido.

#### Passing by reference, or address
swap valores. Preciso de uma terceira variável.
Os argumentos de uma função são passados como valores. Então só trocandos os valores em uma função, não funcionará

| Computer's Memory |
| ------------- |
| machine code |
| globals |
| heap |
| I - heap grows|
| V - heap grows|
| A - stack grows|
| I - stack grows|
| stack |
Durante a execução do código, fica alocado num espaço a memórica para o código, as variáveis globais; no heap fica o malloc, ele cresce para baixo, por fim a stack, esta cresce para cima. A stack é usada sempre que uma função é chamada.
Primeiro na stack fica a função main(), com seus argumentos, ao chamar outra função, ela vai pra cima da main(), cada função com suas variáveis locais.
Um escopo é um pedaço da memória, o que está dentro das chaves {}

Após o fim do programa os valores podem continuar na memórica como lixo. Assim como uma função, quando ela return, seus valores continuam guardados, então ao invés de ser um lixo, é um resquício do programa.
heap e stack crescem um contra o outro e de fato isso vai causar um conflito se não cuidar com muitos malloc ou com muitas chamadas de funções.

heap overflow -> chamar mallco muitas vezes, vai sobrescrever a memória de uma outra área.
stack overflow -> muitas cahamdas de funções que podem causar overflow nelas mesmas ou em outras partes da memória.

Esses dois são exemplos de buffer overflow, sendo um buffer um chunk de memória, um pedaço de memória. Uma array é como um buffer, se tentar acessar elementos fora do seu limite, estará causando um overflow eventualemnte.

### File I/O 
Entrada e saída de dados. No C se usa scanf() que recebe o endereço da variável para atribuir um valor a ela. Problema se for uma string, pois se eu não inicializá-la com um tamanho de bytes, ela será um ponteiro para algum lugar com lixo, o que pode causar problemas. Até mesmo se alocar um espaço grande pra string, eu ainda posso passar esse valor.

Também, como acessar arquivos? Há várias funções para isso.

## Primeiro problem-set
Para leitura de arquivos é usado o tipo FILE que será um ponteiro para cada byte do arquivo a ser lido. fread() guarda a posição do ponteiro, ou seja, se eu primerio fazer um fread() até o byte 44, da próxima vez que eu executar fread(), o ponteiro já estará posicionado no byte 45.
