#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma always_inline on
#pragma inline_depth(8)

extern "C" {
extern float Math_CosThunk(float);
extern float Math_SinThunk(float);
extern float Math_Cos(float);
extern float Math_Sin(float);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void __construct_array(void* arr, void* ctor, void* dtor, int size, int n);
extern void func_001D7D90(void);
extern void func_001DFA30(void);
extern void func_001DF9E0(void);
extern void func_001DF980(void);
extern float D_0049F718;
extern float D_0049F720;
}

struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct E { float x, y, z; E(float a, float b, float c) { x = a; y = b; z = c; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~E() {} } __attribute__((aligned(16)));
struct AA { float x, y, z, a; AA(float i, float j, float k, float l) { float ty, ta; ta = l; ty = j; y = ty; a = ta; z = k; x = i; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~AA() {} };

static inline void EQ(V& q, const E& e)
{
    float h = 0.5f;
    float hx = h * e.x;
    float hy = h * e.y;
    float hz = h * e.z;
    float cx = Math_CosThunk(hx);
    float cy = Math_CosThunk(hy);
    float cz = Math_CosThunk(hz);
    float sx = Math_SinThunk(hx);
    float sy = Math_SinThunk(hy);
    float sz = Math_SinThunk(hz);
    float cycz = cy * cz;
    float sysz = sy * sz;
    float sycz = sy * cz;
    float cysz = cy * sz;
    q.w = cx * cycz - sx * sysz;
    q.x = sx * cycz - cx * sysz;
    q.y = cx * sycz + sx * cysz;
    q.z = cx * cysz + sx * sycz;
}

static inline void EQh(V& q, const E& e, float h)
{
    float hx = h * e.x;
    float hy = h * e.y;
    float hz = h * e.z;
    float cx = Math_CosThunk(hx);
    float cy = Math_CosThunk(hy);
    float cz = Math_CosThunk(hz);
    float sx = Math_SinThunk(hx);
    float sy = Math_SinThunk(hy);
    float sz = Math_SinThunk(hz);
    float cycz = cy * cz;
    float sysz = sy * sz;
    float sycz = sy * cz;
    float cysz = cy * sz;
    q.w = cx * cycz - sx * sysz;
    q.x = sx * cycz - cx * sysz;
    q.y = cx * sycz + sx * cysz;
    q.z = cx * cysz + sx * sycz;
}

static inline void AQ(V& q, const AA& a)
{
    float px, py;
    float h = 0.5f * a.a;
    float c = Math_Cos(h);
    float s = Math_Sin(h);
    float x = a.x, y = a.y, z = a.z;
    px = s * x; py = s * y;
    s = s * z;
    q.w = c;
    q.x = px;
    q.y = py;
    q.z = s;
}

struct SO { float x, y, z; };
static inline float IS2(float a)
{
    float t = 1.0f / Math_Sin(0.5f * a);
    return t * t;
}
static inline void SinInit(SO* o, float a, float b, float c)
{
    o->x = IS2(a);
    o->y = IS2(b);
    o->z = IS2(c);
}

struct Str48 { char s[48]; } __attribute__((aligned(16)));
static inline void KQZero(void* dd, int nn)
{
    int n = nn; void* d = dd;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
static inline void KQCopy(void* d0, void* s0) { int n = 3; void* s = s0; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq $a0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $a0, -0x10(d)
        .set reorder
    }
}
static inline void KInit(char* dst, const char* src)
{
    {
        unsigned char ckc_end = 0;
        int ckc_i = 0;
        char ckc_c;
        const char* ckc_s = src;
        for (; ckc_i < 0x2F; ckc_i++) {
            if (ckc_s[ckc_i] == 0) ckc_end = 1;
            ckc_c = 0;
            if (ckc_end) asm { .set reorder } else ckc_c = *(volatile const char*)&ckc_s[ckc_i];
            dst[ckc_i] = ckc_c;
        }
        dst[ckc_i] = 0;
    }
}
#define S(p) (p)
#define Z() 0
struct Ent {
    unsigned char id;
    Str48 name;
    void* a;
    void* b;
    void* c;
    unsigned char f0, f1, f2, f3;
};
static inline void SetEnt(Ent& e, unsigned char id, const char* nm, void* a, void* b, void* c,
                          unsigned char f0, unsigned char f1, unsigned char f2, unsigned char f3)
{
    Str48 k;
    KInit(k.s, nm);
    e.id = id;
    KQCopy(&e.name, &k);
    e.a = a;
    e.b = b;
    e.c = c;
    unsigned char one = 1;
    e.f0 = f0 ? one : 0;
    e.f1 = f1 ? one : 0;
    e.f2 = f2 ? one : 0;
    e.f3 = f3 ? one : 0;
}
static inline void KQCopyN(void* d0, void* s0, int n) { void* s = s0; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq $a0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $a0, -0x10(d)
        .set reorder
    }
}
static inline void SetEnt3(Ent& e, const char* nm, void* a, void* b, void* c,
                          unsigned char f0, unsigned char f1, unsigned char f2, unsigned char f3)
{
    Str48 k;
    KInit(k.s, nm);
    int n = 3;
    e.id = n;
    KQCopyN(&e.name, &k, n);
    e.a = a;
    e.b = b;
    e.c = c;
    unsigned char one = 1;
    e.f0 = f0 ? one : 0;
    e.f1 = f1 ? one : 0;
    e.f2 = f2 ? one : 0;
    e.f3 = f3 ? one : 0;
}
static inline void SetEnt3b(Ent& e, const char* nm, void* a, void* b, void* c,
                          unsigned char f0, unsigned char f1, unsigned char f2, unsigned char f3)
{
    Str48 k;
    KInit(k.s, nm);
    int n = 3;
    KQCopyN(&e.name, &k, n);
    e.id = n;
    e.a = a;
    e.b = b;
    e.c = c;
    unsigned char one = 1;
    e.f0 = f0 ? one : 0;
    e.f1 = f1 ? one : 0;
    e.f2 = f2 ? one : 0;
    e.f3 = f3 ? one : 0;
}


static inline void SetEnt(Ent& e, unsigned char id, int nm, void* a, void* b, void* c,
                          unsigned char f0, unsigned char f1, unsigned char f2, unsigned char f3)
{
    Str48 k;
    KQZero(&k, 3);
    e.id = id;
    KQCopy(&e.name, &k);
    e.a = a;
    e.b = b;
    e.c = c;
    unsigned char one = 1;
    e.f0 = f0 ? one : 0;
    e.f1 = f1 ? one : 0;
    e.f2 = f2 ? one : 0;
    e.f3 = f3 ? one : 0;
}

#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off

extern "C" {
extern char D_0048A3A0[], D_0048A400[], D_0048A460[], D_0048A4C0[], D_0048A520[], D_0048A580[], D_0048A5E0[], D_0048A640[], D_0048A6E0[], D_0048A700[], D_0048A720[], D_0048A740[], D_0048A760[], D_0048A780[], D_0048A7A0[], D_0048A7C0[], D_0048A7E0[], D_0048A800[], D_0048A820[], D_0048A840[], D_0048A860[], D_0048A880[], D_0048A8A0[], D_0048A8C0[], D_0048A8E0[], D_0048A900[], D_0048A920[], D_0048A940[], D_004A01A0[], D_004A01C0[], D_004A01E0[], D_004A01F8[], D_004A0210[], D_004A0238[], D_004A0250[], D_004A0270[], D_004A0290[], D_004A02B0[], D_004A02C0[], D_004A02D0[], D_004F2EE0[], D_004F2EF0[], D_004F2F00[], D_004F2F10[], D_004F2F20[], D_004F2F30[], D_004F2F40[], D_004F2F50[], D_004F2F60[], D_004F2F70[], D_004F2F80[], D_004F2F90[], D_004F2FA0[], D_004F2FB0[], D_004F2FC0[], D_004F2FD0[], D_004F2FE0[], D_004F2FF0[], D_004F3000[], D_004F3010[], D_004F3020[], D_004F3180[], D_004F31E0[], D_004F3240[], D_004F3298[], UpperBodyNodeTable[];
extern V D_004F2D90, D_004F2DA0, D_004F2DB0, D_004F2DC0, D_004F2DD0, D_004F2DE0, D_004F2DF0, D_004F2E00, D_004F2E10, D_004F2E20, D_004F2E30, D_004F2E40, D_004F2E50, D_004F2E60, D_004F2E70, D_004F2E80, D_004F2E90, D_004F2EA0, D_004F2EB0, D_004F2EC0, D_004F2ED0;
extern SO D_004F3030, D_004F3040, D_004F3050, D_004F3060, D_004F3070, D_004F3080, D_004F3090, D_004F30A0, D_004F30B0, D_004F30C0, D_004F30D0, D_004F30E0, D_004F30F0, D_004F3100, D_004F3110, D_004F3120, D_004F3130, D_004F3140, D_004F3150, D_004F3160, D_004F3170;
extern Ent SecondaryStateTable, D_0049F7E0, D_0049F830, D_0049F880, D_0049F8D0, D_0049F920, D_0049F970, D_0049F9C0, D_0049FA10, D_0049FA60, D_0049FAB0, D_0049FB00, D_0049FB50, D_0049FBA0, D_0049FBF0, D_0049FC40, D_0049FC90, D_0049FCE0, D_0049FD30, D_0049FD80, D_0049FDD0, D_0049FE20, D_0049FE70, D_0049FEC0, D_0049FF10;
}
extern "C" void func_004C90C0(void);
void func_004C90C0(void)
{
    D_0049F718 = 0.35f;
    { float h = 0.5f; D_0049F720 = h; EQh(D_004F2D90, E(0.0f, 0.0f, 0.0f), h); }
    EQ(D_004F2DA0, E(-0.2617994f, 0.0f, 0.0f));
    EQ(D_004F2DB0, E(-0.2617994f, 0.0f, 0.0f));
    EQ(D_004F2DC0, E(0.0f, 0.0f, 0.0f));
    EQ(D_004F2DD0, E(0.0f, 0.0f, 0.0f));
    EQ(D_004F2DE0, E(0.0f, 0.0f, 0.0f));
    EQ(D_004F2DF0, E(0.0f, -0.17453292f, -0.34906584f));
    AQ(D_004F2E00, AA(0.0f, -0.70710677f, 0.70710677f, -1.2217305f));
    EQ(D_004F2E10, E(0.7853982f, 0.0f, 0.0f));
    EQ(D_004F2E20, E(0.0f, 0.0f, 0.0f));
    EQ(D_004F2E30, E(0.0f, 0.17453292f, 0.34906584f));
    AQ(D_004F2E40, AA(0.0f, -0.70710677f, 0.70710677f, 1.2217305f));
    EQ(D_004F2E50, E(0.7853982f, 0.0f, 0.0f));
    EQ(D_004F2E60, E(1.2217305f, 0.0f, 0.0f));
    EQ(D_004F2E70, E(-1.3962634f, 0.0f, 0.0f));
    EQ(D_004F2E80, E(0.0f, 0.0f, 0.0f));
    EQ(D_004F2E90, E(0.0f, 0.0f, 0.0f));
    EQ(D_004F2EA0, E(1.2217305f, 0.0f, 0.0f));
    EQ(D_004F2EB0, E(-1.3962634f, 0.0f, 0.0f));
    EQ(D_004F2EC0, E(0.0f, 0.0f, 0.0f));
    EQ(D_004F2ED0, E(0.0f, 0.0f, 0.0f));
    { float a = 3.1415927f; SinInit(&D_004F3030, a, a, a); }
    __register_global_object(&D_004F3030, func_001D7D90, D_004F2EE0);
    { float a, b, c; c = 0.87266463f; b = 0.6981317f; a = 0.5235988f; SinInit(&D_004F3040, a, b, c); }
    __register_global_object(&D_004F3040, func_001D7D90, D_004F2EF0);
    { float a, b; b = 0.87266463f; a = 0.5235988f; SinInit(&D_004F3050, a, a, b); }
    __register_global_object(&D_004F3050, func_001D7D90, D_004F2F00);
    { float a = 0.7853982f; SinInit(&D_004F3060, a, a, a); }
    __register_global_object(&D_004F3060, func_001D7D90, D_004F2F10);
    { float a = 0.7853982f; SinInit(&D_004F3070, a, a, a); }
    __register_global_object(&D_004F3070, func_001D7D90, D_004F2F20);
    { float a, b; b = 0.61086524f; a = 0.5235988f; SinInit(&D_004F3080, a, b, b); }
    __register_global_object(&D_004F3080, func_001D7D90, D_004F2F30);
    { float a = 1.7453293f; SinInit(&D_004F3090, a, a, a); }
    __register_global_object(&D_004F3090, func_001D7D90, D_004F2F40);
    { float a = 1.5707964f; SinInit(&D_004F30A0, a, a, a); }
    __register_global_object(&D_004F30A0, func_001D7D90, D_004F2F50);
    { float a, b; b = 0.87266463f; a = 1.5707964f; SinInit(&D_004F30B0, a, a, b); }
    __register_global_object(&D_004F30B0, func_001D7D90, D_004F2F60);
    { float a, b; b = 0.61086524f; a = 0.5235988f; SinInit(&D_004F30C0, a, b, b); }
    __register_global_object(&D_004F30C0, func_001D7D90, D_004F2F70);
    { float a = 1.7453293f; SinInit(&D_004F30D0, a, a, a); }
    __register_global_object(&D_004F30D0, func_001D7D90, D_004F2F80);
    { float a = 1.5707964f; SinInit(&D_004F30E0, a, a, a); }
    __register_global_object(&D_004F30E0, func_001D7D90, D_004F2F90);
    { float a, b; b = 0.87266463f; a = 1.5707964f; SinInit(&D_004F30F0, a, a, b); }
    __register_global_object(&D_004F30F0, func_001D7D90, D_004F2FA0);
    { float a, b, c; c = 0.61086524f; b = 1.3089969f; a = 1.3962634f; SinInit(&D_004F3100, a, b, c); }
    __register_global_object(&D_004F3100, func_001D7D90, D_004F2FB0);
    { float a, b, c; c = 0.61086524f; b = 1.3089969f; a = 1.3962634f; SinInit(&D_004F3110, a, b, c); }
    __register_global_object(&D_004F3110, func_001D7D90, D_004F2FC0);
    { float a, b; b = 0.5235988f; a = 0.7853982f; SinInit(&D_004F3120, a, b, b); }
    __register_global_object(&D_004F3120, func_001D7D90, D_004F2FD0);
    { float a, b; b = 0.5235988f; a = 1.5707964f; SinInit(&D_004F3130, a, b, b); }
    __register_global_object(&D_004F3130, func_001D7D90, D_004F2FE0);
    { float a, b, c; c = 0.61086524f; b = 1.3089969f; a = 1.3962634f; SinInit(&D_004F3140, a, b, c); }
    __register_global_object(&D_004F3140, func_001D7D90, D_004F2FF0);
    { float a, b, c; c = 0.61086524f; b = 1.3089969f; a = 1.3962634f; SinInit(&D_004F3150, a, b, c); }
    __register_global_object(&D_004F3150, func_001D7D90, D_004F3000);
    { float a, b; b = 0.5235988f; a = 0.7853982f; SinInit(&D_004F3160, a, b, b); }
    __register_global_object(&D_004F3160, func_001D7D90, D_004F3010);
    { float a, b; b = 0.5235988f; a = 1.5707964f; SinInit(&D_004F3170, a, b, b); }
    __register_global_object(&D_004F3170, func_001D7D90, D_004F3020);
    SetEnt(SecondaryStateTable, 0, Z(), D_0048A6E0, D_0048A820, D_004F31E0, 0, 0, 0, 0);
    SetEnt(D_0049F7E0, 1, Z(), D_0048A6E0, D_0048A820, D_004F31E0, 0, 0, 0, 0);
    SetEnt(D_0049F830, 2, S(D_004A01A0), D_0048A740, D_0048A880, D_0048A4C0, 1, 1, 0, 1);
    SetEnt3(D_0049F880, S(D_004A01C0), D_0048A760, D_0048A8A0, D_0048A3A0, 1, 1, 1, 1);
    SetEnt(D_0049F8D0, 4, S(D_004A01A0), D_0048A740, D_0048A880, D_0048A4C0, 1, 1, 0, 1);
    SetEnt(D_0049F920, 5, S(D_004A01E0), D_0048A7A0, D_0048A8E0, D_0048A520, 1, 1, 1, 1);
    SetEnt(D_0049F970, 6, S(D_004A01F8), D_0048A740, D_0048A880, D_0048A4C0, 1, 1, 0, 1);
    SetEnt(D_0049F9C0, 7, S(D_004A01F8), D_0048A740, D_0048A880, D_0048A4C0, 0, 1, 0, 1);
    SetEnt(D_0049FA10, 8, S(D_004A0210), D_0048A760, D_0048A8A0, D_0048A3A0, 1, 1, 1, 1);
    SetEnt(D_0049FA60, 9, S(D_004A0210), D_0048A760, D_0048A8A0, D_0048A400, 1, 1, 1, 1);
    SetEnt(D_0049FAB0, 0xA, S(D_004A0210), D_0048A760, D_0048A8A0, D_0048A3A0, 1, 1, 1, 1);
    SetEnt(D_0049FB00, 0xB, S(D_004A0210), D_0048A760, D_0048A8A0, D_0048A400, 1, 1, 1, 1);
    SetEnt(D_0049FB50, 0xC, S(D_004A0238), D_0048A780, D_0048A8C0, D_0048A460, 1, 1, 1, 1);
    SetEnt(D_0049FBA0, 0xD, S(D_004A0250), D_0048A7C0, D_0048A900, D_004F3180, 0, 0, 1, 1);
    SetEnt(D_0049FBF0, 0xE, S(D_004A0270), D_0048A7C0, D_0048A900, D_004F3180, 0, 0, 1, 1);
    SetEnt(D_0049FC40, 0xF, S(D_004A0290), D_0048A7C0, D_0048A900, D_004F3180, 0, 0, 1, 1);
    SetEnt(D_0049FC90, 0x10, S(D_004A0238), D_0048A780, D_0048A8C0, D_0048A460, 1, 0, 1, 1);
    SetEnt(D_0049FCE0, 0x11, S(D_004A02B0), D_0048A720, D_0048A860, D_0048A580, 0, 0, 0, 0);
    SetEnt(D_0049FD30, 0x12, S(D_004A02C0), D_0048A720, D_0048A860, D_0048A580, 0, 0, 0, 0);
    SetEnt(D_0049FD80, 0x13, S(D_004A01F8), D_0048A720, D_0048A860, D_0048A580, 0, 0, 0, 0);
    SetEnt(D_0049FDD0, 0x14, S(D_004A02D0), D_0048A720, D_0048A860, D_0048A580, 0, 0, 0, 0);
    SetEnt(D_0049FE20, 0x15, Z(), D_0048A700, D_0048A840, D_004F3180, 0, 0, 0, 0);
    SetEnt(D_0049FE70, 0x16, Z(), D_0048A720, D_0048A860, D_0048A5E0, 0, 1, 0, 0);
    SetEnt(D_0049FEC0, 0x17, S(D_004A01A0), D_0048A7E0, D_0048A920, D_0048A640, 1, 1, 0, 1);
    SetEnt(D_0049FF10, 0x18, S(D_004A01E0), D_0048A800, D_0048A940, D_004F3240, 0, 0, 1, 1);
    __construct_array(UpperBodyNodeTable, func_001DFA30, func_001DF9E0, 0x100, 0x15);
    __register_global_object(UpperBodyNodeTable, func_001DF980, D_004F3298);
}
