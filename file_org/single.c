#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

struct File {
  char name[100];
  int size;
};

int main() {
  struct File files[MAX_FILES];
  int numFiles;

  printf("Enter the number of files: ");
  scanf("%d", &numFiles);
  printf("Enter the files and their sizes:\n");
  for (int i = 0; i < numFiles; i++) {
    scanf("%s%d", files[i].name, &files[i].size);
  }

  printf("Files and their sizes:\n");
  for (int i = 0; i < numFiles; i++) {
    printf("%s\t%d\n", files[i].name, files[i].size);
  }

  return 0;
}
