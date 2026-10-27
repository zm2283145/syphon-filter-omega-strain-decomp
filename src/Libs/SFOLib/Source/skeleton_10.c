/*
 * Libs/SFOLib/Source/skeleton: 1 file, 003AA640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AA640 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x1D0]; } SkelNode;
typedef struct { int cap; int count; SkelNode* data; } SkelVec;
extern void cBone_opAssign(SkelNode* d, SkelNode* s);
extern void cBone_dtor(SkelNode* p, int f);

SkelNode* std_vector_imp_cBone_erase(SkelVec* v, SkelNode* first, SkelNode* last)
{
    SkelNode* end;
    int n;
    SkelNode* p;
    if (first == last) return first;
    end = v->data + v->count;
    n = end - last;
    if (n != 0) {
        SkelNode* s;
        SkelNode* d;
        d = first; s = last;
        while (s < end) {
            cBone_opAssign(d, s);
            s++; d++;
        }
    }
    p = first + n;
    while (p < end) {
        cBone_dtor(p, -1);
        p++;
    }
    v->count -= last - first;
    return first;
}
static inline void merge_flush_func_003AA640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA640 */
