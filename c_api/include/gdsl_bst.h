#ifndef GDSL_BST_H
#define GDSL_BST_H

#include "gdsl_config.h"
#include "gdsl_mode.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GDSL_BST GDSL_BST;

GDSL_BST* gdsl_bst_create();
GDSL_BST* gdsl_bst_copy(GDSL_BST* other);
void gdsl_bst_destroy(GDSL_BST* tree);

int gdsl_bst_insert(GDSL_BST* tree, int item);
int gdsl_bst_remove(GDSL_BST* tree, int item);
int gdsl_bst_search(GDSL_BST* tree, int item);

void gdsl_bst_insert_array(GDSL_BST* tree, int* arr, unsigned long size);

long gdsl_bst_size(GDSL_BST* tree);

void gdsl_bst_view(GDSL_BST* tree, int mode);
void gdsl_bst_view_dfs(GDSL_BST* tree, int order);
void gdsl_bst_view_bfs(GDSL_BST* tree, int order);

void gdsl_bst_view_in(GDSL_BST* tree);
void gdsl_bst_view_pre(GDSL_BST* tree);
void gdsl_bst_view_post(GDSL_BST* tree);

#ifdef __cplusplus
}
#endif

#endif