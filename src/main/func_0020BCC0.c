#include "types.h"
#pragma optimization_level 1

typedef struct Rec14 {
    char b[0x14];
} Rec14;

extern void cSkaSwitchItem_opAssign(Rec14*, void*);

/* Constructs count records from value. */
void std_fill_n_cSkaSwitchItem_int_fill_n(Rec14* p, int count, void* value) {
    while (count != 0) {
        cSkaSwitchItem_opAssign(p, value);
        p++;
        count--;
    }
}
