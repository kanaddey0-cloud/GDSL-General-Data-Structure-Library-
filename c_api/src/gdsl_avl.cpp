#include "gdsl_avl.h"
#include "NonLinear/Tree/AdelsonVelskyLandisTree.hpp"

struct GDSL_AVL {
    AVLTREE<int>* obj;
};

GDSL_AVL* gdsl_avl_create() {
    return new GDSL_AVL{ new AVLTREE<int>() };
}

GDSL_AVL* gdsl_avl_copy(GDSL_AVL* other) {
    if (!other || !other->obj) return nullptr;
    return new GDSL_AVL{ new AVLTREE<int>(*(other->obj)) };
}

void gdsl_avl_destroy(GDSL_AVL* tree) {
    if (!tree) return;
    delete tree->obj;
    delete tree;
}

int gdsl_avl_insert(GDSL_AVL* tree, int item) {
    if (!tree || !tree->obj) return 0;
    tree->obj->insert(item);
    return 1;
}

int gdsl_avl_remove(GDSL_AVL* tree, int item) {
    if (!tree || !tree->obj) return 0;
    return tree->obj->remove(item);
}

int gdsl_avl_search(GDSL_AVL* tree, int item) {
    if (!tree || !tree->obj) return 0;
    return tree->obj->search(item);
}

long gdsl_avl_size(GDSL_AVL* tree) {
    if (!tree || !tree->obj) return 0;
    return tree->obj->size();
}

void gdsl_avl_view(GDSL_AVL* tree, GDSL_MODE mode) {
    if (!tree || !tree->obj) return;
    tree->obj->view((MODE)mode);
}