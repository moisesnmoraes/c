#include <locale.h>
#include <stdio.h>
#include <stdlib.h> 

void main(){
	setlocale(LC_ALL, "");
	
	//declaração de variáveis
	int valores[3][2], x, mult_valor;

	//valores armazendos: valores.
	//x: ponteiro
	// mult_valor: valor multiplicado por ele mesmo.
		
			
	for(x=0; x<=2; x++){
		
		//captura valores e armazena
		printf(" Informe um valor:\n");
		scanf("%d", &valores[x][0]);
		
		//multiplica números por ele mesmo e armazena
		mult_valor = valores[x][0] * valores[x][0];
		valores[x][1] = mult_valor;
	}

	//mostra os valores
	for(x=0; x<=2; x++){
		printf("%d", valores[x][0]);
		printf(" | ");
		printf("%d \n", valores[x][1]);
	}	
		
}
