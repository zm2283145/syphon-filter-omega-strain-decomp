#pragma cplusplus on
#include "types.h"
/* propagation off keeps the inlined copies' dead address computations; loops test at the bottom */
#pragma opt_propagation off
#pragma opt_rotateloops off

extern "C" {
long long strtod(char*, char**);
float SoftFloat_DoubleToFloat(long long);
char* strchr(const char*, int);
long strtoul(char*, char**, int);
long strtol(char*, char**, int);
float SoftFloat_U64ToFloat(unsigned long long);
float SoftFloat_S64ToFloat(long long);
long long SoftFloat_DoubleMultiply(long long, long long);
int SoftFloat_DoubleNotEqual(long long, long long);
char* strncpy(char*, const char*, int);
void String_Copy(char*, const char*);
void ParticleLib_NormalizeName(char*, char*, int);
extern char D_004BC648[];
}

/* max.s has no C form */
static inline float FMax_43A0(float lo, float x) { float r; asm { max.s r, x, lo } return r; }
/* VU0 identity-matrix store (vf0/qmfc2/pexcw): no C equivalent */
static inline void UnitMtx_43A0(void* p) { void* d = p; __int128 t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(d) : "memory"); }

struct V4_43A0 {
    float x, y, z, w;
    V4_43A0() {}
    V4_43A0(const V4_43A0& o)
    {
        { void* xx = this; } /* dead on purpose: retail computes the destination first */
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
    }
    V4_43A0& operator=(const V4_43A0& o)
    {
        { void* xx = this; } /* dead on purpose: retail computes the destination first */
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct Mk_43A0 : V4_43A0 {
    Mk_43A0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

struct Range_43A0 {
    V4_43A0 a, b;
    Range_43A0(const V4_43A0& pa, const V4_43A0& pb) : a(pa), b(pb) {}
    Range_43A0& operator=(const Range_43A0& o)
    {
        __int128 qa, qb;
        __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); sq %1, 0x10(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
};

struct Mtx_43A0 {
    V4_43A0 r[4];
    /* VU0 identity-matrix store (vf0/qmfc2/pexcw): no C equivalent */
    void Identity()
    {
        { void* xx = this; } /* dead on purpose: retail computes the matrix address twice */
        __int128 t;
        __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(this) : "memory");
    }
};

struct Ent_43A0 {
    char name[0x10];
    int cnt;
    float key[16];
    float val[16];
    char pad94[0xA0 - 0x94];
    Mtx_43A0 m;
};

struct PD_43A0 {
    virtual void v0();
    virtual void Parse(char* s, float ver);
    virtual void Bounds(float* c, V4_43A0* lo, V4_43A0* hi);
    char pad4[0xC - 0x4];
    int i0C;
    float f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34;
    int i38, i3C;
    float f40, f44, f48, f4C, f50, f54;
    int i58, i5C, i60;
    unsigned char b64;
    float f68, f6C, f70;
    char pad74[0x140 - 0x74];
    float f140[3];
    float f14C;
    char pad150[0x15C - 0x150];
    float f15C;
    char pad160[0x16C - 0x160];
    float f16C;
    char name170[0x10];
    int i180;
    char pad184[0x190 - 0x184];
    Ent_43A0 e[8];
    Range_43A0 r890;
    Mtx_43A0 m8B0;
    int i8F0;
};

#define RD() SoftFloat_DoubleToFloat(strtod(s, &s))
#define NL() s = strchr(s, '\n') + 1
#define HALF ((long long)0x3FE00000 << 32)

extern "C" bool ParticleDef_ParseCommon(PD_43A0* self, char* str, char* name, float ver)
{
    char* s = str;
    bool ok; /* a bool local gives retail's daddiu return value */
    V4_43A0 lo;
    V4_43A0 hi;
    self->f140[0] = RD();
    self->f140[1] = RD();
    self->f140[2] = RD();
    NL();
    lo.w = RD();
    NL();
    self->i0C = strtoul(s, &s, 10);
    self->f10 = SoftFloat_U64ToFloat(strtoul(s, &s, 10));
    NL();
    self->f14 = SoftFloat_DoubleToFloat(SoftFloat_DoubleMultiply(HALF, strtod(s, &s)));
    self->f18 = RD();
    NL();
    self->f1C = SoftFloat_DoubleToFloat(SoftFloat_DoubleMultiply(HALF, strtod(s, &s)));
    self->f20 = 1.0f / FMax_43A0(1e-7f, RD());
    NL();
    self->f24 = SoftFloat_DoubleToFloat(SoftFloat_DoubleMultiply(HALF, strtod(s, &s)));
    self->f28 = 1.0f / FMax_43A0(1e-7f, RD());
    NL();
    self->f50 = RD();
    self->f2C = RD();
    if (ver < 1.9f) {
        self->f50 *= 0.5f;
        self->f2C *= 0.5f;
    }
    self->f14C = self->f50;
    NL();
    self->f30 = self->f14C / FMax_43A0(1e-7f, RD());
    self->f34 = 1.0f / FMax_43A0(1e-7f, RD());
    NL();
    if (ver >= 2.0f) {
        self->i58 = strtoul(s, &s, 10);
        self->f54 = RD();
        NL();
    } else {
        self->i58 = 0;
    }
    self->i38 = strtoul(s, &s, 10);
    NL();
    self->i3C = strtoul(s, &s, 10);
    self->f40 = RD();
    self->f44 = SoftFloat_DoubleToFloat(SoftFloat_DoubleMultiply((long long)0x40600000 << 32, strtod(s, &s)));
    self->f48 = RD();
    NL();
    if (ver >= 1.9f) {
        self->f4C = RD();
        NL();
    } else {
        *(int*)&self->f4C = 0;
    }
    if (strchr(s, ';')[1] == 's') {
        self->i5C = strtol(s, &s, 10);
        NL();
    } else {
        self->i5C = 0;
    }
    if (ver >= 1.5f) {
        self->i60 = strtoul(s, &s, 10);
        NL();
    } else {
        self->i60 = 0;
    }
    if (ver >= 1.9f) {
        self->b64 = SoftFloat_DoubleNotEqual(strtod(s, &s), 0);
        NL();
        self->f68 = RD();
        self->f6C = RD();
        self->f70 = RD();
        NL();
    } else {
        self->b64 = 0;
        *(int*)&self->f68 = 0;
    }
    if (ver >= 2.0f) {
        self->i8F0 = strtoul(s, &s, 10);
        NL();
    } else {
        self->i8F0 = 0;
    }
    NL();
    if (*s != ' ' && name) {
        int n = 0;
        s = strchr(s, ';') - 5;
        while ((s - n)[-1] != '\\') n++;
        strncpy(name, s - n, n);
        String_Copy(name + n, D_004BC648);
    } else {
        *name = 0;
    }
    NL();
    NL();
    NL();
    lo.x = RD();
    lo.y = RD();
    lo.z = RD();
    self->f15C = 1.0f / FMax_43A0(1e-7f, RD());
    NL();
    hi.x = RD();
    hi.y = RD();
    hi.z = RD();
    self->f16C = 1.0f / FMax_43A0(1e-7f, RD());
    NL();
    {
        char* e = strchr(s, ';');
        *(__int128*)self->name170 = 0;
        ParticleLib_NormalizeName(self->name170, s, e - s - 1);
    }
    NL();
    self->i180 = strtoul(s, &s, 10);
    NL();
    for (int i = 0; i < self->i180; i++) {
        {
            char* e = strchr(s, ';');
            int off = i * sizeof(Ent_43A0); /* explicit offset: retail adds it before self */
            Ent_43A0* en = (Ent_43A0*)(off + (char*)self->e);
            *(__int128*)en->name = 0;
            ParticleLib_NormalizeName(en->name, s, e - s - 1);
        }
        NL();
        int cnt = strtoul(s, &s, 10);
        if (s[1] == 'n' || s[2] == 'n') {
            self->e[i].cnt = cnt;
            if (cnt > 0) {
                NL();
                for (int k = 0; k < cnt; k++) {
                    self->e[i].key[k] = SoftFloat_S64ToFloat(strtol(s, &s, 10)) / 60.0f;
                    self->e[i].val[k] = RD();
                }
            }
        } else {
            self->e[i].cnt = 1;
            *(int*)&self->e[i].key[0] = 0;
            self->e[i].val[0] = 1.0f;
        }
        NL();
        UnitMtx_43A0(&self->e[i].m);
        self->e[i].m.r[0].x = RD();
        self->e[i].m.r[0].y = RD();
        self->e[i].m.r[0].z = RD();
        NL();
        self->e[i].m.r[1].x = RD();
        self->e[i].m.r[1].y = RD();
        self->e[i].m.r[1].z = RD();
        if (s[1] == 'm' || s[2] == 'm') {
            NL();
            self->e[i].m.r[2].x = RD();
            self->e[i].m.r[2].y = RD();
            self->e[i].m.r[2].z = RD();
            NL();
            self->e[i].m.r[3].x = RD();
            self->e[i].m.r[3].y = RD();
            self->e[i].m.r[3].z = RD();
            NL();
        } else {
            V4_43A0 t(self->e[i].m.r[0]);
            self->e[i].m.r[3] = t;
            NL();
        }
    }
    {
    V4_43A0 c0;
    V4_43A0 c1;
    if (ver >= 1.6f) {
        c0.x = RD();
        c0.y = RD();
        c0.z = RD();
        c0.w = 1.0f;
        NL();
        if (ver >= 1.7f) {
            c1.x = RD();
            c1.y = RD();
            c1.z = RD();
            c1.w = 1.0f;
            NL();
        } else {
            c0 = Mk_43A0(0.0f, 0.0f, 0.0f, 1.0f);
            c1 = Mk_43A0(0.0f, 0.0f, 0.0f, 1.0f);
        }
    } else {
        c0 = Mk_43A0(0.0f, 0.0f, 0.0f, 1.0f);
        c1 = Mk_43A0(0.0f, 0.0f, 0.0f, 1.0f);
    }
    self->r890 = Range_43A0(c0, c1);
    }
    if (ver >= 1.9f) {
        self->m8B0.Identity();
        self->m8B0.r[0].x = RD();
        self->m8B0.r[0].y = RD();
        self->m8B0.r[0].z = RD();
        NL();
        self->m8B0.r[1].x = RD();
        self->m8B0.r[1].y = RD();
        self->m8B0.r[1].z = RD();
        NL();
        self->m8B0.r[2].x = RD();
        self->m8B0.r[2].y = RD();
        self->m8B0.r[2].z = RD();
        NL();
    } else {
        self->m8B0.Identity();
    }
    self->Parse(s, ver);
    self->Bounds(self->f140, &lo, &hi);
    ok = 1;
    return ok;
}
