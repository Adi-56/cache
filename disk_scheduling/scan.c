#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int requests[MAX_REQUESTS];
  int head;
  int numRequests;
  int direction;

  printf("Enter the number of disk requests: ");
  scanf("%d", &numRequests);
  printf("Enter the requests in order of arrival:\n");
  for (int i = 0; i < numRequests; i++) {
    scanf("%d", &requests[i]);
  }
  printf("Enter the initial position of the disk head: ");
  scanf("%d", &head);
  printf("Enter the direction (0 for left, 1 for right): ");
  scanf("%d", &direction);

  qsort(requests, numRequests, sizeof(int), compare);

  int totalSeekTime = 0;
  int current = head;
  for (int i = 0; i < numRequests; i++) {
    if (direction == 0) {
      if (requests[i] >= head) {
        break;
      }
    } else {
      if (requests[i] <= head) {
        continue;
      }
    }
    int seekTime = abs(requests[i] - current);
    totalSeekTime += seekTime;
    current = requests[i];
  }
  if (direction == 0) {
    totalSeekTime += abs(current - requests[numRequests - 1]);
  } else {
    totalSeekTime += abs(requests[0]);
  }

  printf("The total seek time is: %d\n", totalSeekTime);
  printf("The average seek time is: %.2f\n", (float) totalSeekTime / numRequests);

  return 0;
}
