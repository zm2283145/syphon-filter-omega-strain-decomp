#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#include "types.h"
#include "vslot_pad.h"
/* cNIEventOBJ_v01 (message handler): for play messages, start (kind 0:
 * finish flags on the rotation/switch tracks, forward to the children),
 * stop (kind 1: forward) or reset (kind 2: rewind the tracks, rebuild the
 * node matrix from the first position key and the start rotations like
 * cNIEventOBJ_v48 (NIEvent_23B450.c), reset the attached object, forward and
 * return 1); everything else goes to NiEvent_HandlePlayMsg. Message layout
 * as in NiEvent_Stop (NiEvent_Stop.c). */
struct V4_B7D0 { float x, y, z, w;
    void Set(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M4_B7D0 { V4_B7D0 r[4];
    M4_B7D0() {}
};
static inline float Rad_B7D0(float d) { return d * 0.017453292f; }
static inline __int128 LoadQ_B7D0(const V4_B7D0* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); return t; }
struct K64_B7D0 { float t; char pad4[0xC]; V4_B7D0 pos; char pad20[0x20]; };
struct Key_B7D0 { float t; float v; char pad8[8]; };
struct Rot_B7D0 { float val; int cap; int n; Key_B7D0* data; int pad10; int state; int t; unsigned char flag; char pad1D[3]; };
extern "C" { extern int D_004F7C28; extern char D_004DC2F0[]; }
struct Msg_B7D0;
extern "C" { void Event_Construct(Msg_B7D0* m, void* name); void cMessage_dtor(Msg_B7D0* m, int flags); }
struct Msg_B7D0 { void* vtable; char pad04[0x1C]; unsigned char b20; char pad21[3]; int kind; char pad28[8];
};
class Obj_B7D0 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Enable(int on);
    virtual void Show(int on);
    char pad4[0x6C - 4];
    int f6C;
};
class Self_B7D0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD4(d) VPAD2(e) VPAD1(f)
    virtual void Rewind(float t);
    char pad4[0x60 - 0x4];
    int mode;
    char pad64[0xA0 - 0x64];
    int an; void** adata;
    char padA8[0xB4 - 0xA8];
    K64_B7D0* d1;
    char padB8[0xC0 - 0xB8];
    int t1;
    char padC4[0xD8 - 0xC4];
    int t2;
    char padDC[0xE0 - 0xDC];
    V4_B7D0 pos;
    M4_B7D0 mtx;
    unsigned char b130;
    char pad131[0x140 - 0x131];
    Obj_B7D0* obj;
    Rot_B7D0 rx;
    Rot_B7D0 ry;
    Rot_B7D0 rz;
    char pad1A4[4];
    unsigned char b1A8;
    char pad1A9[3];
    int i1AC;
};
extern "C" {
extern int D_004F7C28;
extern char D_004DC2F0[];
int* Event_GetType(void* ev);
void Event_Construct(Msg_B7D0* m, void* name);
void Event_Send(Msg_B7D0* m, void* target, int a);
void cMessage_dtor(Msg_B7D0* m, int flags);
float Vec4_GetX(V4_B7D0* v);
float Vec4_GetY(V4_B7D0* v);
float Vec4_GetZ(V4_B7D0* v);
void Mtx_MakeAxisRotation(M4_B7D0* m, float x, float y, float z, float a);
void cMatrix_ctor_void(M4_B7D0* m);
void Mtx_Multiply(M4_B7D0* a, M4_B7D0* b);
int NiEvent_HandlePlayMsg(Self_B7D0* self, Msg_B7D0* ev);
int cNIEventOBJ_v01(Self_B7D0* self, Msg_B7D0* ev);
}
static inline void VCopy_B7D0(V4_B7D0* d, const V4_B7D0* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void Cp_B7D0(void* d, const void* s) { __int128 t; asm volatile { .set reorder; lq t, 0(s); sq t, 0(d) } }
static inline void MakeRot_B7D0(M4_B7D0* m, const V4_B7D0& a, float ang) { Mtx_MakeAxisRotation(m, a.x, a.y, a.z, ang); }
static inline void Rewind_B7D0(Rot_B7D0* r) {
    r->t = 0;
    if (r->n > 0)
        r->val = r->data[0].v;
}

static inline void BuildRot_B7D0(Self_B7D0* o, M4_B7D0* pm)
{
    V4_B7D0 ax1;
    V4_B7D0 ax2;
    V4_B7D0 ax3;
    M4_B7D0 m1;
    M4_B7D0 m2;
    float ang; float bng; float cng;
    ang = Rad_B7D0(o->rx.val);
    ax1.Set(1.0f, 0.0f, 0.0f, 0.0f);
    Mtx_MakeAxisRotation(pm, Vec4_GetX(&ax1), Vec4_GetY(&ax1), Vec4_GetZ(&ax1), ang);
    bng = Rad_B7D0(o->ry.val);
    ax2.Set(0.0f, 1.0f, 0.0f, 0.0f);
    cMatrix_ctor_void(&m1);
    MakeRot_B7D0(&m1, ax2, bng);
    Mtx_Multiply(pm, &m1);
    cng = Rad_B7D0(o->rz.val);
    ax3.Set(0.0f, 0.0f, 1.0f, 0.0f);
    cMatrix_ctor_void(&m2);
    MakeRot_B7D0(&m2, ax3, cng);
    Mtx_Multiply(pm, &m2);
}

// 4x128-bit lq/sq matrix copy, interleaved as in retail (no C equivalent for the quadword pairing)
static inline void CopyM_B7D0(M4_B7D0* d, const M4_B7D0* s) { __int128 qa; __int128 qb; asm { lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
extern "C" int cNIEventOBJ_v01(Self_B7D0* self, Msg_B7D0* ev)
{
    Msg_B7D0* e = ev;
    int i;
    Msg_B7D0* p;
    Msg_B7D0* q;
    int j;
    Self_B7D0* o = self;
    int t;
    t = *Event_GetType(e);
    if (t == D_004F7C28) {
        switch (e->kind) {
        case 0:
            o->rx.flag = 1;
            o->ry.flag = 1;
            o->rz.flag = 1;
            o->b1A8 = 1;
            for (i = 0; i < o->an; i++) {
                Msg_B7D0 m;
                p = &m;
                Event_Construct(p, &D_004F7C28);
                p->vtable = D_004DC2F0;
                p->kind = 0;
                m.b20 = 1;
                Event_Send(p, o->adata[i], 0);
                m.vtable = D_004DC2F0;
                cMessage_dtor(p, 0);
            }
            break;
        case 1:
            for (i = 0; i < o->an; i++) {
                Msg_B7D0 m;
                p = &m;
                Event_Construct(p, &D_004F7C28);
                p->vtable = D_004DC2F0;
                p->kind = 1;
                m.b20 = 1;
                Event_Send(p, o->adata[i], 0);
                m.vtable = D_004DC2F0;
                cMessage_dtor(p, 0);
            }
            break;
        case 2: {
            M4_B7D0 m0;
            Rewind_B7D0(&o->rx);
            Rewind_B7D0(&o->ry);
            Rewind_B7D0(&o->rz);
            o->i1AC = 0x80000000;
            o->b1A8 = 0;
            o->t1 = 0;
            o->t2 = 0;
            Cp_B7D0(&o->pos, &o->d1[0].pos);
            BuildRot_B7D0(o, &m0);
            { V4_B7D0* pd = &m0.r[3]; __int128 t = LoadQ_B7D0(&o->pos); *(__int128*)pd = t; CopyM_B7D0(&o->mtx, &m0); }
            if (o->mode == 2 && o->obj) {
                o->obj->f6C = 0;
                o->obj->Show(1);
                o->obj->Enable(1);
            }
            o->Rewind(0.0f);
            o->b130 = 0;
            for (j = 0; j < o->an; j++) {
                Msg_B7D0 m;
                q = &m;
                Event_Construct(q, &D_004F7C28);
                q->vtable = D_004DC2F0;
                q->kind = 2;
                m.b20 = 1;
                Event_Send(q, o->adata[j], 0);
                m.vtable = D_004DC2F0;
                cMessage_dtor(q, 0);
            }
            return 1;
        }
        }
    }
    return NiEvent_HandlePlayMsg(o, e);
}
