#include "gdsl_list.h"
#include "Linear/List/SinglyList.hpp"

#include <new>

struct GDSL_LIST {
    LIST<int>* obj;
};

struct GDSL_LIST_CURSOR {
    iterator<int>* it;
};

GDSL_LIST* gdsl_list_create() {
    GDSL_LIST* l = new GDSL_LIST;
    l->obj = new LIST<int>();
    return l;
}

GDSL_LIST* gdsl_list_copy(const GDSL_LIST* other) {
    if (!other) return nullptr;

    GDSL_LIST* l = new GDSL_LIST;
    l->obj = new LIST<int>(*(other->obj));
    return l;
}

void gdsl_list_destroy(GDSL_LIST* list) {
    if (!list) return;
    delete list->obj;
    delete list;
}

void gdsl_list_assign(GDSL_LIST* dest, const GDSL_LIST* src) {
    if (!dest || !src) return;
    *(dest->obj) = *(src->obj);
}

long gdsl_list_size(const GDSL_LIST* list) {
    if (!list) return 0;
    return list->obj->size();
}

/* =========================
        MODIFIERS
   ========================= */

int gdsl_list_insert(GDSL_LIST* list, int value, long index) {
    if (!list) return 0;
    return list->obj->insert(value, index);
}

int gdsl_list_remove(GDSL_LIST* list, long index) {
    if (!list) return 0;

    try {
        list->obj->remove(index);
        return 1;
    } catch (...) {
        return 0;
    }
}

long gdsl_list_drop(GDSL_LIST* list, int value) {
    if (!list) return -1;
    return list->obj->drop(value);
}

long gdsl_list_update(GDSL_LIST* list, int prev, int curr, int insert_if_not_found) {
    if (!list) return -1;
    return list->obj->update(prev, curr, insert_if_not_found != 0);
}

int gdsl_list_modify(GDSL_LIST* list, int value, long index) {
    if (!list) return 0;

    try {
        list->obj->modify(value, index);
        return 1;
    } catch (...) {
        return 0;
    }
}

int gdsl_list_add(GDSL_LIST* list, const GDSL_LIST* other) {
    if (!list || !other) return 0;
    return list->obj->add(*(other->obj));
}

void gdsl_list_reverse(GDSL_LIST* list) {
    if (!list) return;
    list->obj->reverse();
}

int gdsl_list_get(const GDSL_LIST* list, long index) {
    if (!list) return 0;

    try {
        return list->obj->value(index);
    } catch (...) {
        return 0;
    }
}

long gdsl_list_index(const GDSL_LIST* list, int value) {
    if (!list) return -1;
    return list->obj->index(value);
}

void gdsl_list_view(const GDSL_LIST* list, int verbose) {
    if (!list) return;
    list->obj->view(verbose);
}

GDSL_LIST_CURSOR* gdsl_list_cursor_begin(const GDSL_LIST* list) {
    if (!list) return nullptr;

    GDSL_LIST_CURSOR* c = new GDSL_LIST_CURSOR;
    c->it = new iterator<int>(list->obj->begin());
    return c;
}

GDSL_LIST_CURSOR* gdsl_list_cursor_end(const GDSL_LIST* list) {
    if (!list) return nullptr;

    GDSL_LIST_CURSOR* c = new GDSL_LIST_CURSOR;
    c->it = new iterator<int>(list->obj->end());
    return c;
}

void gdsl_cursor_next(GDSL_LIST_CURSOR* cursor) {
    if (!cursor) return;
    ++(*(cursor->it));
}

int gdsl_cursor_get(const GDSL_LIST_CURSOR* cursor) {
    if (!cursor) return 0;

    try {
        return *(*(cursor->it));
    } catch (...) {
        return 0;
    }
}

int gdsl_cursor_equal(const GDSL_LIST_CURSOR* a, const GDSL_LIST_CURSOR* b) {
    if (!a || !b) return 0;
    return (*(a->it) == *(b->it));
}

void gdsl_cursor_destroy(GDSL_LIST_CURSOR* cursor) {
    if (!cursor) return;
    delete cursor->it;
    delete cursor;
}