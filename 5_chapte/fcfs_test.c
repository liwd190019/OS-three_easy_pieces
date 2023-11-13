#include <stdio.h>

typedef struct _Process
{
  int processID;
  float burstTime;
  float waitTime;
  float turnAroundTime;
}Process;

int main(int argc, char const *argv[])
{
  int numProcess;
  printf("Please input the numebr of process: ");
  scanf("%d", &numProcess);

  Process process[numProcess];
  for (int i = 0; i < numProcess; i++)
  {
    int process_id = i+1;
    
  }
  
  return 0;
}
