#include "types.h"
typedef struct { char pad0[0x1C]; char item[0x1C]; } EDC80;
typedef struct { EDC80 e[0x540 / 0x38]; int mode; char pad1[0x560 - 0x544]; int count; int sel; char pad2[0x59C - 0x568]; unsigned char failed; unsigned char pad3; unsigned char ok; unsigned char pad4; unsigned char done; } PDC80;
typedef struct { PDC80* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } CDC80;
extern int MemCardWrap_MatchName(void* key, void* item);
extern int func_0040E5D0(PDC80* p);
static inline int dc80find(PDC80* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((MemCardWrap_MatchName(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* Selects the entry matching key and runs the state machine until it settles. */
int func_0040DC80(CDC80* c, void* key) {
    PDC80* p;
    int i = dc80find(c->p, key);
    if (i < 0)
        return 0;
    c->p->sel = i;
    p = c->p;
    p->mode = 6;
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