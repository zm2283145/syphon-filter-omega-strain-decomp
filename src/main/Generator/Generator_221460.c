/*
 * main/Generator: range (3 files, 00221460-00221610)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "net_local_id.h"

/* merge_units: begin func_00221460 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; char f0C[4]; } Gen00221460;
extern unsigned char D_005721C8;
extern void Object_Deactivate(Gen00221460* self, int a);
extern void func_0043B190(void* msg);
extern void func_0043A030(void* msg, void* target);
void cGenerator_v16(Gen00221460* self)
{
    Object_Deactivate(self, 0);
    if (D_005721C8) {
        int msg[1];
        func_0043B190(msg);
        func_0043A030(msg, self->f0C);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00221460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00221460 */

/* merge_units: begin func_002214B0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
typedef struct { char pad[0xC]; char key[0x20]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x9D]; unsigned int maskCC; } Gen_12D0;
extern "C" {
void func_003CE810(void);
void Object_Activate(void* o, int on);
#if 0 /* merge_units */
void func_0043B190(void* ctx);
#endif /* merge_units */
#define func_0043B190(a0) (func_0043B190((a0))) /* merge_units */

int func_0043AB20(void* ctx, void* key);
void func_00439D00(void* ctx, void* key, int id);
void func_0043A420(void* ctx, void* key);
}
extern "C" void cGenerator_v15(Gen_12D0* g)
{
    char ctx[4];
    Object_Activate(g, 0);
    if (D_005721C8) {
    int ok = g->b2D != 0;
    ok = ok ? g->b2C != 0 : ok;
    ok = ok ? (g->b2E != 0) ^ 1 : ok;
    if (ok) {
        func_0043B190(ctx);
        if ((g->maskCC & (1 << NetLocalId())) && func_0043AB20(ctx, g->key) == 0) {
            void* key = g->key;
            func_00439D00(ctx, key, NetLocalId());
        }
        func_0043A420(ctx, g->key);
    }
    }
}
#undef func_0043B190 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002214B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002214B0 */

