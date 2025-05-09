	# Reading Levels
Assim como na escola, as pessoas têm níveis de leitura, um texto pode ser mais fácil ou mais difícil, dependendo para a pessoa

Palavras simples: “"One fish, two fish, red fish, blue fish.” Uma frase de 1º ano
Uma frase de 3º ano ou um texto, maior, um parágrado, mas como que pensamos nisso? Qual a lógica que usamos para pensar nisso e como escrever ela em código?
## Criptografia
Uma ciência sobre esconder e embaralhar frases e informação, para uma mensagem privada, …
- Ciphertext - é a mensagem encriptografada, já embaralhada
U I J T J T D T 50 → This is CS50
É possível perceber que há um padrão na verdade nesse ciphertexto, primeiro pelo comprimento das palvras, ambos são iguais, além disso, na mensagem criptografada, as letras são apenas as seguintes da mensagem original, na ordem alfabética, antes de U vem o T, antes de I vem o H e assim por diante.

## Como analisar letra por letra em uma string?
Importante analisar o texto.

Source code → compiler → machine code
O compiler é responsável por analisar o source code, passo a passo e convertê-lo em machine code
Make na verdade é um comando que automatiza um compilador para você. O que é usado no curso é o clang - C language. Então na verdade make roda um outro programa chamado clang, mas ele não é user friendly, ele cria um arquivo a.out
Com o clang é possível passar o argumento -o para ter um nome diferente de executável, como clang -o hello hello.c, terá agora um arquivo hello, não um a.out

## O que é compilar?
preprocessing, compiling, assembling, linking

#### Preprocessamento
protótipo é a primeira linha de uma função, ponto e vírgula, só para dizer pro compilador que essa função existe, só não está definida agora, mais pra frente no código
Quando tem um # será um diretório pré processado.
Para cs50.h, quando usamos por exemplo a função get_string(); o compilador terá que achar a definição dessa função, o protótipo dela no próprio código ou no diretório pré processado, neste caso. Na verdade, o compilador copia todo o arquivo cs50.h e o stdio.h. O preprocessamento seria basicamente copiar todos os protótipos

#### Compilar
Traduzir o código para um outra língua, outra linguagem, no caso de c, traduz o código c para código assembly. No assembly também tem uma menção ao main, get_string(), printf(), … Além de outras palavras. Então o processador a CPU só entendem 0 e 1, mas o que realmente entendem são os comandos específicos que tem no assembly que são pushq, movq, subq entre muitos outros. Esses comandos tem já padrões de 0 e 1, mas tem uma documentação para todos os low level comands, as instruções que a CPU realmente entende

#### Assembling
Finalmente converter o código assembly para 0 e 1, porque de fato é isso que o computador entende. Assim, seria algo como 110101010101110101000010010101001110101010101010010101101010101101010101010001010011111111010000101101111100110101001010101010111101001000101010101
comando xxd e xxd -b no terminal para um arquivo de texto para ver os binários

#### Linking
Num simples arquivo, temos o nosso hello.c que tem um include para stdio.c e cs50.c, 3 arquivos, após passar pela compilação e assembling temos três conjuntos de binários. O linking junta todos esses binário para um conjunto só. Quando usa o argumento -o de clang estamos apenas especificando para qual arquivo o linking enviará esses binários. Quando usa o argumento -l daí nome da biblioteca, o -l não é pra library, mas sim para link e é necessário para código de terceiros

### Decompilar, a partir do binário reconstruir o código
Bem, é possível, se for analisar os binário e também agrupá-los em 32 ou 64 bits, é possível ter uma ideia de qual é o código original.
Mas com os bits, eu não sei se foi usado algum loop, for, while, …
No fim das contas, analisar os binários para reconstruir o programa seria muito tedioso e trabalhoso. Mais fácil só refazer o programa.

