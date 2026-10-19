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

Word* func_00268950(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int func_00268960(ListPos* a, ListPos* b) {
    return a->node != b->node;
}

void func_00268980(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* List iterator increment: node = node->next. */
ListPos* func_00268990(ListPos* it) {
    it->node = ((ListNode*)it->node)->next;
    return it;
}

/* List iterator dereference: address of the node's value. */
int* func_002689B0(ListPos* it) {
    return &((ListNode*)it->node)->value;
}

float* func_002689C0(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void func_002689D0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_002689E0(void* self) {
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
int func_00268B50(char *, void **);                      
extern char D_004A82B8;
extern char D_004F83E0;
extern unsigned char D_00533880;
extern int D_00533888;

char * ScriptArray_Create(int arg0) {
    char * sp4C;
    char * temp_s0;
    char * temp_s2;

    sp4C = NULL;
    if ((arg0 > 0) && (arg0 < 0x3E8)) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s0 = (char *)(Mem_Alloc(0, 0xC, &D_004A82B8, 0x19E));
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s0 != NULL) {
            if (D_00533880 != 0) {
                Alloc_Lock(9);
            }
            D_00533888 += 1;
            temp_s2 = (char *)(Mem_Alloc(0, arg0 * 4, &D_004A82B8, 0x127));
            if (D_00533880 != 0) {
                Alloc_Unlock(9);
            }
            D_00533888 -= 1;
            F_(temp_s0, 0x0, int) = (int)(temp_s2);
            F_(temp_s0, 0x4, int) = arg0;
            F_(temp_s0, 0x8, int) = 0;
        }
        sp4C = temp_s0;
        func_00268B50(&D_004F83E0, &sp4C);
    }
    return sp4C;
}
#pragma pop /* merge_units */
/* merge_units: end func_002689F0 */
