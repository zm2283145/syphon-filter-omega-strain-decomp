#pragma opt_strength_reduction off
#include "types.h"
typedef struct { int pad0; int count; int* data; } PtrVec_1A0080;
typedef struct { char pad[0xB4]; PtrVec_1A0080 list; } Owner_1A0080;
typedef struct { char pad[0xB0]; Owner_1A0080* owner; } O_1A0080;
extern void PtrVector_Resize(PtrVec_1A0080* v, int n, int* fill);
static inline void Remove_1A0080(PtrVec_1A0080* v, int value)
{
    int i;
    int last = v->count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &v->data[i];
        if (*e == value) {
            *e = v->data[last];
            last--;
        }
    }
    fill = 0;
    PtrVector_Resize(v, last + 1, &fill);
}
void func_001A0080(O_1A0080* o)
{
    if (o->owner) {
        Remove_1A0080(&o->owner->list, (int)o);
        o->owner = 0;
    }
}
#pragma opt_strength_reduction reset