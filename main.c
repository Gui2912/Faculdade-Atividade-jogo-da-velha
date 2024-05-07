# include<stdio.h>
# include<ctype.h>

const int TAMANHO_TABULEIRO = 3;
const int FALSE = 0;
const int TRUE = 1;

int turno = 'X';

char querNovamente();
void zerarTabuleiro(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void preencherTabuleiro(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void imprimirTabuleiro(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void jogar(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
int ninguemVenceu(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int qtdJogadas);
int jogadaValida(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna);


int main()
{
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    do
    {
        zerarTabuleiro(tabuleiro);
        turno = 'X';

        jogar(tabuleiro);

    } while (querNovamente() == 's');

    return 0;
}

char querNovamente(){
    char opcao = ' ';
    do
    {
        printf("\n\nQuer jogar novamente (s/n)?");
        scanf(" %c", &opcao);

        opcao = tolower(opcao);

    } while (opcao != 's' && opcao != 'n');

    return opcao;

}

void zerarTabuleiro(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    for (int i = 0; i < TAMANHO_TABULEIRO; i++){
        for(int j = 0; j < TAMANHO_TABULEIRO; j++){
            mtr[i][j] = ' ';
        }
    }
}

void preencherTabuleiro(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){

}

void imprimirTabuleiro(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    printf("   1   2   3\n");
    for(int i = 0; i < TAMANHO_TABULEIRO; i++){
        if(i != 0){
            printf("  ---+---+---\n");
        }
        printf("%d ", i+1);
        for(int j = 0; j < TAMANHO_TABULEIRO; j++){
            if(j != 0){
                printf("|");
            }
            printf(" %c ", mtr[i][j]);
        }
        printf("\n");
    }
}



void jogar(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    int jogadas = 0;
    int linha;
    int coluna;

    do
    {
        imprimirTabuleiro(mtr);
        printf("Agora é a vez do jogador %c\n", turno);
        printf("Entre com sua jogada!\n");
        do
        {
            printf("Digite uma linha: ");
            scanf("%d", &linha);

            printf("Digite uma coluna: ");
            scanf("%d", &coluna);
        } while (!jogadaValida(mtr, linha -1, coluna -1));

        mtr[linha -1][coluna -1] = turno;
        turno = (turno == 'X')? 'O' : 'X';
        jogadas++;

    } while (ninguemVenceu(mtr, jogadas));

    imprimirTabuleiro(mtr);

    turno = (turno == 'X')? 'O' : 'X';

    if(jogadas != 9){
        printf("\n%c venceu!\n", turno);

    }
    else{
        if(!ninguemVenceu(mtr,0))
        {
            printf("%c venceu!\n", turno);
        }
        else
        {
            printf("Empatou!");
        }
    }
}

int ninguemVenceu(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int qtdJogadas)
{
    int alguemVenceu = FALSE;

    if(
            mtr[0][0] == mtr[0][1]
            && mtr[0][1] == mtr[0][2]
            && mtr[0][0] != ' ')
    {
        alguemVenceu = TRUE;
    } else if( mtr[1][0] == mtr[1][1]
               && mtr[1][1] == mtr[1][2]
               && mtr[1][0] != ' ')
    {
        alguemVenceu = TRUE;
    } else if( mtr[2][0] == mtr[2][1]
               && mtr[2][1] == mtr[2][2]
               && mtr[2][0] != ' ')
    {
        alguemVenceu = TRUE;
    }else if(mtr[0][0] == mtr[1][0]
             && mtr[1][0] == mtr[2][0]
             && mtr[1][0] != ' ')
    {
        alguemVenceu = TRUE;
    }else if(mtr[0][1] == mtr[1][1]
             && mtr[1][1] == mtr[2][1]
             && mtr[1][1] != ' ')
    {
        alguemVenceu = TRUE;
    }else if(mtr[0][2] == mtr[1][2]
             && mtr[1][2] == mtr[2][2]
             && mtr[1][2] != ' ')
    {
        alguemVenceu = TRUE;
        //Começando a verificar as diagonais
    }else if(mtr[0][0] == mtr[1][1]
             && mtr[1][1] == mtr[2][2]
             && mtr[0][0] != ' ')
    {
        alguemVenceu = TRUE;
    }else if(mtr[0][2] == mtr[1][1]
             && mtr[1][1] == mtr[2][0]
             && mtr[0][2] != ' ')
    {
        alguemVenceu = TRUE;
    } else if(qtdJogadas == 9){
        alguemVenceu = TRUE;
    }

    return !alguemVenceu;
}

int jogadaValida(char mtr[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna)
{
    if(
            (linha < 0 || linha >= TAMANHO_TABULEIRO) ||
            (coluna < 0 || coluna >= TAMANHO_TABULEIRO) ||
            (mtr[linha][coluna] != ' ')
            ){
        printf("Jogada Inválida\n");
        return FALSE;
    }

    return TRUE;
}
