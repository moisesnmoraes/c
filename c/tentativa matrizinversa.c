#include <stdio.h>


void main(){
	
	int x[2][2];
	int y[2][2];
	int a;
	
	
	for(a=0;a<2;a++){
		printf("informe o valor da primeira matriz");
		scanf("%d",&x[a][0]);
		
		
	}
	for(a=0;a<2;a++){
		printf("imforme o valor para segunda matriz");
		scanf("%d",y[a][0]);
		//d",&y[a][0]);
							
	}
	for(a=0;a<4;a++){
		printf("matriz inversa %d",x[a][0]);
		x[a][0]++;
		
	}
	
	
	
}
