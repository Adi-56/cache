#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
  int burstTime;
  int priority;
  int waitTime;
  int turnaroundTime;
  int processNum;
} Process;

int compareProcesses(const void *a, const void *b) {
  return ((Process*)a)->priority - ((Process*)b)->priority;
}

int main() {
  int numProcesses;
  Process processes[MAX_PROCESSES];

  printf("Enter the number of processes: ");
  scanf("%d", &numProcesses);

  for (int i = 0; i < numProcesses; i++) {
    printf("Enter the burst time for process %d: ", i + 1);
    scanf("%d", &processes[i].burstTime);
    printf("Enter the priority for process %d: ", i + 1);
    scanf("%d", &processes[i].priority);
    processes[i].processNum = i + 1;
  }

  // Sort the processes by priority
  qsort(processes, numProcesses, sizeof(Process), compareProcesses);

  // Calculate the waiting time and turnaround time for each process
  processes[0].waitTime = 0;
  processes[0].turnaroundTime = processes[0].burstTime;

  for (int i = 1; i < numProcesses; i++) {
    processes[i].waitTime = processes[i - 1].waitTime + processes[i - 1].burstTime;
    processes[i].turnaroundTime = processes[i].waitTime + processes[i].burstTime;
  }

  // Print the results
  printf("Process\tBurst Time\tPriority\tWait Time\tTurnaround Time\n");
  for (int i = 0; i < numProcesses; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processNum, processes[i].burstTime, processes[i].priority, processes[i].waitTime, processes[i].turnaroundTime);
  }

  return 0;
}
