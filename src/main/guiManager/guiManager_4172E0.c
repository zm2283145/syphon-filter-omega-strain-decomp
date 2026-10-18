/*
 * main/guiManager: 3 files, 004172E0-004173B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004172E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_004172E0, String_Dtor)
#pragma pop /* merge_units */
/* merge_units: end func_004172E0 */

/* merge_units: begin func_00417340 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_classes.h"

typedef struct { char pad[4]; VSlots67* ctl; char p1[0x1C]; void* res; } Obj_417340;
extern "C" void IeElement_SetShown(void*, int);
extern "C" void func_003E8DC0(void*, int);

extern "C" void GuiInterfaceDecorator_Draw(Obj_417340* o)
{
    if (o->res) {
        IeElement_SetShown(o->res, 1);
        func_003E8DC0(o->res, 0);
        IeElement_SetShown(o->res, 0);
    }
    o->ctl->slot10();
}
#pragma pop /* merge_units */
/* merge_units: end func_00417340 */

/* merge_units: begin func_004173B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "vc_copy.h"

typedef struct E_4173B0 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; } E_4173B0;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_4173B0;
struct Inst_4173B0 {
    VPAD1(p)
    virtual float Time();
    float t;
};
struct Base_4173B0 {
    VPAD8(p) VPAD4(q) VPAD1(r)
    virtual bool Handle(int a1, unsigned short msg, int p1, int p2);
    char pad4[0x3C - 4];
    float w;
    float h;
    float& W() { return w; }
    float& H() { return h; }
};
struct Self_4173B0 {
    char pad0[4];
    Base_4173B0* base;
    char pad8[0x24 - 8];
    Inst_4173B0* inst;
    char pad28[0x30 - 0x28];
    V4_4173B0 v30;
    char pad40[0x60 - 0x40];
    V4_4173B0 v60;
    char pad70[0x80 - 0x70];
    E_4173B0* cur;
};

extern "C" {
E_4173B0* GuiInterfaceDecorator_FindEvent(Self_4173B0* o, char* name);
int GuiInterfaceDecorator_FireEvent(Self_4173B0* o, char* name);
void IeElement_UpdateAnimation(Inst_4173B0* i, float t);
void IeElement_EvaluateAt(Inst_4173B0* i, float t);
void IeElement_Fade(Inst_4173B0* i, float t);
void IeElement_PlayRange(Inst_4173B0* i, float a, float b, int f);
void IeElement_SetMatrix(Inst_4173B0* i, V4_4173B0* v);
}

/* GCC-style volatile asm quad copies (lq/sq only): MW does not CSE across them, so the
   dead address local after the first copy and the repeated 2.0f / &base->w loads stay
   as in retail. GC1L declares its source local first to get retail's register order. */
static inline void GC1(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void GC1L(void* d, const void* s) { const void* ss = s; void* dd = d; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
static inline float Yv(E_4173B0* e) { return e->y; }
static inline float Tm(Inst_4173B0* i) { return i->t; }
extern "C" bool GuiInterfaceDecorator_OnEvent(Self_4173B0* self, int a1, unsigned short msg, int p1, int p2)
{
    switch (msg - 4) {
    case 11: {
        E_4173B0* e = self->cur;
        Inst_4173B0* inst;
        bool r;
        if (e == 0 || (inst = self->inst) == 0 || e->kind != 1 || Yv(e) == Tm(inst)) r = 1; else r = 0;
        return r;

    }
    case 2:
        GuiInterfaceDecorator_FireEvent(self, (char*)p1);
        return 0;
    case 1:
        if (p1) *(Inst_4173B0**)p1 = self->inst;
        return 1;
    case 3:
        if (p1 == 0 || 0.0f == *(float*)p1) return 1;
        if (self->inst) IeElement_UpdateAnimation(self->inst, *(float*)p1);
        return 0;
    case 5:
        if (p1 && self->inst) *(float*)p1 = self->inst->t;
        return 1;
    case 4:
        if (p1 && self->inst) *(float*)p1 = self->inst->Time();
        return 1;
    case 0: {
        E_4173B0* e = GuiInterfaceDecorator_FindEvent(self, (char*)p1);
        if (e && p2) {
            *(E_4173B0**)p2 = e;
            return 1;
        }
        return 0;
    }
    case 6:
    case 7:
    case 8:
    case 9:
    case 10: {
        if (self->inst == 0) break;
        switch (msg) {
        case 10:
            IeElement_EvaluateAt(self->inst, p1);
        case 11:
            IeElement_Fade(self->inst, p1);
            break;
        case 12:
            IeElement_EvaluateAt(self->inst, p1);
            IeElement_Fade(self->inst, p2);
            break;
        case 13:
            if (self->inst->t < p1 || self->inst->t > p2) { Inst_4173B0* volatile* pv = &self->inst; IeElement_EvaluateAt(*pv, p1); }
            IeElement_PlayRange(self->inst, p1, p2, 0);
            break;
        case 14:
            if (self->inst->t < p1 || self->inst->t > p2) { Inst_4173B0* volatile* pv = &self->inst; IeElement_EvaluateAt(*pv, p1); }
            IeElement_PlayRange(self->inst, p1, p2, 1);
            break;
        }
        self->cur = 0;
        return 0;
    }
    case 14: {
        V4_4173B0 v;
        GC1L(&v, &self->v60);
        void* xx = &self->v60; /* dead on purpose */
        v.x = (float)p1 + self->base->W() / 2.0f;
        v.z = (float)p2 - self->base->H() / 2.0f;
        GC1(&self->v60, &v);
        if (self->inst) IeElement_SetMatrix(self->inst, &self->v30);
        return 1;
    }
    }
    return self->base->Handle(a1, msg, p1, p2);
}
#pragma pop /* merge_units */
/* merge_units: end func_004173B0 */
