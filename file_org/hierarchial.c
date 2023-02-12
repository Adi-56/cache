#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRECTORIES 100

struct Directory {
  char name[100];
  int numDirectories;
  struct Directory *directories;
};

void printDirectory(struct Directory *directory, int depth) {
  for (int i = 0; i < depth; i++) {
    printf("\t");
  }
  printf("%s\n", directory->name);
  for (int i = 0; i < directory->numDirectories; i++) {
    printDirectory(&directory->directories[i], depth + 1);
  }
}

int main() {
  struct Directory root;
  root.numDirectories = 0;

  printf("Enter the root directory and its subdirectories:\n");
  scanf("%s%d", root.name, &root.numDirectories);
  root.directories = (struct Directory *) malloc(root.numDirectories * sizeof(struct Directory));
  for (int i = 0; i < root.numDirectories; i++) {
    scanf("%s%d", root.directories[i].name, &root.directories[i].numDirectories);
    root.directories[i].directories = (struct Directory *) malloc(root.directories[i].numDirectories * sizeof(struct Directory));
    for (int j = 0; j < root.directories[i].numDirectories; j++) {
      scanf("%s%d", root.directories[i].directories[j].name, &root.directories[i].directories[j].numDirectories);
      root.directories[i].directories[j].directories = (struct Directory *) malloc(root.directories[i].directories[j].numDirectories * sizeof(struct Directory));
      for (int k = 0; k < root.directories[i].directories[j].numDirectories; k++) {
        scanf("%s", root.directories[i].directories[j].directories[k].name);
        root.directories[i].directories[j].directories[k].numDirectories = 0;
      }
    }
  }

  printf("Hierarchical file organization:\n");
  printDirectory(&root, 0);

  return 0;
}
