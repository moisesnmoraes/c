#include<stdlib.h>

#include<stdio.h>

#include<math.h>

int npc;

double total,horae,horas,retotal;

main(){

printf("\n Informe o numero do Computador: ");

scanf("%i",&npc);

fflush(stdin);

printf("\nHora de entrada ex: 12.00: ");

scanf("%lf",&horae);

fflush(stdin);

printf("\nHora de saida ex: 13.00: ");

scanf("%lf",&horas);

fflush(stdin);

total=(horas-horae);

if(total<=59){

retotal=((total*100)*2.5)/60;

printf("\n Valor RS%.2lf\n",retotal);

system("pause");

}

else{

retotal=((total*60)*2.5);

printf("\n Valor RS%.2lf\n",retotal);

system("pause");

return 0;

}

}


