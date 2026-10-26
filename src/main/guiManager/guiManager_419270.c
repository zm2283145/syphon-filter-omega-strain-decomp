/*
 * main/guiManager: range (2 files, 00419270-004193D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "guiManager.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00419270 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct { char p0[20]; unsigned short flags; } PS0_004193D0; /* GuiWidget view */
extern "C" void GuiManager_RemoveWidget(GuiScreenList* self, PS0_004193D0* widget); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
/* Widget seen through its virtual destructor (first vtable slot). */
struct VC_9270 { virtual int v0(int); };
/* List iterator returned by value (begin/end). */
struct NodeIter { GuiPtrNode* node; };
extern "C" {
void ObjectList_EraseRange(int*, GuiPtrList*, GuiPtrNode**, GuiPtrNode**);
NodeIter List_Begin(GuiPtrList*);                 /* begin() */
NodeIter std_list_GuiWidgetPtr_end(GuiPtrList*);                 /* end() */
void std_list_GuiWidgetPtr_generic_iterator_ctor(GuiPtrNode**, const NodeIter&);   /* iterator copy */
void cLListIterator_GuiWidgetPtr_ctor_listR(GuiPtrNode**, const NodeIter&);   /* iterator copy */
#if 0 /* merge_units */
void GuiManager_RemoveWidget(GuiScreenList*, VC_9270*);
#endif /* merge_units */
#define GuiManager_RemoveWidget(a0, a1) (GuiManager_RemoveWidget((a0), (PS0_004193D0 *)(a1))) /* merge_units */

extern char D_004BF138; /* "guiManager.cc" */
}
#pragma opt_common_subs off
/* Remove, destroy and free every widget queued in pendingDelete, then empty the list. */
extern "C" void GuiManager_FlushDeleted(GuiScreenList* self) {
    if (self->pendingDelete.count != 0) {
        GuiPtrNode* end;
        {
            GuiPtrNode* n;
            GuiPtrNode* it;
            std_list_GuiWidgetPtr_generic_iterator_ctor(&it, List_Begin(&self->pendingDelete));
            n = it;
            while ((cLListIterator_GuiWidgetPtr_ctor_listR(&end, std_list_GuiWidgetPtr_end(&self->pendingDelete)), n != end)) {
                VC_9270* w;
                GuiManager_RemoveWidget(self, (VC_9270*)n->item);
                w = (VC_9270*)n->item;
                {
                    AllocGuard g;
                    w->v0(-1);
                    Mem_Free(0, w, &D_004BF138, 0x53);
                }
                n = n->next;
            }
        }
        {
            int res;
            GuiPtrNode* first;
            GuiPtrNode* last;
            last = (GuiPtrNode*)&self->pendingDelete.last; /* sentinel node */
            first = self->pendingDelete.first;
            ObjectList_EraseRange(&res, &self->pendingDelete, &first, &last);
        }
    }
}
#undef GuiManager_RemoveWidget /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00419270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00419270 */

/* merge_units: begin func_004193D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


/* Virtual slots used here: v2 = widget teardown (vtable slot 4), v24 = screen stack notification. */
struct VC004193D0 { virtual int v0(); virtual int v1(); virtual int v2(...); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); };
extern "C" {
int List_Erase(...);                     /* list erase */
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(...);
int opNe_cLListIteratorR_cLListIteratorR_6(...);                     /* iterator != */
int cLList_GuiWidgetPtr_End(...);                     /* end() */
int cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(...);
int cLListIterator_GuiWidgetPtr_opInc(...);                     /* ++iterator */
int *cLListIterator_GuiWidgetPtr_opMul(...);                    /* *iterator */
int cLListIterator_GuiWidgetPtr_opAssign(...);
int cLList_GuiWidgetPtr_Begin(...);                     /* begin() */
int cLListIterator_GuiWidgetPtr_ctor_void(...);
void **Gui_GetScreenStack(...);

}
/*
 * If the widget is set up: find it in the widget list, notify the screen stack
 * (widget flag 0x8), tear the widget down and erase it from the list.
 */
extern "C" void GuiManager_RemoveWidget(GuiScreenList *self, PS0_004193D0 *widget) {
    char * found;
    char * node;
    int erased;
    int pos;
    int it;
    int begin;
    int end;
    void **sub;
    void **stack;

    if (widget->flags & GUI_WIDGET_SET_UP) {
        cLListIterator_GuiWidgetPtr_ctor_void(&it);
        cLList_GuiWidgetPtr_Begin(&begin, &self->widgets);
        cLListIterator_GuiWidgetPtr_opAssign(&it, &begin);
        cLList_GuiWidgetPtr_End(&end, &self->widgets);
        if (opNe_cLListIteratorR_cLListIteratorR_6(&it, &end) != 0) {
loop_3:
            if ((void *)(*cLListIterator_GuiWidgetPtr_opMul(&it)) != (void *)(widget)) {
                cLListIterator_GuiWidgetPtr_opInc(&it);
                cLList_GuiWidgetPtr_End(&end, &self->widgets);
                if (opNe_cLListIteratorR_cLListIteratorR_6(&it, &end) == 0) {

                } else {
                    goto loop_3;
                }
            }
        }
        cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(&found, &it);
        if (F_(found, 0x8, int) != NULL) {
            if ((Gui_GetScreenStack() != NULL) && (widget->flags & 8)) {
                stack = Gui_GetScreenStack();
                ((VC004193D0 *)(stack))->v24(widget);
            }
            /* found->item->self (GuiWidget 0x44) */
            sub = (void **)(F_(F_(found, 0x8, int), 0x44, int));
            ((VC004193D0 *)(sub))->v2();
            node = found;
            std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &node);
            List_Erase(&erased, &self->widgets, &pos);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004193D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004193D0 */
