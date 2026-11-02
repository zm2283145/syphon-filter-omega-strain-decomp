/*
 * SFOGame/Source/terrain: 10 files, 00173D00-001741A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00173D00 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0Add(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
}
static inline void merge_flush_func_00173D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00173D00 */

/* merge_units: begin func_00173D20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

extern int std_vector_pod_int_init_uint_uintR(PtrVec*, int, ValFlag*);

/* Empty vector, then fill through std_vector_pod_int_init_uint_uintR with a {value, 0} argument. */
PtrVec* std_vector_int_ctor_int_int(PtrVec* v, int a1, int value) {
    ValFlag arg;

    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    arg.value = value;
    arg.flag = 0;
    std_vector_pod_int_init_uint_uintR(v, a1, &arg);
    return v;
}
static inline void merge_flush_func_00173D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00173D20 */

/* merge_units: begin func_00173D60 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct { int* p; } It_173D60;
typedef struct { int pad; int size; int* data; } Vec_173D60;
typedef struct { char pad[0x204]; Vec_173D60 zones; } Zm_173D60;
typedef struct { char pad[0x4C]; int type; } Obj_173D60;

extern int D_004EE780;
#if 0 /* merge_units */
extern void cArray_cObjectId_Begin(It_173D60* out, Vec_173D60* v);
#endif /* merge_units */
void cArray_cObjectId_Begin(); /* merge_units */


#if 0 /* merge_units */
extern void cArray_cObjectId_End_void(It_173D60* out, Vec_173D60* v);
#endif /* merge_units */
void cArray_cObjectId_End_void(); /* merge_units */


#if 0 /* merge_units */
extern int cArray_cObjectId_Iterator_opNe(It_173D60* a, It_173D60* b);
#endif /* merge_units */
int cArray_cObjectId_Iterator_opNe(); /* merge_units */


#if 0 /* merge_units */
extern int* cArray_cObjectId_Iterator_opMul(It_173D60* it);
#endif /* merge_units */
int * cArray_cObjectId_Iterator_opMul(); /* merge_units */


#if 0 /* merge_units */
extern int opEq(int* a, int* b);
#endif /* merge_units */
int opEq(); /* merge_units */


#if 0 /* merge_units */
extern void cArray_cObjectId_Iterator_ctor(It_173D60* out, It_173D60* src);
#endif /* merge_units */
Word * cArray_cObjectId_Iterator_ctor(); /* merge_units */


#if 0 /* merge_units */
extern void cArray_cObjectId_Iterator_opInc(It_173D60* it);
#endif /* merge_units */
Iter * cArray_cObjectId_Iterator_opInc(); /* merge_units */


#if 0 /* merge_units */
extern int* std_vector_imp_cObjectId_end(Vec_173D60* v);
#endif /* merge_units */
int * std_vector_imp_cObjectId_end(); /* merge_units */


#if 0 /* merge_units */
extern void std_vector_cObjectId_pointer2iterator(It_173D60* out, Vec_173D60* v, int** p);
#endif /* merge_units */
void std_vector_cObjectId_pointer2iterator(); /* merge_units */


#if 0 /* merge_units */
extern void std_vector_imp_cObjectId_reserve(Vec_173D60* v, int n);
#endif /* merge_units */
void std_vector_imp_cObjectId_reserve(void*, int); /* merge_units */
#define std_vector_imp_cObjectId_reserve(a0, a1) (std_vector_imp_cObjectId_reserve((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_vector_imp_cObjectId_insert(Vec_173D60* v, int* pos, int n, int* key);
#endif /* merge_units */
void std_vector_imp_cObjectId_insert(void*, int*, int, int*); /* merge_units */
#define std_vector_imp_cObjectId_insert(a0, a1, a2, a3) (std_vector_imp_cObjectId_insert((void *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern Obj_173D60* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#endif /* merge_units */
int nGobjManager_LookupGOBJ_cObjectIdR(int* id); /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Obj_173D60 *)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */


void cTerrain_AddActivation(Zm_173D60* self, char* zone, int recurse, char* other)
{
    int* key = (int*)(zone + 0xC);
    It_173D60 r1;
    It_173D60 r2;
    It_173D60 e;
    unsigned char ok;
    {
        It_173D60 it;
        It_173D60 end;
        cArray_cObjectId_Begin(&it, &self->zones);
        cArray_cObjectId_End_void(&end, &self->zones);
        while (cArray_cObjectId_Iterator_opNe(&it, &end)) {
            if (opEq(cArray_cObjectId_Iterator_opMul(&it), key)) {
                cArray_cObjectId_Iterator_ctor(&r1, &it);
                goto found1;
            }
            cArray_cObjectId_Iterator_opInc(&it);
        }
        cArray_cObjectId_Iterator_ctor(&r1, &end);
    found1:;
    }
    ok = 1;
    if (other && self != (Zm_173D60*)other) {
        It_173D60 it;
        It_173D60 end;
        int* key2 = (int*)(other + 0xC);
        cArray_cObjectId_Begin(&it, &self->zones);
        cArray_cObjectId_End_void(&end, &self->zones);
        while (cArray_cObjectId_Iterator_opNe(&it, &end)) {
            if (opEq(cArray_cObjectId_Iterator_opMul(&it), key2)) {
                cArray_cObjectId_Iterator_ctor(&r2, &it);
                goto found2;
            }
            cArray_cObjectId_Iterator_opInc(&it);
        }
        cArray_cObjectId_Iterator_ctor(&r2, &end);
    found2:
        ok = !(r2.p == self->zones.data + self->zones.size);
    }
    if (ok) {
        int* p = std_vector_imp_cObjectId_end(&self->zones);
        std_vector_cObjectId_pointer2iterator(&e, &self->zones, &p);
        if (r1.p == e.p) {
            std_vector_imp_cObjectId_reserve(&self->zones, self->zones.size + 1);
            std_vector_imp_cObjectId_insert(&self->zones, self->zones.data + self->zones.size, 1, key);
        }
    }
    if (recurse) {
        int i;
        for (i = 0; i < self->zones.size; i++) {
            Obj_173D60* o = nGobjManager_LookupGOBJ_cObjectIdR(&self->zones.data[i]);
            if (o && o != (Obj_173D60*)self && o->type == D_004EE780)
                cTerrain_AddActivation((Zm_173D60*)o, zone, 0, other);
        }
    }
}
#pragma opt_strength_reduction reset
#undef std_vector_imp_cObjectId_reserve /* merge_units */
#undef std_vector_imp_cObjectId_insert /* merge_units */
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
static inline void merge_flush_func_00173D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00173D60 */

