#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 a; V4 b; } VP;

extern char D_004DA470[], D_004DA580[], D_004DAD90[], D_004DAD70[], D_004DA440[], D_004DA410[], D_004DA3E0[], D_004DA2F0[];
extern char D_0055C9F0[];
extern float D_0048A158, D_0048A160;
extern float D_004A3FC8;
extern signed char D_004E1D80;
extern VP D_00497F00;

void cGOBJ_ctor(void*, int, int, int*);
void Object_AttachTransform(void*, void*, int);
void func_0017F9D0(void*);
V4* Vec4_GetZero(void);
void Vec4_Assign(void*, V4*);
void func_00132840(void*);
void func_0017F980(void*);
V4 Vec4_SetOrigin(void);
void func_0017F8B0(void*);
float func_0017F860(float);
V4 Quat_SetIdentity(void);
void func_00132800(void*, V4*);
V4 func_0017F820(void);
void CameraCurve_MakeQuaternion(void*, V4*, V4*);
void func_0017F520(void*, V4*, V4*);
void PhysicalBase_Construct(void*, float*, float*);
void Placement_GetIdentity(VP*, V4*, V4*);
void VecPair_Copy(VP*, VP*);
void func_0017F330(void*);
void func_0017F2E0(void*);
void Curve_Construct(void*);
void func_00136540(void*, int*, int*);
void func_001364B0(void*);

#define F(T, p, o) (*(T*)((char*)(p) + (o)))

static inline void Box_Init(char* b)
{
    F(void*, b, 0) = 0;
    F(float, b, 0x10) = 3.4028235e38f;
    F(float, b, 0x14) = 3.4028235e38f;
    F(float, b, 0x18) = 3.4028235e38f;
    F(float, b, 0x1C) = 1.0f;
    F(float, b, 0x20) = -3.4028235e38f;
    F(float, b, 0x24) = -3.4028235e38f;
    F(float, b, 0x28) = -3.4028235e38f;
    F(float, b, 0x2C) = 1.0f;
    F(int, b, 0x30) = 0;
    F(void*, b, 0x34) = 0;
}

static inline void GObj_Init(char* self, int a1)
{
    int z;
    z = 0;
    cGOBJ_ctor(self, a1, 9, &z);
}

static inline void GObj_Init2(char* self, int a1)
{
    GObj_Init(self, a1);
}

static inline void Rig_Init(char* m0)
{
    char* m = m0;
    V4 t0, t1, t2;
    func_0017F9D0(m);
    F(void*, m, 0) = D_004DAD90;
    Vec4_Assign(m + 0x10, Vec4_GetZero());
    func_00132840(m + 0x20);
    func_0017F980(m + 0x30);
    t0 = Vec4_SetOrigin();
    Vec4_Assign(m + 0x40, &t0);
    t1 = Vec4_SetOrigin();
    Vec4_Assign(m + 0x50, &t1);
    F(unsigned char, m, 0x60) = 0;
    t2 = Vec4_SetOrigin();
    Vec4_Assign(m + 0x70, &t2);
    F(unsigned char, m, 0x80) = 0;
    func_0017F8B0(m + 0x90);
}

static inline void Fov_Init(char* m0)
{
    char* m = m0;
    V4 q, t;
    func_0017F9D0(m);
    F(void*, m, 0) = D_004DAD70;
    F(unsigned char, m, 4) = 0;
    F(float, m, 8) = func_0017F860(D_004A3FC8);
    q = Quat_SetIdentity();
    func_00132800(m + 0x10, &q);
    F(int, m, 0x20) = 0;
    F(int, m, 0x24) = 0;
    t = Vec4_SetOrigin();
    Vec4_Assign(m + 0x30, &t);
    Vec4_Assign(m + 0x40, Vec4_GetZero());
}

static inline void QCurve_Init(char* m0, unsigned char on)
{
    char* m = m0;
    V4 q, r;
    q = Quat_SetIdentity();
    r = func_0017F820();
    CameraCurve_MakeQuaternion(m, &q, &r);
    F(void*, m, 0) = D_004DA440;
    F(unsigned char, m, 0xC0) = on;
}

static inline void VCurve_Init(char* m0)
{
    char* m = m0;
    V4 t;
    t = Vec4_SetOrigin();
    func_0017F520(m, &t, Vec4_GetZero());
    F(void*, m, 0) = D_004DA410;
}

static inline void V4Copy(V4* d, V4* s)
{
    __int128 t;
    __asm__ volatile("lq %0, 0(%1)" : "=r"(t) : "r"(s));
    __asm__ volatile("sq %0, 0(%1)" : : "r"(t), "r"(d) : "memory");
}

static inline void VPCopy(VP* d, VP* s)
{
    V4Copy(&d->a, &s->a);
    V4Copy(&d->b, &s->b);
}

