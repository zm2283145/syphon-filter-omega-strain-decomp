#pragma cplusplus on
#include "types.h"
struct V2BE { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual void v21(int, int); };
typedef struct { char pad[0x14]; unsigned short flags; } W2BE;
typedef struct { void* vt; char pad[0x10]; unsigned short flags; char pad2[0x6B]; unsigned char b81; char p82[6]; W2BE* f88; } L2BE;
typedef struct { char pad[0x94]; L2BE* f94; char p98[0x10]; int fa8; char pad2[0x20]; W2BE* fcc; char pad3[0x34]; int f104; int f108; short h10c[1]; } O2BE;
typedef struct { char pad[0x80]; char name[4]; } WD2BE;
extern "C" {
extern void func_00421070(L2BE*);
extern void func_004235B0(L2BE*, int, int);
extern void func_00424430(L2BE*, int, int);
extern int D_004FFD30;
extern WD2BE* WeaponDb_Get(int, int);
extern char* Loc_LookupText(char*);
extern void func_00421290(L2BE*, char*, int, int);
}
extern "C" void func_002BEEE0(O2BE* o) {
    int i;
    func_00421070(o->f94);
    ((V2BE*)o->f94)->v21(1, o->f104 + 1);
    if (o->f104 >= o->fa8) func_004235B0(o->f94, 1, o->fa8);
    else func_004235B0(o->f94, 1, o->f104 + 1);
    func_00424430(o->f94, 0, (int)(void*)o->f108);
    o->f94->b81 = 1;
    o->f94->f88 = o->fcc;
    o->fcc->flags &= ~2;
    for (i = 0; i < o->f104; i++) {
        WD2BE* w = WeaponDb_Get(D_004FFD30, o->h10c[i]);
        char* t = Loc_LookupText(w->name);
        if (t) func_00421290(o->f94, t, i, 0);
        else func_00421290(o->f94, w->name, i, 0);
    }
    func_00421290(o->f94, Loc_LookupText("NoneOption"), i, 0);
    func_00424430(o->f94, 0, (int)(void*)o->f108);
    o->fcc->flags &= ~0x80;
    o->f94->flags &= ~0x80;
}
