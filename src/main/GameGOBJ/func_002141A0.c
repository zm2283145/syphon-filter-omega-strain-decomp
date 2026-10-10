#include "types.h"
#pragma opt_strength_reduction off
typedef struct { char pad[0x68]; int type; char pad2[0x64]; int* p; char pad3[0x8]; unsigned char flag; } LObj_c7;
typedef struct { char pad[0xEC]; int count; LObj_c7** objs; char pad2[0x34]; int* index; } Lift_c7;
unsigned char func_002141A0(Lift_c7* self) {
    int idx = *self->index;
    unsigned char r = 1;
    int i;
    int count;
    if (idx < 0) {
        r = 0;
    } else {
        count = self->count;
        idx = idx * 2;
        i = idx;
        idx = idx + 1;
        for (; i < count && i <= idx; i++) {
            LObj_c7* o = self->objs[i];
            if (o->type == 2) {
                if (!o->flag || *o->p != 0) { r = 0; break; }
            }
        }
    }
    return r;
}