4. the cpu keeps process0 in block state, after finished, it goes to process 2.
Result:

| Time | PID: 0        | PID: 1        | CPU | IOs |
|------|---------------|---------------|-----|-----|
| 1    | RUN:io        | READY         | 1   |     |
| 2    | BLOCKED       | READY         |     | 1   |
| 3    | BLOCKED       | READY         |     | 1   |
| 4    | BLOCKED       | READY         |     | 1   |
| 5    | BLOCKED       | READY         |     | 1   |
| 6    | BLOCKED       | READY         |     | 1   |
| 7*   | RUN:io_done   | READY         | 1   |     |
| 8    | DONE          | RUN:cpu       | 1   |     |
| 9    | DONE          | RUN:cpu       | 1   |     |
| 10   | DONE          | RUN:cpu       | 1   |     |
| 11   | DONE          | RUN:cpu       | 1   |     |

5. When cpu can switch to another process whenever one is waiting for I/O:
when processor0 is blocked, cpu can switch to another processor

| Time | PID: 0     | PID: 1     | CPU | IOs |
|------|------------|------------|-----|-----|
| 1    | RUN:io     | READY      | 1   |     |
| 2    | BLOCKED    | RUN:cpu    | 1   | 1   |
| 3    | BLOCKED    | RUN:cpu    | 1   | 1   |
| 4    | BLOCKED    | RUN:cpu    | 1   | 1   |
| 5    | BLOCKED    | RUN:cpu    | 1   | 1   |
| 6    | BLOCKED    | DONE       |     | 1   |
| 7*   | RUN:io_done| DONE       | 1   |     |

6. with IO_RUN_LATER, when an I/O completes, the process that issued it is not necessarily run right away, rather, whatever was running at the time keeps running.

the system resources are not effectively utilized, since io will stop to wait process1,2,3

| Time | PID: 0     | PID: 1     | PID: 2     | PID: 3     | CPU | IOs |
|------|------------|------------|------------|------------|-----|-----|
| 1    | RUN:io     | READY      | READY      | READY      | 1   |     |
| 2    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 3    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 4    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 5    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 6    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 7*   | READY      | DONE       | RUN:cpu    | READY      | 1   |     |
| 8    | READY      | DONE       | RUN:cpu    | READY      | 1   |     |
| 9    | READY      | DONE       | RUN:cpu    | READY      | 1   |     |
| 10   | READY      | DONE       | RUN:cpu    | READY      | 1   |     |
| 11   | READY      | DONE       | RUN:cpu    | READY      | 1   |     |
| 12   | READY      | DONE       | DONE       | RUN:cpu    | 1   |     |
| 13   | READY      | DONE       | DONE       | RUN:cpu    | 1   |     |
| 14   | READY      | DONE       | DONE       | RUN:cpu    | 1   |     |
| 15   | READY      | DONE       | DONE       | RUN:cpu    | 1   |     |
| 16   | READY      | DONE       | DONE       | RUN:cpu    | 1   |     |
| 17   | RUN:io_done| DONE       | DONE       | DONE       | 1   |     |
| 18   | RUN:io     | DONE       | DONE       | DONE       | 1   |     |
| 19   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 20   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 21   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 22   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 23   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 24*  | RUN:io_done| DONE       | DONE       | DONE       | 1   |     |
| 25   | RUN:io     | DONE       | DONE       | DONE       | 1   |     |
| 26   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 27   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 28   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 29   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 30   | BLOCKED    | DONE       | DONE       | DONE       |     | 1   |
| 31*  | RUN:io_done| DONE       | DONE       | DONE       | 1   |     |


| Stats: Total Time | 31         |
| Stats: CPU Busy   | 21 (67.74%) |
| Stats: IO Busy    | 15 (48.39%) |

7. IO_RUN_IMMEDIATE
Running a process that just completed an I/O again is a good idea, because in this way, the cpu doesn't need to wait IO to complete, it can block process0(which is IO), then go to process other processors.

FInal Result:

| Time | PID: 0     | PID: 1     | PID: 2     | PID: 3     | CPU | IOs |
|------|------------|------------|------------|------------|-----|-----|
| 1    | RUN:io     | READY      | READY      | READY      | 1   |     |
| 2    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 3    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 4    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 5    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 6    | BLOCKED    | RUN:cpu    | READY      | READY      | 1   | 1   |
| 7*   | RUN:io_done| DONE       | READY      | READY      | 1   |     |
| 8    | RUN:io     | DONE       | READY      | READY      | 1   |     |
| 9    | BLOCKED    | DONE       | RUN:cpu    | READY      | 1   | 1   |
| 10   | BLOCKED    | DONE       | RUN:cpu    | READY      | 1   | 1   |
| 11   | BLOCKED    | DONE       | RUN:cpu    | READY      | 1   | 1   |
| 12   | BLOCKED    | DONE       | RUN:cpu    | READY      | 1   | 1   |
| 13   | BLOCKED    | DONE       | RUN:cpu    | READY      | 1   | 1   |
| 14*  | RUN:io_done| DONE       | DONE       | READY      | 1   |     |
| 15   | RUN:io     | DONE       | DONE       | READY      | 1   |     |
| 16   | BLOCKED    | DONE       | DONE       | RUN:cpu    | 1   | 1   |
| 17   | BLOCKED    | DONE       | DONE       | RUN:cpu    | 1   | 1   |
| 18   | BLOCKED    | DONE       | DONE       | RUN:cpu    | 1   | 1   |
| 19   | BLOCKED    | DONE       | DONE       | RUN:cpu    | 1   | 1   |
| 20   | BLOCKED    | DONE       | DONE       | RUN:cpu    | 1   | 1   |
| 21*  | RUN:io_done| DONE       | DONE       | DONE       | 1   |     |

| Stats: Total Time | 21         |
| Stats: CPU Busy   | 21 (100.00%) |
| Stats: IO Busy    | 15 (71.43%)  |


8. I run the command: -s 1 -l 3:50,3:50

```
Produce a trace of what would happen when you run these processes:
Process 0
  cpu
  io
  io_done
  io
  io_done

Process 1
  cpu
  cpu
  cpu

Important behaviors:
  System will switch when the current process is FINISHED or ISSUES AN IO
  After IOs, the process issuing the IO will run LATER (when it is its turn)
```


