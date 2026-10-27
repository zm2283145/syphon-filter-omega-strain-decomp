/*
 * main/GuiKeyboard: 5 files, 0032D640-0032D870
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032D640 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_GuiWidgetPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0032D640 */

/* merge_units: begin func_0032D730 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* std_vector_GuiWidgetPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032D730 */

/* merge_units: begin func_0032D750 */
#pragma push /* merge_units */
typedef struct { char p0[0x14]; char set[1]; } Mgr32D750;
extern void* Gui_Canvas(void);
extern Mgr32D750* Gui_Manager(void);
extern void cLList_GuiWidgetPtr_Find(int* it, void* set, int* key);
extern void cLList_GuiWidgetPtr_End(int* it, void* set);
extern int opNe_cLListIteratorR_cLListIteratorR_6(int* a, int* b);
/* Returns o when it is the root widget or is registered with the manager, else 0. */
void* ValidateWidget_GuiWidgetP_2(void* o)
{
    Mgr32D750* m;
int key[1];
int it[1];
int end[1];
    if (!o) return 0;
    if (o == Gui_Canvas()) return o;
    key[0] = (int)o;
    m = Gui_Manager();
    cLList_GuiWidgetPtr_Find(it, m->set, key);
    cLList_GuiWidgetPtr_End(end, m->set);
    return opNe_cLListIteratorR_cLListIteratorR_6(it, end) ? o : 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032D750 */

/* merge_units: begin func_0032D7E0 */
#pragma push /* merge_units */
extern int strlen(char*);
#pragma opt_rotateloops off
char* func_0032D7E0(char* s) {
    int n;
    while (!((*s != 0) ^ 1) && (unsigned char)*s <= ' ') s++;
    n = strlen(s) - 1;
    while (n >= 0 && (unsigned char)s[n] <= ' ') { s[n] = 0; n--; }
    return s;
}
#pragma opt_rotateloops reset
#pragma pop /* merge_units */
/* merge_units: end func_0032D7E0 */

/* merge_units: begin func_0032D870 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

/* Resize a vector of 4-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem4, 4)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(PtrVector_Resize_32D870, Elem4, std_vector_pod_int_insert, std_vector_pod_int_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_0032D870 */
