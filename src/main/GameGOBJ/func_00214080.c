#include "types.h"
typedef struct { char pad0[0x68]; int state; char pad1[0x98-0x6C]; int count; char pad2[0xD0-0x9C]; int* cur; char pad3[0xDC-0xD4]; unsigned char active; } Obj4080;
typedef struct { char pad0[0x4C]; int kind; } Ent4080;
typedef struct { char pad0[0x70]; int num; char vec[8]; Obj4080** objs; } Lift4080;
extern Ent4080** func_00172990(void* vec, int i);
extern int D_004F5468;
#pragma opt_strength_reduction off
unsigned char func_00214080(Lift4080* p) {
    unsigned char ok = 1;
    int i;
    Obj4080* o;
    for (i = 0; i < p->num; i++) {
        Ent4080** e = func_00172990(p->vec, i);
        if ((*e)->kind == D_004F5468) {
            o = p->objs[i];
            if (o->state == 2) {
                int c = o->count - 1;
                if (!o->active || c != *o->cur) { ok = 0; break; }
            }
        }
    }
    return ok;
}