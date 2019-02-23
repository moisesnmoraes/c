#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	int c;
	int nro;
	char result[100];
	for(c=0; c<10; c++){
	
	printf("numero para transformar em BINARIO!!!\n");
	scanf("%d",&nro);
	
	itoa (nro , result, 2);
	printf("Binario : %s\n", result);
	getch();
	
}
}
