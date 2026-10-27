/*
 * SFOGame/Source/human: 7 files, 001A7CD0-001A7E60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A7CD0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_7D80;
V4_7D80* cQuaternion_Rotate(V4_7D80* self, V4_7D80* o); /* gsynth: defined below */typedef struct { float m[4]; } E2Quat;
typedef struct { char pad[0xA0]; unsigned char dirty; } E2Ident;
typedef struct { char pad[0x160]; int f160; } E2Root;
extern E2Ident* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(E2Root*);
#if 0 /* merge_units */
extern void* cJointInfo_Limits_InJointSpace(void*);
#endif /* merge_units */
void * cJointInfo_Limits_InJointSpace(); /* merge_units */

extern void cQuaternion_opAssign(void*, void*);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(E2Root*);
extern void cQuaternion_ctor_void(E2Quat*);
extern void* cSkaAnimAnchor_TreeNode_GetParentInverseRotation(E2Root*, E2Quat*);
#if 0 /* merge_units */
extern void cQuaternion_Rotate(void*, void*);
#endif /* merge_units */
#define cQuaternion_Rotate(a0, a1) ((void)cQuaternion_Rotate((V4_7D80 *)(a0), (V4_7D80 *)(a1))) /* merge_units */


extern void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(E2Root*);
void cSkaAnimAnchor_SetRotation(E2Root* r, void* q) {
    E2Quat tmp;
    cQuaternion_opAssign(cJointInfo_Limits_InJointSpace((char*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r) + 0x50), q);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(r)) {
        cQuaternion_ctor_void(&tmp);
        cQuaternion_Rotate(cJointInfo_Limits_InJointSpace((char*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r) + 0x50), cSkaAnimAnchor_TreeNode_GetParentInverseRotation(r, &tmp));
    }
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(r)->dirty = 1;
    cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(r);
    r->f160 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7CD0(void) {}
#undef cQuaternion_Rotate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7CD0 */

/* merge_units: begin func_001A7D80 */
#pragma push /* merge_units */
static inline V4_7D80 QMul_(V4_7D80* a, V4_7D80* b) {
    V4_7D80 r; V4_7D80* p = &r;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(a)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(p)
    }
    return r;
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4_7D80* cQuaternion_Rotate(V4_7D80* self, V4_7D80* o) {
    V4_7D80 t; V4_7D80* tp; t = QMul_(self, o); tp = &t; *self = *tp;
    return self;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7D80 */

/* merge_units: begin func_001A7DE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cJointInfo_Limits_InJointSpace(void* self) {
    return self;
}
static inline void merge_flush_func_001A7DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7DE0 */

/* merge_units: begin func_001A7DF0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 cQuaternion_GetRotated(V4* b, V4* c) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(c)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(q1)
    }
    return l0;
}
#pragma pop
static inline void merge_flush_func_001A7DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7DF0 */

/* merge_units: begin func_001A7E40 */
#pragma push /* merge_units */
#include "human_types.h"

void* cHuman_GetLedgeAnchor_void_2(Actor* actor) {
    return actor->edgeRoot;
}

void* cHuman_GetFloorAnchor_void(Actor* actor) {
    return actor->floorRoot;
}
static inline void merge_flush_func_001A7E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7E40 */

/* merge_units: begin func_001A7E60 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int mode; int bits[1]; } Physical;
static inline unsigned char Pcm_Test(Physical* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
void cModeSwitch_WithHistory_12_DeactivateMode(Physical* p, int bit)
{
    int i;
    p->bits[bit / 32] &= ~(1 << (bit & 31));
    for (i = 12; i >= 0 && !Pcm_Test(p, i); i--) {
    }
    if (!Pcm_Test(p, i)) {
        p->mode = -1;
    } else {
        p->mode = i;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7E60 */

/* merge_units: begin func_001A7F40 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; unsigned int type; unsigned char sub; } Ev;
typedef struct { char pad[0xA0]; unsigned char bA0; } Inv;
typedef struct { char pad[0x320C]; char anim[0x33E4 - 0x320C]; unsigned char b33E4; unsigned char b33E5; char pad33E6[2]; unsigned char b33E8;
    char pad33E9[0x3524 - 0x33E9]; Inv* inv; } Act;
extern unsigned char AnimPriority_Helper3(void*, int);
extern void AnimPriority_Helper2(void*, int, int);
extern void AnimPriority_Helper1(void*);
extern void AnimPriority_Helper0(void*, int, int);
extern void cWeapon_ReloadThrow(Inv*);

int Actor_HandleEmbeddedEvent(Act* a, Ev* e)
{
    switch (e->type) {
    case -1:
        break;
    case 0:
        switch (e->sub) case 4: case 5: {
            int r;
            char* p = a->anim;
            r = AnimPriority_Helper3(p + 0xC, 3);
            AnimPriority_Helper2(p + 4, 3, 0);
            AnimPriority_Helper1(p);
            AnimPriority_Helper0(p, 3, r);
        }
        break;
    case 1:
        switch (e->sub) case 4: case 5: a->inv->bA0 = 0;
        break;
    case 2:
        switch (e->sub) case 4: case 5: {
            cWeapon_ReloadThrow(a->inv);
            a->b33E4 = 0;
        }
        break;
    case 3:
        switch (e->sub) case 4: case 5: a->b33E5 = 0;
        break;
    case 4:
        switch (e->sub) case 4: case 5: a->b33E8 = 0;
        break;
    default:
        return 0;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7F40 */
