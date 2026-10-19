/*
 * main/gameCamera: range (2 files, 0017A5D0-0017A600)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0017A5D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int ActiveList_RemoveObject(char* world, int camera);
extern char g_Game[]; /* world object */
extern int World_PushObjectFromAction(char* world, int camera); /* push camera */

int cNIEventOBJ_DeactivateCamera(int camera) {
    return ActiveList_RemoveObject(g_Game, camera);
}

int cNIEventOBJ_ActivateCamera(int camera) {
    return World_PushObjectFromAction(g_Game, camera);
}

void* func_0017A5F0(char* self) {
    return self + 0xB10;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017A5D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017A5D0 */

/* merge_units: begin func_0017A600 */
#pragma push /* merge_units */
typedef struct { char pad[0xB10]; Vec4 v; } ObjB10;
/* Copies a vector into the object's field at +0xB10. */
#pragma peephole off
void func_0017A600(ObjB10* obj, Vec4* v) { obj->v = *v; }
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017A600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017A600 */
