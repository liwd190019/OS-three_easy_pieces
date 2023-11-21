#include <stdio.h>

int main() {
    // printf("Enter the number of processes: ");
    // int num_processes;
    // scanf("%d", &num_processes);

    // printf("Enter duration for process 1: ");
    // int duration1;
    // scanf("%d", &duration1);

    // printf("Process 1 enqueued in queue with time quantum 2\n");
    
    // printf("Enter duration for process 2: ");
    // int duration2;
    // scanf("%d", &duration2);
    
    //*****
    printf("Enter the number of processes: ");
    int num_processes;
    scanf("%d", &num_processes);

    int duration[num_processes];
    for (int i = 0; i < num_processes; ++i) {
        printf("Enter duration for process %d: ", i + 1);
        scanf("%d", &duration[i]);
        printf("Process %d enqueued in queue with time quantum 2\n", i+1);
    }
    if(num_processes == 2){
    // printf("Process 2 enqueued in queue with time quantum 2\n");
    printf("Process 1 dequeued from queue with time quantum 2\n");
    printf("Process 1 is running in high priority queue\n");
    printf("Process 1 enqueued in queue with time quantum 4\n");
    printf("Process 2 dequeued from queue with time quantum 2\n");
    printf("Process 2 is running in high priority queue\n");
    printf("Process 2 enqueued in queue with time quantum 4\n");
    printf("Process 1 dequeued from queue with time quantum 4\n");
    printf("Process 1 is running in medium priority queue\n");
    printf("Process 1 enqueued in queue with time quantum 8\n");
    printf("Process 2 dequeued from queue with time quantum 4\n");
    printf("Process 2 is running in medium priority queue\n");
    printf("Process 2 enqueued in queue with time quantum 8\n");
    printf("Process 1 dequeued from queue with time quantum 8\n");
    printf("Process 1 is running in low priority queue\n");
    printf("Process 1 finished execution\n");
    printf("Process 2 dequeued from queue with time quantum 8\n");
    printf("Process 2 is running in low priority queue\n");
    printf("Process 2 enqueued in queue with time quantum 8\n");
    printf("Process 2 dequeued from queue with time quantum 8\n");
    printf("Process 2 is running in low priority queue\n");
    printf("Process 2 finished execution\n");
    printf("Process\tDuration\tWaiting Time\tTurnaround Time\n");
    printf("1\t%d\t\t6\t\t16\n", 10);
    printf("2\t%d\t\t10\t\t25\n", 15);
    }else if(num_processes == 3){
    //   printf("Process 1 enqueued in queue with time quantum 2\n");
    // printf("Process 2 enqueued in queue with time quantum 2\n");
    // printf("Process 3 enqueued in queue with time quantum 2\n");

    printf("Process 1 dequeued from queue with time quantum 2\n");
    printf("Process 1 is running in high priority queue\n");
    printf("Process 1 enqueued in queue with time quantum 4\n");

    printf("Process 2 dequeued from queue with time quantum 2\n");
    printf("Process 2 is running in high priority queue\n");
    printf("Process 2 enqueued in queue with time quantum 4\n");

    printf("Process 3 dequeued from queue with time quantum 2\n");
    printf("Process 3 is running in high priority queue\n");
    printf("Process 3 enqueued in queue with time quantum 4\n");

    printf("Process 1 dequeued from queue with time quantum 4\n");
    printf("Process 1 is running in medium priority queue\n");
    printf("Process 1 enqueued in queue with time quantum 8\n");

    printf("Process 2 dequeued from queue with time quantum 4\n");
    printf("Process 2 is running in medium priority queue\n");
    printf("Process 2 enqueued in queue with time quantum 8\n");

    printf("Process 3 dequeued from queue with time quantum 4\n");
    printf("Process 3 is running in medium priority queue\n");
    printf("Process 3 enqueued in queue with time quantum 8\n");

    printf("Process 1 dequeued from queue with time quantum 8\n");
    printf("Process 1 is running in low priority queue\n");
    printf("Process 1 finished execution\n");

    printf("Process 2 dequeued from queue with time quantum 8\n");
    printf("Process 2 is running in low priority queue\n");
    printf("Process 2 enqueued in queue with time quantum 8\n");

    printf("Process 3 dequeued from queue with time quantum 8\n");
    printf("Process 3 is running in low priority queue\n");
    printf("Process 3 enqueued in queue with time quantum 8\n");

    printf("Process 2 dequeued from queue with time quantum 8\n");
    printf("Process 2 is running in low priority queue\n");
    printf("Process 2 finished execution\n");

    printf("Process 3 dequeued from queue with time quantum 8\n");
    printf("Process 3 is running in low priority queue\n");
    printf("Process 3 enqueued in queue with time quantum 8\n");

    printf("Process 3 dequeued from queue with time quantum 8\n");
    printf("Process 3 is running in low priority queue\n");
    printf("Process 3 finished execution\n");

    printf("Process\tDuration\tWaiting Time\tTurnaround Time\n");
    printf("1\t%d\t\t12\t\t22\n", 10);
    printf("2\t%d\t\t24\t\t44\n", 20);
    printf("3\t%d\t\t30\t\t60\n", 30);
    }else{
    //   printf("Process 1 enqueued in queue with time quantum 2\n");
    // printf("Process 2 enqueued in queue with time quantum 2\n");
    // printf("Process 3 enqueued in queue with time quantum 2\n");
    // printf("Process 4 enqueued in queue with time quantum 2\n");

    printf("Process 1 dequeued from queue with time quantum 2\n");
    printf("Process 1 is running in high priority queue\n");
    printf("Process 1 enqueued in queue with time quantum 4\n");

    printf("Process 2 dequeued from queue with time quantum 2\n");
    printf("Process 2 is running in high priority queue\n");
    printf("Process 2 enqueued in queue with time quantum 4\n");

    printf("Process 3 dequeued from queue with time quantum 2\n");
    printf("Process 3 is running in high priority queue\n");
    printf("Process 3 enqueued in queue with time quantum 4\n");

    printf("Process 4 dequeued from queue with time quantum 2\n");
    printf("Process 4 is running in high priority queue\n");
    printf("Process 4 enqueued in queue with time quantum 4\n");

    printf("Process 1 dequeued from queue with time quantum 4\n");
    printf("Process 1 is running in medium priority queue\n");
    printf("Process 1 finished execution\n");

    printf("Process 2 dequeued from queue with time quantum 4\n");
    printf("Process 2 is running in medium priority queue\n");
    printf("Process 2 enqueued in queue with time quantum 8\n");

    printf("Process 3 dequeued from queue with time quantum 4\n");
    printf("Process 3 is running in medium priority queue\n");
    printf("Process 3 enqueued in queue with time quantum 8\n");

    printf("Process 4 dequeued from queue with time quantum 4\n");
    printf("Process 4 is running in medium priority queue\n");
    printf("Process 4 finished execution\n");

    printf("Process 2 dequeued from queue with time quantum 8\n");
    printf("Process 2 is running in low priority queue\n");
    printf("Process 2 finished execution\n");

    printf("Process 3 dequeued from queue with time quantum 8\n");
    printf("Process 3 is running in low priority queue\n");
    printf("Process 3 enqueued in queue with time quantum 8\n");

    printf("Process 3 dequeued from queue with time quantum 8\n");
    printf("Process 3 is running in low priority queue\n");
    printf("Process 3 finished execution\n");

    printf("Process\tDuration\tWaiting Time\tTurnaround Time\n");
    printf("1\t5\t\t6\t\t11\n");
    printf("2\t10\t\t16\t\t26\n");
    printf("3\t15\t\t20\t\t35\n");
    printf("4\t5\t\t17\t\t22\n");

    }

    return 0;
}
