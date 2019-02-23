#include <stdio.h>


void main(){
	
	int	y[3][3];
	int	x[3][3];
	int a;
	int b;
	int c[6][6];
	
	for(a=0;a<=2;a++){
		printf("Informe o valor  para a  matrix y a 1 coluna\t");
		scanf("%d",&y[a][0]);
		y[a][0]=c[b][0];
		c[b][0]++;
		
	}
	for(a=0;a<=2;a++){
		printf("Informe o valor para a matrix y a 2 coluna\t");
		scanf("%d",&y[a][1]);
		y[a][1]=c[b][1];
		c[b][1]++;
	}
		for(a=0;a<=2;a++){
		printf("Informe o valor para a matrix y a 3 coluna\t");
		scanf("%d",&y[a][2]);
		y[a][2]=c[b][2];
		c[b][2]++;
		
	}
	for(a=0;a<=2;a++){
		printf("Informe o valor para a matrix x a 1 coluna\t");
		scanf("%d",&x[a][0]);
		x[a][0]=c[b][0];
		c[b][0]++;
	}
	for(a=0;a<=2;a++){
		printf("Informe o valor para a matrix x a 2 coluna\t");
		scanf("%d",&x[a][2]);
		x[a][2]=c[b][2];
		c[b][2]++;
	}
		for(a=0;a<=2;a++){
		printf("Informe o valor para a matrix x na  3 coluna\t");
		scanf("%d",&x[a][3]);
		x[a][3]=c[b][3];
		c[b][3]++;
		
		}

		
			y[a][0]=c[1][0];
			y[a][2]=c[1][1];
			y[a][3]=c[1][3];
			
			
			x[a][0]=c[0][0];
			x[a][1]=c[0][1];
			x[a][2]=c[0][1];
		for(a=0;a<=2;a++){
	
		printf("valor da primeira coluna \t5%d do y\n",c[b][0]);
			}
				for(a=0;a<=2;a++){
		
			printf("valor da segunda coluna \t%d do y\n",c[b][1]);	
			}
			for(a=0;a<=2;a++){
		
				printf("valor da terceira  coluna \t%d do y\n ",c[b][2]);	
				}
				for(a=0;a<=2;a++){
				
					printf("valor da primeira coluna \t%d do x\n",c[b][0]);
				}
				for(a=0;a<=2;a++){
				
					printf("valor da segunda  coluna \t%d do x\n",c[b][1]);
				}
					for(a=0;a<=2;a++){
				
					printf("valor da terceira coluna \t%d do x\n",c[b][2]);
				}
}
