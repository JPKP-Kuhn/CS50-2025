# Python
Linguagem de programção de alto nível, no C tinha que fazer muita coisa, com python fica bem mais simples. Não é necessário gerenciar a memória, é possível iterar por arrays muito mais somples do que no C. Também tem várias bibliotecas escritas por outras pessoas. Assim, fica melhor focar nos problemas que realmente interessam a você.
```python 
print("Hello World")
```
Python é uma linguagem interpretada, enquanto o C é uma linguagem compilada; com C você escreve o código, compila, roda o código, modifica o código, compila, roda, ... para C tem vários compiladores, como clang ou gcc. Para o python tem um interpretador que é python que lida com o papel de fazer o código rodar, além de uma compilação própria dele, ou seja, não gera um arquivo binário, o programa roda direto pelo interpretador.
 A sintaxe é diferente, mas para se tornar um programador experiente é necessário se acostumar com a sintaxe de algumas linguagens diferentes para que, ao se deparar com uma nova, já tenha todas as noções básicas de como ele provavelmente deve funcionar, ter uma certa noção do código olhando pela primeira vez.
C é uma linguagem mais antiga comparada ao python, então muitas das coisas que no C eram meio chatas ou um pouco complicadas de se fazer, ficou facilitado com python, muitos programadores perceberam quais eram problemas comuns, então foram facilitando as coisas.
Python além de libraries, bibliotecas, também tem modules e packages

## Variable interpolation
```python
name = "Joao"
print(f"Hello, {name}")
```
Em versões anteriores seria print("Hello, ", name) ou usar um + para concatenar as strings
No python também não é necessário declarar os tipos de dados das variáveis, o próprio interpretador descobre isso, conforme é usado no código.
Argumentos posicionais primeiro, depois argumentos nomeados. Isso acontece com o próprio print(*objects, sep=' ', end='\n', ...) *objects significa que pode ser mais de uma argumento, podendo ser uma string ou outros dados, para modificar end ou sep, preciso passar como argumento por exemplo para tirar quebra de linha print("Hello, world", end="!\n")
[Documentação oficial do Python](https://docs.python.org/3/)

## Orientação a Objetos (POO)
Um objeto seria basicamente uma versão melhorada das struct do C, os objetos, ou classes, podem adicionar uma funcionalidade, além de variáveis, que tinha nas structs, eu posso adicionar funções, essas funções que estão associadas a um tipo de dado recebem o nome de métodos.
