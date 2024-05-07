# Jogo da Velha em C

Um simples jogo da velha implementado em C.

## Descrição

Este é um jogo da velha básico implementado em C, onde dois jogadores podem jogar alternadamente até que um deles vença ou haja um empate. O tabuleiro é representado em um array bidimensional, e as jogadas são feitas através da entrada do usuário no terminal.

## Funcionalidades

- Jogo da velha tradicional com interface de linha de comando.
- Verificação de vitória ou empate após cada jogada.
- Opção para jogar novamente após o término de uma partida.

## Pré-requisitos

- Compilador C (GCC, Clang, etc.) instalado no sistema.

## Como compilar e executar

1. Clone este repositório:

   ```bash
   git clone https://github.com/seu-usuario/jogo-da-velha-c.git
   ```

2. Navegue até o diretório do projeto:

   ```bash
   cd jogo-da-velha-c
   ```

3. Compile o código-fonte:

   ```bash
   gcc jogo_da_velha.c -o jogo_da_velha
   ```

4. Execute o programa:

   ```bash
   ./jogo_da_velha
   ```

## Regras do Jogo

1. O tabuleiro é uma grade 3x3.
2. Os jogadores alternam entre 'X' e 'O'.
3. O jogador que conseguir alinhar três de suas peças na horizontal, vertical ou diagonal vence.
4. Se todas as células do tabuleiro forem preenchidas sem nenhum vencedor, ocorre um empate.

