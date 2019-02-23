#include <stdio.h>
#include <locale.h>
#include<windows.h>
#include<stdlib.h>

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void main(){
	
	setlocale(LC_ALL, "");
	int opcmenu = 1;
	
	int numero_conta[50], digito_conta[50];
	float valor_saldo[50];
	char nome_conta[50][40];
	int posicaoconta = 0;
	int confirma = 0;
	int x, num_conta, num_digito,num_deposito;
	
	
	while(opcmenu < 6){
		system("cls"); 
		printf("-> MENU PRINCIPAL -< \n");
		printf("-> [1]  -  Cadastrar Conta  \n");
		printf("-> [2]  -  Depositar  \n");
		printf("-> [3]  -  Sacar  \n");
		printf("-> [4]  -  Extrato Banc�rio  \n");
		printf("-> [5]  -  Transfer�ncia  \n");
		printf("-> [6]  -  Sair  \n");
		printf("-> Informe sua op��o [ ]");
		gotoxy(23,8);
		scanf("%d", &opcmenu);
		system("cls");
			
		// cadastrar
		if(opcmenu == 1){
			
			printf(">> Cadastrar Conta >>");
			printf("\n\n");
			printf(">> Informe o n�mero da conta >> ");
			scanf("%d", &numero_conta[posicaoconta]);
			
			// verificar se a conta ja foi cadastrada
			for(x=0; x<=posicaoconta-1; x++){
				if (numero_conta[posicaoconta] == numero_conta[x]){ //se o n�mero j� est� sendo utilizado o sistema n�o deixa colocar o mesmo.
				   printf("N�mero de conta j� cadastrado. \n >> Informe o n�mero da conta >>  \n");							
				   scanf("%d", &numero_conta[posicaoconta]);
					x=-1;													
				}
			}		
			
			
			printf(">> Informe o d�gito da conta >> ");
			scanf("%d", &digito_conta[posicaoconta]);
			printf(">> Informe o titular da conta >> ");
			scanf("%s", &nome_conta[posicaoconta]);
			
			printf(" 1 - CONFIRMAR | 0 - SAIR \n");
			scanf("%d", &confirma);
			
			if(confirma == 1){
			   printf("Conta cadastrado.\n");						
			   posicaoconta++;
			   system("pause");
			}
			
		}
		
		// depositar
		if(opcmenu == 2){
			
			confirma = 0;
			
			printf("Informe o n�mero da conta: \n");
			scanf("%d", &num_conta);
			printf("Informe o digito: \n");
			scanf("%d", &num_digito);
						
			for(x=0; x<=posicaoconta-1; x++){
				if((num_conta == numero_conta[x]) && (num_digito == digito_conta[x])){
					printf("%s \n", nome_conta[x]);
					printf("Informe o valor a depositar: \n");	
					scanf("%d", &num_deposito);
								
					printf(" 1 - Para confirmar o dep�sito: \n 0 - Cancelar opera��o e voltar ao menu principal: \n");
					scanf("%d", &confirma);
								
					if(confirma == 1){										
						valor_saldo[x] = valor_saldo[x] + num_deposito;
						printf("Dep�sito feito com sucesso! \n");
						break;
					}			
				}
			}
			
		}
	}
	
	
	
	
}
