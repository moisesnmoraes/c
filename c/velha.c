#include<stdio.h>       //bibliotecas
#include<string.h>
#include <stdlib.h>
main(){                // corpo principal
       int i,j,k,n;   //variaveis
       int quadro[3][3];       
       int opcao;
       int simbolo;
       int continua;
       char nome1[20];
       char nome2[20];
       int p1,p2;
       int fim;
       int velha;
       int invalido;
       int vence1, vence2;
       int resp;       
       int jogada1,jogada2;
       int ponto1,ponto2;       
       int ajuda;
       int melhor;
       int cont;
      
              
        comeco:
        system("cls");
        fflush(stdin); //quadro inicial de boas vindas
        printf(" _____________________________________________________________________________\n");
        printf("|                                                                             |\n");       
        printf("|\t ________________________________________________________________     |\n");
        printf("|\t|                       JOGO DA VELHA                            |    |\n");
        printf("|\t|________________________________________________________________|    |\n");
        printf("|                                                                             |\n");
        printf("|\t ________________________________________________________________     |\n");
        printf("|\t|  Programa Desenvolvido Para Finalidade Academica               |    |\n");
        printf("|\t|  Utilizando-se plataforma Windows                              |    |\n");
        printf("|\t|  Ferramenta Utilizada: Dev - C ++                              |    |\n");
        printf("|\t|  Desenvolvedor: Moisés Niehues Moraes                          |    |\n");
        printf("|\t|                                                                |    |\n");
        printf("|\t|                                                                |    |\n");
        printf("|\t|                                                                |    |\n");
        printf("|\t|________________________________________________________________|    |\n");
        printf("|                                                                             |\n");
        printf("|                                                                             |\n");
        printf("|                                                                             |\n");
        printf("|                                                                             |\n");
        printf("|                  PARA MELHOR RESOLUCAO, MAXIMIZE A TELA E                   |\n");
        printf("|                      PRESSIONE UMA TECLA PARA INICIAR!                      |\n");
        printf("|                                                                             |\n");
        printf("|                                                                             |\n");
        printf("|_____________________________________________________________________________|\n");
        getchar(); 
 
        while (resp != 4){           //estrutura condicional que roda o menu
              inicio:
              continua = 0;
              k = 0;
              resp = 0;
              p1 = 1;
              p2 = 1; 
              jogada1 = 0;
              jogada2 = 0;
              ponto1 = 0;
              ponto2 = 0;
              ajuda = 0;
              fim =0;
              velha = 0;
              invalido = 0;
              vence1 = 0;
              vence2 = 0; 
              melhor = 1;
             
             
              novo:
              system("cls");
              printf(" _____________________________________________________________________________\n");
              printf("|                                                                             |\n");       
              printf("|      _________________________________________________________________      |\n");
              printf("|     |                     JOGO DA VELHA                               |     |\n");
              printf("|     |_________________________________________________________________|     |\n");
              printf("|                                                                             |\n");
              printf("|                                                                             |\n");
              printf("|                           |------->MENU<-------|                            |\n");
              printf("|                           |____________________|                            |\n");
              printf("|                           | 1 - JOGO RAPIDO!   |                            |\n");
              printf("|                           | 2 - MELHOR DE 3!   |                            |\n");
              printf("|                           | 3 - INICIAL!       |                            |\n");
              printf("|                           | 4 - SAIR!          |                            |\n");
              printf("|                           |____________________|                            |\n");
              printf("|                                                                             |\n");
              printf("|                                                                             |\n");
              printf("|                                                                             |\n");
              printf("|_____________________________________________________________________________|\n");              
              printf("                          Agora, entre com sua opcao: ");
              scanf("%d",&resp);
              if((resp > 4)||(resp < 1)){
                   printf("\n\n\t\t\t        >>  OPCAO INVALIDA!\n\t\t\t>>  PRESSIONE ENTER E TENTE OUTRA VEZ!\n\n\n\n\n\n\n\n\n\n");
                   system("PAUSE");
                   goto inicio;   
              }              
        
              switch(resp){                  //avalia as opcoes digitadas
                    case 2:
                           melhor = 1;
                           for (k=0; k<3; k++){
                           melhor ++;
                           jogada1 = 0;
                           jogada2 = 0;
                           if (melhor != 0)
                                goto pula;
                           
                           
                           rapido:
                           melhor = 0;
                           pula:
                           continua = 0;
                           if (k != 0)
                                goto primeiro;
                           fim = 0;
                           jogada1 = 0;
                           jogada2 = 0;
                           
                           while(continua == 0){
                                 repete:         
                                 ajuda = 0;
                                 system("cls");
                                 printf(" _____________________________________________________________________________\n");
                                 printf("|                                                                             |\n");       
                                 printf("|      _________________________________________________________________      |\n");
                                 printf("|     |               ARVORE DE JOGOS - O JOGO DA VELHA                 |     |\n");
                                 printf("|     |_________________________________________________________________|     |\n");
                                 printf("|                                                                             |\n");
                                 printf("|                                                                             |\n");
                                 printf("|              ____________________        ____________________               |\n");
                                 printf("|             |ESCOLHA SEU SIMBOLO |      |ESCOLHA SEU OPONENTE|              |\n");
                                 printf("|             |____________________|      |____________________|              |\n");
                                 printf("|             | >> 1 p/jogar com 1 |      | >> 1 = MAQUINA     |              |\n");
                                 printf("|             | >> 2 p/jogar com 2 |      | >> 2 = PLAYER 2    |              |\n");
                                 printf("|             |                    |      | >> 3 = VOLTAR      |              |\n");
                                 printf("|             |____________________|      |____________________|              |\n");
                                 printf("|                                                                             |\n");
                                 printf("|                                                                             |\n");
                                 printf("|_____________________________________________________________________________|\n");
                                 printf("\n\n               Digite sua opcao:           Digite sua opcao: \n");
                                 printf("                                 ");
                                 fflush(stdin);
                                 scanf("%d",&simbolo);
                                 if (simbolo == 1){
                                      p1 = 1; 
                                      p2 = 2;                                  
                                 }
                                 else{
                                      p2 = 1;
                                      p1 = 2;
                                 }
                                 printf("                                                             ");
                                 scanf("%d",&opcao);   
                                 if ((opcao > 3)||(opcao < 1)||(simbolo > 2)||(simbolo < 1)){
                                      printf("\n\n\t\t\t        >>  OPCAO INVALIDA!\n\t\t\t>>  PRESSIONE ENTER E TENTE OUTRA VEZ!\n\n\n\n\n\n\n\n\n\n");
                                      system("PAUSE");
                                      goto repete;
                                 }
                                 switch(opcao){
                                       case 1:
                                             strcpy(nome2,"MAQUINA"); 
                                             ajuda = 1;                                                                 
                                       break;  
                                       case 2:
                                             strcpy(nome2,"JOGADOR 2");                        
                                       break; 
                                       case 3:
                                             continua = 3;
                                       break;        
                                 }
                                 
                                 if (continua == 3 ){
                                      printf("\n\n\t\t   >>  VOCE OPTOU POR VOLTAR AO MENU INICIAL!\n\t\t     >>  PRESSIONE ENTER E TENTE OUTRA VEZ!\n\n\n\n\n\n\n\n\n\n");
                                      system("PAUSE");
                                      goto novo;
                                 }
                                 
                                 else{                        
                                      printf(" _____________________________________________________________________________\n");
                                      printf("|                                                                             |\n"); 
                                      printf("|                                                                             |\n");    
                                      printf("|>>  NOME DO JOGADOR 1 : ");
                                      fflush(stdin);
                                      fgets(nome1,20,stdin);
                                      printf("\n|                                                                             |\n");  
                                      if (ajuda == 1){
                                           fflush(stdin);
                                           printf("|>>  SEU ADVERSARIO SERA A MAQUINA!                                           |\n");
                                      }
                                      else{
                                           printf("|>>  NOME DO JOGADOR 2 : ");
                                           fflush(stdin);
                                           fgets(nome2,20,stdin);
                                      }
                                      printf("\n|_____________________________________________________________________________|\n\n\n");
                                      printf("\n\n\t\t   >>  PRESSIONE ENTER PARA COMECAR A JOGAR!\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                      system("PAUSE");       //quadro jogo da velha
                                      primeiro:
                                      fim = 0;
                                      for (i=0; i<3; i++){
                                           for (j=0; j<3; j++){
                                               quadro[i][j] = 0;
                                           }
                                      }    
                                      tabela:
                                      resultado:
                                      invalido = 0;                                        
                                      system("cls");
                                      printf(" _____________________________________________________________________________\n");
                                      printf("|                                                                             |\n"); 
                                      printf("|                           PLACAR E DADOS DO JOGO                            |\n");
                                      printf("|_____________________________________________________________________________|\n");
                                      printf("\n");
                                      printf("   >>JOGADOR 1 = %s   >>JOGADOR 2 = %s\n",nome1,nome2); 
                                      printf("\n");                  
                                      printf("\n      >>JOGADOR 1 JOGA COM : %d       >>JOGADOR 2 JOGA COM : %d",p1,p2);
                                      printf("\n      >>JOGADOR 1 JOGADAS  : %d       >>JOGADOR 2 JOGADAS  : %d",jogada1,jogada2);
                                      printf("\n      >>JOGADOR 1 PONTOS   : %d       >>JOGADOR 2 PONTOS   : %d",ponto1,ponto2);
                                      printf("\n _____________________________________________________________________________\n");
                                      printf("|   >>HORIZONTAL = NUMERO DE COLUNA                                           |\n");
                                      printf("|   >>VERTICAL   = NUMERO DE LINHA                                            |\n");
                                      printf("|_____________________________________________________________________________|\n\n\n\n");
                                      printf("\n\n\n");
                                      printf("       _________________________________________________________________     \n");
                                      printf("      |                      JOGO DA VELHA                              |    \n");
                                      printf("      |_________________________________________________________________|    \n");
                                      printf("\n\n");
                                      printf("\t\t\t        1       2      3\n\n\n");
                                      printf("\n");
                                      printf("\t\t\t            |      |      \n");
                                      printf("\t\t\t1        %d  |   %d  |   %d  \n",quadro[0][0],quadro[0][1],quadro[0][2]);
                                      printf("\t\t\t      ______|______|______\n");
                                      printf("\t\t\t            |      |      \n");
                                      printf("\t\t\t2        %d  |   %d  |   %d  \n",quadro[1][0],quadro[1][1],quadro[1][2]);
                                      printf("\t\t\t      ______|______|______\n");
                                      printf("\t\t\t            |      |      \n");
                                      printf("\t\t\t3        %d  |   %d  |   %d  \n",quadro[2][0],quadro[2][1],quadro[2][2]);
                                      printf("\t\t\t            |      |      \n");
                                      printf("\n\n\n"); 
                                      if (fim == 1)
                                           goto baixo;
                                      if (jogada1 > jogada2)           //determina qual a vez de cada jogador  -> jogador 1
                                           goto jogador2;              
                                      printf("\n\t\t\t>>JOGADOR 1 COLUNA A MARCAR = ");
                                      scanf("%d",&j);
                                      printf("\n\t\t\t>>JOGADOR 1 LINHA A MARCAR  = ");
                                      scanf("%d",&i);
                                      if ((i>3)||(j>3)){
                                           printf("\n\n\n\n\t\t\t        >>  OPCAO INVALIDA!\n\t\t\t>>  PRESSIONE ENTER E TENTE OUTRA VEZ!\n\n\n\n\n\n\n\n\n\n");
                                           invalido = 1;
                                           system("PAUSE");   
                                      }
                                      if (quadro[i-1][j-1] == 0){
                                           quadro[i-1][j-1] = p1;
                                           jogada1 = jogada1 + 1;
                                      }
                                      else{
                                           if (invalido == 0){
                                                printf("\n\n\n\n\t\t\t         >>  OPCAO OCUPADA!\n\t\t\t>>  PRESSIONE ENTER E TENTE OUTRA VEZ!\n\n\n\n\n\n\n\n\n\n");
                                                system("PAUSE");
                                           }
                                      }                                        // -> jogador 2
                                      goto proximo;
                                      jogador2:
                                      printf("\n\t\t\t>>JOGADOR 2 COLUNA A MARCAR = ");
                                      scanf("%d",&j);
                                      printf("\n\t\t\t>>JOGADOR 2 LINHA A MARCAR  = ");
                                      scanf("%d",&i);
                                      if ((i>3)||(j>3)){
                                           printf("\n\n\n\n\t\t\t        >>  OPCAO INVALIDA!\n\t\t\t>>  PRESSIONE ENTER E TENTE OUTRA VEZ!\n\n\n\n\n\n\n\n\n\n");
                                           invalido = 1;
                                           system("PAUSE");  
                                      }
                                      if (quadro[i-1][j-1] == 0){
                                           quadro[i-1][j-1] = p2;
                                           jogada2 = jogada2 + 1;
                                      }
                                      else{
                                           if (invalido == 0){
                                                printf("\n\n\n\n\t\t\t        >>  OPCAO OCUPADA!\n\t\t\t>>  PRESSIONE ENTER E TENTE OUTRA VEZ!\n\n\n\n\n\n\n\n\n\n");
                                                system("PAUSE");
                                           }
                                      }        
                                      proximo:                //estrutura que checa se posicao eh valida na horizontal e marca 
                                      for(i=0; i<3; i++){
                                           for (j=0; j<1; j++){
                                                if(quadro[i][j] != 0){
                                                     if ((quadro[i][j] == quadro[i][j+1])&&(quadro[i][j+1] == quadro[i][j+2])){
                                                          if (quadro[i][j] == p1){
                                                               ponto1 = ponto1 + 1;
                                                               continua = 3;
                                                               fim =1;   
                                                               vence1 = 1;   
                                                               goto resultado;                       
                                                          }
                                                          else{
                                                               ponto2 = ponto2 + 1;
                                                               continua = 3;
                                                               fim =1;
                                                               vence2 = 1;
                                                               goto resultado;                        
                                                          }
                                                     }
                                                }
                                           }
                                      }           
        
                                      for(j=0; j<3; j++){                 //estrutura que checa se posicao eh valida na vertical e marca
                                           i = 0;
                                           if(quadro[i][j] != 0){
                                                if ((quadro[i][j] == quadro[i+1][j])&&(quadro[i+1][j] == quadro[i+2][j])){
                                                     if (quadro[i][j] == p1){
                                                          ponto1 = ponto1 + 1;
                                                          continua = 3;
                                                          fim =1;   
                                                          vence1 = 1;   
                                                          goto resultado;                       
                                                     }
                                                     else{
                                                          ponto2 = ponto2 + 1;
                                                          continua = 3;
                                                          fim =1;
                                                          vence2 = 1;
                                                          goto resultado;                        
                                                     }
                                                }
                                                else{          //checa se dara velha
                                                     if ((quadro[i][j] != quadro[i][j+1])||(quadro[i][j+1] != quadro[i][j+2])){
                                                          if (((quadro[i][j] != 0)&&(quadro[i][j+1] != 0))&&(quadro[i][j+2] != 0)){
                                                               if ((jogada1 + jogada2) == 9){
                                                                    cont ++;
                                                                    continua = 3;
                                                                    fim = 1;                                          
                                                                    goto resultado;
                                                               }
                                                          }
                                                     }                                 
                                                 }
                                             }
                                         }       
                                         //chega na diagonal  esquerda para direita
                                         if ((quadro[0][0] == quadro[1][1])&&(quadro[1][1] == quadro[2][2])){
                                              if (quadro[0][0] == p1){
                                              
                                                   ponto1 = ponto1 + 1;
                                                   continua = 3;
                                                   fim =1;   
                                                   vence1 = 1; 
                                                   goto resultado;                       
                                              }
                                              else{
                                                   if (quadro[0][0] == p2){
                                                        ponto2 = ponto2 + 1;
                                                        continua = 3;
                                                        fim =1;
                                                        vence2 = 1;
                                                        goto resultado;   
                                                   }                     
                                              }
                                         }
                                         //chega na diagonal direita para esquerda        
                                         if ((quadro[0][2] == quadro[1][1])&&(quadro[1][1] == quadro[2][0])){
                                              if (quadro[0][2] == p1){
                                                   ponto1 = ponto1 + 1;
                                                   continua = 3;
                                                   fim =1;   
                                                   vence1 = 1; 
                                                   goto resultado;                       
                                              }
                                              else{
                                                   if (quadro[0][2] == p2){
                                                        ponto2 = ponto2 + 1;
                                                        continua = 3;
                                                        fim =1;
                                                        vence2 = 1;
                                                        goto resultado;    
                                                   }                    
                                              }
                                         }
                                         //imprime o nome do vencedor   
        
                                         baixo:
                                         if ((vence1 == 1)&&(melhor == 0)){
                                              printf("\n\n\t\t >> PARABENS! VOCE ACABA DE VENCER, %s",nome1);
                                              printf("\n\n\t\t   >>  VOLTAREMOS AO MENU INICIAL!\n\t\t  >>  PRESSIONE ENTER PARA RETORNAR!\n\n\n\n\n\n\n\n\n\n");
                                              system("PAUSE");
                                              ponto1 = 0;
                                              ponto2 = 0;
                                              continua = 0;
                                              fim = 0;
                                              vence1 = 0;
                                              vence2 = 0;
                                              goto novo;
                                         }
                                         else{
                                              if ((vence2 == 1)&&(melhor == 0)){
                                                   printf("\n\n\t\t >> PARABENS! VOCE ACABA DE VENCER, %s",nome2);
                                                   printf("\n\n\t\t   >>  VOLTAREMOS AO MENU INICIAL!\n\t\t  >>  PRESSIONE ENTER PARA RETORNAR!\n\n\n\n\n\n\n\n\n\n");
                                                   system("PAUSE");
                                                   ponto1 = 0;
                                                   ponto2 = 0;
                                                   continua = 0;
                                                   fim = 0;
                                                   vence1 = 0;
                                                   vence2 = 0;
                                                   goto novo;
                                              }
                                              else{
                                                   if(jogada1+jogada2 == 9){
                                                        for (i=0; i<3; i++){
                                                             for (j=0; j<3; j++){
                                                             if (quadro[i][j]!=0)
                                                                  velha ++;
                                                             }
                                                        }
                                                        if ((velha == 9)&&(melhor == 0)){
                                                             printf("\n\n\t\t            >> OPS! DEU VELHA!");
                                                             printf("\n\n\t\t     >>  VOLTAREMOS AO MENU INICIAL!\n\t\t  >>  PRESSIONE ENTER PARA RETORNAR!\n\n\n\n\n\n\n\n\n\n");
                                                             system("PAUSE");
                                                             ponto1 = 0;
                                                             ponto2 = 0;
                                                             continua = 0;
                                                             vence1 = 0;
                                                             vence2 = 0;
                                                             fim = 0;
                                                             goto novo;
                                                        }
                                                        
                                                   }
                                              }
                                         }
                                         if (((vence1 == 1)&&(vence2 == 1))&&((melhor == 4)&&(k == 2))&& continua == 3){
                                              printf("\n\n\t\t           >> OPS! DEU EMPATE!");
                                              printf("\n\n\t\t   >>  VOLTAREMOS AO MENU INICIAL!\n\t\t  >>  PRESSIONE ENTER PARA RETORNAR!\n\n\n\n\n\n\n\n\n\n");
                                              system("PAUSE");
                                              ponto1 = 0;
                                              ponto2 = 0;
                                              goto novo;
                                         }
                                         else{
                                         if (((vence1 == 1)&&(k == 2))&&(melhor == 4)&&(continua == 3)){
                                              printf("\n\n\t>> PARABENS! VOCE ACABA DE VENCER A MELHOR DE 3, %s",nome1);
                                              printf("\n\n\t\t   >>  VOLTAREMOS AO MENU INICIAL!\n\t\t  >>  PRESSIONE ENTER PARA RETORNAR!\n\n\n\n\n\n\n\n\n\n");
                                              system("PAUSE");
                                         }
                                         else{
                                              if (((vence2 == 1)&&(k == 2))&&(melhor == 4)&&(continua == 3)){
                                                   printf("\n\n\t>> PARABENS! VOCE ACABA DE VENCER A MELHOR DE 3, %s",nome2);
                                                   printf("\n\n\t\t   >>  VOLTAREMOS AO MENU INICIAL!\n\t\t  >>  PRESSIONE ENTER PARA RETORNAR!\n\n\n\n\n\n\n\n\n\n");
                                                   system("PAUSE");
                                              }
                                              else{
                                                   if (cont == 3){
                                                        printf("\n\n\t\t           >> OPS! DEU VELHA!");
                                                        printf("\n\n\t\t   >>  VOLTAREMOS AO MENU INICIAL!\n\t\t  >>  PRESSIONE ENTER PARA RETORNAR!\n\n\n\n\n\n\n\n\n\n");
                                                        system("PAUSE");
                                                   }
                                                   
                                              }
                                         }
                                              
                                         }
                                         if (continua != 3)
                                         goto tabela;
                                         printf("\n\n________________________________________________________________________________\n");          
                                    }    // fim do else  
                               }// fim do while
                               }// fim do for para melhor de 3
                         break; // fim da primeira opcao
                         case 1:
                                goto rapido;
                         break;
                         case 3:
                                goto comeco;
                         break;
                         case 4:
                                resp = 4;
                                printf("\n\n\n\n");
                                printf("\n\n");
                                printf("\n\n");
                                printf("\n\n\t    >>  VOCE FINALIZOU O JOGO! OBRIGADO PELA PARTICIPACAO!\n\t\t          >>  PRESSIONE ENTER PARA SAIR!\n\n\n\n\n\n\n\n\n\n");
                                system("PAUSE");     
                         break;      
        
        
              }//switch
        
        }//primeiro while     
    }
