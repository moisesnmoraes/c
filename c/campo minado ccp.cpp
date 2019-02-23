#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX 1000
using namespace std;
typedef struct campoMinado{
      int Matriz[12][12];//armazena o campo minado
      int MatrizB[12][12];//armazena a interface
      char records[30];//armazena o melhor resultado
      double tempo;//armazena o tempo do jogo
      int bombas;//armazena a quantidade de bombas
}Minas;
Minas campo[MAX];//variavel de instancia para controlar os jogos
//Funcao para obter o nivel de dificuldade do jogo escolhido pelo usuario
int Menu2(){
    int escolha=0; 
    do{
        fflush(stdin);
    	scanf("%d",&escolha);
    	if(escolha<1 || escolha>3)
    	  printf("Opcao Invalida entre com outra.\n");
    	  
    }while(escolha<1 || escolha>3);
    return escolha;
}//fim funcao menu2
/*funcao para obter a escolha do usuario ela ira servir para o inicio do programa no primeiro menu
e no fim do programa para ver se ele deseja continuar e na listagem dos records*/
int Escolha(){
    int opcao;
    do{
       fflush(stdin);
       scanf("%d",&opcao);
       if(opcao<1 || opcao>2)
	  printf("Opcao Invalida entre com outra.\n");
      }while(opcao<1 || opcao>2);
    return opcao;
}//fim da funcao Escolha
//Funcao para Mostrar o Menu inicial do jogo para o usuario
int menu1(){
    int opcao=0;
    printf(" _______________________________________\n");
    printf("|\t\t\t\t\t|\n");
    printf("|\tBem vindo ao Campo Minado !!\t|\n");
    printf("|\tO que deseja fazer \t\t|\n");
    printf("|\t1-Jogar 2-Sair 3-Records\t|\n");
    printf("|_______________________________________|\n\n");
    opcao=Menu2();
    return opcao;
}//Fim funcao menu1
//funcao para transformar int em char
char inTChar(int i) {
    switch (i) {
           case 0: return '0';
           case 1: return '1';
           case 2: return '2';
           case 3: return '3';
           case 4: return '4';
           case 5: return '5';
           case 6: return '6';
           case 7: return '7';
           case 8: return '8';
    }//fim switch
}//fim funcao inTChar
//imprime a matriz na tela
void Imprime(int cont){
      int i,j,lin,col;
      printf("\t 1  2  3  4  5  6  7  8  9  10\n");
      for(i=1;i<=10;i++){
	    printf("%d",i);
        printf("\t");
	    for( j=1;j<=10;j++)
	       printf("[%c]",campo[cont].Matriz[i][j]);
	    printf("\n");
      }
      printf("\n[ ]vazio\t[3]Bombas ao redor\t[-]Nao visitado\n[#]BOMBA\t99-Sair\n\n");
}//fim da funcao Imprime
//funcao para verificar se a bombas nas celulas vizinhas
void  verificaVizinhanca(int i){
      int qntbombas,lin,col;
      
      //percorrendo a matriz
      for(lin=1;lin<11;lin++){
         for(col=1;col<11;col++){
              qntbombas=0;
              //comparando os oito vizinhos
              if(campo[i].MatrizB[lin][col+1]==9)
                   qntbombas++;
              if(campo[i].MatrizB[lin][col-1]==9)
                   qntbombas++;
              if(campo[i].MatrizB[lin+1][col]==9)
                   qntbombas++;
              if(campo[i].MatrizB[lin-1][col]==9)
                   qntbombas++;
              if(campo[i].MatrizB[lin-1][col+1]==9)
                   qntbombas++;
              if(campo[i].MatrizB[lin-1][col-1]==9)
                   qntbombas++;
              if(campo[i].MatrizB[lin+1][col+1]==9)
                   qntbombas++;
              if(campo[i].MatrizB[lin+1][col-1]==9)
                   qntbombas++;
        //colocando a quantidade de bombas da vizinhanca dentro da celula
        if(campo[i].MatrizB[lin][col]!=9)
           campo[i].MatrizB[lin][col]=qntbombas;
           }//fim do for (col)
           
      }//fim do for (lin)
}//fim da funcao verifica Vizinhanca
/*Funcao para verificar os espacos vagos com a escolha do usuario de linha e coluna essa funcao recursiva
 ira passar todos os lugares vagos marcados com 0 na MatrizB e vai atribuir o valor ' ' para a matriz da interface e -1 para
 a matrizB para ela nao contar o espaco em branco novamente na matrizB quando for percorrer o proximo local pra ver se ele
 tambem e vazio*/
