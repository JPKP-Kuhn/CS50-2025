# SQL e bancos de dados

Cada linguagem de programação fornece algum nível de abstração e são úteis para algumas coisas. Falando sobre banco de dados e sobre a tarefa de buscar e visualizar dados, também há uma linguagem ideal para isso, o SQL.

Para antes de entender o que é o SQL, vamos entender sobre como guardamos nossos dados.

## flat-file database
O banco de dados mais simples possível no mundo, pois apneas usa um arquivo de texto, com vaŕios textos, diferentes linhas ou colunas. Mas também há uma forma de definir os dados nesses arquivos de texto.

### CSV Comma-Separated-Values
Guardar informações de uma forma bem simples, com apenas texto, cada entrada tem a sua própria linha, informações guardadas linha a linha, row by row, ou line by line; e há uma separação por vírgula para separar as colunas. Também tem outros, como o tsv, tab separated values.
`Timestamp,language,problem` Por exemplo essa linha, a primeira, representa o cabeçalho das colunas.
Usar python para ler os dados de um arquivo csv é interessante, mas mais trabalhoso. É necessário às vezes mudar e escrever linhas de código para conseguir coletar ou filtrar as informações desejadas.

## Bancos de dados Relacionais
Guardar dados de uma forma que seja possível relacionar dados. Criar relações entre pedaços de dados.

### SQL - Structure Query Language, linguagem desenhada especificamente para bancos de dados.
Tem o poder de fazer vários filtros e buscas de dados em bancos de dados em um linha de código, de forma bastante eficiente.
O SQL é capaz basicamente de 4 funcionalidades que são conhecidas como CRUD (CREATE, READ, UPDATE, DELETE) isso é um conceito geral para fazer essas 4 operações em um banco de dados. Com SQL a única diferneça em nome de comando é que a função READ é SELECT, o resto têm o mesmo nome. Além de CREATE, também tem o INSERT e além de DELETE tem o DROP.

Os dados em databases são guardados em tabelas, com linhas e colunas. Conjuntos de dados são chamados de tabelas. `CREATE TABLE table (column type, ...);`
Para essas aulas será utilizado o sqlite3.

### Padrões para bancos de dados relacionais
É importante ter uma forma inteligente de organizar os dados da tabela de forma inteligente, para ter uma tabela menor e sem repetição. Com isso tem boas práticas para criar essas tabelas. Uma forma é usando Ids para cada valor, por exemplo, uma tabela com filmes e seus atores. Posso ter um ID único para cada ator e para cada filme. Com isso cada ID pode ser associado em uma outra tabela, diferente de onde esses IDs foram declarados.
Com SQL fica fácil relacionar esses IDs para serem associados entre si.

## Tipos de relações
Tratando de bancos de dados relacionais, há diversas formas de relações possíveis para organizar melhor os dados.
### One to one 
Cada objeto leva a apenas um outro, exemplo, cada filme (tabela filme) leva a uma única avaliação sua, (leva a apenas um elemento da tabela de avaliação). Explicando melhor, na verdade é porque na tabela de avaliações, há apenas uma única referência a um outro elemento de uma outra tabela separada.
```sql
sqlite> .schema shows
CREATE TABLE shows (
    id INTEGER,
    title TEXT NOT NULL,
    year NUMERIC,
    episodes INTEGER,
    PRIMARY KEY(id)
);
sqlite> .schema ratings
CREATE TABLE ratings (
    show_id INTEGER NOT NULL,
    rating REAL NOT NULL,
    votes INTEGER NOT NULL,
    FOREIGN KEY(show_id) REFERENCES shows(id)
);
```
- - -
- **Sobre os tipos de dados no SQL**
INTEGER -> Números inteiros
NUMERIC -> Coisas que são números como datas, anos, tempo, têm uma semântica diferente
REAL -> Valores decimais, com ponto flutuante.
TEXT -> para texto, stirng
BLOB -> Binary Large Object, guardar binários puros
- **Fornecem alguma proteção contra insert ou update de dados que esteja fora do padrão da tabela.**
NOT NULL -> Não pode ser nulo, obrigatoriamente precisa preencher uma valor
UNIQUE -> Precisa ser único, como IDs únicos
- Relacionar os IDs
PRIMARY KEY -> ID único do objeto
FOREIGN KEY -> ID de um outro objeto

### One to Many
Um filme pode ter vários gêneros ao mesmo tempo, assim numa tabela de gêneros de filmes, como essa:
```sql
sqlite> .schema genres
CREATE TABLE genres (
    show_id INTEGER NOT NULL,
    genre TEXT NOT NULL,
    FOREIGN KEY(show_id) REFERENCES shows(id)
);
```
Teremos repetido por exemplo o gênero comédia, pois vários shows são de comédia, mas cada comédia tem um show_id único para os shows.

### Many to Many
Uma relação entre shows de tv e estrelas de tv, um ator pode estar em vários filmes. Então apenas duas tabelas não se torna suficiente para representar todas as relações.

### Indexes
Assim como nas estruturas de dados, podemos também criar um design melhor para nossos bancos de dados, de forma que otimizem a busca, as queries. Podemos guardar informações em índices, de forma a agilizar algumas queries.
Criar um Index ->
`CREATE INDEX name ON table (column, ...);` 
Com isso é criada uma B-tree na memória, que acelerará muito as queries que forma especificadas. Uma B-tree, não é que nem uma binary tree, a B-tree busca ser a mais curta possível, diminuir a distância da raíz para as folhas, porém para isso, ela acaba sendo bem larga, ou seja, os nós podem ter vários filhos.
Importante saber que o SQL vai tentar ainda manter essa tree balanceada, então para outraoperações, como INSERT e DELETE, serão prejudicas, ficarão mais lentas. Cabe a você decidir o qeu será melhor de acordo com a sua plaicação, se ela for muito mais e leitura e consulta, então criar um index será muito útil.

### Race conditions
Quando um processo está atualizando o valor de uma variável e ainda não foi atualizado, então outra função vê o valor desatualizado e decide mexer nele também. Deveria ter alguma forma de travar a mudança na variável ou de avisar que está sob mudança. Por exemplo nas redes sociais, quando tem muitas pessoas curtindo um post ao mesmo tempo (um post viral) fica difícil manter as informações corretas e atualizadas. Tem duas queries ocorrendo ao mesmo tempo, então por exemplo nas curtidas, uma pessoa apertar para curtir, então número de likes vai ser ++, porém ao mesmo tempo praticamente veio outra requisição de ++, só que a variável não foi atualizada ainda, então apenas faz ++ uma vez, enquanto que o correto deveria ter acontecido +=2.

Algumas correções para esse problema ->
BEGIN TRANSACITON - Execute todas essas funções, ou nenhuma delas. Assim fica uma tranca na atualização do databse.
```
db.execute("BEGIN TRANSACITON")
rows = db.execute("SELECT likes FROM posts WHERE id = ?", id);
likes = rows[0]["likes"]
db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes+1, id);
db.execute("COMMIT")
```
COMMIT - Fazer o commit das alterações feitas, para salvar.
ROLLBACK - Previnir inconsistências.

### SQL Injections Attacks
Também semlehante o prompt injeciton attack.
Em uma página de login, é colocado alguns caracteres que o SQL detecta e então acaba-se modificando a query.
por exemplo ' para fechar o input com format string do python, e depois --, pois é com isso que se comenta no SQL.
Usar o ? para entrar variáveis na query protege contra isso.
