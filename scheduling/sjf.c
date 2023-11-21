// #include <stdio.h>

// struct Process {
//     int pid;
//     int duration;
//     int waiting_time;
//     int turnaround_time;
// };

// void swap(struct Process *a, struct Process *b) {
//     struct Process temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void sort_by_duration(struct Process processes[], int num_processes) {
//     for (int i = 0; i < num_processes - 1; ++i) {
//         for (int j = 0; j < num_processes - i - 1; ++j) {
//             if (processes[j].duration > processes[j + 1].duration) {
//                 swap(&processes[j], &processes[j + 1]);
//             }
//         }
//     }
// }

// void calculate_waiting_turnaround_times(struct Process processes[], int num_processes) {
//     processes[0].waiting_time = 0;
//     processes[0].turnaround_time = processes[0].duration;

//     for (int i = 1; i < num_processes; ++i) {
//         processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].duration;
//         processes[i].turnaround_time = processes[i].waiting_time + processes[i].duration;
//     }
// }

// void display_results(struct Process processes[], int num_processes, double avg_waiting_time, double avg_turnaround_time) {
//     printf("Process	Execution Time	Waiting Time	Turnaround Time\n");
//     for (int i = 0; i < num_processes; ++i) {
//         printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].duration, processes[i].waiting_time, processes[i].turnaround_time);
//     }

//     printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
//     printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
// }

// int main() {
//     int num_processes;

//     printf("Enter the number of processes: ");
//     scanf("%d", &num_processes);

//     struct Process processes[num_processes];

//     for (int i = 0; i < num_processes; ++i) {
//         processes[i].pid = i + 1;
//         printf("Enter execution time for process %d: ", processes[i].pid);
//         scanf("%d", &processes[i].duration);
//     }

//     sort_by_duration(processes, num_processes);
//     calculate_waiting_turnaround_times(processes, num_processes);

//     double total_waiting_time = 0, total_turnaround_time = 0;
//     for (int i = 0; i < num_processes; ++i) {
//         total_waiting_time += processes[i].waiting_time;
//         total_turnaround_time += processes[i].turnaround_time;
//     }

//     double avg_waiting_time = total_waiting_time / num_processes;
//     double avg_turnaround_time = total_turnaround_time / num_processes;

//     display_results(processes, num_processes, avg_waiting_time, avg_turnaround_time);

//     return 0;
// }
#include <stdio.h>

int main() {
    int n; // number of processes
    int execution_time[100], waiting_time[100], turnaround_time[100], process_id[100];
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Gather input from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter execution time for process %d: ", i+1);
        scanf("%d", &execution_time[i]);
        process_id[i] = i+1;
    }

    // Bubble sort to arrange processes based on their execution time
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(execution_time[j] > execution_time[j+1]) {
                // Swap execution times
                int temp = execution_time[j];
                execution_time[j] = execution_time[j+1];
                execution_time[j+1] = temp;

                // Swap process IDs to keep them in sync with execution times
                int temp_id = process_id[j];
                process_id[j] = process_id[j+1];
                process_id[j+1] = temp_id;
            }
        }
    }

    // Calculate waiting and turnaround times
    waiting_time[0] = 0;
    turnaround_time[0] = execution_time[0];
    for(int i = 1; i < n; i++) {
        waiting_time[i] = execution_time[i-1] + waiting_time[i-1];
        turnaround_time[i] = execution_time[i] + waiting_time[i];
    }

    // Calculate total waiting and turnaround times
    for(int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Display the results
    printf("Process\tExecution Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", process_id[i], execution_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time/n);

    return 0;
}