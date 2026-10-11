#include "types.h"
typedef struct { char pad0[0x540]; int mode; char pad1[0x59E - 0x544]; unsigned char ok; unsigned char pad2; unsigned char done; } PDB10;
typedef struct { PDB10* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } CDB10;
extern int func_0040E5D0(PDB10* p);
/* Runs the session state machine until it settles; returns its result flag. */
int func_0040DB10(CDB10* c) {
    PDB10* p = c->p;
    p->mode = 1;
    p->done = 0;
    c->state = 5;
    do {
        c->busy = func_0040E5D0(c->p) != 0;
        if (!c->busy)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    return c->p->ok != 0;
}
