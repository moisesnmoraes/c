#include <stdio.h>


void main(){
	
	int mbeta[3][3];
	int x;
	for(x=0;x<=2;x++){
		printf("Informe o valor da primeira coluna\t");
		scanf("%d",&mbeta[x][0]);
		
		
	}
	
	for(x=0;x<=2;x++){
		printf("Informe o valor da segunda coluna\t");
		scanf("%d",&mbeta[x][1]);
		
		
	}	
	for(x=0;x<=2;x++){
		mbeta[x][2] = mbeta[x][0] * mbeta[x][1];
		printf("Resultado %d \n", mbeta[x][2]);
		
	}
	
	
}
