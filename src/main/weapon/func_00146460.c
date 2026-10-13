#pragma inline_depth(8)
#pragma cplusplus on
#include "alloc_guard.h"
#include "types.h"
typedef struct { char p0[0x418]; unsigned char f418; char p419[3]; int f41C; } Blk64;
typedef struct { char name[0x11C]; Blk64 *f11C; char name2[0x1C]; Blk64 *f13C; } Ent64;
typedef struct { char p0[4]; int f4; } Cnt64;
typedef struct { char p0[4]; Cnt64 *f4; char p8[0xC]; Ent64 *f14; } Wpn64;
extern char D_0049B1D0[];
extern "C" void Mem_Free(int, void *, char *, int);
extern "C" void func_0038CC70(Blk64 *);

static inline int NameCmp_64(const char *a, const char *b)
{
    for (;;) {
        int ca = *a;
        int cb = *b;
        int d;
    if (ca == '.') ca = 0;
    if (ca >= 'a' && ca <= 'z') ca -= 0x20;
    if (cb == '.') cb = 0;
    if (cb >= 'a' && cb <= 'z') cb -= 0x20;
        d = ca - cb;
    if (d) return d;
    if (!ca) return 0;
        a++;
        b++;
    }
}

#define FREE64(p, line) { AllocGuard g; Mem_Free(0, p, D_0049B1D0, line); }

static inline void FreeAll(Wpn64 *w, char *name, int n, int& cnt)
{
    int i = 0;
    for (; i < n; i++) {
        Ent64 *e = &w->f14[i];
        if (!NameCmp_64(name, e->name)) {
            if (!cnt) func_0038CC70(e->f13C);
            { Blk64 *p = e->f13C; cnt++; FREE64(p, 0x270); }
            e->f13C = 0;
        }
        if (!NameCmp_64(name, e->name2)) {
            if (!cnt) func_0038CC70(e->f11C);
            { Blk64 *p = e->f11C; cnt++; FREE64(p, 0x279); }
            e->f11C = 0;
        }
    }
}
extern "C" void func_00146460(Wpn64 *w, char *name)
{
    int cnt;
    char* const nm = name; /* const copy: keeps its own register (s3) */
    int total = 0;
    int n = w->f4->f4;
    int i;
    for (i = 0; i < n; i++) {
    Ent64 *e = &w->f14[i];
    if (!NameCmp_64(nm, e->name)) {
        total += e->f13C->f41C;
        if (!e->f13C->f418) return;
    }
    if (!NameCmp_64(nm, e->name2)) {
        total += e->f11C->f41C;
        if (!e->f11C->f418) return;
    }
    }
    if (total > 0) return;
    cnt = 0;
    FreeAll(w, nm, n, cnt);
}

