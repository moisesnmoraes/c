#include <stdio.h>
void main()
{
  float salario, aumento, novo_salario, porc;
  printf("Digite o salario = ");
  scanf("%f",&salario);
  printf("Porcentagem = ");
  scanf("%f",&porc);
  
  aumento = salario * (porc / 100);
  novo_salario = salario + aumento;
  printf("Aumento = R$ %.2f \n",aumento);
  printf("Novo Salario = R$ %.2f \n",novo_salario);
  system("pause");}
