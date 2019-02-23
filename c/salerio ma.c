//#include <stdio.h>
//#include<iostream> 
//#include <cstdlib>
//#include <conio.h>
 
//using namespace std;
 
 
//int main(){
    
  //  float salario=0,calc=0;
    //int i=0;
    //int quantidade=0;
    //float media =0,menorSalario=0,maiorSalario=0;
    
    //cout<<"Digite a quantidade de salarios que deseja cadastrar : ";
    //cin>>quantidade; //ler a quantidade de salarios no maximo 100;
    //cout<<endl;          
    //while(i < quantidade){  
    
      //   if(quantidade > 100){ //verifica se a quantidade digitada pelo usuario é maior que 100  
                       
        //               cout<<"Voce digitou um numero maior que 100 ! "<<endl;
          //             cout<<"----------------------------------------------"<<endl;
            //           main(); // volta a funcao principal
                       
              //         } // fechamento da condicao 
                       
                       //caso a  condicao seja falsa  sera executada os comandos abaixo
                //        cout<<"Digite o salario : "; //digite o seu salario
                  //      cin>>salario;
                    //    maiorSalario=salario; 
                      //  menorSalario=salario;
                        //calc=calc+salario; // soma todos os salarios 
                        //media= (calc/quantidade);//exibe a media dos salarios digitados
                        //i++; // incremento
                        
                        
                        
                        //Verifica qual é o maior e o menor salario
                        
                        
                        //if(salario >maiorSalario){
                          //    maiorSalario=salario;
                                                  
                           //   }
                   //     else if(salario<menorSalario){
                     //        menorSalario=salario;
                             
                             
//                             }      
  //                      }
 
    //                    cout<<"------------------------"<<endl;
      //                  cout<<"Soma do Salario : \a"<<calc<<endl; //exibe a soma na tela
        //                cout<<"Salarios Cadastrados : \a"<<i<<endl; // exibe a quantidade de salarios            
          //              cout<<"Media e : \a"<<media<<endl;  //exibe a media
            //             cout<<"Maior Salario : "<<maiorSalario<<endl; //exibe o maior salario
              //          cout<<"Menor Salario : "<<menorSalario<<endl;//exibe o menor salario
 
//getch();
//return 0;
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <locale.h>
main()
	{
		setlocale(LC_ALL,"");
	float salario[5],soma=0,media,salario_maior=-1,salario_menor=99999;
	char nome[5][20],nome_maior[20],nome_menor[20];
	int i;
		  
	for(i=0;i<5;i++)
	{
	   printf("\nDigite seu salario:");									
	   scanf("%f",&salario[i]);
	   printf("\nDigite seu nome:");		 
	   scanf("%s",&nome[i]);
			 
	}
	for(i=0;i<5;i++)
	   printf("\n%f,%s",salario[i],nome[i]);
	for(i=0;i<5;i++)
	{
	   soma=salario[i]+soma;
	}  
	media=soma/5;
	printf("\nA media é:%f",media);
	for(i=0;i<5;i++)
	{
			if(salario[i]<salario_menor)
		  {
		  salario_menor=salario[i];
		  strcpy(nome_menor,nome[i]);
		  }
	   if(salario[i]>salario_maior)
		  {salario_maior=salario[i];
		  strcpy(nome_maior,nome[i]);
		  }
	 }
	printf("\n%f,%s",salario_menor,nome_menor);
	 printf("\n%f,%s",salario_maior,nome_maior);
}

