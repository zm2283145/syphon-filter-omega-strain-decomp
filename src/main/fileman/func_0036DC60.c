#include "types.h"
typedef struct { char* p0; int p4; char* p8; unsigned char c; } H36DC60;
typedef struct { char pad[0x14C]; unsigned char mode; } D36DC60;
typedef struct { unsigned int flags; char pad[0x80]; short idx; H36DC60 h; char* a98; } S36DC60;
int func_003694D0(void*, void*);
char* func_0036CAB0(void*);
void func_0036CB90(void*, int, int);
char* func_0036D4E0(void*, int);
static inline char* Get(H36DC60* h) { return h->p8 ? h->p8 : h->p0; }
char* FileMan_ReadData(S36DC60* o)
{
    unsigned int f = o->flags;
    H36DC60* h = &o->h;
    if ((f & 4) && h->c) return Get(h);
    if (f & 2) {
        D36DC60* d = (D36DC60*)o->a98;
        if (d->mode == 2) {
            if (h->c) return Get(h);
            func_0036CB90(d, o->idx, 0);
            return func_0036CAB0(o->a98);
        }
        return func_0036D4E0(d, o->idx);
    }
    if (f & 1) return func_003694D0(o->a98, h) ? *(char**)(o->a98 + 0xC4) : 0;
    return 0;
}

