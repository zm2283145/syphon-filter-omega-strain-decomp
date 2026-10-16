/*
 * main/weapon: range (2 files, 00146B80-00146FC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_00146B80 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_0049B1D0[];
extern void *Mem_Alloc(int, int, char *, int);
}
struct Sub6B { char p[0x20]; };
struct Blk6B {
    char p0[0x140];
    Sub6B sub[12];
    char p2C0[0x3E0 - 0x2C0];
    int mn[4];
    int mx[4];
    int f400;
    int f404;
    unsigned short f408;
    short f40A;
    char p40C;
    unsigned char f40D;
    unsigned char f40E;
    char p40F[10];
    unsigned char f419;
    char p41A[2];
    int f41C;
    Blk6B() { Sub6B *p = sub; Sub6B *pe = sub + 12; do { p++; } while (p != pe); mn[0] = 0x7F7FFFFF; mn[1] = 0x7F7FFFFF; mn[2] = 0x7F7FFFFF; mn[3] = 0x3F800000; mx[0] = 0xFF7FFFFF; mx[1] = 0xFF7FFFFF; mx[2] = 0xFF7FFFFF; mx[3] = 0x3F800000; }
    void *operator new(unsigned int sz, int line) { AllocGuard g; return Mem_Alloc(0, sz, D_0049B1D0, line); }
};
typedef struct { char name[0xCC]; unsigned char fCC; char pCD[0x3B]; unsigned char f108; char p109[3]; int f10C; char p110[0xC]; Blk6B *f11C; char name2[0x1C]; Blk6B *f13C; } Ent6B;
typedef struct { int f0; unsigned short f4; } Res6B;
typedef struct { char p0[4]; int *f4; char p8[0xC]; Ent6B *f14; } Wpn6B;
extern "C" Res6B *WeaponDb_GetShellRecord(Wpn6B *, int);

static inline int Cmp6B(char *a, char *b) {
    int ca, cb;
    int d;
    int dot;
    asm { .set reorder }
    dot = '.';
    for (;;) {
        ca = *a;
        cb = *b;
        if (ca == dot) ca = 0;
        if (ca >= 'a' && ca <= 'z') ca -= 0x20;
        if (cb == dot) cb = 0;
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
static inline void QCopy6B(void *dd, void *ss, int nn) {
    void *d = dd; int n = nn; __int128 t; void *s = ss;
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

#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_dead_assignments off
extern "C" int WeaponDb_CloneModel(Wpn6B *w, char *name, void *src) {
    int cnt = 0;
    int n = w->f4[1];
    int i = 0;
    while (i < n) {
        int off = i * (int)sizeof(Ent6B);
        Ent6B *e = (Ent6B *)((char *)w->f14 + off);
        if (Cmp6B(name, e->name) == 0) {
            Res6B *r;
            e->f13C = new (0x1F5) Blk6B;
            QCopy6B(e->f13C, src, 66);
            e->f13C->f40A = i;
            e->f13C->f40D = e->fCC;
            e->f13C->f40E = e->f108;
            r = WeaponDb_GetShellRecord(w, e->f10C);
            if (r != 0) {
                e->f13C->f404 = r->f0;
                e->f13C->f408 = r->f4;
            }
            cnt++;
        }
        if (Cmp6B(name, e->name2) == 0) {
            e->f11C = new (0x208) Blk6B;
            QCopy6B(e->f11C, src, 66);
            cnt++;
            e->f11C->f40A = i;
            e->f11C->f419 = 1;
        }
        i++;
    }
    return cnt;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00146B80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00146B80 */

/* merge_units: begin func_00146FC0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40A]; short f40A; char p40C[0xB]; signed char f417; char p418; unsigned char f419; } BlkV;
typedef struct { char p0[0x11C]; BlkV *f11C; char p120[0x18]; unsigned char f138; char p139[3]; BlkV *f13C; } Ent;
typedef struct { char p0[0x14]; Ent *f14; } Wpn;
extern void func_0038CD90(BlkV* b, int x);
extern void WeaponDb_PropagateModel(Wpn* w, BlkV* name, BlkV* src);
extern void WeaponDb_FreeModel(Wpn* w, BlkV* b);
void WeaponDb_OnModelLoaded(Wpn* w, BlkV* b, int x)
{
    short idx = b->f40A;
    unsigned char kind = b->f419;
    if (idx == -1) {
        if (b->f417 == -1) {
            func_0038CD90(b, x);
            WeaponDb_PropagateModel(w, b, b);
        } else {
            WeaponDb_FreeModel(w, b);
        }
        return;
    }
    {
        Ent* e = &w->f14[idx];
        if (!kind) {
            if (e->f13C) {
                if (e->f13C->f417 == -1) {
                    func_0038CD90(e->f13C, x);
                    WeaponDb_PropagateModel(w, b, b);
                } else {
                    WeaponDb_FreeModel(w, e->f13C);
                    e->f13C = 0;
                }
            }
        } else {
            if (e->f11C && e->f138) {
                if (e->f11C->f417 == -1) {
                    func_0038CD90(e->f11C, x);
                    WeaponDb_PropagateModel(w, b, b);
                } else {
                    WeaponDb_FreeModel(w, e->f11C);
                    e->f11C = 0;
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00146FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00146FC0 */
