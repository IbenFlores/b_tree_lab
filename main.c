#include "b_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  BTreeNode *root = NULL;

  // Medir el tiempo de carga
  clock_t start = clock();
  
  // insercion por archivo
  loadKeysFromFile(&root, "random_numbers_1.csv");
  
  //insercion manual
  // double sequence[] = {30.0, 7.0, 17.0, 10.0, 20.0, 5.0, 6.0, 12.0, 678.0, 234.0, 567.0};
  // int length = sizeof(sequence) / sizeof(sequence[0]);

  // for (int i = 0; i < length; i++) {
  //       insert(&root, sequence[i]);
  //       printf("%.2lf insertado.\n", sequence[i]);
  // }

  clock_t end = clock();
  double load_time = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Carga completa del archivo en el B-tree. Tiempo de carga: %.16lf "
         "segundos.\n",
         load_time);

  printTree(root, 0);

  // Liberar memoria
  freeTree(root);

  return 0;
}