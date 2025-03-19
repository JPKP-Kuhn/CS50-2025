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