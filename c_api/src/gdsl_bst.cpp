#include "gdsl_bst.h"
#include "NonLinear/Tree/BinarySearchTree.hpp"

struct GDSL_BST {
    BSTREE<int>* obj;
};

GDSL_BST* gdsl_bst_create() {
    return new GDSL_BST{ new BSTREE<int>(false) };
}

GDSL_BST* gdsl_bst_copy(GDSL_BST* other) {
    if (!other || !other->obj) return nullptr;
    return new GDSL_BST{ new BSTREE<int>(*(other->obj)) };
}

void gdsl_bst_destroy(GDSL_BST* t) {
    if (!t) return;
    delete t->obj;
    delete t;
}

int gdsl_bst_insert(GDSL_BST* t, int v) {
    if (!t || !t->obj) return 0;
    return t->obj->insert(v);
}

int gdsl_bst_remove(GDSL_BST* t, int v) {
    if (!t || !t->obj) return 0;
    return t->obj->remove(v);
}

int gdsl_bst_search(GDSL_BST* t, int v) {
    if (!t || !t->obj) return 0;
    return t->obj->search(v);
}

long gdsl_bst_size(GDSL_BST* t) {
    if (!t || !t->obj) return 0;
    return t->obj->size();
}

void gdsl_bst_view(GDSL_BST* t, int mode) {
    if (!t || !t->obj) return;
    t->obj->view((MODE)mode);
}