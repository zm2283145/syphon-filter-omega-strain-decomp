#include "types.h"
#pragma optimization_level 1

typedef struct Rec14 {
    char b[0x14];
} Rec14;

extern void func_0020BD30(Rec14*, void*);

/* Constructs count records from value. */
void func_0020BCC0(Rec14* p, int count, void* value) {
    while (count != 0) {
        func_0020BD30(p, value);
        p++;
        count--;
    }
}
