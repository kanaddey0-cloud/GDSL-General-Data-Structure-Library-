#ifndef GDSL_AVL_H
#define GDSL_AVL_H

#include "gdsl_config.h"
#include "gdsl_mode.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GDSL_AVL GDSL_AVL;

GDSL_AVL* gdsl_avl_create();
GDSL_AVL* gdsl_avl_copy(GDSL_AVL* other);
void gdsl_avl_destroy(GDSL_AVL* tree);

int gdsl_avl_insert(GDSL_AVL* tree, int item);
int gdsl_avl_remove(GDSL_AVL* tree, int item);
int gdsl_avl_search(GDSL_AVL* tree, int item);

void gdsl_avl_insert_array(GDSL_AVL* tree, int* arr, unsigned long size);

long gdsl_avl_size(GDSL_AVL* tree);

void gdsl_avl_view(GDSL_AVL* tree, GDSL_MODE mode);
void gdsl_avl_view_dfs(GDSL_AVL* tree, int order);
void gdsl_avl_view_bfs(GDSL_AVL* tree, int order);

void gdsl_avl_view_in(GDSL_AVL* tree);
void gdsl_avl_view_pre(GDSL_AVL* tree);
void gdsl_avl_view_post(GDSL_AVL* tree);

#ifdef __cplusplus
}
#endif

#endif