/*
 * main/scriptUtils: 2 files, 00268950-002689F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00268950 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

Word* cLListIterator_ArrayPtr_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_4(ListPos* a, ListPos* b) {
    return a->node != b->node;
}

void cLList_ArrayPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* List iterator increment: node = node->next. */
ListPos* cLListIterator_ArrayPtr_opInc(ListPos* it) {
    it->node = ((ListNode*)it->node)->next;
    return it;
}

/* List iterator dereference: address of the node's value. */
int* cLListIterator_ArrayPtr_opMul(ListPos* it) {
    return &((ListNode*)it->node)->value;
}

float* cLListIterator_ArrayPtr_opAssign(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void cLList_ArrayPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_ArrayPtr_ctor_void(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00268950 */

/* merge_units: begin func_002689F0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                    
int std_list_ArrayPtr_push_back(char *, void **);                      
extern char D_004A82B8;
extern char D_004F83E0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

char * ScriptArray_Create(int arg0) {
    char * sp4C;
    char * temp_s0;
    char * temp_s2;

    sp4C = NULL;
    if ((arg0 > 0) && (arg0 < 0x3E8)) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0 = (char *)(Mem_Alloc(0, 0xC, &D_004A82B8, 0x19E));
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s0 != NULL) {
            if (g_ProfileLockEnabled != 0) {
                Alloc_Lock(9);
            }
            g_ProfileLockDepth += 1;
            temp_s2 = (char *)(Mem_Alloc(0, arg0 * 4, &D_004A82B8, 0x127));
            if (g_ProfileLockEnabled != 0) {
                Alloc_Unlock(9);
            }
            g_ProfileLockDepth -= 1;
            F_(temp_s0, 0x0, int) = (int)(temp_s2);
            F_(temp_s0, 0x4, int) = arg0;
            F_(temp_s0, 0x8, int) = 0;
        }
        sp4C = temp_s0;
        std_list_ArrayPtr_push_back(&D_004F83E0, &sp4C);
    }
    return sp4C;
}
#pragma pop /* merge_units */
/* merge_units: end func_002689F0 */
