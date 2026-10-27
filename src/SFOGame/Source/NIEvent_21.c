/*
 * SFOGame/Source/NIEvent: 3 files, 0023D6C0-0023D810
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023D6C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Address of element i in an array of 0x40-byte records whose base pointer is at +8. */
char* std_vector_VectorKey_opIndex(char* self, int i) {
    return *(char**)(self + 8) + (i << 6);
}
static inline void merge_flush_func_0023D6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D6C0 */

/* merge_units: begin func_0023D6D0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNIEventBase::UpdateVis: advances the visibility track time, finds the active key
 * (wrapping to the out-of-range-type key when the track has run past its last key)
 * and reports whether the visibility flag changed. */
struct VisKey { float time; unsigned char visible; };
template <class T> struct cArray {
    int x0;
    int size;
    T* data;
    int xC;
    int Size() const { return size; }
    T& operator[](unsigned int i) { return data[i]; } /* std::vector::operator[](unsigned int) */
};
class cNIEventBase {
public:
    char pad0[0xC4];
    cArray<VisKey> mVisKeys;
    int mVisORT;
    float mVisTime;
    unsigned char mVisible;
};
extern "C" bool cNIEventBase_UpdateVis(cNIEventBase* self, float timeStep)
{
    int visKey = self->mVisKeys.Size() - 1;
    int i;
    float leftOver;
    unsigned char oldVis;
    if (visKey == 0) return false;
    self->mVisTime += timeStep;
    for (i = 0; i < self->mVisKeys.Size() - 1; i++) {
        if (self->mVisTime >= self->mVisKeys[i].time && self->mVisTime < self->mVisKeys[i + 1].time) {
            visKey = i;
            break;
        }
    }
    if (visKey == self->mVisKeys.Size() - 1) {
        if (self->mVisORT == -1) {
            self->mVisTime = self->mVisKeys[visKey].time;
            self->mVisible = self->mVisKeys[visKey].visible;
            return true;
        }
        leftOver = self->mVisTime - self->mVisKeys[visKey].time;
        visKey = self->mVisORT;
        self->mVisTime = leftOver + self->mVisKeys[visKey].time;
    }
    oldVis = self->mVisible;
    self->mVisible = self->mVisKeys[visKey].visible;
    return self->mVisible != oldVis;
}
static inline void merge_flush_func_0023D6D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D6D0 */

/* merge_units: begin func_0023D810 */
#pragma push /* merge_units */
typedef struct Node Node_;
typedef struct NodeObj {
    char pad00[0x2C];
    unsigned char f2C;  /* 0x2C */
    unsigned char f2D;  /* 0x2D */
    unsigned char f2E;  /* 0x2E */
    char pad2F[0x60 - 0x2F];
    int state;          /* 0x60 */
    char pad64[0x9C - 0x64];
    PtrVec kids;        /* 0x9C */
} NodeObj;

extern int std_vector_cNIEventBasePtr_size(PtrVec* v);
extern int cArray_cNIEventBasePtr_Size(PtrVec* v);
extern int* cArray_cNIEventBasePtr_opIndex(PtrVec* v, int i);
extern int* std_vector_imp_cNIEventBasePtr_1_opIndex(PtrVec* v, int i);
extern int cGOBJ_IsStreaming(NodeObj* o);
extern int cGOBJ_IsActive(NodeObj* o);

#define COUNTS(o, flag) (!(flag) || (o)->state == 3 || (o)->state == 1 || (o)->state == 6)
#pragma push
#pragma opt_strength_reduction off

int cNIEventBase_NumChildrenActive(NodeObj* self, int flag)
{
    int total = 0; int ok;
    int i;
    ok = self->f2D != 0 && self->f2C != 0 && !(self->f2E != 0); if (ok) {
        if (COUNTS(self, flag)) total++;
    }
    for (i = 0; i < self->kids.count; i++) {
        NodeObj* c = (NodeObj*)self->kids.data[i];
        int n = 0;
        int j;
        ok = c->f2D != 0 && c->f2C != 0 && !(cGOBJ_IsStreaming(c) != 0); if (ok) {
            if (COUNTS(c, flag)) n++;
        }
        for (j = 0; j < std_vector_cNIEventBasePtr_size(&c->kids); j++) {
            NodeObj* g = *(NodeObj**)std_vector_imp_cNIEventBasePtr_1_opIndex(&c->kids, j);
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
        total += n;
    }
    return total;
}
#pragma pop
static inline void merge_flush_func_0023D810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D810 */
