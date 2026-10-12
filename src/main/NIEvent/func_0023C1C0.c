#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#include "v4_asm_copy.h"
#include "q4r.h"
struct V4_23C1C0 {
    float x, y, z, w;
    V4_23C1C0() {}
    V4_23C1C0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M4_23C1C0;
extern "C" M4_23C1C0* Mtx_FromRowsAndTranslation(M4_23C1C0* o, const V4_23C1C0& a, const V4_23C1C0& b, const V4_23C1C0& c, const V4_23C1C0& d);
struct M4_23C1C0 { __int128 q[4];
    M4_23C1C0() {}
    M4_23C1C0(const V4_23C1C0& a, const V4_23C1C0& b, const V4_23C1C0& c, const V4_23C1C0& d) { const V4_23C1C0* pa = &a; Mtx_FromRowsAndTranslation(this, *pa, b, c, d); }
};
struct X_23C1C0 {
    V4_23C1C0 pos;
    M4_23C1C0 m;
    X_23C1C0(const V4_23C1C0& p, const M4_23C1C0& mm) {
        V4_23C1C0* pd = &pos;
        const V4_23C1C0* ps = &p;
        __int128 tt = V4Load(ps);
        M4_23C1C0* d = &m;
        __int128 qa;
        __int128 qb;
        const M4_23C1C0* s = &mm;
        V4Store(pd, tt);
        Q4COPY_N(d, s, qa, qb)
    }
};
typedef struct { int version; int size; unsigned int base; char* cur; } Pop_23C1C0;
struct Name_23C1C0 { char* p; Name_23C1C0(char* s) : p(s) {} };
static inline char* ReadStr_23C1C0(Pop_23C1C0* r)
{
    char* s = r->cur;
    int mis;
    while (*r->cur++)
        ;
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    return s;
}
class Tgt_23C1C0 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c)
    virtual void SetXform(const X_23C1C0& x);
    virtual void SetName(const struct Name_23C1C0& n);
};
struct Self_23C1C0 {
    char pad0[0x2F];
    unsigned char b2F;
    char pad30[0x140 - 0x30];
    Tgt_23C1C0* tgt;
};
extern "C" {
extern char D_004A6FA8[];
void* Mem_Alloc(int pool, int size, char* file, int line);
Tgt_23C1C0* func_001C5950(void* p, int* desc, int v);
}
extern "C" void NiEvent_LoadParticleAsset(Self_23C1C0* self, Pop_23C1C0* r)
{
    int mis;
    X_23C1C0 x(V4_23C1C0(0.0f, 0.0f, 0.0f, 0.0f), M4_23C1C0(V4_23C1C0(1.0f, 0.0f, 0.0f, 1.0f), V4_23C1C0(0.0f, 1.0f, 0.0f, 1.0f),
                  V4_23C1C0(0.0f, 0.0f, 1.0f, 1.0f), V4_23C1C0(0.0f, 0.0f, 0.0f, 1.0f)));
    const Name_23C1C0& name = Name_23C1C0(ReadStr_23C1C0(r));
    Tgt_23C1C0* t;
    int zero;
    {
        AllocGuard g;
        t = (Tgt_23C1C0*)Mem_Alloc(0, 0x74, D_004A6FA8, 0x37B);
    }
    if (t) {
        zero = 0;
        t = func_001C5950(t, &zero, -1);
    }
    self->tgt = t;
    self->tgt->SetXform(x);
    self->tgt->SetName(name);
    self->b2F = 1;
}
