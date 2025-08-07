# Inteligência Artificial
No curso do CS50 tem o rubber ducj para ajudar os alnos com os problemas.
IA na verdade não é tão recente como ocorreu nesses últimos anos, mas teve um significativo aumento do uso e da melhoria das ferramentas.

## IA Generativa
IA gerando alguma coisa, texto, imagem, vídeo, música.
Vai se tornar no futuro importante saber o que foi gerado por uma inteligência artificial ou não, porque a semelhança está ficando cada vez melhor.

Ferramentas como ChatGPT, Claude, Bing, ... São muito úteis, por darem uma resposta rápida e direta, mas se o estudante realmente quiser aprender é necessário um esforço maior.

### Engenharia de Prompt
Basicamente é como fazer boas perguntas para a IA. Não é exatamente uma engenharia, mas ela busca esutdar quais tipos de padrões que fazem a IA produzir uma resposta melhor para você. Isso funciona porque durante o desenvolvimento da IA, alguém desenvolveu um __system prompt__  que se torna um texto pronto para ser concatenado com o __user prompt__ que será a pergunta do usuário.

<br>

IA já vinha sendo usada antes, como identificar se um email é um spam e coloca-lo na caixa de spam automaticamente, identificar a caligrafia de uma pessoa e traduzi-la para o computador (pode ser difiícil de entender o garrancho de alguém) ou sugerir recomendações de filmes e séries baseado no que você já viu, ou sugestões de pessoas ou grupos para seguir nas redes sociais, baseado no conteúdo que você ou seus amigos fazem, também reconhecer voz. Ainda mais antigo são os jogos, com oponentes se comportando sozinho, tomando decisões por conta própria e essas IAs são treinadas com base em uma pontuação.

## Decision tree
Decidir as decisões, com um fluxograma de decisões, com uma condição, você decide sim ou não, então ocorrem outras ações. Como numa árvore binária.

Num jogo da velha, poderia ser algo assim:
Posso ganhar com 3 peças?
sim /                  não \ 
Jogar nessa posição    Meu oponente pode ganhar na próxima jogada?
sim /                   não \
Bloquear ele                Então aqui fica o problema, qual seria a melhor posição 

Já existe um algoritmo que resolve esse problema, garantindo pelo menos que nunca perca. É um tipo de algoritmo que se chama minimax. Maximizar um pontuação ou minimizar.

Supondo que para o O ganhar é uma pontuação de -1 e para o X é 1, portanto O quer minimizar e X quer maximizar. Basicamente, de forma simples, antes de executar uma jogada, é analisado o resultado das próximas, se é a vez de O e ele tem duas opções, uma que causa a vitória do X, portanto 1 outro que dá 0; O quer minizar, então a melhor é com a opção 0.
O problema de simplesmente fazer assim, é que a árvore vai ficar gigantesca. Há 255.168 posições possíveis para uma grade 3x3 no jogo da velha, gravar todas fica pesado.

<br>

IA não se trata tanto em dizer o que exatamente o computador deve fazer, mas sim ensinar o que eles devem fazer. Formas de ensinar: 
- Aprendizagem por Reforço; Reinforcement Learning
Recompensando ou punindo a IA de acordo com o seu retorno, se é o que eu queria, então positivo, continue assim, do contrário, está errado, evite isso.

Além disso tem também exploring vs exploiting. Exploit significa dar mais prioridade para o que já sabe que esta correto, então acha um resultado correto mais rápido, mas este pode não ser o melhor, pois com explore a ideia é tentar várias possibilidades, encontrando muitos erros, mas também soluções que podem ser melhores, para explorar é necessário um pouco de aleatoriedade. Com o chatGPT pode ter isso também, a IA pode alucinar tentando uma resposta diferente para saber se ela é melhor ou não.

<br>

Uma questão importante sobre aprendizagem por reforço é que é necessário alguém monitorando a IA, mas também existe outra forma de treiná-la sem supervisionamento, além disso também o deep learning, onde estão as redes neurais.

## Rede Neural
Vira um grafo, se duas função podem se comunicar ou chegar em um resultado, elas se conectam. Uma rede neural se torna uma caixa preta com tanta abstração que está sendo feita que não é possível apontar para um *neurônio* dessa rede e saber exatamente o que ele quer dizer, com base nos inputs dele. Large language model.

Mais recentemento com uma pesquisa do google, o transformer model, ele analisa qual é a relação entre as palavras, em 2017. Em 2020 foi publicado o GPT-3 Language Model. Em 2022 o ChatGPT Model. É um Generative Pre-Trained Transformers (GPT). Antes de 2017 era difiícil para uma IA ligar informações como nome do estado e então responder qual a capital desse estado. Se representa as palavras como uma tabela e então atribuir números para cada uma dessas palavras e então links entre palavras que estão mais relacionadas, como 'Massachessets' e 'state'.