/* merge_units: begin func_00221610 */
#pragma push /* merge_units */
#pragma cplusplus on
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
struct Ctl_221610 {
    V5(a) V5(b) V5(c) V5(d)
    virtual int IsPlayer(); /* +0x58 */
};
struct Tgt_221610 {
    V5(a) virtual void b0(); virtual void b1();
    virtual void Deactivate(); /* +0x24 */
    V5(c) V5(d) virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
    virtual void Kill(int f); /* +0x60 */
    V5(f) V5(g) V5(h) V5(i) V5(j) V5(k) V5(l) V5(m) virtual void n0();
    virtual unsigned char State(); /* +0x108 */
    int magic;
    int pad8;
    int id;
    char pad10[0x48];
    Ctl_221610* ctl;
};
struct Hnd_221610 { Tgt_221610* p; int id; };
struct It_221610 { void* n; };
struct List_221610 { int size; void* head[2]; };
struct Gen_221610 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void Enable(int f);   /* +0x28 */
    virtual void Disable(int f);  /* +0x2C */
    V5(b) V5(c) virtual void d0(); virtual void d1(); virtual void d2();
    virtual void EnableNet(int f);  /* +0x64 */
    virtual void DisableNet(int f); /* +0x68 */
    char pad4[0x8C];
    List_221610 list90;
    List_221610 list9C;
    char padA8[0x10];
    float fB8;
    char padBC[4];
    int nC0;
    char padC4[0xD];
    unsigned char bD1;
    unsigned char bD2;
};
struct Ev_221610 { void* vt; char pad4[0x20]; int arg; unsigned char kind; };
struct Ev2_221610 { void* vt; char pad4[0x28]; int id; };
extern "C" {
extern int D_005435A8;
extern int D_004A4A68;
extern int D_0051F058;
extern int D_0051F068;
extern int D_004A4A78;
extern int g_cEnableMsgClass;
extern int g_cDisableMsgClass;
extern int D_005383C8;
extern int D_004F56C0;
extern int D_004FFD44;
extern char D_00555070[];
extern unsigned char D_005721C0;
int* Event_GetType(void* ev);
#if 0 /* merge_units */
void func_0043B190(void* ctx);
#endif /* merge_units */
#define func_0043B190(a0) (func_0043B190((a0))) /* merge_units */

void func_0021E0C0(Gen_221610* self, void* m);
Tgt_221610* Object_LookupById(int* id);
void* func_002204B0(It_221610* it);
void func_002204A0(It_221610* out, List_221610* l);
It_221610* func_00220490(It_221610* dst, It_221610* src);
void func_002203E0(It_221610* out, List_221610* l);
int func_002203C0(It_221610* a, It_221610* b);
Hnd_221610* func_00220480(It_221610* it);
int func_00220410(Hnd_221610* a, Hnd_221610* b);
It_221610* func_002203F0(It_221610* it);
It_221610* func_002203B0(It_221610* dst, It_221610* src);
void* func_0021E000(List_221610* l);
It_221610* func_0021DFE0(It_221610* it, void* n);
void func_00222880(It_221610* ret, List_221610* l, It_221610* pos);
void ActorWorld_RequestRemove(int a, Tgt_221610* o);
void Script_DropFromGroups(void* a, Tgt_221610* o);
void Object_DeleteLater(Tgt_221610* o, float f);
}
static inline bool IsType_221610(void* m, int* cls) { int t = *Event_GetType(m); return t == *cls; }
static inline bool IsDying_221610(Tgt_221610* o) { unsigned char s = o->State(); return s == 2 || s == 3; }
static inline int IsAuth_221610(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" bool cGenerator_v01(Gen_221610* self, void* msg)
{
    char ctx[4];
    int id;
    It_221610 found1;
    It_221610 found2;
    It_221610 ret2;
    It_221610 arg2;
    It_221610 ret1;
    It_221610 arg1;
    It_221610 endc1;
    It_221610 endc2;
    int none1;
    int none2;
    It_221610 it1;
    It_221610 beg1;
    It_221610 end1;
    It_221610 it2;
    It_221610 beg2;
    It_221610 end2;
    Hnd_221610 h1;
    Hnd_221610 h2;
    Ev_221610* m = (Ev_221610*)msg;
    bool r;
    if (IsType_221610(m, &D_005435A8)) {
        r = 1;
    } else if (IsType_221610(m, &D_004A4A68)) {
        if (m->kind == 1)
            func_0043B190(ctx);
        r = 1;
    } else if (IsType_221610(m, &D_0051F058)) {
        func_0021E0C0(self, m);
    } else if (IsType_221610(m, &D_0051F068)) {
        Tgt_221610* o;
        id = ((Ev2_221610*)m)->id;
        o = Object_LookupById(&id);
        if (o) {
            bool pl = 0;
            if (o->ctl && o->ctl->IsPlayer())
                pl = 1;
            if (pl)
                o->Kill(0);
            else
                o->Deactivate();
            {
                int* pid = &h1.id;
                *pid = -1;
                h1.p = o;
                *pid = *(o ? &o->id : (none1 = -1, &none1));
            }
            func_002204B0(&it1);
            func_002204A0(&beg1, &self->list90);
            func_00220490(&it1, &beg1);
            for (; func_002203E0(&end1, &self->list90), func_002203C0(&it1, &end1); func_002203F0(&it1)) if (func_00220410(func_00220480(&it1), &h1)) break; //
            func_002203B0(&found1, &it1);
            {
                void* f1 = found1.n;
                func_0021DFE0(&endc1, func_0021E000(&self->list90));
                if (f1 != endc1.n) {
                    if (self->list9C.size > 0) {
                        void* f2;
                        int* pid = &h2.id;
                        *pid = -1;
                        h2.p = o;
                        *pid = *(o ? &o->id : (none2 = -1, &none2));
                        func_002204B0(&it2);
                        func_002204A0(&beg2, &self->list9C);
                        func_00220490(&it2, &beg2);
                        for (; func_002203E0(&end2, &self->list9C), func_002203C0(&it2, &end2); func_002203F0(&it2)) if (func_00220410(func_00220480(&it2), &h2)) break; //
                        func_002203B0(&found2, &it2);
                        f2 = found2.n;
                        func_0021DFE0(&endc2, func_0021E000(&self->list9C));
                        if (f2 != endc2.n) {
                            arg2.n = f2;
                            func_00222880(&ret2, &self->list9C, &arg2);
                        }
                    }
                    {
                        if (!IsDying_221610(o) && !self->bD2)
                            self->nC0--;
                    }
                    arg1.n = f1;
                    func_00222880(&ret1, &self->list90, &arg1);
                }
            }
            ActorWorld_RequestRemove(D_004FFD44, o);
            Script_DropFromGroups(D_00555070, o);
            if (o->magic == (int)0xBEBAAFDE)
                Object_DeleteLater(o, 1.0f);
        }
        r = 1;
    } else if (IsType_221610(m, &D_004A4A78)) {
        unsigned char k = m->kind;
        if (k == 0) {
            self->bD1 = m->arg != 0;
        } else if (k == 1) {
            self->fB8 = m->arg;
        } else if (k == 2) {
            self->nC0 = 0;
        } else if (k == 3) {
            if (D_004F56C0 != D_005383C8)
                D_004F56C0 = D_005383C8;
        }
        r = 1;
    } else {
        if (IsType_221610(m, &g_cEnableMsgClass)) {
            if (!D_005721C8 || IsAuth_221610())
                self->EnableNet(m->arg);
            else
                self->Enable(m->arg);
        } else if (IsType_221610(m, &g_cDisableMsgClass)) {
            if (!D_005721C8 || IsAuth_221610())
                self->DisableNet(m->arg);
            else
                self->Disable(m->arg);
        }
        r = 1;
    }
    return r;
}
#undef func_0043B190 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00221610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00221610 */
