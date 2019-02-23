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
		printf("-> [4]  -  Extrato Bancário  \n");
		printf("-> [5]  -  Transferência  \n");
		printf("-> [6]  -  Sair  \n");
		printf("-> Informe sua opção [ ]");
		gotoxy(23,8);
		scanf("%d", &opcmenu);
		system("cls");
			
		// cadastrar
		if(opcmenu == 1){
			
			printf(">> Cadastrar Conta >>");
			printf("\n\n");
			printf(">> Informe o número da conta >> ");
			scanf("%d", &numero_conta[posicaoconta]);
			
			// verificar se a conta ja foi cadastrada
			for(x=0; x<=posicaoconta-1; x++){
				if (numero_conta[posicaoconta] == numero_conta[x]){ //se o número já está sendo utilizado o sistema não deixa colocar o mesmo.
				   printf("Número de conta já cadastrado. \n >> Informe o número da conta >>  \n");							
				   scanf("%d", &numero_conta[posicaoconta]);
					x=-1;													
				}
			}		
			
			
			printf(">> Informe o dígito da conta >> ");
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
			
			printf("Informe o número da conta: \n");
			scanf("%d", &num_conta);
			printf("Informe o digito: \n");
			scanf("%d", &num_digito);
						
			for(x=0; x<=posicaoconta-1; x++){
				if((num_conta == numero_conta[x]) && (num_digito == digito_conta[x])){
					printf("%s \n", nome_conta[x]);
					printf("Informe o valor a depositar: \n");	
					scanf("%d", &num_deposito);
								
					printf(" 1 - Para confirmar o depósito: \n 0 - Cancelar operação e voltar ao menu principal: \n");
					scanf("%d", &confirma);
								
					if(confirma == 1){										
						valor_saldo[x] = valor_saldo[x] + num_deposito;
						printf("Depósito feito com sucesso! \n");
						break;
					}			
				}
			}
			
		}
	}
	
	
	
	
}
