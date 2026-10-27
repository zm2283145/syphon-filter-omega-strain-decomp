/*
 * Libs/SFOLib/Source/skeleton: 4 files, 003A9220-003A94C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A9220 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Box { V mn; V mx; };
class XV {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
};
struct Sph { unsigned char on; unsigned char local; char pad2[2]; float r; char pad8[8]; V c; };
struct MNode : XV { char pad4[0xC]; M m; unsigned char dirty; char pad51[0x150 - 0x51]; Sph sph; char pad[0x1D0 - 0x170]; };
struct NIt { MNode* p; NIt() {} NIt(const NIt& o) : p(o.p) {} };
struct NVec; struct NIt;
extern "C" {
MNode* std_vector_imp_cBone_begin(NVec* v);
MNode* std_vector_imp_cBone_end(NVec* v);
void std_vector_cBone_pointer2iterator(NIt* out, NVec* v, MNode* const& p);
void cVector_ctor_void(V* v);
V* cVector_opAssign(V* d, const V* s);
void cVector_Transform_cMatrixR(V* v, M* m);
V* func_00133EC0(M* m);
void cVector_ctor_float_float_float_float(V* d, float x, float y, float z, float w);
void cVector_opSub(V* d, const V* c, const V* r);
void cBox_Include(Box* b, const V* v);
void cVector_opAdd(V* d, const V* a, const V* b);
}
static inline void Mk(NIt* r, NVec* v, MNode* p) { MNode* const& q = p; std_vector_cBone_pointer2iterator(r, v, q); }
struct NVec {
    int x0;
    NIt begin() { NIt r; Mk(&r, this, std_vector_imp_cBone_begin(this)); return r; }
    NIt end() { NIt r; Mk(&r, this, std_vector_imp_cBone_end(this)); return r; }
};
static inline bool operator==(const NIt& a, const NIt& b) { MNode* y = b.p; MNode* x = a.p; return x == y; }
static inline bool operator!=(const NIt& a, const NIt& b) { return !(a == b); }
struct Ctx { char pad[0x18]; NVec nodes; char pad1C[0x14]; Box box; };
extern "C" void cSkeleton_UpdateBBox(Ctx* c);
void cSkeleton_UpdateBBox(Ctx* c)
{
    NIt it; NIt e;
    V lo(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    c->box.mn = lo;
    V hi(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    c->box.mx = hi;
    it = c->nodes.begin();
    e = c->nodes.end();
    while (it != e) {
        MNode* n = it.p;
        if (n->dirty) n->Refresh();
        M* m = &n->m;
        Sph* s = &it.p->sph;
        if (s->on) {
            V p;
            cVector_ctor_void(&p);
            if (!s->local) cVector_Transform_cMatrixR(cVector_opAssign(&p, &s->c), m);
            else cVector_opAssign(&p, func_00133EC0(m));
            float r = s->r;
            if (r > 0.0f) {
                V rv; cVector_ctor_float_float_float_float(&rv, r, r, r, 0.0f);
                V a; cVector_opSub(&a, &p, &rv);
                cBox_Include(&c->box, &a);
                V b; cVector_opAdd(&b, &p, &rv);
                cBox_Include(&c->box, &b);
            } else {
                cBox_Include(&c->box, &p);
            }
        }
        it.p++;
    }
}
static inline void merge_flush_func_003A9220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A9220 */

/* merge_units: begin func_003A9450 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int std_vector_deleter_cSkaPlaybackItem_dtor(int, int);                            
#if 0 /* merge_units */
int std_vector_cBone_ctor(int );
#endif /* merge_units */
Rel * std_vector_cBone_ctor(); /* merge_units */
                            

void cSkeleton_DestroyBones(int arg0) {
    int temp_a0;
    int temp_s0;

    temp_a0 = arg0 + 0x18;
    if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
        std_vector_deleter_cSkaPlaybackItem_dtor(temp_a0, 0);
    }
    temp_s0 = arg0 + 0x18;
    if (temp_s0 != NULL) {
        std_vector_cBone_ctor(temp_s0);
        F_(temp_s0, 0xC, signed char) = 1;
    }
}
static inline void merge_flush_func_003A9450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A9450 */

/* merge_units: begin func_003A94C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* std_vector_cBone_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_003A94C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A94C0 */

/* merge_units: begin func_003A94E0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct SNode { unsigned char b[0x1D0]; };
struct SRec { char pad[0x20]; };
struct SHdr { int count; char pad[0xC]; SRec recs[1]; };
struct SArr { int pad0; int count; SNode* data; SNode& At(unsigned int i) { return data[i]; } int Size() const { return count; } };
struct SMtx { float m[16]; };
struct SkelNodesT {
    SHdr* hdr;
    char pad4[0x10];
    unsigned char flag;
    char pad15[3];
    SArr nodes;
};

extern "C" {
void cBone_ctor_void(SNode* n);
void std_vector_imp_cBone_resize(SArr* a, unsigned int n, const SNode& fill);
void cBone_dtor(SNode* n, int flag);
void cBone_Init(SNode* n, SRec* r);
void cBone_SetParent(SNode* n, SNode* parent);
SArr* cSkeleton_GetBoneList(SkelNodesT* s);
SNode* cArray_cBone_opIndex_int_2(SArr* a, int i);
int cArray_cBone_Size(SArr* a);
void* cBone_GetMatrix(SNode* n);
void cMatrix_Copy_InvertRotTrans(SMtx* out, void* in);
void cBone_SetMeshSpaceToBoneSpaceMatrix(SNode* n, SMtx* m);
void cSkeleton_SetupBoneScaleMatrices(SkelNodesT* s);
void cSkeleton_CreateBones(SkelNodesT* s);
}

void cSkeleton_CreateBones(SkelNodesT* s)
{
    SNode tmp;
    SMtx m;
    int i;

    cBone_ctor_void(&tmp);
    std_vector_imp_cBone_resize(&s->nodes, s->hdr->count, tmp);
    cBone_dtor(&tmp, -1);
    for (i = 0; i < s->nodes.count; i++) {
        cBone_Init(&s->nodes.At(i), &s->hdr->recs[i]);
    }
    for (i = 0; i < s->nodes.Size(); i++) {
        SNode* n = &s->nodes.At(i);
        unsigned char p = **(unsigned char**)(n->b + 0xC0);
        if (p != 0xFF)
            cBone_SetParent(n, &s->nodes.At(p));
        else
            cBone_SetParent(n, 0);
    }
    if (s->flag) {
        SArr* a = cSkeleton_GetBoneList(s);
        SNode* n = cArray_cBone_opIndex_int_2(a, 0);
        for (i = 0; i < cArray_cBone_Size(a); i++) {
            cMatrix_Copy_InvertRotTrans(&m, cBone_GetMatrix(n));
            cBone_SetMeshSpaceToBoneSpaceMatrix(n, &m);
            n++;
        }
    }
    cSkeleton_SetupBoneScaleMatrices(s);
}
static inline void merge_flush_func_003A94E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A94E0 */
