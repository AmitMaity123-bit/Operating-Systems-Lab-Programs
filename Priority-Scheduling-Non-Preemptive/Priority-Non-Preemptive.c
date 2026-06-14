#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n], ct[n], wt[n], tat[n], done[n];
    int i, time = 0, completed = 0;

    // Input arrival time, burst time, and priority
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time, Burst Time, and Priority for Process P%d: \n", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        done[i] = 0;
    }

    while (completed < n) {
        int idx = -1;
        int highestPriority = 9999;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && done[i] == 0) {
                if (pr[i] < highestPriority || (pr[i] == highestPriority && at[i] < at[idx])) {
                    highestPriority = pr[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = 1;
            completed++;
        } else {
            time++; // CPU is idle
        }
    }

    // Display results
    float totalWT = 0, totalTAT = 0;
    printf("\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
