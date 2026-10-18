#include "types.h"
#include "SFOLobby_helpers.h"

typedef struct { char pad0[0x14]; int size; short type; char pad1A[2]; char item[0x1C]; } E090;
typedef struct { E090 e[0x540 / 0x38]; int mode; char pad1[0x558 - 0x544]; void* buf; char pad55C[4]; int count; int sel; char pad2[0x59C - 0x568]; unsigned char failed; unsigned char pad3; unsigned char ready; unsigned char present; unsigned char done; } P090;
typedef struct { P090* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } C090;
extern int func_0040E5D0(P090* p);
extern int MemCardWrap_MatchName(void* key, void* item);

static inline int e090find(P090* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((MemCardWrap_MatchName(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
static inline int e090add(P090* p, void* key, int size) {
    if (p->count < 18) {
        if (e090find(p, key) < 0) {
            int k = p->count;
            String_Copy(p->e[k].item, key);
            p->e[k].size = size;
            p->e[k].type = 3;
            return k;
        }
    }
    return -1;
}
/* Writes buf as the entry matching key (creating it when absent); optionally waits for the state machine. */
int MemCardWrap_Write(C090* c, void* key, void* buf, int size, unsigned char wait) {
    P090* p = c->p;
    int i;
    int mode;
    int state;
    if (!p->ready || !p->present)
        return 0;
    i = e090find(p, key);
    mode = 3;
    state = 1;
    if (i < 0) {
        i = e090add(c->p, key, size);
    } else {
        c->p->e[i].size = size;
        mode = 4;
        state = 2;
    }
    if (i >= 0) {
    c->p->sel = i;
    c->p->buf = buf;
    p = c->p;
    p->mode = (unsigned char)mode;
    p->done = 0;
    c->state = state;
    if (wait) {
        do {
            c->busy = func_0040E5D0(c->p) != 0;
            if (!c->busy)
                c->state = 0;
            if (c->cb)
                c->cb();
        } while (!((c->busy != 0) ^ 1) || !c->p->done);
    }
    return c->p->failed == 0;
    }
    return 0;
}
