//#include <iostream>
#include <stdio.h>
int main (){
char matriz[5][5];
char matrizera[5][5];
int ponto = 0;
int bomba=0;
int vencer=0;
int lin;
int col;
int linha;
int coluna;

for(linha=0;linha<5;linha++){
    for(coluna=0;coluna<5;coluna++){
        matriz[linha][coluna] = 'o';
        matrizera[linha][coluna] = 'o';
    }
}
for(linha=0;linha<3;linha++){
    do{
        do{
            printf("Linha da bomba: ");
            scanf("%d",&lin);
        } while(lin<0 || lin>4);
        do{
            printf("Coluna da bomba: ");
            scanf("%d",&col);
        } while(col<0 || col>4);
    if (matrizera[lin][col] == 'x'){
        printf ("\nPosicao repitida\n");
        }
    } while (matrizera[lin][col] == 'x');
matrizera[lin][col] = 'x';
}


do{
    do{
    for(linha=0;linha<5;linha++){
        for(coluna=0;coluna<5;coluna++){
            printf("%c",matriz[linha][coluna]);
        }
        printf("\n");
    }
    do{
        printf("Linha da bomba: ");
        scanf("%d",&lin);
    } while(lin<0 || lin>4);
    do{
        printf("Coluna da bomba: ");
        scanf("%d",&col);
    } while(col<0 || col>4);
    if (matriz[lin][col] == '*'){
        printf ("\nPosicao Repitida\n");
    }
    } while(matriz[lin][col] == '*');
    if(matrizera[lin][col] == 'x'){
        bomba++;
    } else {
        ponto ++;
        matriz[lin][col]='*';
        matrizera[lin][col]='*';
    }
system("cls");
} while (ponto  < 10 && bomba != 1);

if (bomba > 0 ){
    printf ("O jogador 1 foi o vencedor: \n");
}else{
    printf ("O jogador 2 foi o vencedor: \n");
}
for(linha=0;linha<5;linha++){
        for(coluna=0;coluna<5;coluna++){
            printf("%c",matrizera[linha][coluna]);
        }
        printf("\n");
    }}
