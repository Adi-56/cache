#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
  int burstTime;
  int arrivalTime;
  int waitTime;
  int turnaroundTime;
  int processNum;
} Process;

int compareProcesses(const void *a, const void *b) {
  Process *p1 = (Process*)a;
  Process *p2 = (Process*)b;

  if (p1->arrivalTime == p2->arrivalTime) {
    return p1->burstTime - p2->burstTime;
  }

  return p1->arrivalTime - p2->arrivalTime;
}

int main() {
  int numProcesses;
  Process processes[MAX_PROCESSES];

  printf("Enter the number of processes: ");
  scanf("%d", &numProcesses);

  for (int i = 0; i < numProcesses; i++) {
    printf("Enter the burst time for process %d: ", i + 1);
    scanf("%d", &processes[i].burstTime);
    printf("Enter the arrival time for process %d: ", i + 1);
    scanf("%d", &processes[i].arrivalTime);
    processes[i].processNum = i + 1;
  }

  // Sort the processes by arrival time and burst time
  qsort(processes, numProcesses, sizeof(Process), compareProcesses);

  // Calculate the waiting time and turnaround time for each process
  int currentTime = 0;
  processes[0].waitTime = 0;
  processes[0].turnaroundTime = processes[0].burstTime;
  currentTime = processes[0].burstTime;

  for (int i = 1; i < numProcesses; i++) {
    if (processes[i].arrivalTime > currentTime) {
      currentTime = processes[i].arrivalTime;
    }
    processes[i].waitTime = currentTime - processes[i].arrivalTime;
    currentTime += processes[i].burstTime;
    processes[i].turnaroundTime = processes[i].waitTime + processes[i].burstTime;
  }

  // Print the results
  printf("Process\tBurst Time\tArrival Time\tWait Time\tTurnaround Time\n");
  for (int i = 0; i < numProcesses; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processNum, processes[i].burstTime, processes[i].arrivalTime, processes[i].waitTime, processes[i].turnaroundTime);
  }

  return 0;
}
