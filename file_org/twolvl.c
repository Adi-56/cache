#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_DIRECTORIES 10

struct File {
  char name[100];
  int size;
};

struct Directory {
  char name[100];
  int numFiles;
  struct File files[MAX_FILES];
};

int main() {
  struct Directory directories[MAX_DIRECTORIES];
  int numDirectories;

  printf("Enter the number of directories: ");
  scanf("%d", &numDirectories);
  printf("Enter the directories and their files:\n");
  for (int i = 0; i < numDirectories; i++) {
    scanf("%s%d", directories[i].name, &directories[i].numFiles);
    for (int j = 0; j < directories[i].numFiles; j++) {
      scanf("%s%d", directories[i].files[j].name, &directories[i].files[j].size);
    }
  }

  printf("Directories and their files:\n");
  for (int i = 0; i < numDirectories; i++) {
    printf("%s:\n", directories[i].name);
    for (int j = 0; j < directories[i].numFiles; j++) {
      printf("\t%s\t%d\n", directories[i].files[j].name, directories[i].files[j].size);
    }
  }

  return 0;
}
