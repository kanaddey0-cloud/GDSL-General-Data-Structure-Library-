#ifndef GDSL_STACK_H
#define GDSL_STACK_H

#include "gdsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GDSL_STACK GDSL_STACK;

/* lifecycle */
GDSL_STACK* gdsl_stack_create();
GDSL_STACK* gdsl_stack_copy(const GDSL_STACK* other);
void gdsl_stack_destroy(GDSL_STACK* stack);

/* core ops */
long gdsl_stack_size(const GDSL_STACK* stack);
int gdsl_stack_empty(const GDSL_STACK* stack);

/* stack ops */
int gdsl_stack_push(GDSL_STACK* stack, int value);
int gdsl_stack_pop(GDSL_STACK* stack, int* out);
int gdsl_stack_top(const GDSL_STACK* stack, int* out);

/* utilities */
void gdsl_stack_clear(GDSL_STACK* stack);
void gdsl_stack_view(const GDSL_STACK* stack);

#ifdef __cplusplus
}
#endif

#endif