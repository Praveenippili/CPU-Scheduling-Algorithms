#include<stdio.h>

int main()
{
	int i,n,bt[10],at[10],wt[10],tat[10],ct[i];
	int sum;
	float totalTAT=0,totalWT=0;
	float avgwt=0,avgtat=0;
	
	printf("Enter the number of processes :");
	scanf("%d",&n);
	
	printf("Enter the burst time for each process :\n");
	for(i=0;i<n;i++){
		printf("Burst time for P%d :",i+1);
		scanf("%d",&bt[i]);
	}
	
	printf("Enter the arrival time for each process :\n");
	for(i=0;i<n;i++){
		printf("Arrival time for P%d :",i+1);
		scanf("%d",&at[i]);
    }
    printf("\n");
    
    //Completion time for processes
    sum = at[0];
    for(i=0;i<n;i++)
    {
    	sum=sum+bt[i];
    	ct[i]=sum;
	}
	
	//TAT for processes
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		totalTAT=totalTAT+tat[i];
	}
	
		
	//WT for processes
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		totalWT=totalWT+wt[i];
	}
	
	printf("Process \tArrival time \tBurst time \tCompletion time \tTurnaround time \tWaiting time \t \n\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\t\t\t\t\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\n");
	avgtat=totalTAT/n;
	avgwt=totalWT/n;
	
	printf("Average TAT :%f",avgtat);
	printf("\n");
	printf("Average WT :%f",avgwt);
	
	return 0;
	
}
