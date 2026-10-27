/*
 * main/gameobj: range (2 files, 003931F0-003932F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003931F0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct { int pad0; int count; } Vec_3932F0;
typedef struct { unsigned char pad[0xB0]; Vec_3932F0 vec; } Obj_3932F0;
extern "C" void cSkaSystem_DetachParentAnchors_All(Obj_3932F0* o); /* gsynth: defined below */
#pragma pop
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int *cTreeNode_cSkaSystemPtr_Data(char * );                      
int cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(char *, char *);                        
int cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(char *);                               
void **cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(char *);                          
int cArray_cTreeNode_cSkaSystemPtrPtr_End_void(char *, char *);                          
int cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(char *, char *);                          
char *cMatrix_GetYAxis(char *);                             
int cArray_cTreeNode_cSkaSystemPtrPtr_Clear(char *);                               
#if 0 /* merge_units */
int cSkaSystem_DetachParentAnchors_All(int);
#endif /* merge_units */
#define cSkaSystem_DetachParentAnchors_All(a0) (cSkaSystem_DetachParentAnchors_All((void *)(a0))) /* merge_units */
                               

void cSkaSystem_DetachChildren(char *arg0) {
    int sp2C;
    int sp28;
    int sp24;
    int sp20;

    cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(&sp2C, cMatrix_GetYAxis(arg0 + 0x100));
    cArray_cTreeNode_cSkaSystemPtrPtr_End_void(&sp28, cMatrix_GetYAxis(arg0 + 0x100));
    if (cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(&sp2C, &sp28) != 0) {
        do {
            cSkaSystem_DetachParentAnchors_All(*cTreeNode_cSkaSystemPtr_Data(*cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(&sp2C)));
            cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(&sp2C);
        } while (cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(&sp2C, &sp28) != 0);
    }
    cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(&sp24, arg0 + 0x108);
    cArray_cTreeNode_cSkaSystemPtrPtr_End_void(&sp20, arg0 + 0x108);
    if (cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(&sp24, &sp20) != 0) {
        do {
            F_((*cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(&sp24)), 0x4, int) = 0;
            cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opInc(&sp24);
        } while (cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opNe(&sp24, &sp20) != 0);
    }
    cArray_cTreeNode_cSkaSystemPtrPtr_Clear(arg0 + 0x108);
}
#undef cSkaSystem_DetachParentAnchors_All /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003931F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003931F0 */

/* merge_units: begin func_003932F0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Run the per-element cleanup over a vector of 0x180-byte entries. */
typedef struct { unsigned char pad[0x10]; unsigned char sub[0x170]; } Elem_3932F0;



extern "C" {
Elem_3932F0** std_vector_deleter_cSkaAnimAnchorListEntry_data(Vec_3932F0* v);
void cSkaAnimAnchor_TreeNode_DetachParent(void* p);
}

static inline bool Ne_3932F0(Elem_3932F0* a, Elem_3932F0* b) { return !(a == b); }

extern "C" void cSkaSystem_DetachParentAnchors_All(Obj_3932F0* o)
{
    Elem_3932F0* it;
    Vec_3932F0* v = &o->vec;
    Elem_3932F0* end;
    it = *std_vector_deleter_cSkaAnimAnchorListEntry_data(v);
    end = *std_vector_deleter_cSkaAnimAnchorListEntry_data(v) + v->count;
    for (; Ne_3932F0(it, end); it++) {
        cSkaAnimAnchor_TreeNode_DetachParent(it->sub);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003932F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003932F0 */
