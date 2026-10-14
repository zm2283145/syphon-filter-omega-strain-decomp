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
NodeIter func_0013B180(GuiPtrList*);                 /* begin() */
NodeIter func_0028C0A0(GuiPtrList*);                 /* end() */
void func_0028C0B0(GuiPtrNode**, const NodeIter&);   /* iterator copy */
void func_0028C090(GuiPtrNode**, const NodeIter&);   /* iterator copy */
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
            func_0028C0B0(&it, func_0013B180(&self->pendingDelete));
            n = it;
            while ((func_0028C090(&end, func_0028C0A0(&self->pendingDelete)), n != end)) {
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
int func_00138DA0(...);                     /* list erase */
int func_0015AF40(...);
int func_002A8890(...);                     /* iterator != */
int func_002A88B0(...);                     /* end() */
int func_002CCDE0(...);
int func_002CCDF0(...);                     /* ++iterator */
int *func_002CCE10(...);                    /* *iterator */
int func_002CCE20(...);
int func_002CCE30(...);                     /* begin() */
int func_002CCE40(...);
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
        func_002CCE40(&it);
        func_002CCE30(&begin, &self->widgets);
        func_002CCE20(&it, &begin);
        func_002A88B0(&end, &self->widgets);
        if (func_002A8890(&it, &end) != 0) {
loop_3:
            if ((void *)(*func_002CCE10(&it)) != (void *)(widget)) {
                func_002CCDF0(&it);
                func_002A88B0(&end, &self->widgets);
                if (func_002A8890(&it, &end) == 0) {

                } else {
                    goto loop_3;
                }
            }
        }
        func_002CCDE0(&found, &it);
        if (F_(found, 0x8, int) != NULL) {
            if ((Gui_GetScreenStack() != NULL) && (widget->flags & 8)) {
                stack = Gui_GetScreenStack();
                ((VC004193D0 *)(stack))->v24(widget);
            }
            /* found->item->self (GuiWidget 0x44) */
            sub = (void **)(F_(F_(found, 0x8, int), 0x44, int));
            ((VC004193D0 *)(sub))->v2();
            node = found;
            func_0015AF40(&pos, &node);
            func_00138DA0(&erased, &self->widgets, &pos);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004193D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004193D0 */
