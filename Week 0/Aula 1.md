## Scratch
Links: cs50.ai e cs50.dev
### Introdução

#Ciências_da_computação é o estudo da informação, como a representamos e como a processamos.
Mas, mais importante é o [pensamento computacional](https://en.wikipedia.org/wiki/Computational_thinking) → resolver problemas do nosso interesse.

Computer science === Problem Solving
problema → [] → solução (precisamos encontrar a solução)
input → [] → output
[] → como podemos processar o problema para chegar na resposta

#### Mas então como posso resolver os problemas?
Há diversa formas de representar dados como números:
- Usar nossos dedos, [Unary notation](https://en.wikipedia.org/wiki/Unary_numeral_system) em que a quantidade de dedos representa o número. Também chamado de base - 1. Assim, com 1 mão conta-se até 5. 
- E se contarmos até 31 com apenas uma mão? Usando números binários, 0 (0 em binário) é a mão fechada, 1 (1 em binário) com o polegar, 2 (10 em binário) com apenas o indicador levantado, 3 (11) com o indicador e o polegar levantados, 4 (100) com apenas o dedo do meio levantado. Com os 5 (11111) dedos, será o número 31. Assim é a notação em base - 2, sendo o valor expresso apenas se o dedo está abaixado ou levantado. Há apenas dois estados possíveis.
- Base - 10, mais usado entre os humanos

####  #Sistema_binário
Há apenas duas possibilidades, 0 ou 1. Representa-se um bit, um dígito binário, apenas um 0 ou um 1. Ao invés do decimal, com 10 possibilidades, há apenas dois bits para representar a informação. O componente eletrônica responsável por ligar e desligar é o transistor, assim sendo possível guardar informação (com uma grande quantidade de transistor, terá mais informação possível). Representação do 7 (111) em binários, mas matematicamente:
$$1 * 2² + 1 * 2¹ + 1 * 2⁰ = 7$$
Potência de 2 para representar cada coluna dos números.
Para um representar um conjunto de bits, falamos de bytes = 8 bits. Esse valor porque é mais usual.  Assim na potência, é do 2⁰ até o 2⁷.

### Como representar letras?
Será necessário associar cada letra a um número para representá-la. 65 (1000001) representa o A, o B será o próximo, o 66. Essa é a definição do código ASCII. Decidiu-se usar 8 bits para representar os símbolos, assim 256 símbolos possíveis. Cada byte representa um única letra na tabela **ASCII**.

| 01001000 | 01001001 | 00100001 |
| -------- | -------- | -------- |
| 72       | 73       | 33       |
| H        | I        | !        |

3 bytes para representar a mensagem HI!
Mas representar todos os símbolos do inglês com 256 é o suficiente, mas para outras línguas é necessário ter 16, 24 ou até 32 bits, sedo este possível de representar até 4 bilhões de caracteres. Assim hoje em dia se usas o Unicode para ser possível representar qualquer letra. Emojis usam 32 bits, o computador entende o emoji, mas dependendo do hardware terá uma arte até levemente diferente.

### Como representar cores com bytes?
Utiliza-se o **RGB** (Red, Green, Blue), que representam um ponto, um pixel, na cor da tela. Tipicamente usa 3 números, 3 bytes, assim 24 bits por pixel. Juntando uma quantidade de cada uma dessas três cores é possível representar qualquer cor. Os bytes de um arquivo de imagem representam todos os pixels, existem ferramentas para comprimir todos eles.

### Como representar os vídeos?
No início do cinema era utilizado várias imagens, motion pictures. Um vídeo nada mais é do que várias imagens passando rápido o suficiente, criando a sensação de movimento. Podem 30 frames ou imagens por segundo, o mínimo necessário é 24 frames. Como são muitas imagens, os vídeos ocupam muito espaço.

### Como representar som?
O som precisa ser digital, cada frequência também é armazenada. Precisa da informação da frequência, para a nota, o tom, a duração. Podemos assim ter 3 bytes ou 4.

### A #programação é o jeito como tratamos esses bits para terem o output desejado
Escrever como queremos que o computador trate esses 0 e 1

###  #Algorítimo
É uma descrição bem **precisa** sobre como fazer alguma coisa.
Se eu precisasse procurar o telefone do João em uma lista telefônica, como poderia ser meu algoritmo para encontrá-lo?
1. Posso folhear página por página até encontrá-lo.
2.  Folhear duas folhas de uma vez e voltar uma, se passar da letra do nome.
Independente da opção escolhida, se ela foi executada corretamente e o seu nome de fato estiver no livro, em algum momento vou encontrar.
Caso eu procure pulando duas páginas, eu poderia ter falhas, poderia não encontrar o João.
Se o nome fosse com Z, eu precisaria olhar o livro inteiro até encontrar o nome, muito demorado.
#### Um jeito mais inteligente:
Abrir ao meio o livro, eu estaria por volta do M. Sabendo que eu quero encontrar o João, preciso agora olhar a metade da minha primeira partição.
Com apenas um passo desse algoritmo, eu já consigo eliminar metade do tempo de busca. Assim eu continuo repetindo. Ao fim, eu acabo encontrado ele ou pode não estar no livro.

Isso é uma questão sobre código limpo, se ele roda melhor do que seu código anterior.
Se considerarmos o 1º exemplo em um gráfico levaria um tempo para resolver que varia igual ao total de folhas. Já o segundo levaria a metade do tempo do primeiro, pois está indo de 2 em 2. Mas o último algorítimo, mais inteligente, terá um tempo logaritmo de acordo com a quantidade de itens para se analisar, ele é bem mais rápido.
![[Screenshot_28-fev_10-57-18_5958.png]]

No momento de aplicar algorítimos, para um programador, um cientista da computação, precisa decidir qual deles é o melhor a se usar e traduzí-lo para uma linguagem de programação, seja Python, Ruby, C, C++, qualquer linguagem.

###  #Pseudocódigo
É um forma de criar um código, mas utilizando a própria língua para criar o algoritmo. Não há uma regra, apenas diga o que você quer que aconteça.
Instruções -
1. Pegue o livro de telefones
2. Abra no meio do livro de telefones
3. Olhe a página
4. Se a pessoa está na página → Ligue para a pessoa
5. Mas se ela está antes no livro → Abra o livro na metade da primeira parte; Volte para a linha 3.
6. Mas se ela está depois no livro → Abra o livro na metade da segunda parte; Volte para a linha 3
7. Por fim, se ele não está nem antes, nem depois → feche o livro, pois ela não está nele.

**É importante escrever todos os possíveis cenários para que o computador saiba o que fazer, de outro modo ele pode congelar ou reiniciar**

Analisando esse pseudocódigo, há palavras importantes que expressam exatamente o que se fazer, são os verbos. Na programação também há, mas são chamados de funções. Definem exatamente o que fazer.
Mas também há outras palavras chave, se, mas se. Essas são as condições para algo acontecer. Representam bifurcações no código para se analisar onde deve seguir. Isso é definido através de uma expressão booliana, a qual é uma pergunta que só pode ser respondida com sim ou não. Eu só posso seguir a condição se a resposta for sim, só seguir a identação.
Também há as palavras retorne, as quais representam um loop
![[Screenshot_28-fev_12-24-25_7922.png]]


## Inteligência Artificial
Se pensarmos em um chatbot que responde as perguntas de um ser humano. Pelo que sabemos, poderíamos escrever uma condição:
Se perguntar olá:
	Responda olá
Se …
Mas assim seria complicado, pois existe infinitas perguntas possíveis.
O que fazemos com uma inteligência artificial é treiná-la com milhares de dados e deixá-la pensar em como respondê-la.
Para que ela possa pensar, seria como o cérebro humano funciona. Podemos criar uma rede neural, com vários nós ligados entre si, enviando mensagem, trocando informação, até chegarmos ao último nó, o output. Assim ele chega a conclusão da resposta mais provável para certa pergunta.

### Código

```
#include <stdio.h>

int main(void)
{
	printf("hello, world\n")
}
```
Esse código nada mais é do que uma abstração do código binário que o computador entende.
Há diferentes níveis de abstração que é trabalhada na computação, sendo a mais baixa os próprios 0 e 1 do computador.
C é uma linguagem que possui algumas funções de mais baixo nível, enquanto outras como python são mais amigáveis.

Mas para a primeira aula, considerando pseudocódigo, é mais interessante utilizar o scratch.
No próprio site deles é possível programar jogos, criar cenários, música e personagens com programação em blocos.
Sobre as funções, elas apresenta sempre um efeito colateral, seja ele visível para nós, como fizer hello, world, ou qualquer outro, desde somar valores a coisas mais complexas.
No programa scratch, seria essa lógica:
input → algoritmo → output
hello, world → say() → o gato diz hello, world

As vezes também é necessário um valor de retorno,o return. Ele pode ser armazenado em uma variável e assim reutilizada.
Nos blocos do scratch:
Primeiro argumento -
input (What’s your name?) → algoritmo (ask and wait) → output (answer)
Segundo argumento -
input ( dois blocos - hello, answer) → algoritmo (join ) → output (hello, joão) → que acaba sendo o input para a próxima função de say e retorna o gato dizendo a frase.

Argumento é o input para uma função