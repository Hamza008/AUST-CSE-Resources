#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

void merge(int A[],int p, int q, int r){
    int n1 =(q-p+1), n2 =(r-q), i, j, k;
    int L[n1+1],R[n2+1];
    
    for(i=0; i<n1; i++) L[i]=A[p+i];
    
    for(j=0; j<n2; j++) R[j]=A[q+j+1];
    
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;

    i=0;
    j=0;

    for(k=p; k<=r; k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
}
void mergeSort(int A[],int p, int r){
    int q;
    if (p<r){
        q = floor ((p+r)/2);
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}
int main(){
    int A[100];
    int i;
    int n;

	scanf("%d", &n);


	for(i=0; i<n; i++){
		A[i]=rand()%1000;
	}
	
    mergeSort(A,0,n-1);
    
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}