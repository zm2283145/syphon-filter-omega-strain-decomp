/*
 * main/player: 2 files, 0040B810-0040B830
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040B810 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int count, int value);

/* Appends one object to the registry vector. */
int ObjRegistry_InsertOne(PtrVec* v, int obj) {
    return PtrVec_Insert(v, v->data + v->count, 1, obj);
}
#pragma pop /* merge_units */
/* merge_units: end func_0040B810 */

/* merge_units: begin func_0040B830 */
#pragma push /* merge_units */
typedef struct { int pad; int count; void** data; } Vec40B830;
typedef struct { void* vt; char m4[0x10]; char m14[0xC]; } Obj40B830;
extern Vec40B830* GobjScope_GetList(void);
extern void PtrVector_Resize(Vec40B830* v, int n, int* fill);
extern void std_vector_deleter_cObjectId_dtor(void* p, int f);
extern void std_vector_cSystemPtr_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void D1_40B830(void* p) { if (p) std_vector_deleter_cObjectId_dtor(p, 0); }
static inline void D2_40B830(void* p) { if (p) D1_40B830(p); }
static inline void D3_40B830(void* p) { if (p) D2_40B830(p); }
#pragma push
#pragma inline_depth(10)
#pragma opt_strength_reduction off
Obj40B830* GobjScopeBase_Dtor(Obj40B830* self, short del)
{
    if (self) {
        Vec40B830* v = GobjScope_GetList();
        int i;
        int last = v->count - 1;
        int zero;
        for (i = 0; !(last < i); i++) {
            if (v->data[i] == self) {
                v->data[i] = v->data[last];
                last--;
            }
        }
        zero = 0;
        PtrVector_Resize(v, last + 1, &zero);
        D3_40B830(self->m14);
        if (self->m4) std_vector_cSystemPtr_dtor(self->m4, -1);
        if (del > 0) operator_delete(self);
    }
    return self;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0040B830 */
