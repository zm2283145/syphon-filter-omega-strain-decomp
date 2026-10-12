#pragma cplusplus on
#include "types.h"
struct W_342FA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
    char pad4[0x44];
    void* f48;
};
typedef struct { char pad[0xA0]; char fA0[4]; } C_342FA0;
typedef struct { char pad[0xB70]; unsigned char bB70; } A_342FA0;
typedef struct {
    char pad[0x78]; W_342FA0* f78; W_342FA0* f7C; W_342FA0* f80; W_342FA0* f84; W_342FA0* f88; C_342FA0* f8C;
    char pad90[0x114 - 0x90];
    int f114; int f118; int f11C; int f120; int f124; int f128;
    W_342FA0* f12C; W_342FA0* f130; W_342FA0* f134; W_342FA0* f138; W_342FA0* f13C; W_342FA0* f140;
    W_342FA0* f144; W_342FA0* f148; W_342FA0* f14C; W_342FA0* f150; W_342FA0* f154;
} O_342FA0;
extern "C" {
extern char D_004B9F88[]; extern char D_004B9F90[]; extern char D_004B9F98[]; extern char D_004B9FA0[]; extern char D_004B9FA8[]; extern char D_004B9FB0[];
extern char D_004B9FB8[]; extern char D_004B9FC0[]; extern char D_004B9FD0[]; extern char D_004B9FD8[]; extern char D_004B9FE8[]; extern char D_004B9FF8[];
extern char D_004B9F58[]; extern char D_004B9F50[]; extern char D_004B9F60[]; extern char D_004B9F68[];
char D_004BA000[] = "createagent_grp"; extern char D_004BA010[]; extern char D_004BA020[]; extern char D_004BA030[]; extern char D_004BA038[]; extern char D_004BA048[];
extern char D_004BA060[]; extern char D_004BA070[]; extern char D_004BA080[]; extern char D_004BA090[]; extern char D_004BA098[]; extern char D_004B9F20[];
extern char D_004A9870[]; extern char D_004A9C40[]; extern char D_004A7520[]; extern char D_004B88F0[]; extern char D_004A9BF0[];
extern char D_004FFB50[];
extern O_342FA0* D_005331D0;
void func_0041F150(O_342FA0* o);
int Appearance_FindPairByType(void* p, char* name);
void func_003437C0(O_342FA0* o, int v);
void func_00343680(O_342FA0* o, int v);
W_342FA0* func_0041DB80(void* o, char* name);
void func_00341170(O_342FA0* o, W_342FA0* w);
void func_00345020(void);
A_342FA0* Agent_GetSelected(void* p, int i);
char* func_00336170(A_342FA0* a);
char* func_00336110(A_342FA0* a);
void func_0041BEB0(W_342FA0* w, char* s, int f);
int Loc_FindKeyThunk(char* k);
char* Loc_GetTextById(int id);
void func_00340850(O_342FA0* o);
void func_00342FA0(O_342FA0* o);
}
static inline W_342FA0* Cast_342FA0(W_342FA0* w, void* t) { return w && w->IsA(t) ? w : 0; }

void func_00342FA0(O_342FA0* o)
{
    W_342FA0* p;
    W_342FA0* a;
    W_342FA0* b;
    func_0041F150(o);
    o->f114 = Appearance_FindPairByType(o->f8C->fA0, D_004B9F88);
    o->f118 = Appearance_FindPairByType(o->f8C->fA0, D_004B9F90);
    o->f11C = Appearance_FindPairByType(o->f8C->fA0, D_004B9F98);
    o->f120 = Appearance_FindPairByType(o->f8C->fA0, D_004B9FA0);
    o->f124 = Appearance_FindPairByType(o->f8C->fA0, D_004B9FA8);
    o->f128 = Appearance_FindPairByType(o->f8C->fA0, D_004B9FB0);
    func_003437C0(o, o->f120);
    func_003437C0(o, o->f124);
    func_00343680(o, o->f128);
    o->f12C = Cast_342FA0(func_0041DB80(o, D_004B9FB8), D_004A9870);
    o->f130 = Cast_342FA0(func_0041DB80(o, D_004B9FC0), D_004A9870);
    o->f134 = Cast_342FA0(func_0041DB80(o, D_004B9FD0), D_004A9870);
    o->f138 = Cast_342FA0(func_0041DB80(o, D_004B9FD8), D_004A9870);
    o->f13C = Cast_342FA0(func_0041DB80(o, D_004B9FE8), D_004A9870);
    o->f140 = Cast_342FA0(func_0041DB80(o, D_004B9FF8), D_004A9870);
    o->f144 = Cast_342FA0(func_0041DB80(o, D_004B9F58), D_004A9870);
    o->f148 = Cast_342FA0(func_0041DB80(o, D_004B9F50), D_004A9870);
    o->f14C = Cast_342FA0(func_0041DB80(o, D_004B9F60), D_004A9870);
    o->f150 = Cast_342FA0(func_0041DB80(o, D_004B9F68), D_004A9870);
    o->f154 = func_0041DB80(o, D_004BA000);
    o->f78 = Cast_342FA0(func_0041DB80(o, D_004BA010), D_004A9C40);
    o->f7C = Cast_342FA0(func_0041DB80(o, D_004BA020), D_004A7520);
    o->f88 = Cast_342FA0(func_0041DB80(o, D_004BA030), D_004A9870);
    o->f80 = Cast_342FA0(func_0041DB80(o, D_004BA038), D_004B88F0);
    o->f84 = Cast_342FA0(func_0041DB80(o, D_004BA048), D_004A7520);
    func_00341170(o, o->f144);
    func_00341170(o, o->f148);
    func_00341170(o, o->f14C);
    func_00341170(o, o->f150);
    p = Cast_342FA0(func_0041DB80(o, D_004BA060), D_004A9BF0);
    if (p) {
        D_005331D0 = o;
        p->f48 = (void*)func_00345020;
    }
    a = Cast_342FA0(func_0041DB80(o, D_004BA070), D_004A7520);
    b = Cast_342FA0(func_0041DB80(o, D_004BA080), D_004A7520);
    if (Agent_GetSelected(D_004FFB50, -1)->bB70) {
        func_0041BEB0(a, func_00336170(Agent_GetSelected(D_004FFB50, -1)), 0);
        func_0041BEB0(b, func_00336110(Agent_GetSelected(D_004FFB50, -1)), 0);
    } else {
        func_0041BEB0(a, D_004BA090, 0);
        func_0041BEB0(b, Loc_GetTextById(Loc_FindKeyThunk(D_004BA098) + 1), 0);
    }
    if (o->f7C) func_0041BEB0(o->f7C, D_004B9F20, 0);
    func_00340850(o);
}