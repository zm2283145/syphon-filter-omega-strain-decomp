/*
 * SFOGame/Source/hud: 4 files, 00245800-00245810
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00245800 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern void cHud_cHudTimer_ScheduleExpiration(void* p, int a1, float f);

/* Forwards to the member at +0x6C4. */
void HudTimer_Start_Thunk(char* self, int a1, float f) {
    cHud_cHudTimer_ScheduleExpiration(self + 1732, a1, f);
}
static inline void merge_flush_func_00245800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00245800 */

/* merge_units: begin func_00245810 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { char pad[0x6DC]; float a; float b; } B5bObj;
extern unsigned char g_IsMultiplayer;
extern int cDME_GetTime(int);float cHud_GetGlobalTime(B5bObj* o) {
    float t;
    if (g_IsMultiplayer) {
        t = (float)cDME_GetTime(0) / 1000.0f;
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
float cHud_GetGlobalTime();

float cHud_GetMissionTime(int arg0) {
    if (g_IsMultiplayer != 0) {
        return cHud_GetGlobalTime() - F_(arg0, 0x6E0, float);
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
void std_list_imp_voidPtr_remove_if(void* list, Pred_2458E0 p);
void std_list_tCalloutPtr_begin(It_2458E0* out, char* l);
void std_list_tCalloutPtr_end_void(It_2458E0* out, char* l);
void cLListIterator_tCalloutPtr_ctor(It_2458E0* out, It_2458E0* in);
void cInterfaceElement_SetText(int a, int b);
void cIE_GOBJ_AnimateOff(int a);
void cInterfaceElement_Destroy(int a);
void cInterface_dtor(void* p, int f);
void cGameFrontEnd_DestroyGui(int a);
void std_list_tCalloutPtr_dtor(void* p, int f);
void cGOBJ_dtor(void* p, int f);
void cInfoBar_dtor(void* p, int f);
void cHudRadar_dtor(void* p, int f);
void cHudTargetManager_dtor(void* p, int f);
void std_vector_cInterfaceElementPtr_dtor(void* p, int f);
void std_vector_deleter_PDAQuip_dtor(void* p, int f);
void __dl__FPv(void* p);
}
static inline Pred_2458E0 MakePred_(void** r) { Eq_2458E0 e; return Pred_2458E0(e, r); }
static inline void Unreg_(Self_2458E0* s, int* o) { *o = 0; std_list_imp_voidPtr_remove_if(s->x90, MakePred_((void**)&o)); }
static inline void BeginI_(It_2458E0* out, char* l) { It_2458E0 t; std_list_tCalloutPtr_begin(&t, l); cLListIterator_tCalloutPtr_ctor(out, &t); }
static inline void EndI_(It_2458E0* out, char* l) { It_2458E0 t; std_list_tCalloutPtr_end_void(&t, l); cLListIterator_tCalloutPtr_ctor(out, &t); }
static inline void Begin_(It_2458E0* out, char* l) { BeginI_(out, l); }
static inline void End_(It_2458E0* out, char* l) { EndI_(out, l); }
static inline void DelEnt_(Ent_2458E0* e) { AllocGuard g; if (e) { if (e->c) cInterfaceElement_SetText(e->c, 0); if (e->d) cIE_GOBJ_AnimateOff(e->d); } cMemMan_Deallocate(0, e, D_004A7210, 0x1A9); }
static inline void DelV_(V6A0_2458E0* v) { AllocGuard g; v->Destroy(-1); cMemMan_Deallocate(0, v, D_004A7210, 0x1B7); }
static inline void Del54_(void* p) { AllocGuard g; cInterface_dtor(p, -1); cMemMan_Deallocate(0, p, D_004A7210, 0x1B9); }
extern "C" Self_2458E0* cHud_dtor(Self_2458E0* self, short flag)
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
            cInterfaceElement_Destroy(self->x68);
        if (self->x6A0) {
            DelV_(self->x6A0);
        }
        Del54_(self->x54);
        cGameFrontEnd_DestroyGui(D_004FFC04);
        if (self->x6E8)
            std_list_tCalloutPtr_dtor(self->x6E8, 0);
        if (&self->x634) {
            self->x634 = D_004DC4A0;
            cGOBJ_dtor(&self->x634, 0);
        }
        cInfoBar_dtor(self->x100, -1);
        cHudRadar_dtor(&self->xD0, -1);
        cHudTargetManager_dtor(self->x90, -1);
        if (self->x7C)
            std_vector_cInterfaceElementPtr_dtor(self->x7C, -1);
        if (self)
            if (self)
                if (self)
                    std_vector_deleter_PDAQuip_dtor(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002458E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002458E0 */
