#include<stdio.h>
#include<stdlib.h>

#define MAX_REQUESTS 100

int compareRequests(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    int numRequests, RQ[MAX_REQUESTS], TotalHeadMovements, initial, size, direction, i;
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);
    
    printf("Enter the request sequence into the queue: ");
    for(i=0; i < numRequests; i++) {
        scanf("%d", &RQ[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &initial);
    
    printf("Enter the total disk size: ");
    scanf("%d", &size);
    
    printf("Enter the head movement direction(0 for low and 1 for high): ");
    scanf("%d", &direction);
    
    qsort(RQ, numRequests, sizeof(int), compareRequests);
    
    int index;
    for(i=0; i <numRequests; i++) {
        if(initial < RQ[i]) {
            index = i;
            break;
        }
    }
    
    if(direction == 1) {
        for(i = index; i < numRequests; i++) {
            TotalHeadMovements += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // last movement for max size 
        TotalHeadMovements += abs(size-RQ[i-1]-1);
        // movement from max to min of disk
        TotalHeadMovements += abs(size - 1);
        initial = 0;
        for(i=0; i < index; i++) {
            TotalHeadMovements += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        for(i=index-1; i>=0; i--) {
            TotalHeadMovements += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // last movement for min size 
        TotalHeadMovements += abs(RQ[i+1]);
        // movement from min to max of disk 
        TotalHeadMovements += abs(size - 1);
        initial = size - 1;
        for(i=numRequests - 1; i >=0; i--) {
            TotalHeadMovements += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    
    printf("Total head movement is: %d", TotalHeadMovements);
    return 0;
    
    
}