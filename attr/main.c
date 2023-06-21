#include <stdio.h>
#include "attr.h"

#define NUM_ATTRIBUTES 100

int main() {
    struct my_entity my_ent;
    uint32_t ATTR1 = 66;
    bool is_present;
    
    attr_init(&my_ent, NUM_ATTRIBUTES);
    attr_set(&my_ent, ATTR1);
    is_present = attr_get(&my_ent, ATTR1);
    
    if (is_present) {
        printf("ATTR1 is present.\n");
    } else {
        printf("ATTR1 is not set.\n");
    }
    
    attr_fini(&my_ent);
    return 0;
}
