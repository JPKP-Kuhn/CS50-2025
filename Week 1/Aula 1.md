## Linguagem C
Antes era em blocos no scratch, mas agora em #c:
```
#include <stdio.h>

int main(void) 
{
	printf("hello, world\n");
}
```
Isso é um hello world escrito na linguagem de programação c.
Mas na realidade o computador entende apenas 0 e 1, mas agora eles terão outro significado, como o print, ou salvar ou carregar algo.
Computadores utilizam padrões de bits, não só para representarem coisas, mas também para representar funcionalidades fundamentais, como print, play, …
Para isso, alguma coisa precisa transformar o ‘source code’, ou o código em si, para o ‘machine code’, código de máquina, binários. Esse programa é o compilador, que traduz esse input no output.

#### graphical user interface (GUI)
Interface gráfica, #GUI define os botões para clicar, disposição do texto.
#### Command line interface (CLI)
O terminal, #CLI interface baseada em texto para ter acesso ao computador.

#### Executando o arquivo em c no vscode
1. code arquivo.c → code hello.c
2. Após escrever o códio, make arquivo → hello, o compilador já entende que será um arquivo em c
3. ./hello
Nesse passo a passo, o code é específico do vs code para criar o arquivo, o make é importante, pois ela ativa o compiler para traduzir o código para o código de máquina. Source code to machine code. Por fim, o ./hello vai executar o programa, o ./ representa algo nesse arquivo atual em que você está.

Após executar o comando make hello, ele criará esse arquivo, com os binários para executar o código.

### Comparando c com scratch
O bloco say do scratch é semelhante ao printf() do c. Isso é uma função, que precisa ter os parênteses 

- Semelhante à matemática, as função apresentam um parêntesis que contém o elemento em que elas trabalharão
$$f(x)$$
Arguments → [function] → side effect

\n → Move o cursor para uma nova linha
\r → Move o cursor para o começo de uma nova linha
\” → Para colocar uma palavra entre “” → ```printf("hello, \"world\"\n"``` → hello, “world”
\’ e \\ e muitos outros …

## #header_file
Todo arquivo que termina em .h é um #header_file, como o ```#include <stdio.h>```
Dentro desses arquivos há funções que vem junto com o sistema ou com a linguagem de programação em si.
Se não colocar isso no código, o printf não funcionará.
É necessário incluir o stdio.h para ter acesso a uma biblioteca.

- Uma #biblioteca é uma coleção de códigos e funções que outra pessoa escreveu para que você as utilize no seu código
Dessa forma, se ao retirar o stdio.h o printf não funciona, então a definição dessa função deve estar nesse arquivo, seja lá quem o tenha escrito.
Para entender a biblioteca, basta ler sua documentação
stdio.h é para standart io

