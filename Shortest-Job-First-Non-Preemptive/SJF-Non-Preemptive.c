#include <stdio.h>

// Define maximum number of processes
#define MAX 10

int main() {
    int n, i, j;
    int at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX], completed[MAX];
    int time = 0, total_tat = 0, total_wt = 0;

    // Input the number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        printf("\nArrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        completed[i] = 0;  // Initially, no process is completed
    }

    // Process scheduling loop
    int completed_count = 0;
    while (completed_count < n) {
        int idx = -1;
        int min_bt = 9999;

        // Find the shortest job that has arrived and is not completed
        for (i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx != -1) {
            // Process found
            time += bt[idx];             // Update current time
            ct[idx] = time;              // Completion time
            tat[idx] = ct[idx] - at[idx]; // Turnaround time
            wt[idx] = tat[idx] - bt[idx]; // Waiting time
            completed[idx] = 1;          // Mark process as completed
            completed_count++;

            total_tat += tat[idx];
            total_wt += wt[idx];
        } else {
            // If no process is ready to execute, increment time
            time++;
        }
    }

    // Output the results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Print average turnaround and waiting time
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);

    return 0;
}
