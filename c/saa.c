
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
int depend;
float salario_bruto,x,y,salario_liquido;

printf("Entre com o salario bruto\n");// Adicionei \n no final de todos os seus printf para eles quebrarem linha
scanf ("%f", &salario_bruto);
fflush(stdin); // Depois de ler da entrada padrão você tem de limpar o buffer para tirar o enter
x=(salario_bruto*0.82)*0.5; // Aqui faltava o ponto-e-vírgula, além disso você estava usando ',' e não '.' para separar os digitos decimais
//scanf ("%f", &x); // O que faz isso aqui?
printf ("Entre com a quantidade de dependentes\n");
scanf("&d", &depend); // Aqui faltava o ponto-e-vírgula
fflush(stdin); // Depois de ler da entrada padrão você tem de limpar o buffer para tirar o enter
y=(depend*50); // Aqui faltava o ponto-e-vírgula
//scanf ("%f", &y); // E o que faz isso aqui?
// Aqui o :( estavam fora das aspas, além disso argumentos pro printf não são passados com o & na frente deles
printf("O valor total de descontos e: %f\n", x);
// Aqui também
printf("O total de acrescimo e: %f\n", y);
printf("Seu salario liquido e: %f\n", salario_bruto-x+y); // Aqui faltava o %f
getchar();
return(0);}
