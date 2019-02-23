#include <stdio.h>
#include <locale.h>


void main(){
	setlocale(LC_ALL,"");
	int controle=0;
	int c;
	char nome_ca[40][40];	
	char sigla[40][10];
	int numero[40];
	int controle;
	int nc,sc,np, numerorepetido,v,vc;
	numerorepetido = 0;
	nc = 0;
	
	while(controle<=5||controle>=0){
		printf("1 - cadastrar candidatos \n");
		printf("2 - Listrar candidatos \n");
		printf("3 - modulo de voto \n");
		printf("4 - Apurar elecoes \n");
		printf("5 - sair \n");
		scanf("%d",&c);
	
	
	
			if(c==1){
			
				numerorepetido = 0;
				printf("voce vai cadastrar os candidatos \n Informe o nome do candidato \n");
				scanf("%s",&nome_ca[nc]);
				
				printf("informe a sigla do candidato\n");
				scanf("%s",&sigla[nc]);
				
				printf("agora informe o numero do partido\n");
				
				// validação para não permitir os elementos ser inseridos em duplicidade.
				while(numerorepetido == 0){
					numerorepetido = 1;
					scanf("%d",&numero[nc]);
					
					for(np=0;np<=nc;np++){			
						if(numero[nc] == numero[np] && np != nc){
							printf("Número já informado \n");
							printf("Informe o número novamente \n");
							numerorepetido = 0;
						}
					
					}
				}
				
				
				for(np=0;np<=nc;np++){			
					puts(nome_ca[np]);	
					puts(sigla[np]);
					printf("%d \n", numero[np]);
				}
				
				nc++;
			
		}
		if(c==2){
		
		printf("NÚMERO      NOME     SIGLA PART.\t");	
		for(nc=0;nc<40;nc++){
		printf(" \n%d      %s      %s \n",numero[nc], nome_ca[nc], sigla[nc]);
		}
		
}
		if(c==3){
		
		
		printf("módulo de votaçaõ\n");
		printf("informe o numero do candidato que deseja votar\n");
		scanf("%d",&v);
		for(controle=0;controle<40;controle++){
			
		}
			
			
		//	printf("voce vai votar no candidato %s deseja confirmar o seu voto\n 1 - sim\n 2 - nao ",nome_ca[nc]);
		//	scanf("%d",&vc);
			
		//	vc++;
		}
		if(c==4){
			("apurar eleiçoes \t");
			printf("%d",)
			
		}
		
		if(c==5){
		 return(0);
		}
		}
				
		}
