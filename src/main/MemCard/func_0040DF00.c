#include "types.h"
#include "SFOLobby_helpers.h"

typedef struct { char pad0[0x14]; int size; char pad18[4]; char item[0x1C]; } EDF00;
typedef struct { EDF00 e[0x540 / 0x38]; int mode; char pad1[0x558 - 0x544]; void* buf; char pad55C[4]; int count; int sel; char pad2[0x59C - 0x568]; unsigned char failed; unsigned char pad3; unsigned char ok; unsigned char pad4; unsigned char done; } PDF00;
typedef struct { PDF00* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } CDF00;
extern int MemCard_MemCardMain(PDF00* p);
extern int MemCardWrap_MatchName(void* key, void* item);

static inline int df00find(PDF00* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((MemCardWrap_MatchName(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* Selects the entry matching key and reads it into buf when bufSize can hold it. */
int MemCardWrap_Read(CDF00* c, void* key, void* buf, int bufSize) {
    PDF00* p;
    int i = df00find(c->p, key);
    if (i < 0)
        return 0;
    p = c->p;
    if (bufSize < p->e[i].size)
        return 0;
    p->sel = i;
    c->p->buf = buf;
    p = c->p;
    p->mode = 5;
    p->done = 0;
    c->state = 3;
    do {
        c->busy = MemCard_MemCardMain(c->p) != 0;
        if (!c->busy)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    return c->p->failed == 0;
}
