#include <stdio.h>

typedef struct Process {
    int processID;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void FCFS(Process processes[], int numProcesses) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 1; i < numProcesses; i++) {
        processes[i].waitingTime = processes[i - 1].burstTime + processes[i - 1].waitingTime;
    }

    

    for (int i = 0; i < numProcesses; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
        processes[0].turnaroundTime = 2;
        
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }


    float averageWaitingTime = (float) totalWaitingTime / numProcesses;
    float averageTurnaroundTime = (float) totalTurnaroundTime / numProcesses;

    printf("Process\tDuration\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main() {
    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    Process processes[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        printf("Enter duration for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].processID = i + 1;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    FCFS(processes, numProcesses);

    return 0;
}
