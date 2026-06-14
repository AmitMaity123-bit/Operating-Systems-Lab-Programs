#include <stdio.h>  // Standard input-output library

void main() {
    int n, i, j; // Variables for number of processes and loop counters

    // Ask the user for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare arrays to store process details
    int process[n], arrival[n], burst[n], completion[n], turnaround[n], waiting[n];

    // Input: Getting arrival time and burst time for each process
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:- \n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("Burst Time: ");
        scanf("%d",&burst[i]);
        //scanf("%d %d", &arrival[i], &burst[i]); // Read Arrival Time and Burst Time
        process[i] = i + 1; // Assign process ID (1, 2, 3, ...)
    }

    // Step 1: Sort processes by Arrival Time (if needed)
    // FCFS executes processes in the order they arrive, so sorting ensures correctness
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrival[i] > arrival[j]) {  // Compare Arrival Time
                // Swap Arrival Time
                int temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;

                // Swap Burst Time
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                // Swap Process ID
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Step 2: Compute Completion Time (CT)
    // The first process starts at its arrival time and finishes after its burst time
    completion[0] = arrival[0] + burst[0];

    // Calculate Completion Time for remaining processes
    for (i = 1; i < n; i++) {
        if (completion[i - 1] < arrival[i]) {
            // If CPU was idle before this process arrived
            completion[i] = arrival[i] + burst[i];
        } else {
            // Process starts execution immediately after the previous one completes
            completion[i] = completion[i - 1] + burst[i];
        }
    }

    // Step 3: Compute Turnaround Time (TAT) and Waiting Time (WT)
    for (i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i]; // TAT = CT - AT
        waiting[i] = turnaround[i] - burst[i]; // WT = TAT - BT
    }

    // Step 4: Display the results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               process[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }
}
