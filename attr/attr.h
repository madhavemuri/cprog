#ifndef ATTR_H
#define ATTR_H

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

struct my_entity {
    int64_t *attr;
    uint32_t attr_nr;
    pthread_mutex_t lock;
};

int attr_init(struct my_entity *entity, int32_t nr);
bool attr_set(struct my_entity *entity, uint32_t attr_num);
bool attr_get(struct my_entity *entity, uint32_t attr_num);
void attr_fini(struct my_entity *entity);

#endif  // ATTR_H