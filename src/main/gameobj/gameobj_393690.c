/*
 * main/gameobj: range (2 files, 00393690-00393760)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00393690 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int cArray_cSkaAnimAnchorListEntry_Iterator_opNe();                        
int cArray_cSkaAnimAnchorListEntry_Iterator_opInc();                               
int cSkaAnimAnchor_DetachParent();                               
int cSkaAnimAnchorListEntry_Anchor();                             
int cArray_cSkaAnimAnchorListEntry_Iterator_opArrow();                             
int cArray_cSkaAnimAnchorListEntry_End();                          
int cArray_cSkaAnimAnchorListEntry_Begin();                          
int cSkaParams_GetAnimAnchorList();                             
int cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved();                      

void cSkaSystem_DetachParent(int arg0) {
    int sp3C;
    int sp38;
    char * sp34;
    int temp_v0;
    int temp_v1_2;
    char * temp_v1;

    temp_v0 = cSkaParams_GetAnimAnchorList(arg0 + 0x10);
    cArray_cSkaAnimAnchorListEntry_Begin(&sp3C, temp_v0);
    cArray_cSkaAnimAnchorListEntry_End(&sp38, temp_v0);
    if (cArray_cSkaAnimAnchorListEntry_Iterator_opNe(&sp3C, &sp38) != 0) {
        do {
            cSkaAnimAnchor_DetachParent(cSkaAnimAnchorListEntry_Anchor(cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(&sp3C)));
            cArray_cSkaAnimAnchorListEntry_Iterator_opInc(&sp3C);
        } while (cArray_cSkaAnimAnchorListEntry_Iterator_opNe(&sp3C, &sp38) != 0);
    }
    temp_v1 = (char *)(arg0 + 0x100);
    sp34 = temp_v1;
    temp_v1_2 = F_(*(char * volatile *)&sp34, 0x4, int);
    if (temp_v1_2 != 0) {
        cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(temp_v1_2 + 8, &sp34);
        F_(sp34, 0x4, int) = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393690 */

/* merge_units: begin func_00393760 */
#pragma push /* merge_units */
#pragma opt_propagation off

typedef struct { float v[4]; } V4;
typedef struct { char p[0x1D8]; } SkelNode;

typedef struct Anim {
    int x0;
    char p4[0xC];
    char x10[0xF0];
    char x100[0x10];
} Anim;

typedef struct Sub2E50 {
    int x0;
    char x4[0x10];
    unsigned char x14;
    char p15[3];
    char x18[0x10];
    int x28;
    char p2c[4];
    char x30[0x20];
    V4 x50;
} Sub2E50;

typedef struct Tail {
    int x0;
    char p4[0xC];
    float mn[4];
    float mx[4];
    int x30;
    int x34;
    char p38[8];
    Sub2E50* x40;
    int x44;
} Tail;

static inline void Tail_ctor(Tail* t, Sub2E50* s)
{
    t->x0 = 0;
    t->mn[0] = 3.4028235e38f;
    t->mn[1] = 3.4028235e38f;
    t->mn[2] = 3.4028235e38f;
    t->mn[3] = 1.0f;
    t->mx[0] = -3.4028235e38f;
    t->mx[1] = -3.4028235e38f;
    t->mx[2] = -3.4028235e38f;
    t->mx[3] = 1.0f;
    t->x30 = 0;
    t->x34 = 0;
    t->x40 = s;
    t->x44 = 0;
}

typedef struct Actor {
    void* vt;
    char p4[0x2B];
    unsigned char x2F;
    int x30;
    char p34[0x2C];
    char x60[0x2E50 - 0x60];
    Sub2E50 x2E50;
    int x2EB0;
    char p2EB4[0xC];
    Anim x2EC0;
    char p2FD0[0x2FE0 - 0x2EC0 - sizeof(Anim)];
    Tail x2FE0;
} Actor;

extern char D_004DF740[];
extern void cGOBJ_ctor(Actor* self, int* name, int type, int* extra);
extern void cMan_ctor(void*);
extern void cArray_cBoneScale_ctor(void*);
extern void cBone_ctor_void(SkelNode*);
extern void cArray_cBone_ctor(void*, int, SkelNode*);
extern void cBone_dtor(SkelNode*, int);
extern void cBox_ctor_void(void*);
extern void cVector_Get0001(V4*);
extern void cVector_ctor_cVectorR(V4*, V4*);
extern void cSkaParams_ctor(void*, void*, void*);
extern void cTreeNode_cSkaSystemPtr_ctor(void*, Anim**);
extern void cSkaSystem_SetInitialAnimation(Anim*);

static inline void Anim_ctor(Anim* a, void* owner)
{
    a->x0 = 0;
    cSkaParams_ctor(a->x10, owner, 0);
    cTreeNode_cSkaSystemPtr_ctor(a->x100, &a);
    cSkaSystem_SetInitialAnimation(a);
}

Actor* cSKM_GOBJ_ctor_cObjectIdR_cSubclassIdR(Actor* me, int* name, int* extra)
{
    Sub2E50* s;
    Actor* self = me;
    cGOBJ_ctor(me, name, 2, extra);
    self->vt = D_004DF740;
    cMan_ctor(self->x60);
    s = &self->x2E50;
    s->x0 = 0;
    cArray_cBoneScale_ctor(s->x4);
    s->x14 = 0;
    {
        SkelNode n;
        cBone_ctor_void(&n);
        cArray_cBone_ctor(s->x18, 0, &n);
        cBone_dtor(&n, -1);
    }
    s->x28 = 0;
    cBox_ctor_void(s->x30);
    {
        V4 v;
        cVector_Get0001(&v);
        cVector_ctor_cVectorR(&s->x50, &v);
    }
    self->x2EB0 = 0xDEADBEEF;
    Anim_ctor(&self->x2EC0, &self->x2E50);
    Tail_ctor(&self->x2FE0, &self->x2E50);
    self->x2F = 1;
    self->x30 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393760 */
