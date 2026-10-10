#include "types.h"
typedef struct { char pad[0x40]; char item[0x1C0]; } E36A;
typedef struct { int a; int count; char pad[0x38]; char items[1][0x1C0]; } H36A;
extern void func_00369C50(void* p);
void func_0036A0F0(H36A* h)
{
    int i;
    for (i = 0; i < h->count; i++) {
        func_00369C50(h->items[i]);
    }
}