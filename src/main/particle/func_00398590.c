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
unsigned int* DmaPacket_Open(void* q, int a, int b, int c, int d);
void DmaPacket_Close(void* q, int a, void* end);
int func_003797D0(void* r);
void* func_00398B00(int reg, int tex);
u64_t* Gs_MakeTex1(void* t);
u64_t* func_00379700(void* t);
void func_001AE170(void* d, void* s, int n);
Q_0050* ParticleRandom_QwordAt(void* tbl, int i);
unsigned int func_003700D0(void* q, int n);
float Math_Powf(float x, float y);
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

extern "C" void PhysEmitter_Draw(char* e, float t, float a, float b, float c)
{
    float u;
    float v;
    float z;
    float w;
    float el;
    int i;
    if (F_(e, 0x6C, int) <= 0) return;
    z = 0.0f;
    w = z;
    el = t + F_(F_(e, 0x120, char*), 0x9B0, float) - F_(e, 0x64, float);
    if (F_(F_(e, 0x120, char*), 0x3C, int) > 0) {
        u = 60.0f * el;
        v = 60.0f * F_(F_(e, 0x120, char*), 0x40, float);
    } else {
        v = z;
        u = 60.0f * el;
    }
    if (F_(F_(e, 0x120, char*), 0x8F0, int)) {
        V3Copy_0050((V4_0050*)(F_(e, 0x120, char*) + 0x980), (V4_0050*)(e + 0x50));
    }
    if (!D_0053B540 || !F_(F_(e, 0x120, char*), 0x58, int)) {
        F_(F_(e, 0x120, char*), 0x98C, float) = F_(F_(e, 0x120, char*), 0x50, float) * c;
    } else {
        F_(F_(e, 0x120, char*), 0x98C, float) = F_(F_(e, 0x120, char*), 0x54, float) * c;
    }
    F_(e, 0xAC, float) = a;
    F_(e, 0xBC, float) = b;
    for (i = 0; i < F_(F_(e, 0x120, char*), 0x3C, int) + 1; i++) {
        char* s3;
        char* s7;
        int left;
        int lim;
        u64_t* p;
        float pw = Math_Powf(u, F_(F_(e, 0x120, char*), 0x9A8, float));
        float pk = pw * F_(F_(e, 0x120, char*), 0x9AC, float);
        *(V4_0050*)(e + 0xC0) = V4_0050(el, u, z, w);
        F_(F_(e, 0x120, char*), 0x920, float) = pw;
        F_(F_(e, 0x120, char*), 0x930, float) = pk;
        D_005381C8 = DmaPacket_Open(D_00537F80, 1, 1, 0, 0);
        Vif_PutV(0x11000000);
        Vif_Put(0);
        Vif_PadTo(0xC);
        Vif_Put(Unpack_0050(0xF, 5));
        QCopy1_0050(D_005381C8, 5, e + 0x90);
        D_005381C8 += 0x14;
        {
            char* src = F_(e, 0x120, char*) + 0x900;
            Vif_PadTo(0xC);
            Vif_Put(Unpack_0050(0x14, 9));
            QCopy_0050(src, D_005381C8, 9);
        }
        D_005381C8 += 0x24;
        Vif_PadTo(0);
        DmaPacket_Close(D_00537F80, 1, D_005381C8);
        s3 = F_(e, 0x120, char*);
        s7 = F_(e, 0x70, char*);
        left = F_(e, 0x6C, int);
        u -= v;
        z += F_(s3, 0x44, float);
        w += F_(s3, 0x48, float);
        F_(s3, 0xB0, u64_t) = *Gs_MakeTex1(func_00398B00(func_003797D0(g_Video), F_(s3, 0x74, int)));
        F_(s3, 0xC0, u64_t) = *func_00379700(func_00398B00(func_003797D0(g_Video), F_(s3, 0x74, int)));
        lim = 0x21;
        if (F_(s3, 0x64, unsigned char)) {
            F_(s3, 0xB8, u64_t) = 0x15;
            lim = 0xE;
            F_(s3, 0xC8, u64_t) = 7;
            F_(s3, 0xD0, u64_t) = 1 | ((u64_t)0x612F4000 << 32);
            F_(s3, 0xD8, u64_t) = 1 | ((u64_t)0x602F4000 << 32);
        }
        p = (u64_t*)DmaPacket_Open(D_00537F80, 1, 1, 0, 1);
        *p = 0;
        p++;
        while (left > 0) {
            int n = left < lim ? left : lim;
            F_(s3, 0x130, u64_t) = (long long)n | (0x8000 | ((u64_t)0x602F4000 << 32));
            *p = 0;
            p++;
            *p = (u64_t)0x6C0D8000 << 32;
            p++;
            func_001AE170(p, s3 + 0x80, 0xC);
            p += 0x18;
            *(Q_0050*)p = *ParticleRandom_QwordAt(D_0053B6A0, (int)(s7 + left));
            p += 2;
            *p = func_003700D0(D_00538080, 0x16);
            p++;
            *p = 0;
            p++;
            left -= n;
        }
        DmaPacket_Close(D_00537F80, 1, p);
        if (u < 0.0f) u = u; /* no-op on purpose: retail keeps this compare (its body was compiled out) */
    }
}
