#include "types.h"
#define NULL 0
typedef struct { int q[0x107]; int f41C; } __attribute__((aligned(16))) Blk;
typedef struct { char pad[0x404]; int f404; unsigned short f408; short f40A; char p40C; unsigned char f40D; unsigned char f40E; char p40F[10]; unsigned char f419; char p41A[2]; int f41C; } BlkV;
typedef struct { char name[0xCC]; unsigned char fCC; char pCD[0x3B]; unsigned char f108; char p109[3]; int f10C; char p110[0xC]; BlkV *f11C; char name2[0x1C]; BlkV *f13C; } Ent;
typedef struct { int f0; unsigned short f4; } Res;
typedef struct { char p0[4]; int *f4; char p8[0xC]; Ent *f14; } Wpn;
Res *func_00147880(Wpn *, int, int);

static inline int Cmp(char *a, char *b) {
    int ca, cb;
    int d;
    for (;;) {
        ca = *a;
        cb = *b;
        if (ca == '.') ca = 0;
        if (ca >= 'a' && ca <= 'z') ca -= 0x20;
        if (cb == '.') cb = 0;
        if (cb >= 'a' && cb <= 'z') cb -= 0x20;
        d = ca - cb;
        if (d != 0) {
            return d;
        } else {
            if (ca == 0) return 0;
            a++;
            b++;
        }
    }
}

#pragma opt_rotateloops off
#pragma opt_strength_reduction off
static inline void QCopy(void *dd, void *ss, int nn) {
    int n = nn; void *d = dd; __int128 t; void *s = ss;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 16
        addi n, n, -1
        addiu s, s, 16
        bgtz n, lp
        sq t, -16(d)
        .set reorder
    }
}

void func_001468E0(Wpn *w, char *name, Blk *src) {
    int n = w->f4[1];
    int i = 0;
    while (i < n) {
        Ent *e = &w->f14[i];
        if (Cmp(name, e->name) == 0) {
            BlkV *b = e->f13C;
            int save;
            Res *r;
            if ((Blk *)b == src) goto next;
            save = b->f41C;
            QCopy(b, src, 66);
            e->f13C->f41C = save;
            e->f13C->f40A = i;
            e->f13C->f40D = e->fCC;
            e->f13C->f40E = e->f108;
            r = func_00147880(w, e->f10C, save);
            if (r != NULL) {
                e->f13C->f404 = r->f0;
                e->f13C->f408 = r->f4;
            }
        }
        if (Cmp(name, e->name2) == 0) {
            int save;
            BlkV *b = e->f11C;
            if ((Blk *)b != src) {
                save = b->f41C;
                QCopy(b, src, 66);
                e->f11C->f41C = save;
                e->f11C->f40A = i;
                e->f11C->f419 = 1;
            }
        }
        next:
        i++;
    }
}
