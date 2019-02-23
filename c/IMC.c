 #include <stdio.h>
 
 
 void main(){
 	int co;
 	float altura, peso, imc;
 	for(co=0;co<10;co++){
	 
 	printf("___calcule____ seu ____imc_______________\n");
 	printf("\n__________\n_______________\n");
 	printf("informe sua altura\n");
 	scanf("%f",&altura);
 	
 	printf("\n___________\n________________\n");
 	printf("informe seu peso\n");
 	scanf("%f",&peso);
 	
 	//calculo do imc
 	imc = peso / (altura * altura);
 	
 	printf("seu IMC é %.2f\n",imc);
 	
 	if(imc<18.5){
 		printf("voce esta abaixo do peso\n");
 		printf("\n\n");
		 }
		else if(imc<=18.5 || imc<25){
	 		printf("voce esta com peso normal\n");
	 		printf("\n\n");
	 	
			 }
 			else if(imc>24.9 || imc<30){
 				printf("voce esta com sobre peso\n");
 				printf("\n\n");
 		
			 }
 				else if(imc>=30 && imc<40){
 				printf("voce esta obeso\n");
 				printf("\n\n");
			 }
 					else if(imc>=40){
 		
 						printf("CUIDADO \n Voce esta com obesidade morbida\n");
 							printf("\n\n");
						 }
	 system("\n pause \n");
	 system("cls");
	 
}
 }
