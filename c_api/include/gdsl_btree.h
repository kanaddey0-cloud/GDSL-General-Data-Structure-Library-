#ifndef GDSL_BTREE_H
#define GDSL_BTREE_H

#include "gdsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "gdsl_mode.h"

typedef struct GDSL_BTREE GDSL_BTREE;

GDSL_BTREE* gdsl_btree_create(unsigned short order);
GDSL_BTREE* gdsl_btree_copy(GDSL_BTREE* other);
void gdsl_btree_destroy(GDSL_BTREE* tree);

int gdsl_btree_insert(GDSL_BTREE* tree, int item);
int gdsl_btree_remove(GDSL_BTREE* tree, int item);
int gdsl_btree_search(GDSL_BTREE* tree, int item);

long gdsl_btree_size(GDSL_BTREE* tree);

void gdsl_btree_view(GDSL_BTREE* tree, int mode);
void gdsl_btree_view_dfs(GDSL_BTREE* tree, int order);
void gdsl_btree_view_bfs(GDSL_BTREE* tree, int order);

#ifdef __cplusplus
}
#endif

#endif