#include <stdio.h>
#include <limits.h>
#include <stdbool.h> //boolean type bool and the values true and false

// Maximum number of processes
#define MAX 10

int main() {
    int n; // Number of processes
    int arrival_time[MAX], burst_time[MAX], remaining_time[MAX];
    int completion_time[MAX], turnaround_time[MAX], waiting_time[MAX];
    bool is_done[MAX] = {false};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process P%d: \n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i]; // Initially, remaining time is equal to burst time
    }

    int complete = 0, current_time = 0;

    // Loop until all processes are completed
    while (complete != n) {
        int shortest = -1;
        int min_remaining = INT_MAX;

        // Find the process with the shortest remaining time among the arrived processes
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && !is_done[i] && remaining_time[i] < min_remaining && remaining_time[i] > 0) {
                min_remaining = remaining_time[i];
                shortest = i;
            }
        }

        // If no process is available at the current time
        if (shortest == -1) {
            current_time++;
            continue;
        }

        // Execute the selected process for 1 unit of time
        remaining_time[shortest]--;
        current_time++;

        // If the process is finished
        if (remaining_time[shortest] == 0) {
            completion_time[shortest] = current_time;
            is_done[shortest] = true;
            complete++;
        }
    }

    // Calculate turnaround time and waiting time for each process
    float total_tat = 0, total_wt = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        total_tat += turnaround_time[i];
        total_wt += waiting_time[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    // Print average turnaround time and waiting time
    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
