#include <stdio.h>

int main() {
    int n, i, time = 0, tq, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], wt[n], tat[n], ct[n];

    // Input arrival and burst times
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time and burst time for process P%d: \n", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  // Remaining time initialized to burst time
        wt[i] = 0;
        tat[i] = 0;
        ct[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int allDone = 0;
    while (completed < n) {
        allDone = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                allDone = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    completed++;
                }
            }
        }
        if (allDone) {
            time++;
        }
    }

    // Output the results
    float totalWT = 0, totalTAT = 0;
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
