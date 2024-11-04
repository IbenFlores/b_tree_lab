#include "b_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define EPSILON 1e-10

struct BTreeNode *createNode() {
  struct BTreeNode *newNode =
      (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  if (newNode == NULL) {
    printf("La asignación de memoria falló.\n");
    exit(1);
  }
  newNode->num_keys = 0;
  for (int i = 0; i < MAX_KEYS + 1; i++) {
    newNode->children[i] = NULL;
  }
  return newNode;
}

void insert(struct BTreeNode **root, double key) {
  if (*root == NULL) {
    *root = createNode();
    (*root)->keys[0] = key;
    (*root)->num_keys = 1;
  } else {
    if ((*root)->num_keys == MAX_KEYS) {
      struct BTreeNode *newRoot = createNode();
      newRoot->children[0] = *root;
      splitChild(newRoot, 0);
      *root = newRoot;
    }
    insertNonFull(*root, key);
  }
}

void splitChild(struct BTreeNode *parent, int index) {
  struct BTreeNode *child = parent->children[index];
  struct BTreeNode *newChild = createNode();
  newChild->num_keys = MAX_KEYS / 2;
  for (int i = 0; i < MAX_KEYS / 2; i++) {
    newChild->keys[i] = child->keys[i + MAX_KEYS / 2 + 1];
  }
  if (child->children[0] != NULL) {
    for (int i = 0; i < MAX_KEYS / 2 + 1; i++) {
      newChild->children[i] = child->children[i + MAX_KEYS / 2 + 1];
    }
  }
  child->num_keys = MAX_KEYS / 2;
  for (int i = parent->num_keys; i >= index + 1; i--) {
    parent->children[i + 1] = parent->children[i];
  }
  parent->children[index + 1] = newChild;
  for (int i = parent->num_keys - 1; i >= index; i--) {
    parent->keys[i + 1] = parent->keys[i];
  }
  parent->keys[index] = child->keys[MAX_KEYS / 2];
  parent->num_keys++;
}

void insertNonFull(struct BTreeNode *node, double key) {
  int i = node->num_keys - 1;
  if (node->children[0] == NULL) {
    insertKey(node, key);
    return;
  }
  while (i >= 0 && node->keys[i] > key) {
    i--;
  }
  i++;
  if (node->children[i]->num_keys == MAX_KEYS) {
    splitChild(node, i);
    if (node->keys[i] < key) {
      i++;
    }
  }
  insertNonFull(node->children[i], key);
}

void insertKey(struct BTreeNode *node, double key) {
  int i = node->num_keys - 1;
  while (i >= 0 && node->keys[i] > key) {
    node->keys[i + 1] = node->keys[i];
    i--;
  }
  node->keys[i + 1] = key;
  node->num_keys++;
}

void loadKeysFromFile(BTreeNode **root, const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Error: could not open file: %s\n", filename);
    return;
  }

  char line[128];
  int index; // variable to hold the integer before the comma
  double key;

  while (fgets(line, sizeof(line), file)) {
    // Parse the line to extract the intxeger and the floating-point number
    if (sscanf(line, "%d,%lf", &index, &key) == 2) {
      printf("%.16lf \n", key);
      insert(root, key);
    } else {
      fprintf(stderr, "Warning: skipping malformed line: %s", line);
    }
  }

  fclose(file);
}


void printTree(BTreeNode *node, int level) {
    if (node == NULL) {
        return; // Base case: if the node is NULL, return
    }
    
    // Print the keys of the current node
    for (int i = 0; i < node->num_keys; i++) {
        // Indent based on level
        for (int j = 0; j < level; j++) {
            printf("   "); // Indentation for visual clarity
        }
        printf("%lf ", node->keys[i]); // Print the key
    }
    printf("\n");
    
    // Recursively print the children
    for (int i = 0; i <= node->num_keys; i++) {
        printTree(node->children[i], level + 1); // Increase level for child nodes
    }
}

int search(struct BTreeNode *root, double key) {
    if (root == NULL) {
        return 0; // The tree is empty
    }

    int i = 0;

    // Find the first key greater than or equal to the search key
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }

    // Check if the found key is equal to the search key
    if (i < root->num_keys && root->keys[i] == key) {
        return 1; // Key found
    }

    // If the node is a leaf node, key is not found
    if (root->children[0] == NULL) {
        return 0; // Key not found
    }

    // Recursively search in the child node
    return search(root->children[i], key);
}

// Free the memory allocated for the B-tree
void freeTree(BTreeNode *root) {
    if (root == NULL) {
        return; // Base case: if the node is NULL, return
    }

    // Recursively free all children
    for (int i = 0; i <= root->num_keys; i++) {
        freeTree(root->children[i]);
    }

    free(root); // Free the current node
}