##  Debugging
História de Grace Hopper, o primeiro bug, insetom que estava no computador atrapalhando a execução do programa.
- Rubber duck: Explicar para o pato qual a sua dúvida para resolver o código, o que não está entendendo.
- Posso usar a função printf para ocnseguir visualizar cada variável do meu código e ajudar a encontrar o erro.
- Breakpoints são como placas de Pare! Assim a execução do programa para naquele exato ponto
- A ferramenta de debug pode ser muit útil, pois com ela você pode ver o seu código ser executado linha por linha, mais de vagar e entender melhor o que está acontecendo.

### Types
Tudo no computador são 0 e 1. Mas esses binários podem ser interpretados e tratados como se fossem algum outro tipo. No C temos, mais nos dias de hoje, temos:
- bool (1 byte, tecnicamente poderia ser até 1 bit), 
- int (4 bytes), 
- long (8 bytes), 
- float (4 bytes), 
- double (8 bytes), 
- char (1 byte), 
- string (? bytes, varia de acordo com o tamanho da palavra ou frase).

Dentro de uma memória de computador, temos os endereços de memória, onde os bits estão localizados. Cada dado está armazenados nos bits de memória, então alguma informação de 1 bit pode estar localizada no bit 0 da posição da memória por exemplo. 
Posso pensar na memória como uma grade, com cada espaço sendo um byte.
![[Screenshot_29-abr_21-37-41_22070.png]]
Se temos, como um int, algo com 4 bytes, então ele ocupará 4 bytes na memória, indo da posição 0 até a 3 por exemplo, ou seja, precisa ser contínuo
No caso da imagem, temos a variável int score1 que armazena o valor 72, ela ocupa 4 quadrados, pois é um int.

Esses números representam três padrões de 32 bits

## Arrays
É uma sequência de valores, que estão juntos, unidos um após o outro na memória. Todos os elementos de uma array no c precisam ser do mesmo tipo, assim: int, int, int ; char, char, char ; ….
Então:
int scores[3]; 
tipo_do_array nome [número de elementos dentro]
Assim, ao invés de ter uma variável para cada número, na verdade fica armazenado na memória scores[0], scores[1] e scores[2]

### char e string
Um char representa apenas um caractere e é representado por ‘ ’ aspas simples. Sendo uma letra em ASCII, posso fazer printf(%c) que é pra char, mas também %i, assim o compilador vai interpretar os bits para serem como números, retornando o código ASCII da letra.

Agora, as string são como um conjunto de char, ao serem armazenadas na memória, é como vários char juntos um após o outro. Assim, uma string é uma array de caracteres, como uma mensagem “HI!”, sendo s[0] = ‘H’, s[1] = ‘I’ e s[2] = ‘!’2
Um detalhe importante é que o computador sabe que é o fim de uma string porque o último elemento é um byte de 0, representando de fato o último elemento da string. O último byte de uma string vai ser o 0, mais exatamente \0 que é um símbolo para representar o fim. Esse caracter terminal é o NUL na tabela ASCII

```
  string words[2];
  words[0] = "HI!";
  words[1] = "BYE!";

  printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]); // Primeiro pro índice 0, depois pro caracter, um array de array de caracteres
  printf("%c%c%c\n", words[1][0], words[1][1], words[1][2]); // Primeiro pro índice 0, depois pro caracter, um array de array de caracteres
```
words[0] é a palavra “HI!” que é um array de caracteres


### Comprimento de uma string
Pode só fazer um for para contar até acabar no \0 ou só usar o código que outra pessoa já escreveu.
Realmente, tem a biblioteca string.h que possui uma função que implementa isso, strlen();
Além disso, temos muitas outras para diversas funções.
*Curiosidade: Na tabela ASCII a distância entre letras maiúscula para minúscula é de 32

### Argumentos de entrada
int main(int argc, string argv[])
argc - Conta quantos argumentos estão sendo fornecidos
argv - vetor, outra palavra pra array

### Exemplos de saída
A saída pode ser um número, como um código de erro. Servem para padronizar o que pode ocorrer de errado em um programa.
Quando tem return 0 está tudo certo. Quando é qualquer outro número, representa um erro

