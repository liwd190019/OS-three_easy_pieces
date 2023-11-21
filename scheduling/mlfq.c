#include <stdio.h>

#define MAX_PROCESSES 100
#define MAX_QUEUES 3

struct Process {
    int pid;
    int duration;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

struct Queue {
    struct Process processes[MAX_PROCESSES];
    int front, rear;
    int time_quantum;
};

void enqueue(struct Queue *queue, struct Process process) {
    if (queue->rear == MAX_PROCESSES - 1) {
        printf("Queue is full. Process %d cannot be enqueued.\n", process.pid);
        return;
    }

    queue->rear++;
    queue->processes[queue->rear] = process;
}

struct Process dequeue(struct Queue *queue) {
    struct Process process = {0};

    if (queue->front <= queue->rear) {
        process = queue->processes[queue->front];
        queue->front++;
    }

    return process;
}

void initialize_queues(struct Queue queues[], int num_queues) {
    int time_quantum = 2; // Initial time quantum for high-priority queue

    for (int i = 0; i < num_queues; ++i) {
        queues[i].front = 0;
        queues[i].rear = -1;
        queues[i].time_quantum = time_quantum;
        time_quantum *= 2; // Double the time quantum for each lower-priority queue
    }
}

void display_process_state(struct Process process, const char *state) {
    printf("Process %d is %s. Remaining time: %d\n", process.pid, state, process.remaining_time);
}

void mlfq_scheduler(struct Process processes[], int num_processes, struct Queue queues[], int num_queues) {
    int current_time = 0;

    while (1) {
        int flag = 1;

        for (int i = 0; i < num_processes; ++i) {
            if (processes[i].remaining_time > 0) {
                flag = 0;

                if (processes[i].remaining_time > queues[0].time_quantum) {
                    display_process_state(processes[i], "running in high-priority queue");
                    processes[i].remaining_time -= queues[0].time_quantum;

                    // Move to the next queue
                    display_process_state(processes[i], "moved to medium-priority queue");
                    enqueue(&queues[1], processes[i]);
                } else {
                    display_process_state(processes[i], "running in high-priority queue");
                    processes[i].remaining_time = 0;

                    // Process finished execution
                    display_process_state(processes[i], "finished execution");
                    processes[i].turnaround_time = current_time + processes[i].waiting_time;
                }
            }
        }

        if (flag)
            break;

        // Rotate queues
        struct Process process = dequeue(&queues[0]);
        if (process.pid != 0) {
            enqueue(&queues[0], process);
            display_process_state(process, "moved to the end of high-priority queue");
        }

        for (int j = 1; j < num_queues; ++j) {
            while (queues[j].front <= queues[j].rear) {
                struct Process p = dequeue(&queues[j]);
                enqueue(&queues[j - 1], p);
                display_process_state(p, "moved to a higher-priority queue");
            }
        }

        current_time++;
    }
}

void calculate_averages(struct Process processes[], int num_processes) {
    double total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < num_processes; ++i) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    double avg_waiting_time = total_waiting_time / num_processes;
    double avg_turnaround_time = total_turnaround_time / num_processes;

    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
}

int main() {
    int num_processes;
    struct Process processes[MAX_PROCESSES];
    struct Queue queues[MAX_QUEUES];

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; ++i) {
        processes[i].pid = i + 1;
        printf("Enter the duration for Process %d: ", processes[i].pid);
        scanf("%d", &processes[i].duration);
        processes[i].remaining_time = processes[i].duration;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;

        // Enqueue processes to the high-priority queue initially
        enqueue(&queues[0], processes[i]);
    }

    initialize_queues(queues, MAX_QUEUES);

    printf("\nMLFQ Scheduler Output:\n");
    mlfq_scheduler(processes, num_processes, queues, MAX_QUEUES);

    printf("\nProcess Duration Waiting Time Turnaround Time\n");
    for (int i = 0; i < num_processes; ++i) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].duration, processes[i].waiting_time, processes[i].turnaround_time);
    }

    calculate_averages(processes, num_processes);

    return 0;
}
