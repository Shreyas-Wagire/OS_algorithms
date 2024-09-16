#include<stdio.h>

int main(){
	int pid[10],at[10],bt[10];
	int n;
	
	
	printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    //for id
    printf("Enter the Process IDs of all Processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process ID: ");
        scanf("%d", &pid[i]);
    }
    
    
    // for arrive time
    printf("Enter the Arrive Time of all Processes:\n");
    for (int i = 0; i < n; i++){
    	printf("Arrive Time: ");
    	scanf("%d", &at[i]);
	}
	
	
	// for brust time
	printf("Enter the Brust Time of all Processes:\n");
	for(int i = 0; i < n; i++){
		printf("Brust Time: ");
		scanf("%d", &bt[i]);
	}
	
	int ct[n],tat[n],wt[n];
	ct[0] = bt[0];
	
	// for completion time
	for (int i = 0; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }
	
	// for turnAround time
	for (int i = 0; i < n; i++) {
		tat[i] = ct[i] - at[i];
	}
	
	// for waiting time 1
	for (int i = 0; i < n; i++) {
		wt[i] = tat[i] - bt[i];
	}
	
	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("  %d\t %d\t %d\t %d\t %d\t %d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
	
}