No C essas bibliotecas são chamadas de manual pages, que foram escritas a décadas atrás
Entrar no site do [manual.cs50.io](https://manual.cs50.io/) A bibliioteca do curso é cs50.h
No C é bem difícil fazer um input, então tem uma biblioteca do curso para essas funções -
- get_char
- get_string
- get_int
- get_float
Entre outras

### Como fazer um código que guarda o nome de alguém no input, e printa “hello, ” nome?
argument → [function] → return value
Usando a biblioteca do cs50 fica -
```
string answer = get_string("What's your name? ");
```
answer é a variável que guardará o valor de get_string(), além disso é necessário definir o que será esse valor, qual tipo de binário o programa tem que guardar.
com stdio.h consigo usar o printf() e com cs50.h consigo usar o get_string()

Agora para que no printf() tenha a variável, é necessário fazer assim:
```
printf("hello, %s\n", answer )
```
%s é um placeholder. %s está dizendo que será uma string

## Alguns comandos de terminal importantes
1. cd - change directory, para entrar numa pasta, para retornar para o parent é com .. ou só cd retorna pra origem
2. cp - copy, faz uma cópia de um arquivo, podendo colocar um novo nome para essa cópia
3. mv - move, para mover um arquivo para dentro de um diretório ou mudar o nome do arquivo
4. rm - remove, remove o arquivo
5. mkdir - make directory, cria um diretório
6. rmdir - remove directory, apaga o diretório, não vazio, mas pode forçar para fazer

## #Data_types, tipos primitivos no C
Tipos de dados - 
- String - um texto, conjunto de texto “” aspas duplas
- bool - true ou falseá
- char - caractere, ‘’ aspas simples
- int - número inteiro
- double, float, longer

## #Format_code
%s - string
$i - int

## #Condicionais
if (x < y)
{
	printf(“x é menor do que y\n“);
}
- - -
if (x < y)
{
	printf(“x é menor do que y\n);
}
else
{
	printf(“x não é menor do que y\n);
}

if (x < y)
{

}
else if (x > y)
{

}
else if ( x == y)
{

}

## #Operators
- =
- >
- <
- <=
- >=
- ==
- !=

## #Variables
Guardar algum valor:
int counter = 0; Precisa dizer que tipo de variável ela é 
counter = counter + 1; //adiciona 1 a essa variável. Também pode ser counter += 1; ou ainda counter++; ou para subtrair é counter–;

#### Fluxograma do código compare.c
[[fluxograma do código compare.c]]
É importante se atentar ao design do código. Encadeando um monte de if else, não é bom, pois o fluxo do código passará por todos esses if, por todas essas perguntas, e às vezes pode não ser necessário passar por todas elas.

## #Loop
while(){} só para de executar quando a condição não é mais satisfeita.
esse é o #while_loop e também tem o #for_loop que escreve tudo em uma linha só

```
int i = 0;
while (i <= 3)
{
	printf("oi\n");
	i++;
}
```
- - - 
```
for (int i = 0; i <= 3; i++)
{
	printf("oi\n");
}
```

## Argumento em funções
```
#include <stdio.h>
#include <cs50.h>

void meow(int n); //prototipo da funcao

int main(void)
{
    meow(3);
}

void meow(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("meow\n");
  }
}
```

## Scope
Variáveis só existem no escopo em que foram criadas

## Coisas importantes no mundo da programação
- Correção: o código precisa fazer o que se espera que seja feito, se não, não faz sentido escrevê-lo.
- design: a forma como organiza o seu código, seja para que funcione melhor ou para que seja mais compreensível.
- style: Se está bem comentado, bem explicado, fácil de implementar ou entender.

### #Constants
Variáveis que são constantes e não podem ser modificadas

### #Comments
Comentários para explicar o código.

### #Operadores
+, -, *, %, /
- = assignment operator - vai atribuir algum valor a uma variável

### #Integer_overflow
Com 32 bits conseguimos representar 4 bilhões de números, então até 2 bilhões positivo e 2 bilhões negativo. Dessa maneira, quando passamos desse valor que o 32 bit consegue representar, o próximo encremento de bit acaba bugando todos os outros. Não há um 33º bit, então todos os outros flipam para 0, pois o 33º deveria ser 1, mas ele não está lá. Não há memória suficiente. Se contar alto o suficiente, as coisas podem quebrar. Se há um limite de memória, é possível que ocorra um overflow.

- int no c, só tem um limite de 32 bit, mas há um outro tipo chamado long o que representa uma versão maior do int, agora com 64 bit

### #Truncation
int / int = int. se a resposta for decimal, só sairá o valor inteiro, então, não está arredondando, está truncado.
No c, apenas converter o número para float, não é o suficiente. Ambos precisam estar em float. Para converter o tipo de um número, eu preciso usar o casting.
Float usa 32 bit também
### #Floating-point_imprecision
Imprecisão do float, ele tem um limite de até quando pode ser preciso

### #Magic_number
Números que se repetem muito no código e que são comuns, como o total de cartas em um baralho, podem ser definidos como uma constante. Não uma variável global porque assim o código é menos seguro. No c, há um preprocessor directive, também chamado de macro, para criar constantes simbólicas.:
```
	#define NAME REPLACEMENT
	// por exemplo
	#define PI 3.14159265
	#define COURSE "cs50"

	#define DECKSIZE 52
	card deal_cards(deck name)
	{
		for (int i = 0; i < DECKSIZE; i++)
		{
			//deal the cardo
		}
	}
```
Não é obrigatório que o define seja sempre em capital, mas é bom para diferenciar de uma variável. O DECKSIZE é imutável, não dá pra fazer DECKSIZE++