/*
 * SFOGame/Source/GuiMessageBox: 2 files, 002A88C0-002A89A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A88C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct LNode_88C0 { struct LNode_88C0* prev; struct LNode_88C0* next; int data; } LNode_88C0;
typedef union { LNode_88C0* p; LNode_88C0* volatile vp; } LIt_88C0;
extern "C" {
#if 0 /* merge_units */
void std_list_GuiWidgetPtr_begin(LIt_88C0* out, void* list);
#endif /* merge_units */
void std_list_GuiWidgetPtr_begin(Iter* out, PtrVec* v); /* merge_units */
#define std_list_GuiWidgetPtr_begin(a0, a1) (std_list_GuiWidgetPtr_begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

void std_list_GuiWidgetPtr_end(LIt_88C0* out, void* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(LIt_88C0* r, LIt_88C0* s);
}
struct LItS_88C0 { LNode_88C0* p; LItS_88C0(LNode_88C0* n) : p(n) {} };
extern "C" LItS_88C0 cLList_GuiWidgetPtr_Find(void* list, const int& val)
{
    LIt_88C0 it;
    LIt_88C0 c;
    LIt_88C0 end;
    LIt_88C0 b0;
    LIt_88C0 e0;
    std_list_GuiWidgetPtr_begin(&b0, list);
    cLListIterator_GuiWidgetPtr_ctor_listR(&c, &b0);
    for (it = c; std_list_GuiWidgetPtr_end(&e0, list), cLListIterator_GuiWidgetPtr_ctor_listR(&end, &e0), it.p != end.p; it.p = it.vp->next) {
        if (it.p->data == val) break;
    }
    return LItS_88C0(it.p);
}
#undef std_list_GuiWidgetPtr_begin /* merge_units */
static inline void merge_flush_func_002A88C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A88C0 */

/* merge_units: begin func_002A89A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void std_list_GuiWidgetPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_002A89A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A89A0 */
