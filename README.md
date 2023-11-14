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
Limited direct execution: just run the program directly on the CPU. When the OS wishes to start a program running, it creates a process entry for it in a process list, allocates some memory for it, loads the program code into memory (from disk).

But this approach gives rise to a few problems: 1. How can system run efficiently when program exception occurs; 2. How can system stop a process from running and switch to another, then go back to run the process?
1. The first problem: how os deals with program exceptions?
- introduce a new process mode
**user mode**: code that runs in user mode is restricted in what it can do.

**kernel mode**: the operating system (or kernel) runs in.
- what should a user program do when it wishes to perform some kind of privileged operation?
Perform system call: system calls allow the kernel to carefully expose certain key pieces of functionality to user programs.

**How to execute a system call?** a program must execute a special *trap* instruction. This instruction simultaneously jumps into the kernel and raises the privilege level to kernel mode; once in kernel, hte system can now perform whatever privileged operations are needed(if allowed), and thus do the required work for the calling process. When finished, the OS calls a special *return-from-trap* instruction, which, as you might expect, returns into the calling suer program while simultaneously reducing the privilege level back to user mode.

(tips) when executing a trap, the ahrdware needs to be a bit careful. more detail on intel systems manuals. see book page 52.

There is one important thing left behind:
**How does the trap know which code to run inside the OS?** the calling process can't specify an address to jump to; doing so would allow programs to jump anywhere inside a kernel. So the kernel must carefully know what codes executes upon a trap. (know trap refers to what code)

The kernel does so by setting up a trap table at boot time. （电脑启动时间）. thus is free to configure machine hardware as need be. When the machine boots up, it does so in privileged (kernel) mode,, and thus is free to configure machien hardware as need be. Once the hardware is informed, it remembers the location of these handlers until the machine is next rebooted, and thus the hardware knows what to do (like keyboard interruption occurs, the hardware knows what code to jump to, *trap handler*) when system calls and other exceptional events take place.

*system-call numebr:* specify the exact system call. assigned to each system call. The user code is thus responsible for placing the desired system-call numebr in a register or at a specified location on the stack; the OS examines these numbers and ensures it's valid. *protection*: user code cannot specify an exact address to jump to, but rather must request a particular service via number.

We assume each process has a kernel stack where registers (including general purpose registers and the program counter) are saved to and restored form when transitioning into and out of the kernel.

**Switch between processes**
- how can OS regain control of teh CPU so that it can switch between processes.
Two approaches:
1. cooperative approach: wait for system calls
the OS trusts the processes of teh system to behave reasonably. processes that run for too long are assumed to periodically give up the CPU so that the OS can decide to run some other task. Most processes transfer control of teh CPU to the OS quite frequently by making system calls(to open a file and subsequently read it). system like this oftern include an explicit yield system call.
- A Non-Cooperative Approach: The OS takes control


## Chapter 15
Hardware support for memory reallocation:
1. require two different CPU modes, OS->privileged mode, the applications run in user mode
2. The hardware must provide base and bounds registers themselves, each CPU thus has an additional pair of registers, patt of the memory management unit of the CPU.
3. the hardware should provide special instructions to modify the base and bounds registers, allowing OS to change them when different processes run.
4. the CPU must be able to handle exceptions
Operating System Issues:
1. the OS must take action when a process is created, finding space for its address space in memory
2. the OS must do some work when a process is terminated. puts the memory back on the freelist.
3. perform a few additional steps when a context switch occurs
4. provide exceptional handles
  

## chapter 17: free-space management
explore three questions:
- how should variable-size requests be maaged?
- how can we reduce fragmentation?
- what are hte time and space overheads of different approaches?


