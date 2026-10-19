/*
 * main/texman: range (4 files, 00380C90-00380D40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "texman_types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_00380C90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List iterator helpers.
 */


/* Iterator inequality. */
int func_00380C90(TexListIter* a, TexListIter* b) {
    return a->node != b->node;
}

void func_00380CB0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Post-increment: returns the current node and advances it. */
void func_00380CC0(TexListIter* out, TexListIter* it) {
    TexListNode* node = it->node;

    it->node = node->next;
    out->node = node;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00380C90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00380C90 */

/* merge_units: begin func_00380CE0 */
#pragma push /* merge_units */
extern void List_Erase_383560(int* out, void* a, int* b);

/* Calls List_Erase_383560 with a copy of *b and stores the produced word in *out. */
void func_00380CE0(int* out, void* a, int* b) {
    int value;
    int result;
    value = *b;
    List_Erase_383560(&result, a, &value);
    *out = result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00380CE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00380CE0 */

/* merge_units: begin func_00380D20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator helpers.
 */


/* Address of the value held by the iterator's node. */
int* func_00380D20(TexListIter* it) {
    return &it->node->value;
}

void func_00380D30(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00380D20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00380D20 */

/* merge_units: begin func_00380D40 */
#pragma push /* merge_units */
extern void func_0036DFB0(void* obj, char* name, void* obj2);
extern void TexMan_LoadNewTexture(void* self, void* obj, __int128* name);
/* Formats a 16-byte name into a buffer, applies it to obj, then forwards to TexMan_LoadNewTexture. */
void Tex_FindByName(void* self, __int128 name, void* obj)
{
    char buf[80];
    sprintf(buf, "%s.TDX", &name);
    func_0036DFB0(obj, buf, obj);
    TexMan_LoadNewTexture(self, obj, &name);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00380D40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00380D40 */
