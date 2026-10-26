#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#include "types.h"
#include "vslot_pad.h"
/* cNIEventOBJ_v46 (update): updates the event node, then drives the attached
 * object from the owner's matrix: for mode 5 with rows 1 and 2 swapped and
 * the new row 1 negated (Y/Z swap), otherwise through the play or idle
 * matrix slot depending on whether the event is playing; finally pokes every
 * child element of the two attach types. Types as in cNIEventOBJ_v48
 * (NIEvent_23B450.c) and cNIEventLight_v42. */
#pragma always_inline on
#pragma inline_depth(8)
struct V4_A2D0 { float x, y, z, w; } __attribute__((aligned(16)));
struct M4_A2D0 { V4_A2D0 r[4]; };
class Owner_A2D0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char p4[0x10 - 4];
    M4_A2D0 mtx;
    unsigned char dirty;
};
class Obj_A2D0 {
public:
    VPAD32(a) VPAD2(b) VPAD1(c)
    virtual void SetMatrix(M4_A2D0* m);
    VPAD4(d) VPAD1(e)
    virtual void SetIdleMatrix(M4_A2D0* m);
    char p4[0x50 - 4];
    void* model;
};
class Elem_A2D0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void Attach();
    char p4[0x4C - 4];
    int type;
};
struct PtrVec_A2D0 { int cap; int n; Elem_A2D0** data; };
class Ev_A2D0 {
public:
    VPAD1(a)
    char p4[0x50 - 4];
    Owner_A2D0* owner;
    char p54[0x60 - 0x54];
    int mode;
    char p64[0x9C - 0x64];
    PtrVec_A2D0 elems;
    char pA8[0x130 - 0xA8];
    unsigned char playing;
    char p131[0x140 - 0x131];
    Obj_A2D0* obj;
};
extern "C" {
extern int D_004F7C60;
extern int D_004F7C98;
void NiEvent_UpdateNode(Ev_A2D0* self);
Elem_A2D0** std_vector_cNIEventBasePtr_opIndex(PtrVec_A2D0* v, int i);
void Mtx_SetRow0(M4_A2D0* m, V4_A2D0* v);
void Mtx_SetRow1(M4_A2D0* m, V4_A2D0* v);
void Mtx_SetRow2(M4_A2D0* m, V4_A2D0* v);
void cNIEventOBJ_v46(Ev_A2D0* self);
}
static inline void GQR(void* dd, void* ss) { void* s = ss; void* d = dd; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void VCopy(V4_A2D0* d, const V4_A2D0* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline Elem_A2D0* At(PtrVec_A2D0* v, int i) { return *std_vector_cNIEventBasePtr_opIndex(v, i); }
static inline bool Is(int k, Elem_A2D0* e) { return e->type == k; }
static inline Owner_A2D0* SyncedOwner(Ev_A2D0* self) { Owner_A2D0* o = self->owner; if (o->dirty) o->Sync(); return o; }

extern "C" void cNIEventOBJ_v46(Ev_A2D0* self)
{
    int i;
    NiEvent_UpdateNode(self);
    if (self->obj && self->obj->model) {
        if (self->mode != 5) {
            if (self->playing) {
                Owner_A2D0* o = SyncedOwner(self);
                self->obj->SetMatrix(&o->mtx);
            } else {
                Owner_A2D0* o = SyncedOwner(self);
                self->obj->SetIdleMatrix(&o->mtx);
            }
        } else {
            Owner_A2D0* o = SyncedOwner(self);
            M4_A2D0 m;
            V4_A2D0 r0;
            V4_A2D0 r1;
            V4_A2D0 r2;
            GQR(&m, &o->mtx);
            VCopy(&r0, &m.r[0]);
            VCopy(&r1, &m.r[1]);
            VCopy(&r2, &m.r[2]);
            r2.x = -r2.x;
            r2.y = -r2.y;
            r2.z = -r2.z;
            Mtx_SetRow0(&m, &r0);
            Mtx_SetRow1(&m, &r2);
            Mtx_SetRow2(&m, &r1);
            self->obj->SetMatrix(&m);
        }
    }
    for (i = 0; i < self->elems.n; i++) {
        if (Is(D_004F7C60, At(&self->elems, i)))
            self->elems.data[i]->Attach();
        else if (Is(D_004F7C98, At(&self->elems, i)))
            self->elems.data[i]->Attach();
    }
}
