#include "types.h"
#pragma optimization_level 1

typedef struct Counter {
    char pad[0xC];
    int count;
} Counter;

/* Decrements a positive counter at +0xC. */
void func_003F5E80(Counter* c) {
    if (c->count > 0) c->count--;
}
