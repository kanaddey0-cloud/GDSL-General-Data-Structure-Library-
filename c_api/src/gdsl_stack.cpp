#include "gdsl_stack.h"
#include "Linear/Stack.hpp"

struct GDSL_STACK {
    LIST<int> obj;
};

/* lifecycle */

GDSL_STACK* gdsl_stack_create() {
    return new GDSL_STACK;
}

GDSL_STACK* gdsl_stack_copy(const GDSL_STACK* other) {
    if (!other) return nullptr;
    GDSL_STACK* s = new GDSL_STACK;
    s->obj = other->obj;
    return s;
}

void gdsl_stack_destroy(GDSL_STACK* stack) {
    delete stack;
}

/* core */

long gdsl_stack_size(const GDSL_STACK* stack) {
    if (!stack) return 0;
    return stack->obj.size();
}

int gdsl_stack_empty(const GDSL_STACK* stack) {
    return (!stack || stack->obj.size() == 0);
}

/* operations */

int gdsl_stack_push(GDSL_STACK* stack, int value) {
    if (!stack) return 0;
    return stack->obj.insert(value);
}

int gdsl_stack_pop(GDSL_STACK* stack, int* out) {
    if (!stack || stack->obj.size() == 0) return 0;

    *out = stack->obj.remove(-1);
    return 1;
}

int gdsl_stack_top(const GDSL_STACK* stack, int* out) {
    if (!stack || stack->obj.size() == 0) return 0;

    *out = stack->obj.value(-1);
    return 1;
}

/* utils */

void gdsl_stack_clear(GDSL_STACK* stack) {
    if (!stack) return;

    while (stack->obj.size() > 0) {
        stack->obj.remove(-1);
    }
}

void gdsl_stack_view(const GDSL_STACK* stack) {
    if (!stack) return;
    stack->obj.view(false);
}