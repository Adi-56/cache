#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define PAGE_FRAME_SIZE 10

int main() {
  int pages[MAX_PAGES];
  int pageFrame[PAGE_FRAME_SIZE];
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
  }

  int j = 0;
  for (int i = 0; i < numPages; i++) {
    int isPageFault = 1;
    for (int k = 0; k < PAGE_FRAME_SIZE; k++) {
      if (pageFrame[k] == pages[i]) {
        isPageFault = 0;
        break;
      }
    }
    if (isPageFault) {
      pageFrame[j] = pages[i];
      j = (j + 1) % PAGE_FRAME_SIZE;
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
