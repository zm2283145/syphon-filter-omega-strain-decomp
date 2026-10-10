#include "types.h"
extern void func_001AEF70(void*, int);
typedef struct { char d[0x3C]; } G6E1B;
typedef struct { int x; int count; G6E1B* arr; } G6C1B;
void func_001BFCB0(G6C1B* c)
{
    G6E1B* arr = c->arr;
    G6E1B* e = arr + c->count;
    while (arr < e) {
        --e;
        func_001AEF70(e, -1);
    }
    c->count = 0;
}