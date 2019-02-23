#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //permite a esecução do comando sleep

//sleep é uma função que faz o programa ficar suspenso por um determido tempo.

int main(){
	
	int tempo;
	
	printf("digite o valor para seer conometrado\n");
	scanf("%d",&tempo);
	
	while(tempo>=0){
		Sleep(1000);
		system("cls");
		printf("%d segundos",tempo);
		tempo--;
		
	}
	system("cls");
	printf("\n---------------------\n");
	printf("\nTEMPO ESGOTADO\n");
	printf("\n----------------------\n");
}



