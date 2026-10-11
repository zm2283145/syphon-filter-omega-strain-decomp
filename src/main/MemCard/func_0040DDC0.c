#include "types.h"
typedef struct { char pad0[0x1C]; char item[0x1C]; } EDDC0;
typedef struct { EDDC0 e[0x540 / 0x38]; int mode; char pad1[0x560 - 0x544]; int count; int sel; char pad2[0x57C - 0x568]; char name[0x59C - 0x57C]; unsigned char failed; unsigned char pad3; unsigned char ok; unsigned char pad4; unsigned char done; } PDDC0;
typedef struct { PDDC0* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } CDDC0;
extern int func_0040E370(void* key, void* item);
extern void String_Copy(void* dst, void* src);
extern int func_0040E5D0(PDDC0* p);
static inline int dDC0find(PDDC0* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((func_0040E370(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* Selects the entry matching key, stores its name and runs the state machine until it settles. */
int func_0040DDC0(CDDC0* c, void* key, void* name) {
    PDDC0* p = c->p;
    int i = dDC0find(p, key);
    if (i >= 0)
        String_Copy(p->name, name);
    p->sel = i;
    p->mode = 9;
    p->done = 0;
    do {
        c->busy = func_0040E5D0(c->p) != 0;
        if (!c->busy)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    return c->p->failed == 0;
}
