#include "gdsl_queue.h"
#include "Linear/Queue/SimpleQueue.hpp"

struct GDSL_QUEUE {
    LIST<int> obj;
};

/* lifecycle */

GDSL_QUEUE* gdsl_queue_create() {
    return new GDSL_QUEUE;
}

GDSL_QUEUE* gdsl_queue_copy(const GDSL_QUEUE* other) {
    if (!other) return nullptr;
    GDSL_QUEUE* q = new GDSL_QUEUE;
    q->obj = other->obj;
    return q;
}

void gdsl_queue_destroy(GDSL_QUEUE* queue) {
    delete queue;
}

/* core */

long gdsl_queue_size(const GDSL_QUEUE* queue) {
    if (!queue) return 0;
    return queue->obj.size();
}

int gdsl_queue_empty(const GDSL_QUEUE* queue) {
    return (!queue || queue->obj.size() == 0);
}

/* operations */

int gdsl_queue_enqueue(GDSL_QUEUE* queue, int value) {
    if (!queue) return 0;
    return queue->obj.insert(value);
}

int gdsl_queue_dequeue(GDSL_QUEUE* queue, int* out) {
    if (!queue || queue->obj.size() == 0) return 0;

    *out = queue->obj.remove(0);
    return 1;
}

int gdsl_queue_front(const GDSL_QUEUE* queue, int* out) {
    if (!queue || queue->obj.size() == 0) return 0;

    *out = queue->obj.value(0);
    return 1;
}

int gdsl_queue_rear(const GDSL_QUEUE* queue, int* out) {
    if (!queue || queue->obj.size() == 0) return 0;

    *out = queue->obj.value(-1);
    return 1;
}

/* utils */

void gdsl_queue_clear(GDSL_QUEUE* queue) {
    if (!queue) return;

    while (queue->obj.size() > 0) {
        queue->obj.remove(0);
    }
}

void gdsl_queue_view(const GDSL_QUEUE* queue) {
    if (!queue) return;
    queue->obj.view(false);
}