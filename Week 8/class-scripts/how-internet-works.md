# Como a internet funciona?

Basicamente, a internet nada mais é do que vários computadores conectados entre si, de forma física ou virtual, por meio de fios ou sem, o que permite a comunicação entre computadores.
Conseguimos dados de um ponto A até um ponto B através dessas conexões.

## Arpanet

Primeira conexão entre computadores nos Estados Unidos, primeiramente entre universidades e para fins militares.

## Roteadores

São servidores cujo propósito é rotear informação de um ponto até outro. Lembrando que um servidor nada mais é do que um computador. Mas eles vivem em data centers. Mas é graças ao software que também permite com que eles definem como rotear essas informações.

- A linguagem, protocolo, utilizado pelos roteadores é o TCP/IP. Para redes de computadores é mais o IP na verdade, mas o TCP é utilizado junto.

### IP Adress, Internet Protocol

endereço que os computadores utilizam para enviar informações entre eles. Com ele, são criados os endereços dos computadores no mundo.
`#.#.#.#` cada `#`é um número de 0 até 255, ou seja, é usado um byte e ao todo um endereço ip tem 4 bytes. Atualmente já tem mais de 4 bilhões de computadores, máximo que esse protocolo permite, o Ipv4) então atualmente já tem o IPv6, ainda não amplamente utilizado.

Cabeçalho do protocolo IP -
0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |Version|  IHL  |Type of Service|          Total Length         |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |         Identification        |Flags|      Fragment Offset    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  Time to Live |    Protocol   |         Header Checksum       |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                       Source Address                          |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Destination Address                        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Options                    |    Padding    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

                    Example Internet Datagram Header
[Documento](https://datatracker.ietf.org/doc/html/rfc791)
Enviar uma mensagem é como enviar um envelope, em que você precisa passar algumas informações para que os carteiros possam entregar corretamente.
Com o endereço IP, os roteadores conseguem se comunicar entre si para descobrir qual outro roteador se comunica diretamente com o destinatário. O caminho pelo qual a mensagem será encaminhada é definido pelos roteadores que com seu software vão tentar fazer o mais rápido possível.

Para enviar arquivos muito grandes, os dados podem ser divididos, mas como os dados podem chegar em ordens diferentes, precisamos de um protoclo melhor para isso. Com isso tem o TCP.

### TCP Transmission Control Protocol

Um dos problemas que são resolvidos é que ele garante com certeza quantos pedaços de "envelope" estamos enviando, basicamente numerando eles para se tenha uma ordem, assim tmabém consegue saber se tem algum pacote faltando, o número de acknowledge.

Já temos muitas aplicações hoje em dia.
Uma coisa importante do tcp é que ele cria o conceito de portas, que são identificadores numéricos para serviços na internet. Por exemplo a porta 80 é para HTTP, já para o HTTPS usa a porta 443, 25 para emails, 22 para ssh, entre várias outras.
Agora os endereços possuem seu IP : porta, assim com essa porta sabemos exatamente qual o serviço que está rodando no endereço.

Os servidores em si trabalham com os endereços IP.

### DNS Domain Name System

Não usamos diretamente os números de endereço IP/TCP, então na verdade o DNS consegue associar um nome, uma string, a um endereço ip.
No mundo existem os servidores de DNS que traduzem os nomes para os endereços. São tabelas com duas colunas:
Fully Qualified Domain Name | IP Address
Os dados podem ser organizados de forma que seja mais acessado como primeiro.

Ao redor do mundo tem também servidores menores que fazem uma intermediação com os maiores servidores. Podem ser muitos servidores até que se consiga chegar no endereço desejado.

Os endereços IP não mudam com frequência, então os aparelhos podem guardar os endereços IP para que não seja necessário fazer uma nova busca nos servidores.

### DHCP Dynamic Host Configuration Protocol

Fornece para os computadores um endereço ip sempre que ele troca de roteador, vai para um novo lugar. O roteador fornece um endereço ip para os dispositivos.

Mas o DHCP também lhe informa outros detalhes importantes, ele também diz qual é o seu servidor DNS e qual o seu roteador.

---
Não é necssário que se programe todos esses protocolos diretamente para usá-los em aplicações, eles vêm em bibliotecas.

### HTTP Hypertext Transfer Protocol

Define com web browser e web seervers se comunicam entre si, outro é o HTTPS que usa criptografia de forma segura para esconder dados na requisição. http:// ou https:// são necessários para fazer uma busca

- <https://www.example.com/> este é um nome de domínio.
a barra no final é para carregar a página padrão do que você quer acessar.

Também é comum encontrar /path para acessar um diretório no servidor. Muitas está em busca de um arquivo .html que é como os sites são feitos. Com isso seria: <https://www.example.com/file.html>, ou se usar /folder/file.html
O domínio em si tá mais para o example.com, já o www é nome do servidor específico, do host name

Empresas grandes que precisam de muitos servidores com muitas páginas precisam de uma coleção de endereços, então o www serve para se referir a eles de uma forma mais geral.

TLD indica qual tipo de domínio é esse, ele é o .com, tem muitos atualmente. Cada país tem o seu, como .br. uk, mas outros com .io, .ai, .dev

o início diz o protocolo, https ou http que basicamente faz um aperto de mãos com o servidor para conseguir se comunicar com ele.

Os comandos, os "envelopes" que são trocados com os servidores são alguns exemplos a seguir:

GET - Para pegar informações do servidor, pegar um web page
POST - Para enviar mensagens para o servidor, pode ser informações sensíveis, cartão de crédito, ou preencher um formulário.

Um comando de GET, exemplo de um cabeçalho de http

```http
GET / HTTP/2
Host: www.harvard.edu
...
```

A resposta seria a seguinte:

```http
HTTP/ 2 200
Content-Type: text/html
...
```

```bash
curl -I https://www.harvard.edu/
```

O parâmetro -I mostra o cabeçalho da mensagem da requisição. Nessa requisição terá vários códigos com seus significados, como:
200 OK - Tudo certo, página carregada
301 Moved Permanently - O link da página foi trocado
`curl -I http://safetyschool.org/`
404 Not Found - A página procurada não existe
Entre muitos outros que ajudam a identificar erro do lado do usuário ou do lado do servidor
