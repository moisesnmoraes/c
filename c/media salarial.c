#include <stdio.h>
#include <locale.h>


void main(){
	
	setlocale(LC_ALL,"");
	char nome [100];
	
	 int controle, funcionarios;
	 float salario, acumula, constante, media,ms;
	controle=1;
	while (controle ==1 ){
		printf("Nome do Funcionário\n");
		gets(nome);
		//strcpy(nome,"gents");
		
		 printf("salario ");
		scanf("%f",&salario);
	//	setbuf(stdin, NULL);
		acumula=(acumula + salario);
		constante=constante+1;
		//puts(nome);
		
		printf("");
		
	printf("deseja continuar \n1 - sim \n2 - nao ");	
		scanf("%d",&controle);
		setbuf(stdin, NULL);
		
		system("cls");
	}
	
	media = (acumula/constante);
	printf("media é %f \n",media);
	printf("soma dos salarios é %f \n",acumula);
	puts(nome);
	


}
	
	
	
	
	
	
		  
		  
	
	

