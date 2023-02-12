#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define PAGE_FRAME_SIZE 10

int main() {
  int pages[MAX_PAGES];
  int pageFrame[PAGE_FRAME_SIZE];
  int nextUsage[PAGE_FRAME_SIZE];
  int numPages;
  int pageFaults = 0;

  printf("Enter the number of pages: ");
  scanf("%d", &numPages);
  printf("Enter the pages:\n");
  for (int i = 0; i < numPages; i++) {
    scanf("%d", &pages[i]);
  }

  for (int i = 0; i < PAGE_FRAME_SIZE; i++) {
    pageFrame[i] = -1;
    nextUsage[i] = -1;
  }

  int j = 0;
  for (int i = 0; i < numPages; i++) {
    int isPageFault = 1;
    for (int k = 0; k < PAGE_FRAME_SIZE; k++) {
      if (pageFrame[k] == pages[i]) {
        isPageFault = 0;
        nextUsage[k] = -1;
        break;
      }
    }
    if (isPageFault) {
      int farthestUsageIndex = 0;
      for (int k = 0; k < PAGE_FRAME_SIZE; k++) {
        if (nextUsage[k] == -1) {
          farthestUsageIndex = k;
          break;
        }
        int farthestIndex = k;
        for (int l = k + 1; l < PAGE_FRAME_SIZE; l++) {
          if (nextUsage[l] > nextUsage[farthestIndex]) {
            farthestIndex = l;
          }
        }
        farthestUsageIndex = farthestIndex;
      }
      pageFrame[farthestUsageIndex] = pages[i];
      nextUsage[farthestUsageIndex] = -1;
      for (int k = i + 1; k < numPages; k++) {
        if (pages[k] == pageFrame[farthestUsageIndex]) {
          nextUsage[farthestUsageIndex] = k;
          break;
        }
      }
      pageFaults++;
    }
    printf("Page frame after page %d: [", i);
    for (int k = 0; k < PAGE_FRAME_SIZE; k++) {
      if (pageFrame[k] != -1) {
        printf(" %d ", pageFrame[k]);
      } else {
        printf(" . ");
      }
    }
    printf("]\n");
  }

  printf("The number of page faults is: %d\n", pageFaults);

  return 0;
}
