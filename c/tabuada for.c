#include <stdio.h>


void  main(){
	
	printf("PROGRAMA PARA VER QUALQUER TABUADA \n");
	system("pause");
	system("cls");
	int nro, cont, result;
	
	while(nro!=result){
	
	printf("digite a tabuada que deseja visualizar\n");
	scanf("%d",&nro);
	
	for(cont=0;cont<=10;cont++){
		result=(nro*cont);
		printf("\n %d X %d = %d\n",nro,cont, result);
	}
	}
			system("cls");	
	
	

}
