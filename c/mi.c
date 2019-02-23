	#include <stdio.h>
	
	
	
	void main(){
	
	
	int mat3[10][10]; 
	int bomb;
	 int vet_bomb[10];
	int x, y, z = 1;
	int	carrega_matri;
	int mat1[10][10];
	int op, bomba, i, tentativas = 1;
	int vetor_bombas[10];

	printf("Bem-vindo ao jogo de Campo Minado em C\n\n\n");
	printf("O que voce deseja?\n\n1 - Jogar\n2 - Sair\n\n");
	scanf("%d", &op);

	if(op == 2){
		exit(1);
	}
	else{
		system("cls"); // Limpa a tela 

		// Vai iniciar e criar o vetor de valores aleatorios de onde serao colocadas as bombas
		srand(time(NULL));
		for(i=0; i<10; i++){
			vetor_bombas[i] = 1 + rand() % (100 - 1);
		}

		 // Carrega a matriz original
		
		printf("Intrucoes de Jogo:\n\n");
		printf("\tVoce devera escolher um numero de 1 a 100 para desarmar as bombas.\n\tExistem 10 bombas espalhadas pelo cenario. Caso voce escolha um \n\tnumero de onde se encontra uma bomba, aparecera o simbolo B no lugar.\n\tCaso voce escolha um numero de onde nao ha bomba, \n\taparecera o simbolo N.\n\tO objetivo do jogo é encontrar as 10 bombas em ate 35 tentativas.\n\n\tUpdate: Simulando um jogo real de Campo Minado, caso voce escolha \n\tum valor que nao exista bomba e que em todos ao redor deles tambem \n\tnao exista bomba, todos sao trocados por N.\n\n\n");
		printf("Esta pronto para comecar o jogo?\n\n1 - Jogar\n2 - Sair\n\n");
		scanf("%d", &op);

		if(op == 2){
			exit(1);
		}
		else{
			while((tentativas <= 36) && (glo_bomb <= 9)){
				system("cls"); // Limpa a tela 
				imprime_matriz(matriz); // Imprime a matriz, ja com as alteracoes
				printf("\n\n\n");
				if(tentativas < 36)
					printf("Tentativa: %da\tBombas encontradas: %d\n\n\n\n", tentativas, glo_bomb);
				else if (tentativas == 36){
					printf("Tentativa: %da\tBombas encontradas: %d\n\n\n\n", (tentativas-1), glo_bomb);
					break;
				}
				printf("Qual numero voce deseja explodir?\n");
				scanf("%d", &bomba);
				explode(matriz, bomba, vetor_bombas); // Manda a matriz, o valor escolhido e o vetor de bombas para verificar se era um B ou um N
				tentativas++;
			}
			if(glo_bomb <=9)
				printf("Que pena, voce nao conseguiu. Tente de novo!\n\n");
			else if(glo_bomb==10)
				printf("Parabens! voce conseguiu!\n\n");
		}
	}
	system("pause");
	return 0;
}
}
