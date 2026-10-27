#pragma cplusplus on
#pragma opt_rotateloops off
#include "types.h"

typedef unsigned long long u64_t;

struct V4_0050 {
    float x, y, z, w;
    V4_0050() {}
    V4_0050(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4_0050& operator=(const V4_0050& o)
    {
        { void* xx = this; } /* dead on purpose: retail computes the destination first */
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
/* quadword copy through a register (lq/sq) */
static inline void QC_0050(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct Q_0050 { __int128 q; };


extern "C" {
extern char D_00537F80[];
extern char g_Video[];
extern char D_00538080[];
extern char D_0053B6A0[];
extern unsigned char D_0053B540;
extern unsigned int* D_005381C8;
unsigned int* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(void* q, int a, int b, int c, int d);
void cDmaMan_EndChain_int_ulongP(void* q, int a, void* end);
int XLib_GetTexMan(void* r);
void* cTexMan_GetHalTexture(int reg, int tex);
u64_t* cTexture_GetTEX1_1(void* t);
u64_t* cTexture_GetTEX0_1(void* t);
void MEMCPY16(void* d, void* s, int n);
Q_0050* cRandomVector_Vector(void* tbl, int i);
unsigned int cVU1Man_GetMSCAL(void* q, int n);
}

static inline unsigned int Unpack_0050(unsigned int a, unsigned int n) { return (0x6C000000 | ((n) << 16) | (a)); }
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

/* the original copies quadwords into the packet with this inline-asm loop */
static inline void QCopy_0050(const void* s, void* d, int n)
{
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
/* per-site copy of QCopy_0050: parameter order picks retail registers */
static inline void QCopy1_0050(void* d, int n, const void* s)
{
    __int128 t;
    const void* ss = s;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu d, d, 0x10
        addi n, n, -1
        addiu ss, ss, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

static inline void V3Copy_0050(V4_0050* d, const V4_0050* s)
{
    float w = d->w;
    QC_0050(d, s);
    d->w = w;
}

static inline void Vif_Put(unsigned int v)
{
    unsigned int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = v;
}

/* same as Vif_Put with the value copied first (register choice at the first site) */
static inline void Vif_PutV(unsigned int v)
{
    unsigned int x = v;
    unsigned int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = x;
}

static inline void Vif_PadTo(unsigned int m)
{
    while (((unsigned int)D_005381C8 & 0xF) != m) {
        Vif_Put(0);
    }
}

extern "C" void cParticleSpline_Render(char* e, float t, float a, float b, float c)
{
    float x;
    float y;
    float z;
    float w;
    int i;
    if (F_(e, 0x6C, int) <= 0) return;
    x = 0.0f;
    F_(e, 0xAC, float) = a;
    y = 1.0f / (1.0f + x);
    F_(F_(e, 0x100, char*), 0x94C, float) = t - F_(e, 0x64, float);
    z = x;
    F_(F_(e, 0x100, char*), 0x970, float) = b;
    w = x;
    if (F_(F_(e, 0x100, char*), 0x8F0, int)) {
        V3Copy_0050((V4_0050*)(F_(e, 0x100, char*) + 0x900), (V4_0050*)(e + 0x50));
    }
    if (!D_0053B540 || !F_(F_(e, 0x100, char*), 0x58, int)) {
        F_(F_(e, 0x100, char*), 0x90C, float) = F_(F_(e, 0x100, char*), 0x50, float) * c;
    } else {
        F_(F_(e, 0x100, char*), 0x90C, float) = F_(F_(e, 0x100, char*), 0x54, float) * c;
    }
    for (i = 0; i < F_(F_(e, 0x100, char*), 0x3C, int) + 1; i++) {
        char* s3;
        char* s7;
        int left;
        int lim;
        u64_t* p;
        *(V4_0050*)(e + 0xC0) = V4_0050(x, y, z, w);
        D_005381C8 = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 0);
        Vif_PutV(0x11000000);
        Vif_Put(0);
        Vif_PadTo(0xC);
        Vif_Put(Unpack_0050(0xF, 7));
        QCopy1_0050(D_005381C8, 7, e + 0x90);
        D_005381C8 += 0x1C;
        {
            char* src = F_(e, 0x100, char*) + 0x900;
            Vif_PadTo(0xC);
            Vif_Put(Unpack_0050(0x16, 0xB));
            QCopy_0050(src, D_005381C8, 0xB);
        }
        D_005381C8 += 0x2C;
        Vif_PadTo(0);
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, D_005381C8);
        s3 = F_(e, 0x100, char*);
        s7 = F_(e, 0x70, char*);
        left = F_(e, 0x6C, int);
        x -= F_(s3, 0x40, float);
        z += F_(s3, 0x44, float);
        w += F_(s3, 0x48, float);
        F_(s3, 0xB0, u64_t) = *cTexture_GetTEX1_1(cTexMan_GetHalTexture(XLib_GetTexMan(g_Video), F_(s3, 0x74, int)));
        F_(s3, 0xC0, u64_t) = *cTexture_GetTEX0_1(cTexMan_GetHalTexture(XLib_GetTexMan(g_Video), F_(s3, 0x74, int)));
        lim = 0x21;
        if (F_(s3, 0x64, unsigned char)) {
            F_(s3, 0xB8, u64_t) = 0x15;
            lim = 0xE;
            F_(s3, 0xC8, u64_t) = 7;
            F_(s3, 0xD0, u64_t) = 1 | ((u64_t)0x612F4000 << 32);
            F_(s3, 0xD8, u64_t) = 1 | ((u64_t)0x602F4000 << 32);
        }
        p = (u64_t*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 1);
        *p = 0;
        p++;
        while (left > 0) {
            int n = left < lim ? left : lim;
            F_(s3, 0x130, u64_t) = (long long)n | (0x8000 | ((u64_t)0x602F4000 << 32));
            *p = 0;
            p++;
            *p = (u64_t)0x6C0D8000 << 32;
            p++;
            MEMCPY16(p, s3 + 0x80, 0xC);
            p += 0x18;
            *(Q_0050*)p = *cRandomVector_Vector(D_0053B6A0, (int)(s7 + left));
            p += 2;
            *p = cVU1Man_GetMSCAL(D_00538080, 0x18);
            p++;
            *p = 0;
            p++;
            left -= n;
        }
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, p);
    }
}
