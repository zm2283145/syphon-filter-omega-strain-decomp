/*
 * main/weapon: range (3 files, 00146040-001468E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00146040 */
#pragma push /* merge_units */
#pragma cplusplus on
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0049B1D0[];
extern char *D_00489CC0[];
#if 0 /* merge_units */
extern "C" void Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */

#if 0 /* merge_units */
extern "C" void Alloc_Unlock(int);
#endif /* merge_units */
#define Alloc_Unlock(a0) (Alloc_Unlock((a0))) /* merge_units */

extern "C" void *Mem_Alloc(int, int, char *, int);
struct Sub46 { char p[0x20]; Sub46() {} };
struct Obj46 {
    char p0[0x140];
    Sub46 sub[12];
    char p2C0[0x3E0 - 0x2C0];
    float mn[4];
    float mx[4];
    char p400[0x20];
    Obj46() { mn[0] = 3.4028235e38f; mn[1] = 3.4028235e38f; mn[2] = 3.4028235e38f; mn[3] = 1.0f; mx[0] = -3.4028235e38f; mx[1] = -3.4028235e38f; mx[2] = -3.4028235e38f; mx[3] = 1.0f; }
    void *operator new(unsigned int sz, int line) { void *o; if (D_00533880) Alloc_Lock(9); D_00533888++; o = Mem_Alloc(0, sz, D_0049B1D0, line); if (D_00533880) Alloc_Unlock(9); D_00533888--; return o; }
};
typedef struct { char p0[4]; int f4; } Tbl46;
typedef struct { char p0[0x148]; Tbl46 *f148; } Src46;
typedef struct { char p0[0xB8]; Obj46 *slot[7]; } Slot46;
extern "C" char *Archive_GetMemberName(Src46 *, int);
extern "C" int Hog_GetMemberInPlace(Src46 *, int);
extern "C" void ManModel_ctor(Obj46 *, char *, int, int, int, int, int, int);
extern "C" void ActorModel_LoadFromHog(Obj46 *, int);
extern "C" void WeaponDb_CloneModel(void *, Obj46 *, Obj46 *);

static inline int NameCmp_46(const char *a, const char *b)
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

#define OBJ46_NEW(o, line) do { if (D_00533880) Alloc_Lock(9); D_00533888++; o = (Obj46 *)Mem_Alloc(0, 0x420, D_0049B1D0, line); if (D_00533880) Alloc_Unlock(9); D_00533888--; o = new (o) Obj46; } while (0)

extern "C" void WeaponDb_LoadShellsArchive(Slot46 *self, Src46 *src)
{
    int n __attribute__((aligned(32))) = src->f148->f4;
    int i;
    for (i = 0; i < n; i++) {
        int found = 0;
        char *name = Archive_GetMemberName(src, i);
        int x = Hog_GetMemberInPlace(src, i);
        int k;
        for (k = 0; k < 7; k++) {
            if (NameCmp_46(D_00489CC0[k], name) == 0) {
                self->slot[k] = new (0x293) Obj46;
                ManModel_ctor(self->slot[k], D_00489CC0[k], k, 0, 0, 0, 0, 0);
                ActorModel_LoadFromHog(self->slot[k], x);
                found = 1;
            }
        }
        if (!found) {
            Obj46 *t = new (0x2B4) Obj46;
            ManModel_ctor(t, name, 0, 0, 0, 0, 0, 0);
            ActorModel_LoadFromHog(t, x);
            WeaponDb_CloneModel(self, t, t);
            if (D_00533880) Alloc_Lock(9);
            D_00533888++;
            Mem_Free(0, t, D_0049B1D0, 0x2BC);
            if (D_00533880) Alloc_Unlock(9);
            D_00533888--;
        }
    }
}
#undef Alloc_Lock /* merge_units */
#undef Alloc_Unlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00146040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00146040 */

/* merge_units: begin func_00146460 */
#pragma push /* merge_units */
#pragma inline_depth(8)
#pragma cplusplus on
typedef struct { char p0[0x418]; unsigned char f418; char p419[3]; int f41C; } Blk64;
typedef struct { char name[0x11C]; Blk64 *f11C; char name2[0x1C]; Blk64 *f13C; } Ent64;
typedef struct { char p0[4]; int f4; } Cnt64;
typedef struct { char p0[4]; Cnt64 *f4; char p8[0xC]; Ent64 *f14; } Wpn64;
extern "C" void ActorModel_Release(Blk64 *);

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
            if (!cnt) ActorModel_Release(e->f13C);
            { Blk64 *p = e->f13C; cnt++; FREE64(p, 0x270); }
            e->f13C = 0;
        }
        if (!NameCmp_64(name, e->name2)) {
            if (!cnt) ActorModel_Release(e->f11C);
            { Blk64 *p = e->f11C; cnt++; FREE64(p, 0x279); }
            e->f11C = 0;
        }
    }
}
extern "C" void WeaponDb_FreeModel(Wpn64 *w, char *name)
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00146460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00146460 */

/* merge_units: begin func_001468E0 */
#pragma push /* merge_units */
#define NULL 0
typedef struct { int q[0x107]; int f41C; } __attribute__((aligned(16))) Blk;
typedef struct { char pad[0x404]; int f404; unsigned short f408; short f40A; char p40C; unsigned char f40D; unsigned char f40E; char p40F[10]; unsigned char f419; char p41A[2]; int f41C; } BlkV;
typedef struct { char name[0xCC]; unsigned char fCC; char pCD[0x3B]; unsigned char f108; char p109[3]; int f10C; char p110[0xC]; BlkV *f11C; char name2[0x1C]; BlkV *f13C; } Ent;
typedef struct { int f0; unsigned short f4; } Res;
typedef struct { char p0[4]; int *f4; char p8[0xC]; Ent *f14; } Wpn;
Res *WeaponDb_GetShellRecord(Wpn *, int, int);

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

void WeaponDb_PropagateModel(Wpn *w, char *name, Blk *src) {
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
            r = WeaponDb_GetShellRecord(w, e->f10C, save);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001468E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001468E0 */
