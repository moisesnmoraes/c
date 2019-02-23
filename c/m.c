    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>
    #include <conio.h>
    /* Arquivo CampoMinado.h Criado com as Funções Mais Usadas,
    tela inicial, sobre, sair, seletor de dificuldade, finalizações,
    etc...*/
    #include <CampoMinado.h>
    
    int tamx=10,tamy=10; // TAMANHO DO TABULEIRO. SEMPRE ADICIONAR 1 A MAIS. (Para 9, Digitar 10...) Max 15. (Valores Padrões)
    int minas=25; // NUMERO DE BOMBAS NO TABULEIRO. (Valor Padrão)
    int flagtype=0; // TIPO DE BANDEIRA (0 = LIMITADA COM BLOQUEIO, 1 = ILIMITADA - PARA VENCER NAO PODE USAR MAIS QUE O NUMERO DE BOMBAS EM BANDEIRAS)
    int mines[16][16]={0}, icon[16][16]={-1}, c[16][16], open[16][16]; //  DECLARAÇÃO DAS MATRIZES TABULEIRO. 
    /* Mines armazena apenas a posição das minas. Icon armazena casas a serem mostradas no tabuleiro.
    c armazena as dicas, valores de referencia para as bombas e open armazena as casas já abertas.*/
    
    int loser=0,acertos=0,minasreg=0,bandcount=0, py = 0, px = 1, casasclose=0; // Outras Variáveis acessadas por várias funções.
    
    
    /* Verifica a matriz inteira procurando quadrados brancos ao redor de 
    quadrados brancos já abertos, fazendo assim todas as casas brancas
    ligadas serem abertas juntas. 1 Posição de numeros envolta dessas
    casas brancas também é aberta aqui.*/
    void verifica_quadradro()
    {
     int lx=-1,ly=-1, count=0, a=0, b=0;
    
    // O Do Faz com que essa operação seja realizada N vezes ateh nenhum quadrado branco mais poder ser aberto. (var count).
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
                                   visto que a matriz icon é a matriz que é exibida e c é a que contem as referencias.*/
                                   icon[a][b]=c[a][b];
                                   // Diminui um das casas disponíveis.
                                   if(open[a][b] != 1 && a > 0 && a <= tamx && b >= 0 && b <= tamy) casasclose-=1;
                                   // Colocando 1 nessa posição da matriz open estamos dizendo que essa posição está aberta.
                                   open[a][b]=1;    
                                   // Esse count indica que pelo menos um quadrado branco foi aberto a mais.                                                                                                      
                                   count+=1;
                                   }    
                                   }                                
    } while(count>0);
      return;
     }
     
     /* Essa função gera as dicas, valores de referencia.
     Ela é executada sempre que uma nova bomba é gerada
     na função gera_bomba. Sua funcionalidade é simples.
     Ela soma 1 a matriz c nos 8 quadrados envolta da 
     posição da bomba.*/
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
    
    /* Função para Gerar as bombas. Utilizando Apenas a Função Rand
    Conseguimos gerar todas as bombas necessárias.*/
    int gera_bomba()
    {
    int a=0,plus=0,xmine=0,ymine=0,reg=0;
    srand(time(NULL)); // Comando para a utilização do rand.
    for (a = 0; a < minas; a++) { // For para criar todas as minas necessárias.
     do { // Do para fazer com que as minas sejam criadas se qualquer empasse aparecer.
      plus=rand() % 2; // Rand primário, geração randomica "plus"
      xmine=rand() % tamx+plus; // Geração randomica da Bomba no Tabuleiro
      plus=rand() % 2; // Rand primário, geração randomica "plus"   
      ymine=rand() % tamy+plus; // Geração randomica da Bomba no Tabuleiro
      } while(mines[xmine][ymine] == 1 || xmine < 1 || xmine > tamx || ymine > tamy); // Verificação para determinar bomba fora do tabuleiro ou sobre outra já existente.
    mines[xmine][ymine]=1; // Indicação que a mina foi criada, foi inserida na sua matriz corretamente.
    gera_dica(xmine,ymine); // Chamada da função que irá gerar os valores de referência.
    reg+=1; // Registro que conta o número de bombas criadas com sucesso.
    }
    return reg;
    }
    
    /* Essa função é chamada dentro do MAIN durante a execução do jogo.
    a função dela é captar a tecla precionada e então executar uma ação determinada.*/
    
        // Ascii Codes Das Setas de Função
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
    if(d == '0') d=0; // Caso a Tecla Precionada seja 0, o Jogo é Finalizado.
    if(loser != 0) d=perder(); // Caso o Jogador tenha aberto uma Bomba, a Variável Loser é setada diferente de 0 O usuário abriu uma bomba, ele perdeu.
    if(acertos == minasreg && minasreg-bandcount == 0) d=vencer(); // Se o Numero de Acertos (bandeiras) do usuário for = ao numero de bombas e as bandeiras no jogo não excedão o limite, o usuário venceu. 
    if(d >= 97 && d <= 97+14) { // Verifica se a tecla precionada no teclado é uma letra (ateh a 15ª posição) para navegação por teclado.
     do { p=getch(); } while(p<97 || p>97+14);  // Caso uma letra nesse padrão tenha sido precionada, ele aguarda por outra letra no mesmo padrão (linha x coluna)
     if (96-d>tamx || 96-p>tamy) return; // Caso a segunda tecla precionada não seja no mesmo padrão da primeira, essa sequencia é finalizada.
     px=d-96; // Define a Posição Na Matriz Campo Quando a navegação está sendo realizada por letras.
     py=p-97; // Define a Posição Na Matriz Campo Quando a navegação está sendo realizada por letras.
     }  
    if(d == 63 && icon[px][py] == 383 && open[px][py] != 1) { icon[px][py]=63; bandcount-=1; } // Insere o Caractere ? no Tabuleiro Sobrescrevendo uma Bandeira
    if(d == 63 && icon[px][py] != 63 && open[px][py] != 1) { icon[px][py]=63;} // Insere o Caractere ? no Tabuleiro Fechado.
    if(d == 75 && py > 0) py-=1; // Faz o Cursor Andar Para a Esquerda. Navegação por Setas.
    if(d == 32 && icon[px][py] == 383) { icon[px][py]=-1; bandcount-=1; } // Remove uma Bandeira de Determinada Casa Utilizando o Espaço.
    else if(d == 32 && icon[px][py] != 383 && (bandcount<minas || flagtype == 1) && open[px][py] != 1) { icon[px][py]=383; bandcount+=1; } // Insere uma Bandeira em Determinada casa Utilizando o Espaço.
    if(d == 8 && icon[px][py] == 383 && open[px][py] != 1) { icon[px][py]=-1; bandcount-=1; } // Elimida uma Bandeira Utilizando o Backspace
    if(d == 8 && icon[px][py] != 0 && open[px][py] != 1) { icon[px][py]=-1;} // Elimina um Caractere ? Utilizando o Backspace
    if(d == 77 && py < tamy) py+=1; // Faz o Cursor Andar Para a Direita. Navegação por Setas.
    if(d == 72 && px > 1) px-=1; // Faz o Cursor Andar Para Cima. Navegação por Setas.
    if(d == 80 && px < tamx) px+=1; // Faz o Cursor Andar Para Baixo. Navegação por Setas.
    if(d == 13 && mines[px][py] == 1 && icon[px][py] != 383 && icon[px][py] != 0) { icon[px][py]=9; open[px][py]=1; loser=1;} // Abre um Casa com Bomba. Assim que a Matriz exibir essa bomba, o usuário será informado que o jogo acabou.
    if(d == 13 && mines[px][py] != 1 && icon[px][py] != 383 && icon[px][py] != 0) { casasclose-=1; icon[px][py]=c[px][py]; open[px][py]=1; if(c[px][py] == 0) verifica_quadradro(); } // Abre uma casa sem bomba. Logo é iniciada uma verificação por quadrados vazios.
    return d;
    }
        
    /* Código Principal. Aqui é iniciado o jogo, bem como chamado várias funções, inclusive
    do arquivo CampoMinado.h, desenhado a matriz jogo, etc.*/;    
    void main()
    {  
    int a=0, b=0, ctrl=0, tecla=0,iniciar=0, ordema=64, ordemb=64;
    int xmine=0, ymine=0, plus=0, cor=0, dif=0;
    definir_cor(240);
    limpar();
    // é Chamada a Tela Inicial, o Menu, do arquivo CampoMinado.h Aqui o usuário irá escolher a opção. 
    // O código só retornará para essa função após o usuário escolher a dificuldade ou escolher fechar o jogo.
    iniciar=tela_inicial();
    if(iniciar < 4) { // Caso o valor retornado seja menor que 4, uma dificuldade foi selecionada. Caso seja 4, o usuário optou por fexar o jogo.
    dif=seletor_dificuldade(&tamx,&tamy,&minas); // Aqui a função também presente no CampoMinado.h é chamada para que o usuário escolha a dificuldade.
    if(dif == 1) { // Caso a Dificuldade Fácil Seja Selecionada, a função retorna 1 e os valores são definidos aqui.
       tamx=10;
       tamy=10;
       minas=10;
       casasclose=90; 
       }
    if(dif == 2) { // Caso a dificuldade avançado seja selecionada, a função retorna 2 e os valores são definidos aqui.
       tamx=15;
       tamy=15;
       minas=30;
       casasclose=195;
       }     
       // Caso nem fácil nem avançado seja selecionado, e sim personalizado, os valores são definidos normalmente integrando o valor no endereço das variáveis definidas acima.
    tamx-=0;
    tamy-=1;  // Correção de um bug na hora da criação da matriz.   
    if(casasclose == 0) casasclose=(tamx*(tamy+1))-minas; 
    //Definir Valores da Matriz NORMAL como -1 (NULO)
    for(a=0;a<=tamx;a++)
    for(b=0;b<=tamy;b++)
    icon[a][b]=-1; // Como o valor 0 representa um espaço vazio, sem valor, utilizamos o -1 para representar uma casa fechada ainda.
    
    minasreg=gera_bomba(); // Aqui é chamada a função que gera as minas no tabuleiro. A variável minasreg recebe quantas bombas forão inseridas com sucesso.
      
      do { // Do faz com que a matriz seja redesenhada todas as vezes que o usuário entrar com uma tecla de ação, a menos que o jogo seja finalizado.
          //loser=0; // Define a variável que indica que o usuário perdeu como 0.
          definir_cor(240);
          limpar();
          printf("\n        ");
          printf("%c",201);
          // Criação do "Placar" Que exibe algumas informações para o usuário durante o jogo.
          for(a=0;a<29;a++) printf("%c",205);
          printf("%c",187);
          printf("\n        %c  ",186);
          definir_cor(249);
          printf("Bandeiras Disponiveis: %d ",minasreg-bandcount,186); // Informa para o usuário quantas bandeiras ainda pode inserir.
          definir_cor(240);;
          if(minasreg-bandcount <= 9) printf("  %c\n        %c  ",186,186);
          else printf(" %c\n        %c  ",186,186);
          definir_cor(249);         
          printf("Bombas em Jogo: %d        ",minasreg,186); // Infoirma ao usuário quantas bombas estão em jogo.
          definir_cor(240);
          if(minasreg <= 9) printf("  %c\n        %c  ",186,186);
          else printf(" %c\n        %c  ",186,186);
          definir_cor(249);         
          if(casasclose <= 9) printf("Casas sem Bomba: %d        ",casasclose); // Informa para o usuário quantas casas ainda faltam abrir.
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
      if (a > 0) ordema++; // Valor Inicial é 64 Gera os "numeros" de ordem que se tornaram letras, para as laterais do tabuleiro.
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
                 // Verifica se o Quadrado está aberto, para mudar a sua "cor de fundo"
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
                              
                if(icon[a][b] == 383) { // Insere o Caractere Indicando a Bandeira no Código.
                               
                               definir_cor(138);
                               printf("%c",383);
                               definir_cor(135);
                               ctrl+=2;
                              } 
                              
                 if(icon[a][b] >= 0 && icon[a][b] <= 8) { // Insere o Numero de Referência a Quadrados abertos ou espaço vazio no código.
                               
                               definir_cor(127);
                               if(icon[a][b] > 0) printf("%d",icon[a][b]); // Caso a casa não seja vazia, insere o numero de referência.
                               else
                               printf(" ");
                               definir_cor(135);
                               ctrl+=2;
                              } 
                 
                 if(icon[a][b] == 9 || loser == 1) { // Caso o usuário abra uma bomba, é exibido um X vermelho para ele.
                               if((loser == 1 && mines[a][b]==1) || icon[a][b] == 9) {
                               definir_cor(124);
                               printf("X",icon[a][b]);
                               definir_cor(135);
                               ctrl+=2;
                               //loser+=1; // E o mesmo irá para a tela que o informa sua derrota.
                              } }
                                                 
                 if(icon[a][b] >= 0 && icon[a][b] <= 9) definir_cor(119);
                 else definir_cor(135);    
                 if(icon[a][b] == -1 || a != px || b != py) printf("_"); // Caso a seta de navegação não esteja no campo em questão, o terceiro caractere é um _   
                 definir_cor(135);             
                 //printf("%d %d",px,py);
                 if(a == px && b == py) // Caso a seta de navegação ESTEJA no campo em questão, o terceiro caractere é uma Seta.   
                      {
                      if(icon[a][b] >= 0 && icon[a][b] <= 9) definir_cor(127);
                      else definir_cor(143);
                               printf("%c",539);
                               definir_cor(135);
                               ctrl+=1;
                               }
                               
            if(ctrl == 0) printf("_"); // Caso não haja nada aberto no campo em questão, o 3º _ é inserido indicando casa vazia ou branca.
            printf("|");
            }
            }
      printf("\n"); // Pula para a Proxima linha do Tabuleiro.
      }
    ordema=64; // Código inicial para a letra a na tabela ascii.
    ordemb=64; // Código inicial para a letra a na tabela ascii.      
    definir_cor(240);
    printf("\n     # Informe a Linha e em Seguida a Coluna ou Pressione uma Tecla de A%c%co: ",135,198);
    tecla=esperar_tecla(); // é Aguardado o precionamento de uma tecla pelo usuário.
    
    a=0;
    b=0;
    acertos=0;
    do {
    for(a=0;a<=tamx;a++) // 2 FORs para varrerem a matriz buscando quantas bombas o usuário acertou, utilizando a bandeira.
    for(b=0;b<=tamx;b++)
    if(mines[a][b] == 1 && icon[a][b]==383) acertos++; // A Variável acertos é incrementada sempre que acontecer.   
    } while (acertos < bandcount && (a < tamx && b < tamy));
    } while(tecla != 0); // Redesenha o tabuleiro se a tecla '0' ou uma ação não acontecer.
    }
    }
    