static inline void Set4(V4* d, float x, float y, float z, float w)
{
    d->x = x;
    d->y = y;
    d->z = z;
    d->w = w;
}

static inline void Phys_Init(char* m0)
{
    char* m = m0;
    PhysicalBase_Construct(m, &D_0048A158, &D_0048A160);
    F(void*, m, 0) = D_004DA3E0;
}

static inline void Track_Init(char* m0)
{
    char* m = m0;
    func_0017F330(m);
    func_0017F2E0(m + 0x38);
    Curve_Construct(m + 0x80);
}

static inline void Tgt_Init(char* m0)
{
    char* m = m0;
    int c, d;
    d = 0;
    c = 0;
    func_00136540(m, &c, &d);
    F(void*, m, 0) = D_004DA2F0;
    F(int, m, 0x20) = 0;
    Vec4_Assign(m + 0x30, Vec4_GetZero());
    func_001364B0(m + 0x40);
    F(int, m, 0x60) = 0;
}

static inline VP* PlacementIdentity(void)
{
    if (!D_004E1D80) {
        V4 q, o;
        q = Quat_SetIdentity();
        o = Vec4_SetOrigin();
        Placement_GetIdentity(&D_00497F00, &q, &o);
        D_004E1D80 = 1;
    }
    return &D_00497F00;
}

void* Camera_ConstructFov(char* self, int a1, float fov, int a2)
{
    int c, d;
    VP p;
    V4 idc;
    V4 id;

    GObj_Init2(self, a1);
    F(void*, self, 0) = D_004DA470;
    F(float, self, 0x60) = 0.5f * fov;
    F(int, self, 0x64) = 0;
    Object_AttachTransform(self, D_0055C9F0, 0);
    F(int, self, 0x30) = 0;
    F(void*, self, 0) = D_004DA580;
    Rig_Init(self + 0x70);
    Box_Init(self + 0x130);
    Fov_Init(self + 0x170);
    Box_Init(self + 0x1C0);
    F(unsigned char, self, 0x200) = 0;
    F(unsigned char, self, 0x201) = 1;
    QCurve_Init(self + 0x210, 1);
    VCurve_Init(self + 0x2E0);
    VCurve_Init(self + 0x3A0);
    QCurve_Init(self + 0x460, 0);
    QCurve_Init(self + 0x530, 0);
    VCurve_Init(self + 0x600);
    VCurve_Init(self + 0x6C0);
    QCurve_Init(self + 0x780, 1);
    VCurve_Init(self + 0x850);
    VCurve_Init(self + 0x910);
    VCurve_Init(self + 0x9D0);
    Phys_Init(self + 0xA90);
    PlacementIdentity();
    VecPair_Copy(&p, &D_00497F00);
    { __int128 t2; V4* ss = &p.a; char* dd = self + 0xAD0; __int128 t1; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t1), "+r"(dd) : "r"(ss) : "memory"); __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t2) : "r"(self + 0xAE0), "r"(&p.b) : "memory"); }
    {
        V4* q1 = &id;
        asm { sqc2 vf0, 0x0(q1) }
    }
    { __int128 t1, t2; __asm__ volatile("lq %0, 0(%5); sq %0, 0(%4); lq %1, 0(%3); sq %1, 0(%2)" : "=&r"(t1), "=&r"(t2) : "r"(self + 0xAF0), "r"(&idc), "r"(&idc), "r"(&id) : "memory"); }
    Set4((V4*)(self + 0xB00), 0.0f, 0.0f, 0.0f, 1.0f);
    Set4((V4*)(self + 0xB10), 0.0f, 0.0f, 0.0f, 1.0f);
    Track_Init(self + 0xB20);
    F(unsigned char, self, 0xC60) = 0;
    F(unsigned char, self, 0xC62) = 0;
    F(float, self, 0xC64) = fov;
    F(float, self, 0xC68) = fov;
    Tgt_Init(self + 0xC70);
    F(int, self, 0xCE8) = a2;
    F(void*, self, 0x130) = self + 0xC70;
    F(void*, self, 0x164) = self + 0x70;
    F(int, self, 0x160) = 1;
    F(void*, self, 0x1C0) = self + 0xC70;
    F(void*, self, 0x1F4) = self + 0x170;
    F(int, self, 0x1F0) = 4;
    F(float, self, 0x4B0) = 15.0f;
    F(float, self, 0x580) = 15.0f;
    F(float, self, 0x650) = 15.0f;
    F(float, self, 0x710) = 15.0f;
    F(float, self, 0x7D0) = 15.0f;
    F(float, self, 0x8A0) = 15.0f;
    F(float, self, 0x960) = 15.0f;
    F(float, self, 0xA20) = 15.0f;
    F(float, self, 0xAA4) = 15.0f;
    F(int, self, 0xCE0) = 0;
    F(unsigned char, self, 0xCE4) = 0;
    return self;
}
