#include <stdio.h>


void main(){
	
	int mbeta[3][3];
	int momega[3][3];
	int a[3][3];
	int x;
	int y;
	for(x=0;x<=2;x++){
		printf("Informe o valor da primeira coluna\t");
		scanf("%d",&mbeta[x][0]);
		
		
	}
	
	for(x=0;x<=2;x++){
		printf("Informe o valor da segunda coluna\t");
		scanf("%d",&mbeta[x][1]);
		
		
	}	
	
	for(y=0;y<=2;y++){
		printf("Informe o valor da primeira coluna\t");
		scanf("%d",&momega[y][0]);
		
		
	}
	
	for(y=0;y<=2;y++){
		printf("Informe o valor da segunda coluna\t");
		scanf("%d",&momega[y][1]);
		
		
	}	
	for(x=0;x<=2;x++){
		mbeta[x][0] = a[y][0];
		a[y][0]++;
	}
	
	for(x=0;x<=2;x++){
		printf("resultado trocado%d\t \n\n ",a[y][0]);
		
		
		
	}}
