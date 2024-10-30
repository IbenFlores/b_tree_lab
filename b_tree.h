#ifndef B_TREE_H
#define B_TREE_H

#define MAX_KEYS 4

typedef struct BTreeNode BTreeNode;

struct BTreeNode {
    int num_keys;
    double keys[MAX_KEYS];
    BTreeNode *children[MAX_KEYS + 1];
};

BTreeNode *createNode();
void insert(BTreeNode **root, double key);
void splitChild(BTreeNode *parent, int index);
void insertNonFull(struct BTreeNode *node, double key);
void insertKey(BTreeNode *node, double key);
void loadKeysFromFile(BTreeNode **root, const char *filename);
void printTree(BTreeNode *node, int level);
int search(BTreeNode *root, double key);
void freeTree(BTreeNode *root);

#endif