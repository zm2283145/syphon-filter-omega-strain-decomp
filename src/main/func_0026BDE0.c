#include "types.h"
typedef struct { unsigned char type; int a; float f; int b; int c; int id; unsigned char used; } C4Slot26B;
extern C4Slot26B D_004FEED0[][6];
extern int D_0048B270;
int func_0026BDE0(int idx, unsigned char type, int a, int b, float f) {
    int i;
    for (i = 0; i < 6; i++) {
        C4Slot26B* s = &D_004FEED0[idx][i];
        if (!s->used) {
            int id;
            s->used = 1;
            s->type = type;
            s->a = a;
            s->f = f;
            s->b = b;
            s->c = 0;
            id = D_0048B270++;
            s->id = id;
            return s->id;
        }
    }
    return 0;
}