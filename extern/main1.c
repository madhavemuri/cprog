#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "shared.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("usage: ./main1 num");
        return -1;
    }
    a = atoi(argv[1]);
    print_a();
    sleep(5);

    return 0;
}
