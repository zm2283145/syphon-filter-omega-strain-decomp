/*
 * SFOGame/Source/human: 5 files, 00191390-00191480
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00191390 */
#pragma push /* merge_units */
#include "types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(char* self) {
    return self + 180;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00191390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00191390 */

/* merge_units: begin func_001913E0 */
#pragma push /* merge_units */
typedef struct { char pad[0xB8]; void* unkB8; } ObjB8;

/* Returns whether the pointer field at +0xB8 is set. */
int cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(ObjB8* o)
{
    return (o->unkB8 == 0) ^ 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001913E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001913E0 */

/* merge_units: begin func_00191400 */
#pragma push /* merge_units */
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } P_1400;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
P_1400* cQuatVec_InvertAssumingUnitQuat(P_1400* p) {
    VU0_NEG3(p, p)
    { V4* b; V4* a; a = &p->pos; b = &p->pos; VU0_NEG3(a, b) }
    { V4* v; v = &p->pos; VU0_QROT(v, p, v) }
    return p;
}
#pragma pop
static inline void merge_flush_func_00191400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00191400 */

/* merge_units: begin func_00191480 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct Orientation { Q a; Q b; } Orientation;

/* Copies two quadwords (orientation rows) from src to dst; returns dst. */
Orientation* cQuatVec_opAssign(Orientation* dst, Orientation* src)
{
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00191480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00191480 */

/* merge_units: begin func_001914A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cSkaNode_CheckType(unsigned char* self, unsigned char value) {
    return value == self[4];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001914A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001914A0 */
