#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n], rt[n];
    int ct[n], tat[n], wt[n], done[n];

    // Input process data
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time, Burst Time, and Priority for Process P%d: ", pid[i]);
        printf("\nArrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        rt[i] = bt[i]; // Remaining time
        done[i] = 0;
    }

    int time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int highestPriority = 9999;

        // Find the process with highest priority at current time
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (pr[i] < highestPriority || (pr[i] == highestPriority && at[i] < at[idx])) {
                    highestPriority = pr[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            rt[idx]--;
            time++;

            if (rt[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                done[idx] = 1;
                completed++;
            }
        } else {
            time++; // CPU is idle
        }
    }

    // Output results
    float totalWT = 0, totalTAT = 0;
    printf("\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
