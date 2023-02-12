#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

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

  int totalSeekTime = 0;
  for (int i = 0; i < numRequests; i++) {
    int seekTime = abs(requests[i] - head);
    totalSeekTime += seekTime;
    head = requests[i];
  }
  printf("The total seek time is: %d\n", totalSeekTime);
  printf("The average seek time is: %.2f\n", (float) totalSeekTime / numRequests);

  return 0;
}
