#include<stdio.h>

int main() {
        int numProcesses, numResources;

        printf("Enter the number of processes: ");
        scanf("%d", &numProcesses);

        printf("Enter the number of resources: ");
        scanf("%d", &numResources);

        int allocation[numProcesses][numResources], max[numProcesses][numResources], need[numProcesses][numResources], available[numResources];

        printf("Enter the values to be entered in the allocation matrix: ");
        for(int i=0; i < numProcesses; i++) {
                for(int j=0; j < numResources; j++) {
                        scanf("%d", &allocation[i][j]);
                }
        }

        printf("Enter the values to be entered in the max matrix: ");
        for(int i=0; i < numProcesses; i++) {
                for(int j=0; j < numResources; j++) {
                        scanf("%d", &max[i][j]);
                }
        }

        printf("Enter the values to be entered in the available matrix: ");
        for(int i=0; i < numResources; i++) {
                scanf("%d", &available[i]);
        }

        int finished[numProcesses], sequence[numProcesses], index = 0;

        for(int i=0; i< numProcesses; i++) {
                finished[i] = 0;
        }

        // calculate the values in need matrix

        for(int i=0; i < numProcesses; i++) {
                for(int j=0; j < numResources; j++) 
                        need[i][j] = max[i][j] - allocation[i][j];
        }

        int y=0;
        // trying to allocate the resources to the processes
        for(int k=0; k < numProcesses; k++) {
                for(int i=0; i < numProcesses; i++) {
                        if(finished[i] == 0) {
                                int flag =0;
                                for(int j=0; j < numResources; j++) {
                                        if(need[i][j] > available[j]) {
                                                flag = 1;
                                                break;
                                        }
                                }

                                if(flag == 0) {
                                        sequence[index++] = i;
                                        for(y=0; y<numResources; y++)
                                                available[y] += allocation[i][y];
                                                finished[i] = 1;
                                }
                        }
                }
        }

        int flag = 1;
        for(int i=0; i< numProcesses; i++) {
                if(finished[i] == 0) {
                        flag = 0;
                        printf("The following system is not safe!");
                        break;
                }
        }

        if(flag == 1) {
                printf("Following is the safe sequence\n");
                for(int i=0; i < numProcesses-1; i++)
                        printf(" P%d ->", sequence[i]);
                printf(" P%d", sequence[numProcesses-1]);
        }

        return 0;
}
