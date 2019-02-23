#include <stdio.h>

void main(){
	int k[3][3];
	int mbeta[3][3];
	int x;
	int l;
	int p;
	for(x=0;x<=2;x++){
		printf("Informe os elementos para coluna 0 \n");
		scanf("%d", &mbeta[x][0]);
	}
	
	for(x=0;x<=2;x++){
		printf("Informe os elementos para coluna 1 \n");
		scanf("%d", &mbeta[x][1]);
	}
	
		for(x=2;x>=0;x--){
			printf("primeira coluna %d\n",mbeta[x][0]);
			mbeta[x][0]++;
		}
		
		for(x=2;x>=0;x--){
			printf("segunda coluna %d\n",mbeta[x][1]);
			mbeta[x][1]++;
			
			}
			mbeta[x][0]=l;
			mbeta[0][x]=p;
		
		/*	mbeta[x][1] = mbeta[x][0];
			mbeta[x][0]++;
			mbeta[x][0] = mbeta[x][1];
			mbeta[x][1]++;*/
			for(x=0;x<=2;x++){
			
			
		
			
			
			//mbeta[x][1]=p[x];
		//	p[x]++;
			printf("primeira coluna sendo a segunda %d %d\n",l,p);
			
			//printf("segunda  coluna sendo a primeira %d \n",p[x]);
		
		
			
		}
}
