/*
 * main/hud: range (3 files, 00245810-002458E0)
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

/* merge_units: begin func_00245810 */
#pragma push /* merge_units */
typedef struct { char pad[0x6DC]; float a; float b; } B5bObj;
extern unsigned char D_005721C8;
extern int func_0042B1A0(int);float func_00245810(B5bObj* o) {
    float t;
    if (D_005721C8) {
        t = (float)func_0042B1A0(0) / 1000.0f;
        if (o->b < 0.0f) {
            o->b = t;
            return t;
        }
    } else {
        t = o->a;
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00245810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00245810 */

/* merge_units: begin func_00245890 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
float func_00245810();

float Hud_GetMissionTime(int arg0) {
    if (D_005721C8 != 0) {
        return func_00245810() - F_(arg0, 0x6E0, float);
    }
    return F_(arg0, 0x6DC, float);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00245890(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00245890 */

/* merge_units: begin func_002458E0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int key; int x4; int id; int c; int d; } Ent_2458E0;
typedef struct Node_2458E0 { struct Node_2458E0* prev; struct Node_2458E0* next; Ent_2458E0* ent; } Node_2458E0;
typedef struct { Node_2458E0* n; } It_2458E0;
struct Eq_2458E0 {};
struct Pred_2458E0 { Eq_2458E0 op; void** ref; Pred_2458E0(const Eq_2458E0& e, void** r) : op(e), ref(r) {} };
struct V6A0_2458E0 { int owner; virtual void v0(); virtual void v1(); virtual void v2(); virtual void Destroy(int f); };
struct Own_2458E0 { int owner; };
typedef struct {
    char pad0[0x54]; void* x54; char pad58[0xC]; int x64; int x68; char pad6C[0x10]; char x7C[0x14]; char x90[0x40];
    Own_2458E0 xD0; char padD4[0x2C]; char x100[0x534]; void* x634; char pad638[0x68]; V6A0_2458E0* x6A0; char pad6A4[0x44]; char x6E8[4];
} Self_2458E0;
extern "C" {
extern char D_004A7210[];
extern char D_004DC4A0[];
extern int D_004FFC04;
void ActiveList_EraseMatching(void* list, Pred_2458E0 p);
void func_00242E30(It_2458E0* out, char* l);
void CalloutList_End(It_2458E0* out, char* l);
void func_002426A0(It_2458E0* out, It_2458E0* in);
void IeElement_SetText(int a, int b);
void HudTracker_Kill(int a);
void IeElement_Release(int a);
void Interface_Dtor(void* p, int f);
void FrontEnd_TeardownGui(int a);
void func_00245D80(void* p, int f);
void cGOBJ_dtor(void* p, int f);
void func_003FA4B0(void* p, int f);
void func_00261950(void* p, int f);
void func_00273F00(void* p, int f);
void func_00245C90(void* p, int f);
void func_00246FF0(void* p, int f);
void __dl__FPv(void* p);
}
static inline Pred_2458E0 MakePred_(void** r) { Eq_2458E0 e; return Pred_2458E0(e, r); }
static inline void Unreg_(Self_2458E0* s, int* o) { *o = 0; ActiveList_EraseMatching(s->x90, MakePred_((void**)&o)); }
static inline void BeginI_(It_2458E0* out, char* l) { It_2458E0 t; func_00242E30(&t, l); func_002426A0(out, &t); }
static inline void EndI_(It_2458E0* out, char* l) { It_2458E0 t; CalloutList_End(&t, l); func_002426A0(out, &t); }
static inline void Begin_(It_2458E0* out, char* l) { BeginI_(out, l); }
static inline void End_(It_2458E0* out, char* l) { EndI_(out, l); }
static inline void DelEnt_(Ent_2458E0* e) { AllocGuard g; if (e) { if (e->c) IeElement_SetText(e->c, 0); if (e->d) HudTracker_Kill(e->d); } Mem_Free(0, e, D_004A7210, 0x1A9); }
static inline void DelV_(V6A0_2458E0* v) { AllocGuard g; v->Destroy(-1); Mem_Free(0, v, D_004A7210, 0x1B7); }
static inline void Del54_(void* p) { AllocGuard g; Interface_Dtor(p, -1); Mem_Free(0, p, D_004A7210, 0x1B9); }
extern "C" Self_2458E0* func_002458E0(Self_2458E0* self, short flag)
{
    if (self) {
        It_2458E0 it;
        It_2458E0 end;
        Ent_2458E0* e;
        Node_2458E0* n;
        Unreg_(self, (int*)self->x6A0);
        Unreg_(self, (int*)&self->xD0);
        Begin_(&it, self->x6E8);
        for (n = it.n; End_(&end, self->x6E8), n != end.n; n = n->next) {
            n->ent->c = 0;
            n->ent->d = 0;
            e = n->ent;
            DelEnt_(e);
        }
        if (!self->x64 && self->x68)
            IeElement_Release(self->x68);
        if (self->x6A0) {
            DelV_(self->x6A0);
        }
        Del54_(self->x54);
        FrontEnd_TeardownGui(D_004FFC04);
        if (self->x6E8)
            func_00245D80(self->x6E8, 0);
        if (&self->x634) {
            self->x634 = D_004DC4A0;
            cGOBJ_dtor(&self->x634, 0);
        }
        func_003FA4B0(self->x100, -1);
        func_00261950(&self->xD0, -1);
        func_00273F00(self->x90, -1);
        if (self->x7C)
            func_00245C90(self->x7C, -1);
        if (self)
            if (self)
                if (self)
                    func_00246FF0(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002458E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002458E0 */
