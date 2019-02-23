#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"");
	float result;
	int numero;
	int c = 2;
	while(c==2){
	
	printf("digite um numero\n \n ");
	scanf("%d",&numero);
	if(numero % 2 ==  0){
		
		printf("%d \t … PAR \n \n",numero);
	}
	else{
		
		printf("%d \t… IMPAR \n \n",numero);
	}

	
//	system("cls");
//	system("pause");
}}
