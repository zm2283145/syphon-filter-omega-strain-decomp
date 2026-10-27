/*
 * SFOGame/Source/NIEvent: 3 files, 0023B0B0-0023B1C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023B0B0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on

DEFINE_VTABLE2_BASE_DTOR(cBeamMsg_dtor, D_004DCF30, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_0023B0B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023B0B0 */

/* merge_units: begin func_0023B120 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Child_23B120 { char pad[0x4C]; int kind; };
class Node_23B120 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void slot70();
    char pad04[0x98];
    PtrVec children;
};
extern "C" {
extern int D_004F7C60;
int* std_vector_cNIEventBasePtr_opIndex(PtrVec* v, int i);
void cNIEventOBJ_UpdateChildren(Node_23B120* self);
}
/* Calls virtual slot 70, then recurses into every child whose kind (+0x4C) is NIEventOBJ (D_004F7C60). */
#pragma push
#pragma opt_strength_reduction off
extern "C" void cNIEventOBJ_UpdateChildren(Node_23B120* self)
{
    int i;
    self->slot70();
    for (i = 0; i < self->children.count; i++) {
        Child_23B120* c = (Child_23B120*)*std_vector_cNIEventBasePtr_opIndex(&self->children, i);
        if (c->kind == D_004F7C60)
            cNIEventOBJ_UpdateChildren((Node_23B120*)self->children.data[i]);
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023B120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023B120 */

/* merge_units: begin func_0023B1C0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNIEventOBJ_UpdateAll: advance the event object's tracks; when anything moved, rebuild its rotation matrix and apply */
struct V4_23B4C0 { float x, y, z, w;
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M4_23B4C0 { V4_23B4C0 r[4];
    M4_23B4C0() {}
};
static inline float Rad_23B4C0(float d) { return d * 0.017453292f; }
static inline __int128 LoadQ_23B4C0(const V4_23B4C0* s) { __int128 t; asm { .set noreorder; lq t, 0x0(s); .set reorder } return t; }
/* quad copies (lq/sq); volatile like retail: it also keeps MW's branchy bool materialisation of rot */
static inline void StoreAll_23B4C0(M4_23B4C0* d, const M4_23B4C0* s, __int128 t, V4_23B4C0* pd) { __int128 qa; __int128 qb; asm volatile { .set noreorder; sq t, 0x0(pd); lq qa, 0x0(s); .set reorder; lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
struct K64_23B4C0 { float t; char pad[0x3C]; };
struct K8_23B4C0 { float t; int v; };
struct K16_23B4C0 { float t; char pad[0xC]; };
struct Rot_23B4C0 { float val; int cap; int n; K16_23B4C0* data; int pad10; int state; float t; unsigned char flag; char pad1D[3]; };
extern "C" {
float cVector_X_void(V4_23B4C0* v);
float cVector_Y_void(V4_23B4C0* v);
float cVector_Z_void(V4_23B4C0* v);
void cMatrix_SetWithAxisAngle(M4_23B4C0* m, float x, float y, float z, float a);
void cMatrix_ctor_void(M4_23B4C0* m);
void cMatrix_Rotate(M4_23B4C0* a, M4_23B4C0* b);
void cNIEventFXTrack_Update(void* l, float dt);

bool cNIEventFloatTrack_Update(Rot_23B4C0* p, float dt);
}
static inline void MakeRot_23B4C0(M4_23B4C0* m, const V4_23B4C0& a, float ang) { cMatrix_SetWithAxisAngle(m, a.x, a.y, a.z, ang); }
class Elem_23B4C0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD4(d)
    virtual void Reset();
};
class Self_23B4C0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void Apply();
    VPAD2(e)
    virtual bool Step(float dt);
    virtual bool Step2(float dt);
    char pad4[0x60 - 0x4];
    int mode;
    char pad64[0x9C - 0x64];
    int acap; int an; Elem_23B4C0** adata;
    char padA8[0xB0 - 0xA8];
    int n1; K64_23B4C0* d1;
    char padB8[0xC0 - 0xB8];
    float t1;
    char padC4[0xC8 - 0xC4];
    int n2; K8_23B4C0* d2;
    char padD0[0xD8 - 0xD0];
    float t2;
    char padDC[0xE0 - 0xDC];
    V4_23B4C0 pos;
    M4_23B4C0 mtx;
    unsigned char b130;
    char pad131[0x144 - 0x131];
    Rot_23B4C0 rx;
    Rot_23B4C0 ry;
    Rot_23B4C0 rz;
    char list[4];
};

static inline unsigned char Rot3(Self_23B4C0* self, float dt) { unsigned char r1 = cNIEventFloatTrack_Update(&self->rx, dt); unsigned char r2 = cNIEventFloatTrack_Update(&self->ry, dt); unsigned char r3 = cNIEventFloatTrack_Update(&self->rz, dt); return r1 || r2 || r3; }
static inline unsigned char Moved(Self_23B4C0* self, float dt) { if (self->mode == 3) return 1; return Rot3(self, dt); }

extern "C" void cNIEventOBJ_UpdateAll(Self_23B4C0* self, float dt)
{
    unsigned char a = self->Step(dt);
    unsigned char rot = Moved(self, dt);
    unsigned char b = self->Step2(dt);
    cNIEventFXTrack_Update(self->list, dt);
    if (a || rot || b) {
        if (self->mode != 3) {
            M4_23B4C0 m0;
            V4_23B4C0 ax1;
            V4_23B4C0 ax2;
            V4_23B4C0 ax3;
            M4_23B4C0 m1;
            M4_23B4C0 m2;
            float ang;
            ang = Rad_23B4C0(self->rx.val);
            ax1.Set(1.0f, 0.0f, 0.0f, 0.0f);
            cMatrix_SetWithAxisAngle(&m0, cVector_X_void(&ax1), cVector_Y_void(&ax1), cVector_Z_void(&ax1), ang);
            float ang2 = Rad_23B4C0(self->ry.val);
            ax2.Set(0.0f, 1.0f, 0.0f, 0.0f);
            cMatrix_ctor_void(&m1);
            MakeRot_23B4C0(&m1, ax2, ang2);
            cMatrix_Rotate(&m0, &m1);
            float ang3 = Rad_23B4C0(self->rz.val);
            ax3.Set(0.0f, 0.0f, 1.0f, 0.0f);
            cMatrix_ctor_void(&m2);
            MakeRot_23B4C0(&m2, ax3, ang3);
            cMatrix_Rotate(&m0, &m2);
            StoreAll_23B4C0(&self->mtx, &m0, LoadQ_23B4C0(&self->pos), &m0.r[3]);
        }
        self->Apply();
    }
}
static inline void merge_flush_func_0023B1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023B1C0 */
