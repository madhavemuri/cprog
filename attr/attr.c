#include <stdlib.h>
#include <stdio.h>
#include "attr.h"

int attr_init(struct my_entity *entity, int32_t nr) {
    entity->attr = malloc(sizeof(int64_t) * ((nr / 64) + 1));
    entity->attr_nr = nr;
    pthread_mutex_init(&entity->lock, NULL);
    return 0;
}

bool attr_set(struct my_entity *entity, uint32_t attr_num) {
    if (attr_num >= entity->attr_nr)
        return false;

    pthread_mutex_lock(&entity->lock);
    entity->attr[attr_num / 64] |= (1ULL << (attr_num % 64));
    pthread_mutex_unlock(&entity->lock);
    return true;
}

bool attr_get(struct my_entity *entity, uint32_t attr_num) {
    if (attr_num >= entity->attr_nr)
        return false;

    bool isPresent;
    pthread_mutex_lock(&entity->lock);
    isPresent = (entity->attr[attr_num / 64] & (1ULL << (attr_num % 64))) != 0;
    pthread_mutex_unlock(&entity->lock);
    return isPresent;
}

void attr_fini(struct my_entity *entity) {
    free(entity->attr);
    pthread_mutex_destroy(&entity->lock);
}