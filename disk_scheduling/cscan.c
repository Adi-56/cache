#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100
#define CYLINDERS 200

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int requests[MAX_REQUESTS];
  int head;
  int numRequests;

  printf("Enter the number of disk requests: ");
  scanf("%d", &numRequests);
  printf("Enter the requests in order of arrival:\n");
  for (int i = 0; i < numRequests; i++) {
    scanf("%d", &requests[i]);
  }
  printf("Enter the initial position of the disk head: ");
  scanf("%d", &head);

  qsort(requests, numRequests, sizeof(int), compare);

  int totalSeekTime = 0;
  int current = head;
  int seekTime = 0;
  for (int i = 0; i < numRequests; i++) {
    if (requests[i] >= head) {
      seekTime = abs(requests[i] - current);
      totalSeekTime += seekTime;
      current = requests[i];
    }
  }
  seekTime = abs(current - CYLINDERS - 1) + abs(0 - requests[0]);
  totalSeekTime += seekTime;
  current = 0;
  for (int i = 0; i < numRequests; i++) {
    if (requests[i] < head) {
      seekTime = abs(requests[i] - current);
      totalSeekTime += seekTime;
      current = requests[i];
    }
  }

  printf("The total seek time is: %d\n", totalSeekTime);
  printf("The average seek time is: %.2f\n", (float) totalSeekTime / numRequests);

  return 0;
}
