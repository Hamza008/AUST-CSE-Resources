#include <stdio.h>

int main(void) {
	int i, j, min, temp, t, n;
	int num[100];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		num[i]=rand()%100;
	}
	
	for(i=0; i<n; i++){
		min=num[i];
		t=i;
		for(j=i; j<n; j++){
			if(num[j]<min){
				min=num[j];
				t=j;
			}
		}
		temp=num[i];
		num[i]=num[t];
		num[t]=temp;
	}
	
	for(i=0; i<n; i++){
		printf("%d, ", num[i]);
	}
	return 0;
}
