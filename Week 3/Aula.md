# Algoritmos
Como posso buscar um valor de forma inteligente?
Desde a primeira semana já foi apresentado sobre um código que procura um nome numa lista telefônica. Se olhar página por página, esse algoritmo levará um  tempo de n, supondo que tenha que percorrer a lista inteira, o que nos limita é o próprio tamanho da lista. Mas como podemos sere mais eficientes e mais rápidos nessa busca? Olhando a cada duas páginas, o que nos dá n/2 ou melhor ainda, abrir no meio da lista e assim ir trabalhando apenas com a metade, assim será log2(n)

Vamos tratar como se computadores fossem capazes de olhar apenas para um espaço da memória por vez, na verdade atualmente eles conseguem fazer várias coisas ao mesmo tempo.

pseudocódigo:
For i from 0 to n-1 
    if 50 is behind doors[i]
        Return true
Return false

Binary search, divide o problema em duas partes menores
pseudocódigo:
if no doors left
    return false
if 50 is behind middle door 
    return true
else if 50 < middle door 
    search left half
else if 50 > middle door
    search right half

Binary search não é sempre eficiente, na verdade, é necessário primeiro organizar os dados para poder usar esse algoritmo

## Asymptotic Notation
### Big O notation
Upper bound, o maior tempo possível
Usar um O para dizer o tempo que leva para executar um algoritmo
Para os dois que levam n e n/2 apenas dizemos O(n) porque para ambos, se n for muito grande, vai demorar muito do mesmo jeito. Já o outro que era log2(n) dizemos O(log n)
Algumas notações comuns de se encontrar:
- O(n²)
- O(n log n)
- O(n) linear search
- O(log n) binary search
- O(1)

### Big Ômega (letra grega)
lower bound, o menor tempo possível
Em linear search seria Ômega(1) porque pode estar logo na primeira porta; binary search também está aqui, pois podemos ser sortudos e o que procuramos está no meio

### Big Theta notation
Quando um algoritmo tem um O e um Ômega iguais


## Sorting
Como posso organizar os dados? Como já foi visto nos tipos de search, posso precisar dos dados organizados ou não.
Se eu tiver poucos dados, pode não ser necessários organizá-los, pois perco mais eficiência fazendo isso. 
Mas se eu precisar de usar muitos dados, torna-se importante.
Então como posso organizar?

Há vários algorítmos de organização, por exemplo:
Dada uma lista de números e quero organizá-los em ordem crescente:
Olho elemento por elemento e salvo quem é o menor número da lista, após percorrer ela toda, já sei quem é o menor número e troco ele da posição em que está com o número que está na primeira posição, assim, o primeiro elemento está na posição correta. Agora começo pelo segundo elemento e novamente, guardo o menor e troco ele de lugar com o número da segunda posição e repito até verificar que está organizada.

Outra maneira, é eu ficar olhando pares de números e trocar a posição deles entre si. Ou seja, primeiro olho o primeiro e o segundo, se o primerio é maior que o segundo, eu troco a posição deles, se não eu mantenho assim; depois olho o segundo e o terceiro e aplico a mesma regra. No fim, sei que o último elemento estará correto, então da próxima só percorrer o total-1.

### Selection sort
É o primeiro exemplo de sorting, percorre até encontrar o menor elemento e move para o início. Não é muito eficiente O(n²), faz muitas comparações repetidas.

pseudocódigo:
For i from 0 to n-1
    Find smallest number between numbers[i] and numbers[n-i]
    Swap smallest number with numbers[i]

E quanto ao Ômega desse código? Também é n², porque no melhor caso, a lista já está ordenada, mas pelo pseudocódigo, isso não é verificado. Assim selction sort é um algoritmo de Theta(n²)

### Bubble sort
pseudocódigo:
Repeat n times 
    For i from 0 to n-2 
        If numbers[i] and numbers[i+1] out of order 
            Swap them

També é O(n²), mas em Ômega também é n² se eu adicionar um if no Swaps: Quit; então Ômega(n)


## Recursividade
Uma função recursiva é uma função que chama a si mesma, ou seja, return functionName();
exemplo de pseudocódigo de busca binária:
If no doors left
    Return false
If number behind middle door
    Return true
Else if number < middle door
    Search left half
Else if number > middle door
    Search right half

## Merge Sort 
pseudocódigo
if only one number
    Quit
else
    Sort left half of numbers
    Sort rigth half of numbers
    Merge sorted halves

Aponta para a metade, então compara o primeiro da metade da esquerda com o primeiro da metade direita. Eficiência de O(n), mas ele precisa de uma outra lista para poder organizar
Ele vai dividindo a lista pela metade até os dois primeiros elementos e aí compara os dois, organiza eles e então coloca de volta na lista original.
Fica como um O(logN), mas como precisa repetir esse processo de acordo com o tamanho da lista, então o big O do merge sort é de O(n log n)
