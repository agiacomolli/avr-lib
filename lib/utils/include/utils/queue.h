#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

typedef struct {
    uint8_t head;
    uint8_t tail;
    uint8_t count;
    uint8_t capacity;
    char *buf;
} queue_t;

static inline void queue_init(queue_t *q, char *buf, int size)
{
    q->head = q->tail = q->count = 0;
    q->capacity = size;
    q->buf = buf;
}

static inline int queue_read(queue_t *q, char *buf, int size)
{
    int i;

    if (size > q->count)
        size = q->count;

    for (i = 0; i < size; i++) {
        q->count--;
        q->head++;
        buf[i] = q->buf[q->head % q->capacity];
    }

    return i;
}

static inline int queue_write(queue_t *q, char *buf, int size)
{
    int i;

    for (i = 0; i < size && q->count < q->capacity; i++) {
        q->tail++;
        q->count++;

        q->buf[q->tail % q->capacity] = buf[i];
    }

    return i;
}

#endif /* QUEUE_H */

