/*
 * main/NPCInfoObject: range (2 files, 00436BA0-00436C00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00436BA0 */
#pragma push /* merge_units */
extern int D_00582A68;
extern void operator_delete(void* allocation);

/* Release a shared NPC node and optionally destroy it. */
int* func_00436BA0(int* node, short deleteFlag)
{
    if (node) {
        D_00582A68--;
        if (deleteFlag > 0)
            operator_delete(node);
    }
    return node;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00436BA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00436BA0 */

/* merge_units: begin func_00436C00 */
#pragma push /* merge_units */
typedef struct NPCInfoObject NPCInfoObject;

extern unsigned char D_00582778;
extern void func_004355D0(NPCInfoObject* self);

/* Ensure shared NPC information is initialized and increment its user count. */
NPCInfoObject* func_00436C00(NPCInfoObject* self) {
    if (D_00582778 == 0) {
        func_004355D0(self);
    }
    D_00582A68++;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00436C00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00436C00 */
