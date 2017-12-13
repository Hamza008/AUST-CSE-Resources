#include <stdio.h>

int main(void) {
	int num[100];
	int i, j, temp, n;
	scanf("%d", &n);

	for(i=0; i<n; i++){
		num[i]=rand()%100;
	}

	for(i=1; i<n; i++){
      		temp=num[i];
		for(j=i; j>0; j--){
			if(num[j-1]>temp){
				num[j]=num[j-1];
			}else{
				break;
			}
		}
		num[j]=temp;
	}

	for(i=0; i<n; i++){
		printf("%d, ", num[i]);
	}
	return 0;
}

