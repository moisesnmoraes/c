  #include <stdio.h>
  
  
  void main(){
 
  
   int matrizA[10][10]; 
   int temp;
    int i,j;
    int k;
    int l;
    //preenchendo a matriz
    for(k=0;k<10;k++){
   
        for(l=0;l<10;l++){
            matrizA[k][l] = k+l;
        }
    }  
  
    for(i=0;i<10;i++){
   
        temp = matrizA[1][i];
        matrizA[1][i] = matrizA[7][i];
        matrizA[7][i] = temp;
    }

    for(j=0;j<10;j++){
    
        temp = matrizA[j][3];
        matrizA[j][3] = matrizA[j][9];
        matrizA[j][9] = temp;
    }

    //imprimindo
    for( k=0;k<10;k++){
  
        for( l=0;l<10;l++){
        
            printf("%d ", matrizA[k][l]);
        }
        printf("\n");
    }
  }
