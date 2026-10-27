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
extern unsigned char g_IsMultiplayer;
extern void cGOBJ_Deactivate(Gen00221460* self, int a);
extern void cGenInfoObject_ctor(void* msg);
extern void cGenInfoObject_Deactivate(void* msg, void* target);
void cGenerator_Deactivate(Gen00221460* self)
{
    cGOBJ_Deactivate(self, 0);
    if (g_IsMultiplayer) {
        int msg[1];
        cGenInfoObject_ctor(msg);
        cGenInfoObject_Deactivate(msg, self->f0C);
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
void cGOBJ_NetActivate(void);
void cGOBJ_Activate(void* o, int on);
#if 0 /* merge_units */
void cGenInfoObject_ctor(void* ctx);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */

int cGenInfoObject_HasOwner(void* ctx, void* key);
void cGenInfoObject_SetOwner(void* ctx, void* key, int id);
void cGenInfoObject_Activate(void* ctx, void* key);
}
extern "C" void cGenerator_v15(Gen_12D0* g)
{
    char ctx[4];
    cGOBJ_Activate(g, 0);
    if (g_IsMultiplayer) {
    int ok = g->b2D != 0;
    ok = ok ? g->b2C != 0 : ok;
    ok = ok ? (g->b2E != 0) ^ 1 : ok;
    if (ok) {
        cGenInfoObject_ctor(ctx);
        if ((g->maskCC & (1 << NetLocalId())) && cGenInfoObject_HasOwner(ctx, g->key) == 0) {
            void* key = g->key;
            cGenInfoObject_SetOwner(ctx, key, NetLocalId());
        }
        cGenInfoObject_Activate(ctx, g->key);
    }
    }
}
#undef cGenInfoObject_ctor /* merge_units */
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
extern int g_LosResultMsgClass;
extern int D_004A4A68;
extern int D_0051F058;
extern int D_0051F068;
extern int D_004A4A78;
extern int g_cEnableMsgClass;
extern int g_cDisableMsgClass;
extern int g_VideoFrameCounter;
extern int D_004F56C0;
extern int g_ActorList;
extern char D_00555070[];
extern unsigned char D_005721C0;
int* cMessage_Name(void* ev);
#if 0 /* merge_units */
void cGenInfoObject_ctor(void* ctx);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */

void cGenerator_NetSpawn(Gen_221610* self, void* m);
Tgt_221610* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void* cLListIterator_cSafePtr_cGOBJ_ctor_void(It_221610* it);
void cLList_cSafePtr_cGOBJ_Begin(It_221610* out, List_221610* l);
It_221610* cLListIterator_cSafePtr_cGOBJ_opAssign(It_221610* dst, It_221610* src);
void cLList_cSafePtr_cGOBJ_End(It_221610* out, List_221610* l);
int opNe_cLListIteratorR_cLListIteratorR_3(It_221610* a, It_221610* b);
Hnd_221610* cLListIterator_cSafePtr_cGOBJ_opMul(It_221610* it);
int cSafePtr_cGOBJ_opEq(Hnd_221610* a, Hnd_221610* b);
It_221610* cLListIterator_cSafePtr_cGOBJ_opInc(It_221610* it);
It_221610* cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(It_221610* dst, It_221610* src);
void* std_list_deleter_cSafePtr_cGOBJ_tail(List_221610* l);
It_221610* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(It_221610* it, void* n);
void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(It_221610* ret, List_221610* l, It_221610* pos);
void cBaseObjList_Remove(int a, Tgt_221610* o);
void cScriptInterpreter_RemoveFromAllGroups(void* a, Tgt_221610* o);
void cSystem_ActualScheduleDelete(Tgt_221610* o, float f);
}
static inline bool IsType_221610(void* m, int* cls) { int t = *cMessage_Name(m); return t == *cls; }
static inline bool IsDying_221610(Tgt_221610* o) { unsigned char s = o->State(); return s == 2 || s == 3; }
static inline int IsAuth_221610(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" bool cGenerator_HandleMessage(Gen_221610* self, void* msg)
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
    if (IsType_221610(m, &g_LosResultMsgClass)) {
        r = 1;
    } else if (IsType_221610(m, &D_004A4A68)) {
        if (m->kind == 1)
            cGenInfoObject_ctor(ctx);
        r = 1;
    } else if (IsType_221610(m, &D_0051F058)) {
        cGenerator_NetSpawn(self, m);
    } else if (IsType_221610(m, &D_0051F068)) {
        Tgt_221610* o;
        id = ((Ev2_221610*)m)->id;
        o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
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
            cLListIterator_cSafePtr_cGOBJ_ctor_void(&it1);
            cLList_cSafePtr_cGOBJ_Begin(&beg1, &self->list90);
            cLListIterator_cSafePtr_cGOBJ_opAssign(&it1, &beg1);
            for (; cLList_cSafePtr_cGOBJ_End(&end1, &self->list90), opNe_cLListIteratorR_cLListIteratorR_3(&it1, &end1); cLListIterator_cSafePtr_cGOBJ_opInc(&it1)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it1), &h1)) break; //
            cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found1, &it1);
            {
                void* f1 = found1.n;
                std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&endc1, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
                if (f1 != endc1.n) {
                    if (self->list9C.size > 0) {
                        void* f2;
                        int* pid = &h2.id;
                        *pid = -1;
                        h2.p = o;
                        *pid = *(o ? &o->id : (none2 = -1, &none2));
                        cLListIterator_cSafePtr_cGOBJ_ctor_void(&it2);
                        cLList_cSafePtr_cGOBJ_Begin(&beg2, &self->list9C);
                        cLListIterator_cSafePtr_cGOBJ_opAssign(&it2, &beg2);
                        for (; cLList_cSafePtr_cGOBJ_End(&end2, &self->list9C), opNe_cLListIteratorR_cLListIteratorR_3(&it2, &end2); cLListIterator_cSafePtr_cGOBJ_opInc(&it2)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it2), &h2)) break; //
                        cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found2, &it2);
                        f2 = found2.n;
                        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&endc2, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list9C));
                        if (f2 != endc2.n) {
                            arg2.n = f2;
                            std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret2, &self->list9C, &arg2);
                        }
                    }
                    {
                        if (!IsDying_221610(o) && !self->bD2)
                            self->nC0--;
                    }
                    arg1.n = f1;
                    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret1, &self->list90, &arg1);
                }
            }
            cBaseObjList_Remove(g_ActorList, o);
            cScriptInterpreter_RemoveFromAllGroups(D_00555070, o);
            if (o->magic == (int)0xBEBAAFDE)
                cSystem_ActualScheduleDelete(o, 1.0f);
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
            if (D_004F56C0 != g_VideoFrameCounter)
                D_004F56C0 = g_VideoFrameCounter;
        }
        r = 1;
    } else {
        if (IsType_221610(m, &g_cEnableMsgClass)) {
            if (!g_IsMultiplayer || IsAuth_221610())
                self->EnableNet(m->arg);
            else
                self->Enable(m->arg);
        } else if (IsType_221610(m, &g_cDisableMsgClass)) {
            if (!g_IsMultiplayer || IsAuth_221610())
                self->DisableNet(m->arg);
            else
                self->Disable(m->arg);
        }
        r = 1;
    }
    return r;
}
#undef cGenInfoObject_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00221610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00221610 */
