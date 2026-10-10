#include "types.h"
typedef struct { int used; void* owner; float time; int val; } A1_Slot;
extern A1_Slot D_0053B560[4];
typedef struct { char pad[0x108]; A1_Slot* slot; } A1_Ent;
int func_0039B110(A1_Ent* e, int* out, float t) {
    int ret = 0;
    int val = 0;
    int i;
    A1_Slot* s = e->slot;
    if (s != 0 && s->owner == e) {
        s->time = t;
        val = e->slot->val;
        ret = 2;
    } else {
        for (i = 0; i < 4; i++) {
            if (D_0053B560[i].used) {
                if (D_0053B560[i].owner == 0 || t < D_0053B560[i].time + 5.0f) {
                    D_0053B560[i].owner = e;
                    D_0053B560[i].time = t;
                    e->slot = &D_0053B560[i];
                    val = D_0053B560[i].val;
                    ret = 1;
                    break;
                }
            }
        }
    }
    if (!ret) e->slot = 0;
    if (out) *out = val;
    return ret;
}
