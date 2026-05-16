#include "gdsl_btree.h"
#include "NonLinear/Tree/BalancedTree.hpp"

struct GDSL_BTREE {
    BTREE<int>* obj;
};

GDSL_BTREE* gdsl_btree_create(unsigned short order) {
    return new GDSL_BTREE{ new BTREE<int>(order) };
}

GDSL_BTREE* gdsl_btree_copy(GDSL_BTREE* other) {
    if (!other || !other->obj) return nullptr;
    return new GDSL_BTREE{ new BTREE<int>(*(other->obj)) };
}

void gdsl_btree_destroy(GDSL_BTREE* tree) {
    if (!tree) return;
    delete tree->obj;
    delete tree;
}

int gdsl_btree_insert(GDSL_BTREE* tree, int item) {
    if (!tree || !tree->obj) return 0;
    return tree->obj->insert(item);
}

int gdsl_btree_remove(GDSL_BTREE* tree, int item) {
    if (!tree || !tree->obj) return 0;
    return tree->obj->remove(item);
}

int gdsl_btree_search(GDSL_BTREE* tree, int item) {
    if (!tree || !tree->obj) return 0;
    return tree->obj->search(item);
}

long gdsl_btree_size(GDSL_BTREE* tree) {
    if (!tree || !tree->obj) return 0;
    return tree->obj->size();
}

void gdsl_btree_view_bfs(GDSL_BTREE* tree, int order) {
    if (!tree || !tree->obj) return;
    tree->obj->viewBFS(order);
}

void gdsl_btree_view_dfs(GDSL_BTREE* tree, int order) {
    if (!tree || !tree->obj) return;
    tree->obj->viewDFS(order);
}