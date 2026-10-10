#include "types.h"

typedef struct Cycle3 {
    int unk0;
    int index;
} Cycle3;

/* Returns the next index in a 0..2 cycle. */
unsigned int func_003C0F10(Cycle3* c) {
    unsigned int next = c->index + 1;
    return next < 3 ? next : 0;
}
