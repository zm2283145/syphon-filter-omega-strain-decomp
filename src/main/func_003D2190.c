#include "types.h"
typedef struct { char p0[0x22]; unsigned short frames; } Anim3D2190;
typedef struct { char p0[0x44]; Anim3D2190* anim; char p48[4]; int frame; char p50[0x10]; signed char f60; signed char f61; } Tex3D2190;
typedef struct { int idx; char p4[0x10]; unsigned int count; char p18[0x10]; int cur; } Ent3D2190;
typedef struct { char p0[8]; Tex3D2190** list; } Mgr3D2190;
extern int func_00379740(int, int);
extern int func_003797D0(char*);
extern int func_003D20F0(int*, int);
extern void func_003D2110(int*, int);
extern void func_003D2120(int*);
extern int func_003D2140(int);
extern int func_003D2150(Ent3D2190*);
extern Ent3D2190** func_003D2160(int*);
extern int func_003D2170(int*, int*);
extern void func_003D2180(int*, int);
extern int strcmp(int, int);
extern char D_005381F0[];
extern Mgr3D2190* D_00539248;
#pragma push
#pragma opt_common_subs off
void Global_DecTexture(int list, int name)
{
    int it[1];
    int b[1];
    int e[1];
    int a[1];
    Ent3D2190* found;
    Ent3D2190* ent;
int db;
    unsigned int n;
    Tex3D2190* t;

    found = 0;
    func_003D2180(b, list);
    func_003D2170(it, b);
    func_003D2110(a, list);
    while (func_003D20F0(it, func_003D2170(e, a)) != 0) {
        ent = *func_003D2160(it);
        db = func_003797D0(D_005381F0);
        if (strcmp(func_003D2140(func_00379740(db, func_003D2150(ent))), name) == 0) {
            found = ent;
            break;
        }
        func_003D2120(it);
        func_003D2110(a, list);
    }
    if (found != 0) {
        n = found->cur - 1;
        if (n < found->count) {
            t = D_00539248->list[found->idx];
            if (n != t->frame && n < t->anim->frames) {
                t->f60 = 0;
                t->f61 = 0;
                t->frame = n;
            }
            found->cur = n;
        }
    }
}
#pragma pop
