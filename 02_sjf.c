#include <stdio.h>

int main() {
    int pid[10], at[10], bt[10];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process IDs
    for (int i = 0; i < n; i++) {
        printf("Process ID: ");
        scanf("%d", &pid[i]);
    }

    // Input arrival times
    for (int i = 0; i < n; i++) {
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
    }

    // Input burst times
    for (int i = 0; i < n; i++) {
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    int ct[10], tat[10], wt[10];
    int completed[10] = {0}; // Track completed processes
    int current_time = 0;
    int completed_count = 0;

    while (completed_count < n) {
        int idx = -1;
        int min_bt = 10000; // A large number for comparison

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && !completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        // If no process is found, move time forward
        if (idx == -1) {
            current_time++;
            continue;
        }

        // Update current time and completion time for the selected process
        current_time += bt[idx];
        ct[idx] = current_time;
        completed[idx] = 1;
        completed_count++;
    }

    // Calculate turnaround and waiting times
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Calculate average waiting time and turnaround time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;

    // Print the results
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}

