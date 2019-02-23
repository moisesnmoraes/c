#include <stdio.h>


int main(){
	int numero [6];
	int i,f;
	
	for(i=0;i<6;i++){
		
		
		printf("digite o %d numero  inteiro ",i+1);
		scanf("%d",&numero[i]);
	}
	printf("\n \n  ultimo numero informado pelo usuario%d\n\n ",numero[i]);
	
	for(i=0;i<6;i++){
		
		printf("\nnumeros fornecidos pelo usuario: %d\n",numero[i]);
	}
	for(i=6;i>=0;i--){
		
		printf("\nnumero em ordem contraria a informada :%d\n",numero[i]);
		numero[i]=f;
	}
	if(f!=1000){
		for(f=10;f<0;f--){
		
		printf(" MAIOR NUMERO E : %d",f);
		}
	}
	
	
	
	
}
