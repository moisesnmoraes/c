    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>
    #include <conio.h>
    /* Arquivo CampoMinado.h Criado com as Fun��es Mais Usadas,
    tela inicial, sobre, sair, seletor de dificuldade, finaliza��es,
    etc...*/
    #include <CampoMinado.h>
    
    int tamx=10,tamy=10; // TAMANHO DO TABULEIRO. SEMPRE ADICIONAR 1 A MAIS. (Para 9, Digitar 10...) Max 15. (Valores Padr�es)
    int minas=25; // NUMERO DE BOMBAS NO TABULEIRO. (Valor Padr�o)
    int flagtype=0; // TIPO DE BANDEIRA (0 = LIMITADA COM BLOQUEIO, 1 = ILIMITADA - PARA VENCER NAO PODE USAR MAIS QUE O NUMERO DE BOMBAS EM BANDEIRAS)
    int mines[16][16]={0}, icon[16][16]={-1}, c[16][16], open[16][16]; //  DECLARA��O DAS MATRIZES TABULEIRO. 
    /* Mines armazena apenas a posi��o das minas. Icon armazena casas a serem mostradas no tabuleiro.
    c armazena as dicas, valores de referencia para as bombas e open armazena as casas j� abertas.*/
    
    int loser=0,acertos=0,minasreg=0,bandcount=0, py = 0, px = 1, casasclose=0; // Outras Vari�veis acessadas por v�rias fun��es.
    
    
    /* Verifica a matriz inteira procurando quadrados brancos ao redor de 
    quadrados brancos j� abertos, fazendo assim todas as casas brancas
    ligadas serem abertas juntas. 1 Posi��o de numeros envolta dessas
    casas brancas tamb�m � aberta aqui.*/
    void verifica_quadradro()
    {
     int lx=-1,ly=-1, count=0, a=0, b=0;
    
    // O Do Faz com que essa opera��o seja realizada N vezes ateh nenhum quadrado branco mais poder ser aberto. (var count).
     do {
         count=0;
         // For's para verificar toda a matriz.
         
         for(a=0;a<=tamx;a++)
            for(b=0;b<=tamy;b++) {
               if(mines[a][b] != 1 && open[a][b] != 1 && (
               (a-1 >= 0 && c[a-1][b] == 0 && open[a-1][b] == 1) || 
               (a+1 <= tamx && c[a+1][b] == 0 && open[a+1][b] == 1) || 
               (b-1 >= 0 && c[a][b-1] == 0 && open[a][b-1] == 1) || 
               (b+1 <= tamy && c[a][b+1] == 0 && open[a][b+1] == 1) || 
               (b-1 >= 0 && a-1 >= 0 && c[a-1][b-1] == 0 && open[a-1][b-1] == 1) || 
               (b+1 <= tamy && a-1 >= 0 && c[a-1][b+1] == 0 && open[a-1][b+1] == 1) ||  
               (b-1 >= 0 && a+1 <= tamx && c[a+1][b-1] == 0 && open[a+1][b-1] == 1) || 
               (b+1 <= tamy && a+1 <= tamx && c[a+1][b+1] == 0 && open[a+1][b+1] == 1)))
                              {
                                   /* Igualando icon a c, estamos fazendo o programa mostrar o valor de c, 
                                   visto que a matriz icon � a matriz que � exibida e c � a que contem as referencias.*/
                                   icon[a][b]=c[a][b];
                                   // Diminui um das casas dispon�veis.
                                   if(open[a][b] != 1 && a > 0 && a <= tamx && b >= 0 && b <= tamy) casasclose-=1;
                                   // Colocando 1 nessa posi��o da matriz open estamos dizendo que essa posi��o est� aberta.
                                   open[a][b]=1;    
                                   // Esse count indica que pelo menos um quadrado branco foi aberto a mais.                                                                                                      
                                   count+=1;
                                   }    
                                   }                                
    } while(count>0);
      return;
     }
     
     /* Essa fun��o gera as dicas, valores de referencia.
     Ela � executada sempre que uma nova bomba � gerada
     na fun��o gera_bomba. Sua funcionalidade � simples.
     Ela soma 1 a matriz c nos 8 quadrados envolta da 
     posi��o da bomba.*/
    void gera_dica(int xmine, int ymine)
     {
    if(xmine-1 >= 0) c[xmine-1][ymine]+=1;
    if(xmine+1 <= tamx+1) c[xmine+1][ymine]+=1;
    if(ymine-1 >= 0) c[xmine][ymine-1]+=1;
    if(ymine+1 <= tamy+1) c[xmine][ymine+1]+=1;
    if(xmine-1 >= 0 && ymine-1 >= 0) c[xmine-1][ymine-1]+=1;
    if(xmine-1 >= 0 && ymine+1 <= tamy+1) c[xmine-1][ymine+1]+=1;
    if(xmine+1 <= tamx+1 && ymine-1 >= 0) c[xmine+1][ymine-1]+=1;
    if(xmine+1 <= tamx+1 && ymine+1 <= tamy+1) c[xmine+1][ymine+1]+=1;  
     }     
    
    /* Fun��o para Gerar as bombas. Utilizando Apenas a Fun��o Rand
    Conseguimos gerar todas as bombas necess�rias.*/
    int gera_bomba()
    {
    int a=0,plus=0,xmine=0,ymine=0,reg=0;
    srand(time(NULL)); // Comando para a utiliza��o do rand.
    for (a = 0; a < minas; a++) { // For para criar todas as minas necess�rias.
     do { // Do para fazer com que as minas sejam criadas se qualquer empasse aparecer.
      plus=rand() % 2; // Rand prim�rio, gera��o randomica "plus"
      xmine=rand() % tamx+plus; // Gera��o randomica da Bomba no Tabuleiro
      plus=rand() % 2; // Rand prim�rio, gera��o randomica "plus"   
      ymine=rand() % tamy+plus; // Gera��o randomica da Bomba no Tabuleiro
      } while(mines[xmine][ymine] == 1 || xmine < 1 || xmine > tamx || ymine > tamy); // Verifica��o para determinar bomba fora do tabuleiro ou sobre outra j� existente.
    mines[xmine][ymine]=1; // Indica��o que a mina foi criada, foi inserida na sua matriz corretamente.
    gera_dica(xmine,ymine); // Chamada da fun��o que ir� gerar os valores de refer�ncia.
    reg+=1; // Registro que conta o n�mero de bombas criadas com sucesso.
    }
    return reg;
    }
    
    /* Essa fun��o � chamada dentro do MAIN durante a execu��o do jogo.
    a fun��o dela � captar a tecla precionada e ent�o executar uma a��o determinada.*/
    
        // Ascii Codes Das Setas de Fun��o
    // 75 = <
    // 77 = >
    // 72 = /\
    // 80 = \/
    // 13 = ENTER
    // 8 = Backspace (Apagar)
    // 32 = Space.
    // a = 97
    // ? = 63
    
    int esperar_tecla() { 
    int d=0, p=0;   
    d=getch(); // Capta a Tecla Precionada.
    if(d == '0') d=0; // Caso a Tecla Precionada seja 0, o Jogo � Finalizado.
    if(loser != 0) d=perder(); // Caso o Jogador tenha aberto uma Bomba, a Vari�vel Loser � setada diferente de 0 O usu�rio abriu uma bomba, ele perdeu.
    if(acertos == minasreg && minasreg-bandcount == 0) d=vencer(); // Se o Numero de Acertos (bandeiras) do usu�rio for = ao numero de bombas e as bandeiras no jogo n�o exced�o o limite, o usu�rio venceu. 
    if(d >= 97 && d <= 97+14) { // Verifica se a tecla precionada no teclado � uma letra (ateh a 15� posi��o) para navega��o por teclado.
     do { p=getch(); } while(p<97 || p>97+14);  // Caso uma letra nesse padr�o tenha sido precionada, ele aguarda por outra letra no mesmo padr�o (linha x coluna)
     if (96-d>tamx || 96-p>tamy) return; // Caso a segunda tecla precionada n�o seja no mesmo padr�o da primeira, essa sequencia � finalizada.
     px=d-96; // Define a Posi��o Na Matriz Campo Quando a navega��o est� sendo realizada por letras.
     py=p-97; // Define a Posi��o Na Matriz Campo Quando a navega��o est� sendo realizada por letras.
     }  
    if(d == 63 && icon[px][py] == 383 && open[px][py] != 1) { icon[px][py]=63; bandcount-=1; } // Insere o Caractere ? no Tabuleiro Sobrescrevendo uma Bandeira
    if(d == 63 && icon[px][py] != 63 && open[px][py] != 1) { icon[px][py]=63;} // Insere o Caractere ? no Tabuleiro Fechado.
    if(d == 75 && py > 0) py-=1; // Faz o Cursor Andar Para a Esquerda. Navega��o por Setas.
    if(d == 32 && icon[px][py] == 383) { icon[px][py]=-1; bandcount-=1; } // Remove uma Bandeira de Determinada Casa Utilizando o Espa�o.
    else if(d == 32 && icon[px][py] != 383 && (bandcount<minas || flagtype == 1) && open[px][py] != 1) { icon[px][py]=383; bandcount+=1; } // Insere uma Bandeira em Determinada casa Utilizando o Espa�o.
    if(d == 8 && icon[px][py] == 383 && open[px][py] != 1) { icon[px][py]=-1; bandcount-=1; } // Elimida uma Bandeira Utilizando o Backspace
    if(d == 8 && icon[px][py] != 0 && open[px][py] != 1) { icon[px][py]=-1;} // Elimina um Caractere ? Utilizando o Backspace
    if(d == 77 && py < tamy) py+=1; // Faz o Cursor Andar Para a Direita. Navega��o por Setas.
    if(d == 72 && px > 1) px-=1; // Faz o Cursor Andar Para Cima. Navega��o por Setas.
    if(d == 80 && px < tamx) px+=1; // Faz o Cursor Andar Para Baixo. Navega��o por Setas.
    if(d == 13 && mines[px][py] == 1 && icon[px][py] != 383 && icon[px][py] != 0) { icon[px][py]=9; open[px][py]=1; loser=1;} // Abre um Casa com Bomba. Assim que a Matriz exibir essa bomba, o usu�rio ser� informado que o jogo acabou.
    if(d == 13 && mines[px][py] != 1 && icon[px][py] != 383 && icon[px][py] != 0) { casasclose-=1; icon[px][py]=c[px][py]; open[px][py]=1; if(c[px][py] == 0) verifica_quadradro(); } // Abre uma casa sem bomba. Logo � iniciada uma verifica��o por quadrados vazios.
    return d;
    }
        
    /* C�digo Principal. Aqui � iniciado o jogo, bem como chamado v�rias fun��es, inclusive
    do arquivo CampoMinado.h, desenhado a matriz jogo, etc.*/;    
    void main()
    {  
    int a=0, b=0, ctrl=0, tecla=0,iniciar=0, ordema=64, ordemb=64;
    int xmine=0, ymine=0, plus=0, cor=0, dif=0;
    definir_cor(240);
    limpar();
    // � Chamada a Tela Inicial, o Menu, do arquivo CampoMinado.h Aqui o usu�rio ir� escolher a op��o. 
    // O c�digo s� retornar� para essa fun��o ap�s o usu�rio escolher a dificuldade ou escolher fechar o jogo.
    iniciar=tela_inicial();
    if(iniciar < 4) { // Caso o valor retornado seja menor que 4, uma dificuldade foi selecionada. Caso seja 4, o usu�rio optou por fexar o jogo.
    dif=seletor_dificuldade(&tamx,&tamy,&minas); // Aqui a fun��o tamb�m presente no CampoMinado.h � chamada para que o usu�rio escolha a dificuldade.
    if(dif == 1) { // Caso a Dificuldade F�cil Seja Selecionada, a fun��o retorna 1 e os valores s�o definidos aqui.
       tamx=10;
       tamy=10;
       minas=10;
       casasclose=90; 
       }
    if(dif == 2) { // Caso a dificuldade avan�ado seja selecionada, a fun��o retorna 2 e os valores s�o definidos aqui.
       tamx=15;
       tamy=15;
       minas=30;
       casasclose=195;
       }     
       // Caso nem f�cil nem avan�ado seja selecionado, e sim personalizado, os valores s�o definidos normalmente integrando o valor no endere�o das vari�veis definidas acima.
    tamx-=0;
    tamy-=1;  // Corre��o de um bug na hora da cria��o da matriz.   
    if(casasclose == 0) casasclose=(tamx*(tamy+1))-minas; 
    //Definir Valores da Matriz NORMAL como -1 (NULO)
    for(a=0;a<=tamx;a++)
    for(b=0;b<=tamy;b++)
    icon[a][b]=-1; // Como o valor 0 representa um espa�o vazio, sem valor, utilizamos o -1 para representar uma casa fechada ainda.
    
    minasreg=gera_bomba(); // Aqui � chamada a fun��o que gera as minas no tabuleiro. A vari�vel minasreg recebe quantas bombas for�o inseridas com sucesso.
      
      do { // Do faz com que a matriz seja redesenhada todas as vezes que o usu�rio entrar com uma tecla de a��o, a menos que o jogo seja finalizado.
          //loser=0; // Define a vari�vel que indica que o usu�rio perdeu como 0.
          definir_cor(240);
          limpar();
          printf("\n        ");
          printf("%c",201);
          // Cria��o do "Placar" Que exibe algumas informa��es para o usu�rio durante o jogo.
          for(a=0;a<29;a++) printf("%c",205);
          printf("%c",187);
          printf("\n        %c  ",186);
          definir_cor(249);
          printf("Bandeiras Disponiveis: %d ",minasreg-bandcount,186); // Informa para o usu�rio quantas bandeiras ainda pode inserir.
          definir_cor(240);;
          if(minasreg-bandcount <= 9) printf("  %c\n        %c  ",186,186);
          else printf(" %c\n        %c  ",186,186);
          definir_cor(249);         
          printf("Bombas em Jogo: %d        ",minasreg,186); // Infoirma ao usu�rio quantas bombas est�o em jogo.
          definir_cor(240);
          if(minasreg <= 9) printf("  %c\n        %c  ",186,186);
          else printf(" %c\n        %c  ",186,186);
          definir_cor(249);         
          if(casasclose <= 9) printf("Casas sem Bomba: %d        ",casasclose); // Informa para o usu�rio quantas casas ainda faltam abrir.
          if(casasclose <= 99 && casasclose > 9) printf("Casas sem Bomba: %d        ",casasclose);
          if(casasclose > 99) printf("Casas sem Bomba: %d       ",casasclose);
          definir_cor(240);
          if(casasclose <= 9) printf(" %c\n        %c",186,200);
          if(casasclose <= 99 && casasclose > 9) printf("%c\n        %c",186,200); 
          if(casasclose > 99) printf("%c\n        %c",186,200);
          
          for(a=0;a<29;a++) printf("%c",205); 
          printf("%c",188);
          printf("\n\n");
          definir_cor(135);
    for(a = 0; a <= tamx; a++) // Inicia o Desenho do Tabuleiro. (LINHA)
    
      {
      definir_cor(240);
      if (a > 0) ordema++; // Valor Inicial � 64 Gera os "numeros" de ordem que se tornaram letras, para as laterais do tabuleiro.
      if(dif == 1 && a > 0) printf("                   %c ",ordema);
      if(dif != 1 && a > 0) printf("       %c ",ordema);
      definir_cor(135);
      if (a > 0) printf("|");
      for(b = 0; b <= tamy; b++) // Desenho do Tabuleiro (COLUNA)
            {
                 ordemb++; // Gera os "numeros" de ordem que se tornaram letras, para a parte superior do tabuleiro.
                 definir_cor(240);
                 if(a == 0 && dif == 1 && b == 0) printf("                       %c",ordemb);
                 if(a == 0 && dif != 1 && b == 0) printf("           %c",ordemb);
                 if(a == 0 && dif == 1 && b > 0) printf("   %c",ordemb);
                 if(a == 0 && dif != 1 && b > 0) printf("   %c",ordemb);
                 definir_cor(135);
                 if (a > 0) {
                 ctrl=0;
                 // Verifica se o Quadrado est� aberto, para mudar a sua "cor de fundo"
                 if(icon[a][b] >= 0 && icon[a][b] <= 9) definir_cor(119);
                 else definir_cor(135);
                 printf("_");
                 definir_cor(135);               
                if(icon[a][b] == 63) { // Insere o Caractere ? na Matriz.
                               
                               definir_cor(142);
                               printf("%c",63);
                               definir_cor(135);
                              ctrl+=2;
                              } 
                              
                if(icon[a][b] == 383) { // Insere o Caractere Indicando a Bandeira no C�digo.
                               
                               definir_cor(138);
                               printf("%c",383);
                               definir_cor(135);
                               ctrl+=2;
                              } 
                              
                 if(icon[a][b] >= 0 && icon[a][b] <= 8) { // Insere o Numero de Refer�ncia a Quadrados abertos ou espa�o vazio no c�digo.
                               
                               definir_cor(127);
                               if(icon[a][b] > 0) printf("%d",icon[a][b]); // Caso a casa n�o seja vazia, insere o numero de refer�ncia.
                               else
                               printf(" ");
                               definir_cor(135);
                               ctrl+=2;
                              } 
                 
                 if(icon[a][b] == 9 || loser == 1) { // Caso o usu�rio abra uma bomba, � exibido um X vermelho para ele.
                               if((loser == 1 && mines[a][b]==1) || icon[a][b] == 9) {
                               definir_cor(124);
                               printf("X",icon[a][b]);
                               definir_cor(135);
                               ctrl+=2;
                               //loser+=1; // E o mesmo ir� para a tela que o informa sua derrota.
                              } }
                                                 
                 if(icon[a][b] >= 0 && icon[a][b] <= 9) definir_cor(119);
                 else definir_cor(135);    
                 if(icon[a][b] == -1 || a != px || b != py) printf("_"); // Caso a seta de navega��o n�o esteja no campo em quest�o, o terceiro caractere � um _   
                 definir_cor(135);             
                 //printf("%d %d",px,py);
                 if(a == px && b == py) // Caso a seta de navega��o ESTEJA no campo em quest�o, o terceiro caractere � uma Seta.   
                      {
                      if(icon[a][b] >= 0 && icon[a][b] <= 9) definir_cor(127);
                      else definir_cor(143);
                               printf("%c",539);
                               definir_cor(135);
                               ctrl+=1;
                               }
                               
            if(ctrl == 0) printf("_"); // Caso n�o haja nada aberto no campo em quest�o, o 3� _ � inserido indicando casa vazia ou branca.
            printf("|");
            }
            }
      printf("\n"); // Pula para a Proxima linha do Tabuleiro.
      }
    ordema=64; // C�digo inicial para a letra a na tabela ascii.
    ordemb=64; // C�digo inicial para a letra a na tabela ascii.      
    definir_cor(240);
    printf("\n     # Informe a Linha e em Seguida a Coluna ou Pressione uma Tecla de A%c%co: ",135,198);
    tecla=esperar_tecla(); // � Aguardado o precionamento de uma tecla pelo usu�rio.
    
    a=0;
    b=0;
    acertos=0;
    do {
    for(a=0;a<=tamx;a++) // 2 FORs para varrerem a matriz buscando quantas bombas o usu�rio acertou, utilizando a bandeira.
    for(b=0;b<=tamx;b++)
    if(mines[a][b] == 1 && icon[a][b]==383) acertos++; // A Vari�vel acertos � incrementada sempre que acontecer.   
    } while (acertos < bandcount && (a < tamx && b < tamy));
    } while(tecla != 0); // Redesenha o tabuleiro se a tecla '0' ou uma a��o n�o acontecer.
    }
    }
    
