#include <stdio.h>

int main(){

	int n,i,j,temp;

	int ct[100];
	int et[100];
	int wt[100];
	int tt[100];
	int sum =0;
	int sum1=0;
	float awt;
	float att;
	float cpuavg;
	int turnat;

	printf("enter the number of processes: ");
	scanf("%d",&n);


	printf("Enter the ct");
	for(i=0;i<n;i++){
		scanf("%d",&ct[i]);
	}


	//sorting according to cpu time
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n-1; j++)
		{
			if(ct[i]>ct[j])
			{
				temp=ct[i];
				ct[i]=ct[j];
				ct[j]=temp;
			}
		}
	}


	for(i=0;i<n;i++){

		sum=sum + ct[i];
	}
	//wait time

	 wt[0]=0;

	for(i=1;i<n;i++){
		wt[i]=wt[i-1] + ct[i-1];


	  // printf("\n%d  %d\n",i, wt[i]);
	 //  printf("%d  %d %d\n ",i, wt[i-1], ct[i-1]);



	}

	for(i=0;i<n;i++){

	 printf("wt %d = %d \n",i,wt[i]);

	}



	for(i=0;i<n;i++){
		sum1+=wt[i];
	}
	awt=(float)sum1/n;
	cpuavg= (float)sum/n ;
	att=(float)awt + cpuavg ;

	for(i=0;i<n;i++){
		tt[i]=wt[i]+ct[i];
		printf("tt %d = %d \n",i,tt[i]);
	}

	printf("average waiting time %f \n",awt );
	printf("average turn around time %f \n",att );


	return 0;

}
