/*
 * Libs/SFOLib/Source/particle: 13 files, 003A3550-003A3890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A3550 */
#pragma push /* merge_units */
#include "types.h"
#include "iter_return_copy.h"

/* Return the end iterator. */
DEFINE_ITER_END(std_list_cParticleDefinitionPtr_end_void)
static inline void merge_flush_func_003A3550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3550 */

/* merge_units: begin func_003A3580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Small container helpers.
 */


Word* cConstLListIterator_cParticleDefinitionPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003A3580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3580 */

/* merge_units: begin func_003A3590 */
#pragma push /* merge_units */
/* Return the begin iterator. */
DEFINE_ITER_BEGIN(std_list_cParticleDefinitionPtr_begin_void)
static inline void merge_flush_func_003A3590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3590 */

/* merge_units: begin func_003A35C0 */
#pragma push /* merge_units */
#pragma opt_propagation off

/* Look up a resource by its lower-cased short name (up to 16 chars, stops at '.'). */
typedef struct { __int128 q; } Name_3A35C0;
extern Name_3A35C0 D_0053BAB0;
extern char Libc_Tolower(char c);
extern void GetEffectID__15cParticleSystemCFRC1(void* self, char* name);

void cParticleSystem_GetEffectID(void* self, const char* s)
{
    Name_3A35C0* name = &D_0053BAB0;
    unsigned int i;
    char* o;
    int c;
    name->q = 0;
    for (i = 0, o = (char*)name; i < 16 && (c = s[i]) != 0 && c != '.'; i++)
        *o++ = Libc_Tolower(c);
    GetEffectID__15cParticleSystemCFRC1(self, (char*)name);
}
#pragma opt_propagation reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A35C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A35C0 */

/* merge_units: begin func_003A3670 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "alloc_guard.h"
/* cParticleSystem_Clear: destroy every loaded particle definition (releasing its texture), empty the list, free the four shared buffers */
struct PDef { virtual void Destroy(int flags); char pad4[0x74 - 4]; int tex; };
typedef struct PNode { struct PNode* prev; struct PNode* next; PDef* d; } PNode;
union PItU { PNode* n; };
typedef struct { PNode* n; } PIt;
typedef struct { int pad; PNode header; } PList;
struct PLib { int pad0; PList defs; };
struct PBuf { void* p; int n; int pad[2]; };
extern "C" {
extern int g_TextureMgr;
extern PBuf D_0053B560[4];
extern char D_004BC5D0[];
#if 0 /* merge_units */
void std_list_cParticleDefinitionPtr_begin_void_2(PIt* out, PList* l);
#endif /* merge_units */
void std_list_cParticleDefinitionPtr_begin_void_2(Iter* out, PtrVec* v); /* merge_units */
#define std_list_cParticleDefinitionPtr_begin_void_2(a0, a1) (std_list_cParticleDefinitionPtr_begin_void_2((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
PIt* cLListIterator_cParticleDefinitionPtr_ctor(PIt* dst, PIt* src);
#endif /* merge_units */
Word* cLListIterator_cParticleDefinitionPtr_ctor(Word* dst, Word* src); /* merge_units */
#define cLListIterator_cParticleDefinitionPtr_ctor(a0, a1) ((PIt *)cLListIterator_cParticleDefinitionPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_cParticleDefinitionPtr_end_void_2(PIt* out, PList* l);
#endif /* merge_units */
void std_list_cParticleDefinitionPtr_end_void_2(Iter* out, Tree* t); /* merge_units */
#define std_list_cParticleDefinitionPtr_end_void_2(a0, a1) (std_list_cParticleDefinitionPtr_end_void_2((Iter *)(a0), (Tree *)(a1))) /* merge_units */

void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(PIt* out, PList* l, PIt* first, PIt* last);
void cTexMan_RemoveTexture(int a, int b, int c);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cParticleSystem_Clear(PLib* lib);
}
static inline void Begin_(PIt* out, PList* l) { PIt t; std_list_cParticleDefinitionPtr_begin_void_2(&t, l); cLListIterator_cParticleDefinitionPtr_ctor(out, &t); }
static inline void End_(PIt* out, PList* l) { PIt t; std_list_cParticleDefinitionPtr_end_void_2(&t, l); cLListIterator_cParticleDefinitionPtr_ctor(out, &t); }
void cParticleSystem_Clear(PLib* lib)
{
    PItU it;
    PIt b;
    PIt e;
    Begin_(&b, &lib->defs);
    it = *(PItU*)&b;
    while (End_(&e, &lib->defs), it.n != e.n) {
        PDef* d = it.n->d;
        cTexMan_RemoveTexture(g_TextureMgr, d->tex, 0);
        {
            AllocGuard g;
            d->Destroy(-1);
            cMemMan_Deallocate(0, d, D_004BC5D0, 0x4A7);
        }
        it.n = it.n->next;
    }
    PIt r;
    PIt first;
    PIt last;
    last.n = &lib->defs.header;
    first.n = lib->defs.header.next;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, &lib->defs, &first, &last);
    int i;
    for (i = 0; i < 4; i++) {
        PBuf* s = &D_0053B560[i];
        void* p = s->p;
        if (p) {
            {
                AllocGuard g2;
                cMemMan_Deallocate(0, p, D_004BC5D0, 0xD65);
            }
            s->n = 0;
            s->p = 0;
        }
    }
}
#undef std_list_cParticleDefinitionPtr_begin_void_2 /* merge_units */
#undef cLListIterator_cParticleDefinitionPtr_ctor /* merge_units */
#undef std_list_cParticleDefinitionPtr_end_void_2 /* merge_units */
static inline void merge_flush_func_003A3670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3670 */

