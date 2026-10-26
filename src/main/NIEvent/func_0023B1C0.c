#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* cNIEventOBJ_v4B: advance the event object's tracks; when anything moved, rebuild its rotation matrix and apply */
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
float Vec4_GetX(V4_23B4C0* v);
float Vec4_GetY(V4_23B4C0* v);
float Vec4_GetZ(V4_23B4C0* v);
void Mtx_MakeAxisRotation(M4_23B4C0* m, float x, float y, float z, float a);
void cMatrix_ctor_void(M4_23B4C0* m);
void Mtx_Multiply(M4_23B4C0* a, M4_23B4C0* b);
void NiEventList_Advance(void* l, float dt);

bool NiRotationTrack_Update(Rot_23B4C0* p, float dt);
}
static inline void MakeRot_23B4C0(M4_23B4C0* m, const V4_23B4C0& a, float ang) { Mtx_MakeAxisRotation(m, a.x, a.y, a.z, ang); }
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

static inline unsigned char Rot3(Self_23B4C0* self, float dt) { unsigned char r1 = NiRotationTrack_Update(&self->rx, dt); unsigned char r2 = NiRotationTrack_Update(&self->ry, dt); unsigned char r3 = NiRotationTrack_Update(&self->rz, dt); return r1 || r2 || r3; }
static inline unsigned char Moved(Self_23B4C0* self, float dt) { if (self->mode == 3) return 1; return Rot3(self, dt); }

extern "C" void cNIEventOBJ_v4B(Self_23B4C0* self, float dt)
{
    unsigned char a = self->Step(dt);
    unsigned char rot = Moved(self, dt);
    unsigned char b = self->Step2(dt);
    NiEventList_Advance(self->list, dt);
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
            Mtx_MakeAxisRotation(&m0, Vec4_GetX(&ax1), Vec4_GetY(&ax1), Vec4_GetZ(&ax1), ang);
            float ang2 = Rad_23B4C0(self->ry.val);
            ax2.Set(0.0f, 1.0f, 0.0f, 0.0f);
            cMatrix_ctor_void(&m1);
            MakeRot_23B4C0(&m1, ax2, ang2);
            Mtx_Multiply(&m0, &m1);
            float ang3 = Rad_23B4C0(self->rz.val);
            ax3.Set(0.0f, 0.0f, 1.0f, 0.0f);
            cMatrix_ctor_void(&m2);
            MakeRot_23B4C0(&m2, ax3, ang3);
            Mtx_Multiply(&m0, &m2);
            StoreAll_23B4C0(&self->mtx, &m0, LoadQ_23B4C0(&self->pos), &m0.r[3]);
        }
        self->Apply();
    }
}
