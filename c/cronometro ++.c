#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //permite a esecução do comando sleep

int main(){
	
int	tempo=0, hora = 0 , segundo = 0, minuto = 0;
	
		
		while(tempo < 10){
			
			printf("\n CRONOMETRO \n");
			
			
			printf("\n");
			
			printf(" %d : %d : %d ", hora , minuto , segundo);
			
			Sleep(1000);
			
		
			
		
			system("cls");
			
			segundo++;
			
				if(segundo==60){
				segundo=0;
				minuto++;
				}
					if(minuto==60){
					minuto=0;
					hora++;
				
					}
						if(hora==24){
							hora=0;
							
							}
			
		}
	
}
