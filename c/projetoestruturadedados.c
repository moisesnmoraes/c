#include <stdio.h>

void main(){
	
	int a[5][5];
	// Declarei a matriz
	a[0][0] = 10;
	a[2][3] = 33;
	a[4][0] = a[0][0] * a[2][3];
	
	
	printf("%d",a[4][0]);
	
	
}

