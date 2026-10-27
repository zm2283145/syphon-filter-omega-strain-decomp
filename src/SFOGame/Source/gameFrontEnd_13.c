/*
 * SFOGame/Source/gameFrontEnd: 4 files, 002CAA70-002CABA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CAA70 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

#pragma cplusplus on
extern "C" {
void* cMemMan_Allocate(int pool, void* p, char* file, int line);
}
extern "C" void* Sfo_Malloc(void* p)
{
    AllocGuard g;
    char f[] = "sfo_malloc: should only be used in rtime lib";
    return cMemMan_Allocate(2, p, f, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CAA70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CAA70 */

/* merge_units: begin func_002CAB40 */
#pragma push /* merge_units */
extern void GuiMessageBox_SetEditBufferSize(int, int);

void cGameFrontEnd_SetMessageBoxBufSize(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 600);
    cond = a0 == 0;
    if (cond) goto L002CAB60;
    GuiMessageBox_SetEditBufferSize(a0, a1);
L002CAB60:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CAB40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CAB40 */

/* merge_units: begin func_002CAB70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "gameFrontEnd_types.h"

/* True when the screen has a widget with flag bit 3 set. */
int cGameFrontEnd_IsMessageBoxAwake_void_2(FeScreen* screen) {
    FeWidget* w = screen->widget;

    if (w != 0) {
        return 0u < (unsigned int)(w->flags & 8);
    }
    return 0;
}
static inline void merge_flush_func_002CAB70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CAB70 */

/* merge_units: begin func_002CABA0 */
#pragma push /* merge_units */
typedef struct NodeABA0 { struct NodeABA0* prev; struct NodeABA0* next; int key; } NodeABA0;
typedef struct { char pad[0x2FC]; char list[4]; char hdr[4]; } ObjABA0;
extern NodeABA0* func_002CAC70(void* p);
extern NodeABA0* func_002CAC60(void* p);
extern void func_002CAC50(NodeABA0** it, NodeABA0* n);
int* cGameFrontEnd_FindMessageBox(ObjABA0* o, int key)
{
    NodeABA0* n = func_002CAC70(o->hdr)->next;
    NodeABA0* e;
    func_002CAC50(&e, func_002CAC60(o->list));
    while (n != e) {
        if (key == n->key)
            return &n->key;
        n = n->next;
        func_002CAC50(&e, func_002CAC60(o->list));
    }
    return 0;
}
static inline void merge_flush_func_002CABA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CABA0 */
