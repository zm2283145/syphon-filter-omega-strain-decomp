/*
 * SFOGame/Source/humanCollision: 6 files, 001E5070-001E5120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E5070 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x10]; Q a; Q b; Q c; } S1E5070;
#pragma peephole off
#pragma opt_propagation off
void cPointMass_ClearVelocity(S1E5070* s)
{
    __int128* zp;
    s->b = s->a;
    zp = (__int128*)&s->c;
    *zp = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
static inline void merge_flush_func_001E5070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5070 */

/* merge_units: begin func_001E5090 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; __int128 q; } Q5090;
#pragma peephole off
#pragma opt_propagation off
void cPointMass_ClearAcceleration(Q5090* s) {
    __int128* zp = &s->q;
    *zp = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
static inline void merge_flush_func_001E5090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5090 */

/* merge_units: begin func_001E50A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x50]; __int128 q; } Q50A0;
#pragma peephole off
#pragma opt_propagation off
void cPointMass_ClearForce(Q50A0* s) {
    __int128* zp = &s->q;
    *zp = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
static inline void merge_flush_func_001E50A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E50A0 */

/* merge_units: begin func_001E50B0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 cQuaternion_opSub(V4* b) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
static inline void merge_flush_func_001E50B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E50B0 */

/* merge_units: begin func_001E50E0 */
#pragma push /* merge_units */
float func_001E50E0(V4* a, V4* b) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline void merge_flush_func_001E50E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E50E0 */

/* merge_units: begin func_001E5120 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
/* Physical_SetChildOffsets: apply an orientation to every child root and mark it dirty */
typedef struct { char** p; } It_1E5120;
typedef struct { char pad[0xB4]; int vec; int count; } O_1E5120;
extern "C" {
char** std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(int* v);
char** std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(int* v);
void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(It_1E5120* out, int* v, char*** p);
char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(char* r);
void cQuatVec_opAssign(char* t, void* q);
void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(char* r);
void Physical_SetChildOffsets(O_1E5120* self, void* q);
}
static inline int Eq_1E5120(char** a, char** b) { return a == b; }
static inline int EqI_1E5120(int a, int b) { return a == b; }
static inline void SetDirty_1E5120(char* c, unsigned char f) { cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(c)[0xA0] = f; }
void Physical_SetChildOffsets(O_1E5120* self, void* q)
{
    It_1E5120 b;
    It_1E5120 e;
    char** t0;
    char** t1;
    char** it;
    char** end;
    if (EqI_1E5120(self->count, 0) ^ 1) {
        int* v = &self->vec;
        t0 = std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(v);
        std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(&b, &self->vec, &t0);
        it = b.p;
        t1 = std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(v);
        std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(&e, v, &t1);
        end = e.p;
        /* volatile read: retail reloads e.p for the loop guard separately from end */
        if (Eq_1E5120(it, *(char** volatile*)&e.p) ^ 1) {
            do {
                char* c = *it;
                cQuatVec_opAssign(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(c) + 0x50, q);
                SetDirty_1E5120(c, 1);
                cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(c);
                it++;
            } while (Eq_1E5120(it, end) ^ 1);
        }
    }
}
static inline void merge_flush_func_001E5120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5120 */