/* merge_units: begin func_003A3890 */
#pragma push /* merge_units */
void std_list_cParticleDefinitionPtr_end_void_2(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_003A3890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3890 */

/* merge_units: begin func_003A38A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern void * const D_004DFAA0[];
extern "C" VtableChainObject* cParticleDefinition_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFAA0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFAA0[6] = { (void*)0x0, (void*)0x0, (void*)cParticleDefinition_dtor, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_003A38A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A38A0 */

/* merge_units: begin func_003A38F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Small container helpers.
 */


Word* cLListIterator_cParticleDefinitionPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cParticleDefinitionPtr_begin_void_2(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A38F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A38F0 */

/* merge_units: begin func_003A3910 */
#pragma push /* merge_units */
typedef struct Obj3A39 {
    char pad00[0x10];
    int target;            /* 0x10 */
    int unk14;             /* 0x14 */
    char pad18[4];
    unsigned char unk1C;   /* 0x1C */
} Obj3A39;

#if 0 /* merge_units */
extern int D_0053B560;
#endif /* merge_units */
#define D_0053B560 (*(int*)&D_0053B560) /* merge_units */

extern int D_0053B564;
extern int D_0053B570;
extern int D_0053B574;
extern int D_0053B580;
extern int D_0053B584;
extern int D_0053B590;
extern int D_0053B594;
extern unsigned long long D_0053B680;
extern unsigned long long D_0053B688;
extern unsigned long long D_0053B690;
extern unsigned long long D_0053B698;

/* Resets the object and the four global register slots (GS register tags 0x44/0x68/0x48/0x46). */
void cParticleSystem_Init(Obj3A39* obj, int target) {
    obj->target = target;
    obj->unk14 = 0;
    obj->unk1C = 0;
    D_0053B564 = 0;
    D_0053B560 = 0;
    D_0053B680 = 0x44 | ((unsigned long long)0x80 << 32);
    D_0053B574 = 0;
    D_0053B688 = 0x68 | ((unsigned long long)0x80 << 32);
    D_0053B570 = 0;
    D_0053B690 = 0x48 | ((unsigned long long)0x80 << 32);
    D_0053B584 = 0;
    D_0053B698 = 0x46 | ((unsigned long long)0x80 << 32);
    D_0053B580 = 0;
    D_0053B594 = 0;
    D_0053B590 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3910(void) {}
#undef D_0053B560 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A3910 */

/* merge_units: begin func_003A39B0 */
#pragma push /* merge_units */
/* cSplineDefinition_SetMiscData (particle, mw38): copy two V4s and a {xyz,(float)count} V4 into a particle emitter.
   GCC-style volatile lq/sq copy + dead address locals give retail's duplicate addius (LESSONS c57da). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { float x, y, z; } V3;
typedef struct P39 { char pad0[0x900]; V4 m900; char pad910[0x40]; V4 m950; V4 m960; char pad970[0xCC]; unsigned int nA3C; } P39;
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline V4* VA(V4* d, const V4* s) { GQ(d, s); return d; }
static inline void MK(V4* t, float x, float y, float z, float w) { t->x = x; t->y = y; t->z = z; t->w = w; }
#pragma peephole off
void cSplineDefinition_SetMiscData(P39* p, const V4* a, const V4* b, const V3* c)
{
    V4 t;
    void* xx;
    void* yy;
    VA(&p->m900, a);
    xx = &p->m950; /* dead on purpose */
    VA(&p->m950, b);
    MK(&t, c->x, c->y, c->z, (float)p->nA3C);
    yy = &p->m960; /* dead on purpose */
    VA(&p->m960, &t);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A39B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A39B0 */

/* merge_units: begin func_003A3A40 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off

extern "C" {
int strtod(char*, char**);
float SoftFloat_DoubleToFloat(int);
char* strchr(const char*, int);
long strtoul(char*, char**, int);
}

struct V4_3A3A40 {
    float x, y, z, w;
    V4_3A3A40& operator=(const V4_3A3A40& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct Obj3A3A40 {
    char pad0[0x18];
    float f18, f1C, f20, f24, f28, f2C, f30, f34;
    char pad38[0x4C - 0x38];
    float f4C;
    char pad50[0x64 - 0x50];
    unsigned char b64;
    char pad65[0x15C - 0x65];
    float f15C;
    char pad160[0x16C - 0x160];
    float f16C;
    char pad170[0x8F4 - 0x170];
    int i8F4;
    char pad8F8[0x910 - 0x8F8];
    V4_3A3A40 v910, v920, v930, v940;
    char pad950[0x974 - 0x950];
    float f974, f978;
    char pad97C[0x980 - 0x97C];
    float f980, f984, f988, f98C;
    V4_3A3A40 v990;
    float f9A0, f9A4, f9A8, f9AC;
    char pad9B0[0xA20 - 0x9B0];
    float fA20, fA24, fA28, fA2C, fA30, fA34, fA38;
    int iA3C;
    float fA40, fA44, fA48, fA4C, fA50, fA54, fA58, fA5C, fA60, fA64, fA68, fA6C;
};

struct Mk3A3A40 : V4_3A3A40 {
    Mk3A3A40(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

#define RD() SoftFloat_DoubleToFloat(strtod(s, &s))
#define NL() s = strchr(s, '\n') + 1

extern "C" void cSplineDefinition_Load(Obj3A3A40* self, char* str)
{
    char* s = str;
    self->fA20 = RD();
    self->fA24 = RD();
    self->fA28 = RD();
    NL();
    self->fA2C = RD();
    self->fA30 = RD();
    NL();
    self->fA34 = RD();
    self->fA38 = RD();
    self->iA3C = strtoul(s, &s, 10);
    NL();
    self->fA40 = RD();
    self->fA44 = RD();
    self->fA48 = RD();
    self->fA4C = 1.0f;
    NL();
    self->fA50 = RD();
    self->fA54 = RD();
    self->fA58 = RD();
    self->fA5C = 1.0f;
    NL();
    self->fA60 = RD();
    self->fA64 = RD();
    self->fA68 = RD();
    self->fA6C = 1.0f;
    NL();
    self->f980 = RD();
    self->f988 = RD();
    self->f9A0 = RD();
    self->f9A8 = RD();
    NL();
    self->f984 = RD();
    self->f98C = RD();
    self->f9A4 = RD();
    self->f9AC = RD();
    NL();
    self->v990 = Mk3A3A40(self->f988, self->f98C, self->f9A0, self->f9A4);
    self->i8F4 = strtoul(s, &s, 10);
    if (self->i8F4 != 0) self->iA3C = -1;
    self->f974 = self->f4C;
    self->f978 = (unsigned int)self->b64;
    {
    void* d0 = &self->v910; /* dead on purpose */
    void* d1 = &self->v920; /* dead on purpose */
    void* d2 = &self->v930; /* dead on purpose */
    void* d3 = &self->v940; /* dead on purpose */
    self->v910 = Mk3A3A40(self->fA34, self->fA38, self->f2C, self->f18);
    self->v920 = Mk3A3A40(self->f30, self->f34, self->f1C, self->f24);
    self->v930 = Mk3A3A40(self->f15C, self->f16C, self->f20, self->f28);
    self->v940 = Mk3A3A40(self->fA30, self->fA28, self->fA2C, 0.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3A40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3A40 */

/* merge_units: begin func_003A3EF0 */
#pragma push /* merge_units */
/* First quad copy uses a "+r" destination operand (G1) so the dest gets t0 and q gets v1 as in retail. */

typedef struct P3E { char pad0[0x60]; unsigned int n60; char pad64[0x8FC]; V4 m960; V4 m970; V4 m980; } P3E;
static inline void G1(void* d, const void* s) { __int128 q; __asm__ volatile("lq %1, 0(%2); sq %1, 0(%0)" : "+r"(d), "=&r"(q) : "r"(s) : "memory"); }
#pragma peephole off
void cSprayDefinition_SetMiscData(P3E* p, const V4* a, const V4* b, const V3* c)
{
    V4 t;
    void* xx;
    void* yy;
    G1(&p->m960, b);
    MK(&t, c->x, c->y, c->z, (float)p->n60);
    xx = &p->m970; /* dead on purpose */
    yy = &p->m980; /* dead on purpose */
    VA(&p->m970, &t);
    VA(&p->m980, a);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3EF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3EF0 */

/* merge_units: begin func_003A3F80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off

extern "C" {
}

struct V4_3A3F80 {
    float x, y, z, w;
    V4_3A3F80& operator=(const V4_3A3F80& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        { void* xx = this; } /* dead on purpose: retail recomputes &v[k] after each copy */
        return *this;
    }
} __attribute__((aligned(16)));

struct Obj3A3F80 {
    char pad0[0x18];
    float f18, f1C, f20, f24, f28, f2C, f30, f34;
    char pad38[0x15C - 0x38];
    float f15C;
    char pad160[0x16C - 0x160];
    float f16C;
    char pad170[0x8F4 - 0x170];
    int i8F4;
    char pad8F8[0x900 - 0x8F8];
    V4_3A3F80 v[9];
    float f990, f994, f998, f99C, f9A0, f9A4, f9A8, f9AC;
    float f9B0, f9B4, f9B8, f9BC, f9C0, f9C4;
    int i9C8;
    unsigned char b9CC;
};

struct Mk3A3F80 : V4_3A3F80 {
    Mk3A3F80(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

extern "C" void cSprayDefinition_Load(Obj3A3F80* self, char* str, float ver)
{
    char* s = str;
    self->f990 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f994 = SoftFloat_DoubleToFloat(strtod(s, &s));
    s = strchr(s, '\n') + 1;
    self->f9A0 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9A4 = SoftFloat_DoubleToFloat(strtod(s, &s));
    s = strchr(s, '\n') + 1;
    self->f998 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f99C = SoftFloat_DoubleToFloat(strtod(s, &s));
    s = strchr(s, '\n') + 1;
    self->f9A8 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9AC = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9AC = self->f9AC / self->f9A8;
    s = strchr(s, '\n') + 1;
    self->f9B0 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9B4 = 0.0f;
    s = strchr(s, '\n') + 1;
    self->f9B8 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9BC = SoftFloat_DoubleToFloat(strtod(s, &s));
    s = strchr(s, '\n') + 1;
    if (ver >= 1.5f) {
        self->f9C0 = SoftFloat_DoubleToFloat(strtod(s, &s));
        self->f9C4 = SoftFloat_DoubleToFloat(strtod(s, &s));
        s = strchr(s, '\n') + 1;
        self->i8F4 = strtoul(s, &s, 10);
        s = strchr(s, '\n') + 1;
    } else {
        self->f9C0 = 0.0f;
        self->f9C4 = 0.0f;
        self->i8F4 = 0;
    }
    if (ver >= 2.0f) {
        self->i9C8 = strtoul(s, &s, 10);
        if (self->i9C8 == 0) self->i9C8 = 1;
        self->b9CC = strtoul(s, &s, 10) != 0;
        s = strchr(s, '\n') + 1;
    } else {
        self->i9C8 = 1;
        self->b9CC = 0;
    }
    {
    V4_3A3F80* d0 = &self->v[0];
    *d0 = Mk3A3F80(self->f990, self->f998, self->f9B8, self->f9B0);
    }
    {
    self->v[1] = Mk3A3F80(self->f994, self->f99C, self->f9BC, self->f9B4);
    self->v[2] = Mk3A3F80(0.0f, self->f9A0, self->f9C0, self->f9C4);
    self->v[3] = Mk3A3F80(0.0f, self->f9A4, self->f2C, self->f18);
    self->v[4] = Mk3A3F80(self->f30, self->f34, self->f1C, self->f24);
    self->v[5] = Mk3A3F80(self->f15C, self->f16C, self->f20, self->f28);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3F80 */
