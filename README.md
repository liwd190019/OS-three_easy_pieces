# My Notes and work of *Operating System: Three easy pieces*

## Chapter 4
**Process**: The abstraction provided by the OS of a running program.

Process API:
what must be included in any interface of an operating system: create, destroy, wait, iscellaneous control, and status.

## Chapter 5
[fcfs_test.c]

FCFS Algorithm:  
First come first serve  
The average waiting time under an FCFS policy is generally not minimal and may vary substantially if the process's CPU burst time vary greatly  
FCFS scheduling algorithm is not nonpreemepive

*burst time*: also referred to as "execution time", is the amound of CPU time the process requires to complete its execution.

*preemptive*: a process can be placed back in the ready queue if that process still has CPU burst time remaining.

*non-preemptive:* once the resources (CPU cycles) are allocated to a process, the process holds the CPU till it gets terminated or reaches a waiting state.

*turnaround time*: The amount of time taken to complete a process or fulfill a request.

## 5_chapter

**user mode**: 

**kernel mode**: