#include "types.h"
typedef struct { char pad[0x3C]; } G7E35;
typedef struct { int pad; int count; G7E35* data; } G7V35;
extern void func_001AEF70(void* p, int x);
void func_0035F910(G7V35* v)
{
    G7E35* b = v->data;
    G7E35* e = b + v->count;
    while (b < e) {
        e--;
        func_001AEF70(e, -1);
    }
    v->count = 0;
}