/* merge_units: begin func_00174000 */
#pragma push /* merge_units */
void std_vector_cObjectId_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cObjectId_end(PtrVec* v) {
    return v->data + v->count;
}

int cArray_cObjectId_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cObjectId_Iterator_opInc(Iter* it) {
    it->p++;
    return it;
}

Word* cArray_cObjectId_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Word equality. */
int opEq(Word* a, Word* b) {
    return a->value == b->value;
}

int* cArray_cObjectId_Iterator_opMul(Iter* it) {
    return it->p;
}

void cArray_cObjectId_End_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cObjectId_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_00174000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174000 */

/* merge_units: begin func_001740E0 */
#pragma push /* merge_units */
#pragma bool off
#pragma cplusplus on
struct IdVec_40E0;
#if 0 /* merge_units */
extern "C" int** std_vector_deleter_cObjectId_data_void(IdVec_40E0* v);
#endif /* merge_units */
extern "C" void* std_vector_deleter_cObjectId_data_void(char* self); /* merge_units */
#define std_vector_deleter_cObjectId_data_void(a0) ((int * *)std_vector_deleter_cObjectId_data_void((char *)(a0))) /* merge_units */

extern "C" 
struct IdVec_40E0 { int cap; int count; int* data; int size() const { return count; } int* begin() { return *std_vector_deleter_cObjectId_data_void(this); } int* end() { return *std_vector_deleter_cObjectId_data_void(this) + count; } };
struct It_40E0 {
    int* p;
};
static inline int NotEq(int* a, int* b) { return !(a == b); }
extern "C" {

void std_vector_pod_int_reserve(void* list, int n);
int nGobjManager_LookupGOBJ_cObjectIdR(int* id);

void std_vector_cGOBJPtr_push_back(void* list, int* obj);
void std_vector_deleter_cObjectId_clear(IdVec_40E0* v);
}
typedef struct { char pad[0x1F4]; int list[4]; IdVec_40E0 ids; char pad2[0x250 - 0x210]; unsigned char resolved; } T_40E0;
extern "C" void cTerrain_FinalizeActivation(T_40E0* self)
{
    int* it = self->ids.begin();
    int* end = self->ids.end();
    std_vector_pod_int_reserve(self->list, self->ids.size());
    while (NotEq(it, end)) {
        int id = *it;
        int obj;
        it++;
        obj = nGobjManager_LookupGOBJ_cObjectIdR(&id);
        std_vector_cGOBJPtr_push_back(self->list, &obj);
    }
    std_vector_deleter_cObjectId_clear(&self->ids);
    self->resolved = 1;
}
#undef std_vector_deleter_cObjectId_data_void /* merge_units */
static inline void merge_flush_func_001740E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001740E0 */

/* merge_units: begin func_001741A0 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
extern void std_vector_imp_cObjectId_reserve(Vec_741B0* v, int n);
#endif /* merge_units */
#define std_vector_imp_cObjectId_reserve(a0, a1) (std_vector_imp_cObjectId_reserve((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_vector_imp_cObjectId_insert(Vec_741B0* v, int* pos, int n, int* key);
#endif /* merge_units */
#define std_vector_imp_cObjectId_insert(a0, a1, a2, a3) (std_vector_imp_cObjectId_insert((void *)(a0), (a1), (a2), (a3))) /* merge_units */

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
#undef std_vector_imp_cObjectId_reserve /* merge_units */
#undef std_vector_imp_cObjectId_insert /* merge_units */
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
#if 0 /* merge_units */
extern Vec_74310* std_vector_int_ctor_int_int(Vec_74310* v, int n, int value);
#endif /* merge_units */
#define std_vector_int_ctor_int_int(a0, a1, a2) ((Vec_74310 *)std_vector_int_ctor_int_int((PtrVec *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int* std_vector_int_opIndex_uint_2(Vec_74310* v, int i);
#endif /* merge_units */
int * std_vector_int_opIndex_uint_2(); /* merge_units */


extern void func_0013A040(void* v, int flag);
#if 0 /* merge_units */
extern void std_vector_imp_cObjectId_reserve(Vec_74310* v, int n);
#endif /* merge_units */
#define std_vector_imp_cObjectId_reserve(a0, a1) (std_vector_imp_cObjectId_reserve((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void std_vector_imp_cObjectId_insert(Vec_74310* v, int* pos, int n, int* key);
#endif /* merge_units */
#define std_vector_imp_cObjectId_insert(a0, a1, a2, a3) (std_vector_imp_cObjectId_insert((void *)(a0), (a1), (a2), (a3))) /* merge_units */


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
#undef std_vector_int_ctor_int_int /* merge_units */
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
#if 0 /* merge_units */
extern char D_004EE780[];
#endif /* merge_units */
#define D_004EE780 ((char*)&D_004EE780) /* merge_units */

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
#undef D_004EE780 /* merge_units */
static inline void merge_flush_func_00174500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174500 */
