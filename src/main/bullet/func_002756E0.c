#include "types.h"
typedef struct { int cap; int count; int* data; } Vec2756;
typedef struct { char pad[0x78]; Vec2756 list; } Obj2756;
extern void PtrVector_Resize(Vec2756* v, int n, int* fill);
#pragma opt_strength_reduction off
void func_002756E0(Obj2756* s, int value) {
    int i;
    int last = s->list.count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &s->list.data[i];
        if (*e == value) {
            *e = s->list.data[last];
            last--;
        }
    }
    fill = 0;
    PtrVector_Resize(&s->list, last + 1, &fill);
}
#pragma opt_strength_reduction reset