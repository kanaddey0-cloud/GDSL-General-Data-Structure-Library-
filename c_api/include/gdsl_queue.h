#ifndef GDSL_QUEUE_H
#define GDSL_QUEUE_H

#include "gdsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GDSL_QUEUE GDSL_QUEUE;

/* lifecycle */
GDSL_QUEUE* gdsl_queue_create();
GDSL_QUEUE* gdsl_queue_copy(const GDSL_QUEUE* other);
void gdsl_queue_destroy(GDSL_QUEUE* queue);

/* core */
long gdsl_queue_size(const GDSL_QUEUE* queue);
int gdsl_queue_empty(const GDSL_QUEUE* queue);

/* queue ops */
int gdsl_queue_enqueue(GDSL_QUEUE* queue, int value);
int gdsl_queue_dequeue(GDSL_QUEUE* queue, int* out);
int gdsl_queue_front(const GDSL_QUEUE* queue, int* out);
int gdsl_queue_rear(const GDSL_QUEUE* queue, int* out);

/* utilities */
void gdsl_queue_clear(GDSL_QUEUE* queue);
void gdsl_queue_view(const GDSL_QUEUE* queue);

#ifdef __cplusplus
}
#endif

#endif