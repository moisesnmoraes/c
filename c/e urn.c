#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main(){
	
	setlocale(LC_ALL ,"");
	
	int menu= 0, f=0, x, sair=1, rep1=1, num1, con, valido, confi, ga=0, u=0;
	char nome[40][40];
	char sigu[40][40];
	int num[40];
	int vot[40];
	
	

		do {
			
			system("cls");
	rep1=1;
	con=0;
	
	printf("\n1 - Cadastrar nome Candidato \n\a\a");
      printf("2 - Listar Candidatos \n");
     	printf("3 - Area de votação \n");
	       printf("4 - Apurar Eleiçoes \n");
	            printf("5 - Sair \n\n");
	                printf("Informe Opção desejada ");
	                scanf("%d", &menu);
	
	if(menu>5 || menu<1){
		printf("\nOpcão solicitada Incorreta\n");
		     system("pause");
	}
	
		
	
	switch(menu) {
		
		case 1 :
			printf("Informe  Nome Do Candidato para cadastrar \n");
			     scanf("%s",&nome[f]);
			
			printf("Sigla Do Partido do candidato ");
			     scanf("%s",&sigu[f]);
			
			     vot[f]=0;
			
			while(rep1==1){
			
			rep1=0;
				
			printf("Número do candidato");
			     scanf("%d",&num[f]);
			
			num1=num[f];
			
			for(x=0;x<f;x++) {
			     if(num[x]==num1){
				     printf("Já existe um cadastro com esse número, digite outro numero do candidato \n\n");
				         rep1=1;
			}
				
}
			
		}
			
			f++;
			
		break;
		
		case 2 :
			
			printf("\n\nNúmero \t");
			     printf("Nome       \t");
			         printf("Sigla partido \n");
			
			for(x=0;x<f;x++) {
		
			printf("%d \t",num[x]);
			     printf("%s       \t",nome[x]);
			         printf("%s\n",sigu[x]);
		}
			
			system("pause");		

		break;
			
		case 3 :
			while(con>=0){
			
			     valido=0;
			
			         printf("\nDigite o Número do Candidato ");
			             scanf("%d",&con);
			
			for(x=0;x<f;x++){
				
				if(con==num[x]){
				
				printf("%s \t %s \n\n", nome[x], sigu[x]);
				     printf("Deseja Confirmar o Voto\n");
				         printf("1 - SIM    2 - NÃO ");
				             scanf("%d",&confi);
				
				if(confi==1){
				
			       	vot[x]=1+vot[x];
				
				printf("Voto salvo com suseso\n");
				}else{if(confi==2){
					    printf("Voto cancelado com sucesso\n");
				}else{
					   printf("Opção invlida");
				}
				}
				
				valido=1;
				}
				
			}
				
				if(valido==0 && con>=0){
				     printf("Esse candidato não existe\n");
			}	 
			
			}
			
			
			
		break;
			
		case 4 :
			
			for(x=0;x<f;x++){
				if(vot[x]>ga){
				  	ga=vot[x];
				     	u=x;
				}  
		 }
		 
			
			printf(" %s , Venceu as eleições com %d votos.\n ",nome[u],vot[u]);
			     printf("APURAÇÃO\n\n");
			    
		
			printf("NUMERO \t");
			     printf("NOME \t");
			         printf("SIGLA PART. \t");
			           
			for(x=0;x<f;x++){
				
			
			printf("\n%d \t", num[x]);
			     printf("%s \t", nome[x]);
			         printf("%s \t", sigu[x]);
			             printf("%d \n", vot[x]);
		}
			system("pause");
			
		break;
		
		case 5 :
			
			sair=0;
			
		break;
		
	default:;
		
}
	           menu=0;
}                     while(menu>5 || menu<1 & sair==1);

}

