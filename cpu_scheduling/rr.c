#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100
#define MAX_QUANTUM 10

typedef struct {
  int burstTime;
  int waitTime;
  int turnaroundTime;
  int processNum;
  int remainingTime;
} Process;

int main() {
  int numProcesses;
  int quantum;
  Process processes[MAX_PROCESSES];

  printf("Enter the number of processes: ");
  scanf("%d", &numProcesses);
  printf("Enter the time quantum: ");
  scanf("%d", &quantum);

  for (int i = 0; i < numProcesses; i++) {
    printf("Enter the burst time for process %d: ", i + 1);
    scanf("%d", &processes[i].burstTime);
    processes[i].processNum = i + 1;
    processes[i].remainingTime = processes[i].burstTime;
  }

  // Calculate the waiting time and turnaround time for each process
  int currentTime = 0;
  int numFinishedProcesses = 0;
  while (numFinishedProcesses < numProcesses) {
    int foundProcess = 0;
    for (int i = 0; i < numProcesses; i++) {
      if (processes[i].remainingTime > 0) {
        foundProcess = 1;
        if (processes[i].remainingTime > quantum) {
          currentTime += quantum;
          processes[i].remainingTime -= quantum;
        } else {
          currentTime += processes[i].remainingTime;
          processes[i].waitTime = currentTime - processes[i].burstTime;
          processes[i].turnaroundTime = currentTime;
          processes[i].remainingTime = 0;
          numFinishedProcesses++;
        }
      }
    }
    if (!foundProcess) {
      break;
    }
  }

  // Print the results
  printf("Process\tBurst Time\tWait Time\tTurnaround Time\n");
  for (int i = 0; i < numProcesses; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].processNum, processes[i].burstTime, processes[i].waitTime, processes[i].turnaroundTime);
  }

  return 0;
}
