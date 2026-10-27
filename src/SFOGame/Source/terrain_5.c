/*
 * SFOGame/Source/terrain: 5 files, 001741A0-00174500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001741A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* std_vector_deleter_cObjectId_data_void(char* self) {
    return self + 8;
}
static inline void merge_flush_func_001741A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001741A0 */

/* merge_units: begin func_001741B0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { int pad; int size; int* data; } Vec_741B0;
typedef struct { char pad[0xC]; char* cur; } Strm_741B0;
typedef struct { char pad[0x204]; Vec_741B0 keys; char pad210[0x20]; float a[3]; char pad23C[4]; float b[3]; } Ter_741B0;
extern void std_vector_imp_cObjectId_reserve(Vec_741B0* v, int n);
extern void std_vector_imp_cObjectId_insert(Vec_741B0* v, int* pos, int n, int* key);
void cTerrain_InitializeActivation_cPopulationR_cArrayP(Ter_741B0* self, Strm_741B0* s, Vec_741B0* src)
{
    int n;
    int i;
    self->a[0] = *(float*)s->cur; s->cur += 4;
    self->a[1] = *(float*)s->cur; s->cur += 4;
    self->a[2] = *(float*)s->cur; s->cur += 4;
    self->b[0] = *(float*)s->cur; s->cur += 4;
    self->b[1] = *(float*)s->cur; s->cur += 4;
    self->b[2] = *(float*)s->cur; s->cur += 4;
    n = src->size;
    if (n > 0) {
        std_vector_imp_cObjectId_reserve(&self->keys, self->keys.size + n);
        for (i = 0; i < n; i++) {
            unsigned int v = src->data[i];
            int hi = (v & 0xFF0000) >> 16; int k = (v & 0xFFFF) | (hi << 16);
            std_vector_imp_cObjectId_insert(&self->keys, self->keys.data + self->keys.size, 1, &k);
        }
    }
}
static inline void merge_flush_func_001741B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001741B0 */

/* merge_units: begin func_00174310 */
#pragma push /* merge_units */
typedef struct { int pad; int size; int* data; } Vec_74310;
typedef struct { Vec_74310 v; unsigned char live; } TmpVec_74310;
typedef struct { char pad[0xC]; char* cur; } Strm_74310;
typedef struct { char pad[0x204]; Vec_74310 keys; char pad210[0x20]; float a[3]; char pad23C[4]; float b[3]; } Ter_74310;
extern int D_0048A138;
extern Vec_74310* std_vector_int_ctor_int_int(Vec_74310* v, int n, int value);
#if 0 /* merge_units */
extern int* std_vector_int_opIndex_uint_2(Vec_74310* v, int i);
#endif /* merge_units */
int * std_vector_int_opIndex_uint_2(); /* merge_units */

extern void func_0013A040(void* v, int flag);
#if 0 /* merge_units */
extern void std_vector_imp_cObjectId_reserve(Vec_74310* v, int n);
#endif /* merge_units */
#define std_vector_imp_cObjectId_reserve(a0, a1) (std_vector_imp_cObjectId_reserve((Vec_741B0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_vector_imp_cObjectId_insert(Vec_74310* v, int* pos, int n, int* key);
#endif /* merge_units */
#define std_vector_imp_cObjectId_insert(a0, a1, a2, a3) (std_vector_imp_cObjectId_insert((Vec_741B0 *)(a0), (a1), (a2), (a3))) /* merge_units */

void cTerrain_InitializeActivation_cPopulationR(Ter_74310* self, Strm_74310* s)
{
    int n;
    int i;
    self->a[0] = *(float*)s->cur; s->cur += 4;
    self->a[1] = *(float*)s->cur; s->cur += 4;
    self->a[2] = *(float*)s->cur; s->cur += 4;
    self->b[0] = *(float*)s->cur; s->cur += 4;
    self->b[1] = *(float*)s->cur; s->cur += 4;
    self->b[2] = *(float*)s->cur; s->cur += 4;
    n = *(int*)s->cur; s->cur += 4;
    if (n > 0) {
        TmpVec_74310 t;
        int k;
        std_vector_int_ctor_int_int(&t.v, n, D_0048A138);
        t.live = 1;
        for (i = 0; i < n; i++) {
            int* p = std_vector_int_opIndex_uint_2(&t.v, i);
            *p = *(int*)s->cur; s->cur += 4;
        }
        std_vector_imp_cObjectId_reserve(&self->keys, (int)((unsigned int)self->keys.size + n / 2));
        for (i = 0; i < n; i += 2) {
            int lo = *std_vector_int_opIndex_uint_2(&t.v, i + 1);
            k = lo | (*std_vector_int_opIndex_uint_2(&t.v, i) << 16);
            std_vector_imp_cObjectId_insert(&self->keys, self->keys.data + self->keys.size, 1, &k);
        }
        func_0013A040(&t, -1);
    }
}
#undef std_vector_imp_cObjectId_reserve /* merge_units */
#undef std_vector_imp_cObjectId_insert /* merge_units */
static inline void merge_flush_func_00174310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174310 */

