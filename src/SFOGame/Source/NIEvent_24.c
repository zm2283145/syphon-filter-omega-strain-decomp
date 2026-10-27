/*
 * SFOGame/Source/NIEvent: 3 files, 0023DAD0-0023DDA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023DAD0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct NodeObj {
    char pad00[0x2C];
    unsigned char f2C;  /* 0x2C */
    unsigned char f2D;  /* 0x2D */
    unsigned char f2E;  /* 0x2E */
    char pad2F[0x60 - 0x2F];
    int state;          /* 0x60 */
    char pad64[0x94 - 0x64];
    struct NodeObj* parent; /* 0x94 */
    int pad98;
    PtrVec kids;        /* 0x9C */
} NodeObj;

extern int std_vector_cNIEventBasePtr_size(PtrVec* v);
extern int cArray_cNIEventBasePtr_Size(PtrVec* v);
extern int* cArray_cNIEventBasePtr_opIndex(PtrVec* v, int i);
extern int* std_vector_imp_cNIEventBasePtr_1_opIndex(PtrVec* v, int i);
extern int cGOBJ_IsStreaming(NodeObj* o);
extern int cGOBJ_IsActive(NodeObj* o);
extern int cNIEventBase_NumChildrenActive(NodeObj* o, int flag);

#define COUNTS(o, flag) (!(flag) || (o)->state == 3 || (o)->state == 1 || (o)->state == 6)

int cNIEventBase_NumActiveInTree(NodeObj* self, int flag);

static inline int L1(NodeObj* pp, int flag)
{
    if (pp->parent) {
        return cNIEventBase_NumActiveInTree(pp->parent, flag);
    } else {
        return cNIEventBase_NumChildrenActive(pp, flag);
    }
}

static inline int L2(NodeObj* p, int flag)
{
    if (p->parent) {
        return L1(p->parent, flag);
    } else {
        int m = 0;
        int k;
        if (cGOBJ_IsActive(p)) {
            if (COUNTS(p, flag)) m++;
        }
        for (k = 0; k < cArray_cNIEventBasePtr_Size(&p->kids); k++) {
            m += cNIEventBase_NumChildrenActive(*(NodeObj**)cArray_cNIEventBasePtr_opIndex(&p->kids, k), flag);
        }
        return m;
    }
}

int cNIEventBase_NumActiveInTree(NodeObj* self, int flag)
{
    if (self->parent) {
        return L2(self->parent, flag);
    } else {
        int n = 0;
        int ok;
        int j;
        ok = self->f2D != 0 && self->f2C != 0 && !(cGOBJ_IsStreaming(self) != 0);
        if (ok) {
            if (COUNTS(self, flag)) n++;
        }
        for (j = 0; j < std_vector_cNIEventBasePtr_size(&self->kids); j++) {
            NodeObj* g = *(NodeObj**)std_vector_imp_cNIEventBasePtr_1_opIndex(&self->kids, j);
            int m = 0;
            int k;
            if (cGOBJ_IsActive(g)) {
                if (COUNTS(g, flag)) m++;
            }
            for (k = 0; k < cArray_cNIEventBasePtr_Size(&g->kids); k++) {
                m += cNIEventBase_NumChildrenActive(*(NodeObj**)cArray_cNIEventBasePtr_opIndex(&g->kids, k), flag);
            }
            n += m;
        }
        return n;
    }
}
static inline void merge_flush_func_0023DAD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023DAD0 */

/* merge_units: begin func_0023DD70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern int cNIEventBase_NumActiveInTree(void* self, int flag);
#endif /* merge_units */
#define cNIEventBase_NumActiveInTree(a0, a1) (cNIEventBase_NumActiveInTree((NodeObj *)(a0), (a1))) /* merge_units */


/* True when index is below the count returned by cNIEventBase_NumActiveInTree(self, 1). */
int cNIEventBase_AreVUMsActive(void* self, int index) {
    int count = cNIEventBase_NumActiveInTree(self, 1);
    return index < count;
}
#undef cNIEventBase_NumActiveInTree /* merge_units */
static inline void merge_flush_func_0023DD70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023DD70 */

/* merge_units: begin func_0023DDA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct Info0023DDA0 { int w[16]; };
class Obj0023DDA0 {
public:
    VPAD32(a) VPAD2(b) VPAD1(c)
    virtual void onA(Info0023DDA0* info);
    VPAD4(d) VPAD1(e)
    virtual void onB(Info0023DDA0* info);
    char pad[0x12C];
    unsigned char flag;
};
extern "C" void cNIEventBase_ParentXform(Info0023DDA0* out, Obj0023DDA0* self);
extern "C" void cNIEventBase_ForceMatUpdate(Obj0023DDA0* self)
{
    if (self->flag) {
        Info0023DDA0 a;
        cNIEventBase_ParentXform(&a, self);
        self->onA(&a);
    } else {
        Info0023DDA0 b;
        cNIEventBase_ParentXform(&b, self);
        self->onB(&b);
    }
}
static inline void merge_flush_func_0023DDA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023DDA0 */
