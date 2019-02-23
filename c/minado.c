
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

//Definindo as minahas constantes para verificar acoes
#define vazio 0 //posicoes vazias/casas vazias
#define bombas 1 //posicao com bombas
#define bombasProximas 2 //quantidade de bombas proximas



/* Jogo em c campo minado:
Desenvolvido por Leonildo Carvalho
Criação dia: 05/09/2012
Ultima Atualização: 21/09/2012
Correção das matrizes que gera os numeros aleatorios
30-09-2012 atualizacao */

//variáveis globais
int TAMBombas;
int TAMCampo;

//variaveis que calculam o contador de tmepo
clock_t tInicio, Tfim;//declarando as variaveis da contagem do tempo
double tDecorrido; //variavel do tipo double para armazenar todo o tempo decorrido


//prototipo das funções
void fMenu1();
void fMenu2();
void fConfigurar();
void fJogar();
void tempoInicio ();
void tempoFim();


int main()
{
    fMenu1();

    return 0;
}
//inicio do jogo
void fMenu1(){

    //limpando buffer do teclado
    fflush(stdin);
    //variaveis
    char escolha;

    printf(":::::CAMPO MINADO:::::\n\nMENU INICIAL\n\n");
    printf("(C) Configurar\n(S)Sair\n");
    scanf("%c",&escolha);

    //usando a biblioteac ctype.h para tratar a letra e transformando em maiuscula a letra digitada ex: se recebe c transforma em C
    escolha=toupper(escolha);

    switch(escolha){

        case 'C': fConfigurar();
        break;

        case'S': exit(1);
        break;

        default: printf("Opcao invalida!!!\nC - Configurar e S - Sair\n");
        system("PAUSE");
        system("cls");
        fMenu1();
        break;

        return;
    }
}


//funcao opcao configurar
void fConfigurar(){

    //variaveis
    char nomeJogador[30];
    int quantBombas, tamanhoCampo;

    system("cls");
    printf("CAMPO MINADO\n");
    printf("Nome do jogador: \n");
    fflush(stdin);
    gets(nomeJogador);
    printf("Tamanho do campo minado (6/8/10):  \n");
    scanf("%d",&tamanhoCampo);
    printf("Quantidade de bombas (10/12/14): \n");
    scanf("%d",&quantBombas);

    //testando as opcoes
    if ((tamanhoCampo==6 || tamanhoCampo==8 || tamanhoCampo==10) && (quantBombas==10 || quantBombas==12 || quantBombas==14)){
        system("cls");

        TAMBombas=quantBombas;
        TAMCampo=tamanhoCampo;
        fMenu2();

    }else{
        printf("\n\nERRO: escolha as opcoes de acordo com o menu...\nPressione qualquer tecla voltar as configuracoes...\n\n\n\n");
        printf("\a\a"); // a serve para emitir um beep
        system("PAUSE");
        fConfigurar();
    }


    return;
}

//Funcao jogar
void fMenu2(){

    //limpando buffer do teclado
    fflush(stdin);
    //variaveis
    char escolha;

    printf(":::::CAMPO MINADO:::::\n\nMENU INICIAL\n\n");
    printf("(C) Configurar\n(J)Jogar\n(S)Sair\n");
    scanf("%c",&escolha);

    //usando a biblioteac ctype.h para tratar a letra e transformando em maiuscula a letra digitada ex: se recebe c transforma em C
    escolha=toupper(escolha);

    switch (escolha){

        case 'C': fConfigurar();
        break;

        case 'J': fJogar();

        case'S': exit(1);
        break;

        default: printf("Opcao invalida!!!\nC - Configurar e S - Sair\n");
        system("PAUSE");
        system("cls");
        fMenu1();
        break;

    }

    return;

}

void fJogar(){

    //iniciando o contador de tempo (chamando a funcao que criei)
    void tempoInicio();

//inicializado minha matriz

    //matriz que gera os numeros aleatorios, (entrada)

    int matrizCampo [TAMCampo][TAMCampo];
        int i,j;
        srand(time(NULL));

        for (i=0; i<TAMCampo; i++){
            for (j=0; j<TAMCampo; j++){
             matrizCampo [i][j]=0; //iniciando a matriz com zero
                matrizCampo[i][j]=rand()%TAMBombas;


            }

        }

        //matriz que imprime os numeros aleatorios (saida)

        for (i=0; i<TAMCampo; i++){
            for (j=0; j<TAMCampo;j++){
                printf("%d ", matrizCampo[i][j]); //o %d é usado para dar espaço entre as colunas
            }

            printf("\n");
       }





    //chamado a funcao que finaliza e exibe o contador do tempo
    void tempoFim();
}

void tempoInicio (){

    //iniciando a contagem do tempo
    tInicio=clock();
}

 void tempoFim(){

    //terminando a contagem do tempo
    Tfim=clock();

    //calcuulando o tempo decorrido
    tDecorrido=((double)(tInicio-Tfim)/CLOCKS_PER_SEC); //aqui simplesmente estamos calculando o tempo que inicio e o tempo que terminou e subtraindo o valor

    printf("Tempo gasto: %lf s\n", tDecorrido);
}
