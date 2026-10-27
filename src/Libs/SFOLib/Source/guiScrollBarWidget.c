/*
 * main/GenInfoObject: 6 files, 0043B910-0043BA60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043B910 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004BFDB0[]; void cMemMan_Deallocate(int pool, void* p, char* file, int line); }
extern "C" void cAllocator_node_deallocate_nodeP_uint_18(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        cMemMan_Deallocate(0, node, D_004BFDB0, 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043B910 */

/* merge_units: begin func_0043B9B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* std_tree_pair_tGenInfoPtr_value_compare_node_alloc(char* self) {
    return self + 4;
}

void cAllocator_pair_tGenInfoPtr_destroy(void) {
}

void* std_tree_pair_tGenInfoPtr_value_compare_alloc(void* self) {
    return self;
}

Map* std_tree_pair_tGenInfoPtr_value_compare_ctor(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043B9B0 */

/* merge_units: begin func_0043BA00 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_0043BA00;
extern void std_tree_pair_tGenInfoPtr_value_compare_destroy(R1Tree_0043BA00* t, void* n);
extern void operator_delete(void* p);
R1Tree_0043BA00* std_tree_pair_tGenInfoPtr_value_compare_dtor(R1Tree_0043BA00* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_tGenInfoPtr_value_compare_destroy(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043BA00 */

/* merge_units: begin func_0043BA60 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_0043BA60;
typedef struct { R1Tree_0043BA60 tree; } R1Own_0043BA60;
#if 0 /* merge_units */
extern void std_tree_pair_tGenInfoPtr_value_compare_dtor(R1Tree_0043BA60* t, short del);
#endif /* merge_units */
#define std_tree_pair_tGenInfoPtr_value_compare_dtor(a0, a1) ((void)std_tree_pair_tGenInfoPtr_value_compare_dtor((R1Tree_0043BA00 *)(a0), (a1))) /* merge_units */

R1Own_0043BA60* cAssocArray_tGenInfoPtr_bool_dtor(R1Own_0043BA60* o, short del)
{
    if (o) {
        R1Tree_0043BA60* t = &o->tree;
        if (t)
            std_tree_pair_tGenInfoPtr_value_compare_dtor(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef std_tree_pair_tGenInfoPtr_value_compare_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043BA60 */

/* merge_units: begin func_0043BAC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_tGenInfoPtr_dtor, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_0043BAC0 */

/* merge_units: begin func_0043BB20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiWidget_onInput();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern "C" void GuiScrollBarWidget_GetClassName();
extern "C" void GuiScrollBarWidget_IsClass();
extern "C" void GuiScrollBarWidget_onWake();
extern "C" void GuiScrollBarWidget_onAdd();
extern void * const D_004E0F40[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiScrollBarWidget_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0F40);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0F40[24] = { (void*)0x0, (void*)0x0, (void*)GuiScrollBarWidget_dtor, (void*)GuiScrollBarWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiScrollBarWidget_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiWidget_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiScrollBarWidget_GetClassName, (void*)GuiScrollBarWidget_IsClass, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_0043BB20 */
