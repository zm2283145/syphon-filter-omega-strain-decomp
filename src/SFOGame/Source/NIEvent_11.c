/*
 * SFOGame/Source/NIEvent: 6 files, 0023EE90-0023F350
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023EE90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cNIEventBase_GetVUM(void) {
    return 0;
}
static inline void merge_flush_func_0023EE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023EE90 */

/* merge_units: begin func_0023EEA0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Node_0023EEA0;
struct Vec { int cap; int n; Node_0023EEA0** p; };
class Node_0023EEA0 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46();
    virtual Node_0023EEA0* Find();
    char pad04[0x90];
    Node_0023EEA0* parent;
    int pad98;
    Vec kids;
};
extern "C" {
int std_vector_cNIEventBasePtr_size(Vec*);
int cArray_cNIEventBasePtr_Size(Vec*);
Node_0023EEA0** cArray_cNIEventBasePtr_opIndex(Vec*, int);
Node_0023EEA0** std_vector_imp_cNIEventBasePtr_1_opIndex(Vec*, int);
Node_0023EEA0* cNIEventBase_GetFirstVUM(Node_0023EEA0*);
Node_0023EEA0* cNIEventBase_GetVUMInTree(Node_0023EEA0*);
}
static inline Node_0023EEA0* G(Node_0023EEA0* x)
{
    if (x->Find()) return x->Find();
    for (int k = 0; k < cArray_cNIEventBasePtr_Size(&x->kids); k++) {
        if (!!cNIEventBase_GetFirstVUM(*cArray_cNIEventBasePtr_opIndex(&x->kids, k)))
            return cNIEventBase_GetFirstVUM(*cArray_cNIEventBasePtr_opIndex(&x->kids, k));
    }
    return 0;
}
static inline Node_0023EEA0* H(Node_0023EEA0* o)
{
    if (o->Find()) return o->Find();
    for (int j = 0; j < std_vector_cNIEventBasePtr_size(&o->kids); j++) {
        if (G(*std_vector_imp_cNIEventBasePtr_1_opIndex(&o->kids, j)))
            return G(*std_vector_imp_cNIEventBasePtr_1_opIndex(&o->kids, j));
    }
    return 0;
}
#pragma push
#pragma inline_depth(8)
#pragma opt_strength_reduction off
extern "C" Node_0023EEA0* cNIEventBase_GetFirstVUM(Node_0023EEA0* x)
{
    if (x->Find()) return x->Find();
    for (int i = 0; i < x->kids.n; i++) {
        if (H(x->kids.p[i]))
            return H(x->kids.p[i]);
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_0023EEA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023EEA0 */

/* merge_units: begin func_0023F350 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char enabled; } Part;
typedef struct {
    void* vtable;
    char pad[0x98];
    Part a;
    char padA[0xAC - 0x9C - sizeof(Part)];
    Part b;
    char padB[0xC4 - 0xAC - sizeof(Part)];
    Part c;
    char padC[0x134 - 0xC4 - sizeof(Part)];
    float scale;
} Obj;
extern char D_004DC190[];
extern void cGOBJ_ctor(Obj* self, int* id, int a2, int a3);
extern void std_vector_cNIEventBasePtr_ctor(Part* p);
extern void std_vector_VectorKey_ctor(Part* p);
extern void std_vector_VisKey_ctor(Part* p);

/* Constructor: base GOBJ init, then three enabled parts and unit scale. */
Obj* cNIEventBase_ctor(Obj* self, int a2, int a3)
{
    Part* pa;
    Part* pb;
    Part* pc;
    int id = -1;
    cGOBJ_ctor(self, &id, a2, a3);
    self->vtable = D_004DC190;
    pa = &self->a;
    std_vector_cNIEventBasePtr_ctor(pa);
    pa->enabled = 1;
    pb = &self->b;
    std_vector_VectorKey_ctor(pb);
    pb->enabled = 1;
    pc = &self->c;
    std_vector_VisKey_ctor(pc);
    pc->enabled = 1;
    self->scale = 1.0f;
    return self;
}
static inline void merge_flush_func_0023F350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F350 */

/* merge_units: begin func_0023F3F0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "member_dtor_chain.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

#pragma cplusplus on

DEFINE_MEMBER_DTOR_CHAIN(cArray_VisKey_dtor, std_vector_deleter_VisKey_dtor)
static inline void merge_flush_func_0023F3F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F3F0 */

/* merge_units: begin func_0023F460 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_MEMBER_DTOR_CHAIN(cArray_VectorKey_dtor, std_vector_deleter_VectorKey_dtor)
static inline void merge_flush_func_0023F460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F460 */

/* merge_units: begin func_0023F4D0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_BASE_DTOR_CHAIN(cArray_cNIEventBasePtr_dtor, std_vector_imp_cNIEventBasePtr_1_dtor)
static inline void merge_flush_func_0023F4D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023F4D0 */
