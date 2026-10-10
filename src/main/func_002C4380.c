#include "types.h"
typedef struct { char pad[0x3C]; } G3E_002C4380;
typedef struct { int vt; int count; G3E_002C4380* data; } G3A_002C4380;
extern void func_001AEF70(G3E_002C4380* p, int x);
void func_002C4380(G3A_002C4380* a) {
    G3E_002C4380* begin = a->data;
    G3E_002C4380* p = begin + a->count;
    while (begin < p) {
        p--;
        func_001AEF70(p, -1);
    }
    a->count = 0;
}