/* merge_units: begin func_001744F0 */
#pragma push /* merge_units */
int* std_vector_int_opIndex_uint_2(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_001744F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001744F0 */

/* merge_units: begin func_00174500 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "fileman_entry.h"
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
#define V10(p) V5(p##x) V5(p##y)
struct Reader_74500 { int version; int a, b; char* cur; };
struct Vec_74500 { int a; int b; int c; unsigned char flag; };
struct Ld_74500 { FileManEntry* a; FileManEntry* b; int c; int d; int e; };
struct Terrain_74500 {
    V10(a) virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3();
    virtual void Load(int a); /* +0x40 */
    virtual void Load2(Ld_74500* l); /* +0x44 */
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5();
    virtual void SetActive(int on); /* +0x60 */
    int pad4[2];
    int idC;
    char pad10[0x1F4 - 0x10];
    Vec_74500 v1F4;
    Vec_74500 v204;
    Vec_74500 v214;
    char pad224[0xC];
    int lo[4];
    int hi[4];
    unsigned char b250;
};
extern "C" {
extern char D_004EE780[];
extern char D_004D9BE0[];
extern char D_0049CA58[];
void cVUM_GOBJ_ctor_cObjectIdR_cSubclassIdR(Terrain_74500* o, int* desc, char* info);
void std_vector_cGOBJPtr_ctor_uint_cGOBJPR(Vec_74500* v, int a, int* b);
void std_vector_cObjectId_ctor_uint_cObjectIdR(Vec_74500* v, int a, int* b);
void std_vector_cGOBJPtr_ctor_void(Vec_74500* v);
char* strchr(const char* s, int c);
void Libc_Strcpy(char* d, const char* s);
int cFileMan_EncodeFilename_charP_cHogFileR_bool(void* h, const char* name, int arg, int opt);
unsigned char cFileMan_Open(void* e);
Terrain_74500* cTerrain_ctor(Terrain_74500* self, Reader_74500* r, int a, int b);
}
static inline void ReadInt_74500(Reader_74500* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline void Align_74500(Reader_74500* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
Terrain_74500* cTerrain_ctor(Terrain_74500* self, Reader_74500* r, int a, int b)
{
    int gid;
    FileManEntry e1;
    FileManEntry e2;
    Ld_74500 ld;
    int hi;
    int lo;
    char* s;
    gid = -1;
    cVUM_GOBJ_ctor_cObjectIdR_cSubclassIdR(self, &gid, D_004EE780);
    *(void**)self = D_004D9BE0;
    {
        Vec_74500* v = &self->v1F4;
        int z = 0;
        std_vector_cGOBJPtr_ctor_uint_cGOBJPR(v, 0, &z);
        v->flag = 1;
    }
    {
        int m = -1;
        Vec_74500* v = &self->v204;
        std_vector_cObjectId_ctor_uint_cObjectIdR(v, 0, &m);
        v->flag = 1;
    }
    {
        Vec_74500* v = &self->v214;
        std_vector_cGOBJPtr_ctor_void(v);
        v->flag = 1;
    }
    self->lo[0] = 0x7F7FFFFF;
    self->lo[1] = 0x7F7FFFFF;
    self->lo[2] = 0x7F7FFFFF;
    self->lo[3] = 0x3F800000;
    self->hi[0] = 0xFF7FFFFF;
    self->hi[1] = 0xFF7FFFFF;
    self->hi[2] = 0xFF7FFFFF;
    self->hi[3] = 0x3F800000;
    cFileMan_ctor_void(&e1);
    cFileMan_ctor_void(&e2);
    self->b250 = 0;
    ReadInt_74500(r, &hi);
    ReadInt_74500(r, &lo);
    s = r->cur;
    while (*r->cur++) ;
    Libc_Strcpy(strchr(s, '.'), D_0049CA58);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&e1, s, a, 1);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&e2, s, b, 0);
    Align_74500(r);
    if (cFileMan_Open(&e1) == 0) {
        ld.a = &e1;
        ld.b = &e2;
        ld.c = 0;
        ld.d = 0;
        ld.e = 0;
        self->idC = lo | (hi << 16);
        self->Load(0);
        self->Load2(&ld);
        self->SetActive(1);
    }
    cFileMan_dtor(&e2, -1);
    cFileMan_dtor(&e1, -1);
    return self;
}
static inline void merge_flush_func_00174500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174500 */
