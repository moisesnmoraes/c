#include <stdio.h>


void main(){
	
	int nro[3][3];
	float  linha, coluna;
	
	
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
			
			printf("digite o numero(%d x %d):",coluna+1, linha+1);
			scanf("%f",&nro[linha][coluna]);
		}
		
	}
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
		
		printf("%f",nro[linha][coluna]);
		
		}
	}
	printf("\n");
	
}
