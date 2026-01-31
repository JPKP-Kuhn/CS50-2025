# HTML HyperText Markup Language
Linguagem para texto nos sites. Ela é baseada em tags e atributos.

```html
<!DOCTYPE html>

<html lang="en">
    <head>
        <title>
            hello, there
        </title>
    </head>
    <body>
        General Kenobi!
    </body>
</html>
```

O ambiente de código do curso, cs50.dev ou melhor: https://cs50.dev/ é um servidor para o vs code do github, o code spaces

Também podemos abrir um servidor http na própria máquina com o comando http-server

O DOCTYPE serve para declarar qual é o tipo de documento, versão 5 do html é a atual.
Depois começa a primeira tag que começa o html, com <html> dentro tem o atributo para a língua, depois começa o head, title. Tem o open tag e o end tag.
Algumas dessas tags básicas, são essenciais e devem estar presentes apenas uma delas e devem estar nas suas posições corretas.

O browser organiza os elementos com base no DOM (Document Object Model) que basicamente é uma estrutura de árvore. Quando o web browser acessa um página da web, ele analisa o DOM daquela página