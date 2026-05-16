#ifndef GDSL_LIST_H
#define GDSL_LIST_H

#include "gdsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GDSL_LIST GDSL_LIST;
typedef struct GDSL_LIST_CURSOR GDSL_LIST_CURSOR;


GDSL_LIST* gdsl_list_create();
GDSL_LIST* gdsl_list_copy(const GDSL_LIST* other);
void gdsl_list_destroy(GDSL_LIST* list);

void gdsl_list_assign(GDSL_LIST* dest, const GDSL_LIST* src);

long gdsl_list_size(const GDSL_LIST* list);


int gdsl_list_insert(GDSL_LIST* list, int value, long index);
int gdsl_list_remove(GDSL_LIST* list, long index);
long gdsl_list_drop(GDSL_LIST* list, int value);
long gdsl_list_update(GDSL_LIST* list, int prev, int curr, int insert_if_not_found);
int gdsl_list_modify(GDSL_LIST* list, int value, long index);
int gdsl_list_add(GDSL_LIST* list, const GDSL_LIST* other);
void gdsl_list_reverse(GDSL_LIST* list);


int gdsl_list_get(const GDSL_LIST* list, long index);
long gdsl_list_index(const GDSL_LIST* list, int value);


void gdsl_list_view(const GDSL_LIST* list, int verbose);


GDSL_LIST_CURSOR* gdsl_list_cursor_begin(const GDSL_LIST* list);
GDSL_LIST_CURSOR* gdsl_list_cursor_end(const GDSL_LIST* list);

void gdsl_cursor_next(GDSL_LIST_CURSOR* cursor);
int gdsl_cursor_get(const GDSL_LIST_CURSOR* cursor);

int gdsl_cursor_equal(const GDSL_LIST_CURSOR* a, const GDSL_LIST_CURSOR* b);

void gdsl_cursor_destroy(GDSL_LIST_CURSOR* cursor);

#ifdef __cplusplus
}
#endif

#endif