int verificaCasas(int i, int n, int livres,int c){
		if((campo[c].MatrizB[i][n]>0)||(campo[c].MatrizB[i][n]==-1)||(campo[c].MatrizB[i][n]==9)){//caso base
			return livres;
		}else{
			livres++;
			campo[c].Matriz[i][n]=' ';
			//colocando ' ' para mostrar que essa casa ja foi visitada
			campo[c].MatrizB[i][n]=-1;
			//colocando -1 para mostrar que essa casa ja foi visitada
			//metodos recursivos
			livres = verificaCasas(i+1,n,livres,c);
			livres = verificaCasas(i-1,n,livres,c);
			livres = verificaCasas(i,n+1,livres,c);
			livres = verificaCasas(i,n-1,livres,c);
			return livres;
		}
}//fim da funcao verificaCasas
//Gera posicoes aleatorias para as Bombas
void Sorteio(int c){
    int lin,col,arm,qnt=0;
    srand(time(NULL));
    do{
    	do{
            //gerando numeros aleatorios
    	    lin=rand()%9+1;
    	    col=rand()%9+1;
    	    //verificando se pode colocar bomba naquela posicao
    	    if(campo[c].MatrizB[lin][col]==9){
    	        arm=-1;
                }else{
    		         campo[c].MatrizB[lin][col]=9;
    	             arm=0;
                     }
    	    }while(arm==-1);//condicao de parada de novas posicoes aleatorias
	  qnt++;//acrescenta numero de bombas
      }while(qnt<campo[c].bombas);//condicao de parada das bombas
}//fim da funcao Sorteio
//inicializando a matriz sempre vazia
void inicializa(int cont){
     int i,j;
     //inicializando a matriz B com -1 para indicar vazio
     for(i=0;i<12;i++)
        for(j=0;j<12;j++)
            campo[cont].MatrizB[i][j]=-1;
            
     //inicializando a matriz da Interface
     for( i=0;i<12;i++)
	    for( j=0;j<12;j++)
		  campo[cont].Matriz[i][j]='-';
    
    //inicializando a matriz mas descartando as bordas para a funcao de verificacao das casas livres nao dar bug
     for(i=1;i<11;i++)
        for(j=1;j<11;j++)
            campo[cont].MatrizB[i][j]=0;
}//fim da funcao inicializa
//Funcao para ler o arquivo
void LER(FILE *f,int cont){
     int i;
     for(i=0;i<cont;i++){
        fread(&campo[i],sizeof(campoMinado),1,f);
     }
}//fim funcao LER
//funcao para salvar no arquivo os records
void SalvaRecords(int cont){
    //entrando com o usuario que venceu o jogo
    do{
       fflush(stdin);
       printf("\nEntre com o Nome do Jogador!!\n");
       gets(campo[cont].records);
       }while(campo[cont].records[0]=='\0');//nao deixar entrar com fim de linha (ENTER)
}//fim funcao salvaRecords
//funcao para salvar no arquivo
void Salva(FILE *f,int cont){
     int i;
    //armazena os dados do programa no arquivo
    printf("\nSalvando informacoes...\n");
    fflush(f);
    rewind(f);
    fwrite(&cont,sizeof(int),1,f);
    for(i=0;i<cont;i++){
       fwrite(&campo[i],sizeof(campoMinado),1,f);
       }
    fflush(f);
    fclose(f);
    printf("Informacoes salvas com sucesso.\n"); 
    system("pause");
}// fim funcao SalvaRecords
//funcao para imprimir os records
void ImprimeRecords(int cont){
     int i;
     
     for(i=0;i<cont;i++){
         if(campo[i].records[0]!='\0'){
             printf("nome: %s\n",campo[i].records);
             printf("tempo: %f segundos\n",campo[i].tempo);
             printf("bombas: %d\n",campo[i].bombas);
         }
     }
}//fim funcao ImprimeRecords
//funcao para imprimir a localizacao das bombas ao final
void ImprimeBombas(int cont){
    int lin,col;
     for(lin=1;lin<=10;lin++){
          for(col=1;col<=10;col++){
               if(campo[cont].MatrizB[lin][col]==9){
                     campo[cont].Matriz[lin][col]='#';
                  }
          }
      }
     Imprime(cont);
     system("pause");
}//fim da funcao imprimeBombas
//Inicio do Programa
int main(int argc, char *argv[]){         
    int cont=0,opcao,i,j,lin,col,qnt=0,escolha,resto,total;//variaveis para controlar as escolhas
    char cell;//variavel para controlar o que sera colocado dentro da matriz de interface
    system("color 0f");    
    FILE *f;//ponteiro para o arquivo
    //abrindo o arquivo
     if((f=fopen("CampoMinado.dat","r+b"))==NULL){
         printf("\nComo nao existia um arquivo de dados o programa ira criar um.\n");
         if((f=fopen("CampoMinado.dat","w+b"))==NULL){
              printf("\nErro na leitura do arquivo.\n");
              exit(1);
         }
         else
              printf("\nArquivo criado com sucesso.\n");
    }
    
    else
         printf("\nArquivo aberto com sucesso.\n");   
    system("pause");
    system("cls");
    rewind(f);//voltando para o inicio
    //le quantos jogos estao armazenados no arquivo
    fread(&cont,sizeof(int),1,f);
    LER(f,cont);//le o arquivo
    //funcao para ver se o usuario quer jogar ou sair do programa
    opcao=menu1();
    printf("opcao: %d\n",opcao);
      if(opcao==3)
          ImprimeRecords(cont);//chamando a funcao para listar os records
          
      //inicio do jogo
      while((opcao!=2 && opcao!=3)&& cont<MAX){
      
       //inicializando a matriz               
      inicializa(cont);
      
      //declarando as variaveis para marcar o tempo
      clock_t start_time, end_time;
      
      printf("\n\nEscolha a Dificuldade do jogo!!\n\n[1]Facil\t\t[2]Medio\t\t[3]Dificil\n\n");
       //entrada do usuario niveis dificil medio e facil
      escolha = Menu2();
      system("cls");
    //obtendo o tempo de inicio do programa
      start_time = clock();
      
      //determinando o numero de bombas
      if(escolha==1)
        campo[cont].bombas=10;
    	   else if(escolha==2)
    	      campo[cont].bombas=30;
    	      else
    		      campo[cont].bombas=50;
		  
      printf("\t\t  BOA SORTE!!\n");
      Sorteio(cont);// chamando funcao para sortear a localizacao das bombas
      verificaVizinhanca(cont);//chamando funcao para ver qntas bombas tem ao redor de cada celula
      Imprime(cont);//imprimindo a matriz da interface
      do{
          total=100-campo[cont].bombas;//controlar o total de jogadas restantes
          system("color 0f");
          do{
              do{
                  //entrada da linha e coluna do usuario 
                 fflush(stdin);           
                 printf("Escolha uma linha\n");
                 scanf("%d",&lin);
                 }while((lin<1 || lin>10) && lin!=99);//criterio para nao entrar com posicao errada
              if(lin==99)
                 break;
              do{
                 fflush(stdin);
                 printf("Escolha uma coluna\n");
                 scanf("%d",&col);
                 }while((col<1 || col>10)&& col!=99);
              if(col==99)
                 break;
              escolha = campo[cont].MatrizB[lin][col]; //verificando o que a dentro da MatrizB
              
              //mostrando interface para o usuario que ele ja entrou com essa opcao
              if(campo[cont].Matriz[lin][col]!='-'){
                 system("cls");
                 Imprime(cont);
                 printf("\n\nCampo ja visitado entre com outro!!\n\n");
                 }
              }while(campo[cont].Matriz[lin][col]!='-');//criterio para nao abrir uma casa que ele ja abriu anteriormente
              
              if(lin==99 || col==99)//criterio de parada para forcar a saida
                   break;
          if(escolha==9){//verificando se ha bombas
                campo[cont].Matriz[lin][col] ='#';//colocando a bomba na matriz da interface
                system("cls");
                system("color 2A");
                system("color 3C");//varias mudancas da tela para mostrar que ele acertou uma bomba
                system("color 4D");
                system("color 1E");
                system("color 4B");
                Imprime(cont);//imprimindo
                
                printf("\nVOCE PERDEU!!! \n\n\a\a");//mostrando para o usuario que ele perdeu
                system("pause");
                system("cls");
                ImprimeBombas(cont);
                break;
                }else if(escolha!=0){//verificando se nao e espaco livre onde ele escolheu
                
                     cell= inTChar(campo[cont].MatrizB[lin][col]);
                     //transformando o valor numerico dentro da MatrizB em um Char
                     campo[cont].Matriz[lin][col] = cell; //colocando o Char na Matriz da interface
                     system("cls");
                     Imprime(cont);//imprimindo
                     qnt++;//acrescentando uma jogada
                     }else{
                           //chamando a funcao verificaCasas pois ele acertou um espaco vazio
                           escolha=verificaCasas(lin, col,0,cont);
                           system("cls");
                           Imprime(cont);
                           qnt+=escolha;//acrescentando o numero de jogadas ja feitas
                     }
          resto=(100-qnt)-campo[cont].bombas;//calculando jogadas restantes
          printf("\nJogadas restantes: %d\n",resto);
         }while(resto>0);
           //criterio de parada para verificacao do campo minado 
         //caso ele atinga o as casas todas e nao acerte nenhuma bomba
         
         if(lin==99 || col==99)
             break;//criterio de parada para forca a saida
         
         campo[cont].tempo = (end_time=clock()/600)-start_time/600;//parando o tempo
         qnt=0;//voltando cont para zero caso ele jogue novamente
      
      //mostrando ao usuario que ele venceu
      if(resto==0){
        printf("\n\nPARABENS VOCE GANHOU!!\n\n");
        system("pause");
        system("cls");
        ImprimeBombas(cont);//imprimindo todas as localizacoes das bombas
        }
      printf("Tempo total gasto %.2f segundos\n",campo[cont].tempo);//mostrando o tempo gasto no jogo
      printf("deseja continuar com o jogo 1- Sim 2-nao\n");
      opcao=Escolha();
      
      printf("\nDeseja listar Os Records!! \n[1]Sim [2]Nao\n");
      escolha=Escolha();
      system("cls");
      printf("%d\n",escolha);
      system("cls");
      if(escolha==1){//exibindo os records
          ImprimeRecords(cont);//chamando a funcao para listar os records
          }
      if(resto==0)
         SalvaRecords(cont);
         //salvando os records dos vencedores
      system("pause");
      system("cls");
      if(resto==0);//acrescentando o contador para a proxima posicao caso ele vença
         cont++;//se nao reaproveita a posicao para fazer um novo jogo ou iniciar daquele ponto
  }//fim do While
    
    Salva(f,cont);//salvando no arquivo
    return EXIT_SUCCESS;
}//Fim do programa
