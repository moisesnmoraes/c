#include<stdio.h>
#include<locale.h>

void main(){
	setlocale(LC_ALL,"");

	 float valorvenda,valorparcela;
	 int formadepagamento, condicaopagamento,valortotal,simular;
	 simular = 1;
	while(simular<2) {
	 
	printf("Informe o valor de venda\n");
	scanf("%f",&valorvenda);
	
	printf("");
	valorparcela =0;
	formadepagamento = 0;
	condicaopagamento = 0;
	while(formadepagamento <1||formadepagamento>5){
	
	printf("1- cartão\n");
	printf("2- a vista(dinheiro em especie)\n");
	printf("3- cartão de débito(visa)\n");
	printf("4- cartão de débito(master card)\n");
	printf("5- boleto bancário\n");
	scanf("%d", &formadepagamento);
	
	if(formadepagamento<1||formadepagamento>5){
		printf("forma de pagamento incorreta\n");
		printf("selecione uma forma de pagamento entre 1 e 5\n");
	}
}
while(condicaopagamento<=1||condicaopagamento>=12){

	printf("informe a condição de pagamento \n");
	scanf("%d", &condicaopagamento);
	
	if(condicaopagamento<1||condicaopagamento>12){
		printf("condição invalida!!! \n informe uma condição valida entre 1 e 12\n");
		
	}

}
// FORMAS DE PAGAMENTO
if(formadepagamento == 1 && (condicaopagamento >= 7 && condicaopagamento <= 12)){
	valorparcela = valorvenda/ condicaopagamento;
	valorparcela= valorparcela+((valorparcela * 1.7)/100);
	
}

if(formadepagamento==5 && condicaopagamento >=1 && condicaopagamento <=4){
		valorparcela = valorvenda/ condicaopagamento;
	valorparcela= valorparcela+((valorparcela * 0.3)/100);
	
}
	if(formadepagamento==5 && condicaopagamento >=5 && condicaopagamento <=7){
		valorparcela = valorvenda/ condicaopagamento;
	valorparcela= valorparcela+((valorparcela * 3.3)/100);
}
if(formadepagamento==5 && condicaopagamento >=8 && condicaopagamento <=12){
		valorparcela = valorvenda/ condicaopagamento;
	valorparcela= valorparcela+((valorparcela * 5.3)/100);
	
	
}
printf("valor da parcela com jurod %f\n",valorparcela);
valortotal=valorparcela*condicaopagamento;
printf("total  de parcelas %d\n",condicaopagamento);
printf("valor total %d ",valortotal);

printf("deseja continuar\n (1 - sim  2 - nao)");
scanf("%d",&simular);
system ("cls");
}
}

