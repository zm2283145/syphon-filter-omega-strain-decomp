/*
 * main/path: range (2 files, 00163680-00163730)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00163680 */
#pragma push /* merge_units */
extern void cParticleListItem_cNodeIndex_dtor();
extern void cInsertList_cNodeIndex_dtor();
extern void cInsertList_cNodeIndex_cStartNode_dtor();
extern void * const D_004D9720[];
extern void * const D_004D9730[];
extern void * const D_004D9740[];
extern void * const D_004D9750[];
extern void operator_delete(void* p);
typedef struct { void* vt; } V_3680;
V_3680* cPriorityQueue_cNodeIndex_dtor(V_3680* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004D9750);
        if (self) {
            V_3680* m;
            self->vt = ((char*)D_004D9740);
            m = (V_3680*)((char*)self + 0x10);
            if (m) {
                self[4].vt = ((char*)D_004D9730);
                if (m)
                    self[4].vt = ((char*)D_004D9720);
            }
            m = (V_3680*)((char*)self + 0x4);
            if (m) {
                self[1].vt = ((char*)D_004D9730);
                if (m)
                    self[1].vt = ((char*)D_004D9720);
            }
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9720[4] = { (void*)0x0, (void*)0x0, (void*)cParticleListItem_cNodeIndex_dtor, (void*)0x0 };
void * const D_004D9730[4] = { (void*)0x0, (void*)0x0, (void*)cInsertList_cNodeIndex_cStartNode_dtor, (void*)0x0 };
void * const D_004D9740[4] = { (void*)0x0, (void*)0x0, (void*)cInsertList_cNodeIndex_dtor, (void*)0x0 };
void * const D_004D9750[4] = { (void*)0x0, (void*)0x0, (void*)cPriorityQueue_cNodeIndex_dtor, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163680 */

/* merge_units: begin func_00163730 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; void* vt10; void* vt14; char pad18[8]; void* vt20; char pad24[0xC]; char arr[4]; } S_3730;
#if 0 /* merge_units */
extern char D_004D9720[];
#endif /* merge_units */
#define D_004D9720 ((char*)&D_004D9720) /* merge_units */

#if 0 /* merge_units */
extern char D_004D9730[];
#endif /* merge_units */
#define D_004D9730 ((char*)&D_004D9730) /* merge_units */

#if 0 /* merge_units */
extern char D_004D9740[];
#endif /* merge_units */
#define D_004D9740 ((char*)&D_004D9740) /* merge_units */

#if 0 /* merge_units */
extern char D_004D9750[];
#endif /* merge_units */
#define D_004D9750 ((char*)&D_004D9750) /* merge_units */

void cNodeIndex_dtor(void* p, int f);
void __destroy_array(void* arr, void* dtor, int size, int n);
void operator_delete(void* p);
S_3730* cNodeRequest_dtor(S_3730* self, short del)
{
    if (self) {
        __destroy_array(self->arr, cNodeIndex_dtor, 0x20, 0x20);
        if (&self->vt10) {
            self->vt10 = D_004D9750;
            if (&self->vt10) {
                self->vt10 = D_004D9740;
                if (&self->vt20) {
                    self->vt20 = D_004D9730;
                    if (&self->vt20)
                        self->vt20 = D_004D9720;
                }
                if (&self->vt14) {
                    self->vt14 = D_004D9730;
                    if (&self->vt14)
                        self->vt14 = D_004D9720;
                }
            }
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef D_004D9720 /* merge_units */
#undef D_004D9730 /* merge_units */
#undef D_004D9740 /* merge_units */
#undef D_004D9750 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163730(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163730 */
