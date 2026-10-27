/*
 * Libs/SFOLib/Source/guiManager: 4 files, 00419270-00419530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00419270 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "guiManager.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma push
#pragma cplusplus on
typedef struct { char p0[20]; unsigned short flags; } PS0_004193D0; /* GuiWidget view */
extern "C" void GuiManager_Remove(GuiScreenList* self, PS0_004193D0* widget); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
/* Widget seen through its virtual destructor (first vtable slot). */
struct VC_9270 { virtual int v0(int); };
/* List iterator returned by value (begin/end). */
struct NodeIter { GuiPtrNode* node; };
extern "C" {
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int*, GuiPtrList*, GuiPtrNode**, GuiPtrNode**);
NodeIter std_list_deleter_voidPtr_begin_void(GuiPtrList*);                 /* begin() */
NodeIter std_list_GuiWidgetPtr_end(GuiPtrList*);                 /* end() */
void std_list_GuiWidgetPtr_generic_iterator_ctor(GuiPtrNode**, const NodeIter&);   /* iterator copy */
void cLListIterator_GuiWidgetPtr_ctor_listR(GuiPtrNode**, const NodeIter&);   /* iterator copy */
#if 0 /* merge_units */
void GuiManager_Remove(GuiScreenList*, VC_9270*);
#endif /* merge_units */
#define GuiManager_Remove(a0, a1) ((void)GuiManager_Remove((a0), (PS0_004193D0 *)(a1))) /* merge_units */


extern char D_004BF138; /* "guiManager.cc" */
}
#pragma opt_common_subs off
/* Remove, destroy and free every widget queued in pendingDelete, then empty the list. */
extern "C" void GuiManager_DestroyPending(GuiScreenList* self) {
    if (self->pendingDelete.count != 0) {
        GuiPtrNode* end;
        {
            GuiPtrNode* n;
            GuiPtrNode* it;
            std_list_GuiWidgetPtr_generic_iterator_ctor(&it, std_list_deleter_voidPtr_begin_void(&self->pendingDelete));
            n = it;
            while ((cLListIterator_GuiWidgetPtr_ctor_listR(&end, std_list_GuiWidgetPtr_end(&self->pendingDelete)), n != end)) {
                VC_9270* w;
                GuiManager_Remove(self, (VC_9270*)n->item);
                w = (VC_9270*)n->item;
                {
                    AllocGuard g;
                    w->v0(-1);
                    cMemMan_Deallocate(0, w, &D_004BF138, 0x53);
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
            std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&res, &self->pendingDelete, &first, &last);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00419270(void) {}
#undef GuiManager_Remove /* merge_units */
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
int std_list_deleter_voidPtr_erase_listdeleter(...);                     /* list erase */
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(...);
int opNe_cLListIteratorR_cLListIteratorR_6(...);                     /* iterator != */
int cLList_GuiWidgetPtr_End(...);                     /* end() */
int cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(...);
int cLListIterator_GuiWidgetPtr_opInc(...);                     /* ++iterator */
int *cLListIterator_GuiWidgetPtr_opMul(...);                    /* *iterator */
int cLListIterator_GuiWidgetPtr_opAssign(...);
int cLList_GuiWidgetPtr_Begin(...);                     /* begin() */
int cLListIterator_GuiWidgetPtr_ctor_void(...);
void **Gui_Canvas(...);

}
/*
 * If the widget is set up: find it in the widget list, notify the screen stack
 * (widget flag 0x8), tear the widget down and erase it from the list.
 */
extern "C" void GuiManager_Remove(GuiScreenList *self, PS0_004193D0 *widget) {
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
            if ((Gui_Canvas() != NULL) && (widget->flags & 8)) {
                stack = Gui_Canvas();
                ((VC004193D0 *)(stack))->v24(widget);
            }
            /* found->item->self (GuiWidget 0x44) */
            sub = (void **)(F_(F_(found, 0x8, int), 0x44, int));
            ((VC004193D0 *)(sub))->v2();
            node = found;
            std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &node);
            std_list_deleter_voidPtr_erase_listdeleter(&erased, &self->widgets, &pos);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004193D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004193D0 */

/* merge_units: begin func_00419530 */
#pragma push /* merge_units */
#pragma cplusplus on
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00419530 { virtual int v0(); virtual int v1(...); };
extern "C" {
int std_list_GuiWidgetPtr_push_back_GuiWidgetPR(...);                      
}
extern "C" void GuiManager_Add(int arg0, char * arg1) {
    void **temp_a0;

    if (!(F_(arg1, 0x14, unsigned short) & 1)) {
        std_list_GuiWidgetPtr_push_back_GuiWidgetPR(arg0 + 0x14, &arg1);
        temp_a0 = (void **)(F_(arg1, 0x44, int));
        ((VC00419530 *)(temp_a0))->v1();
    }
}
static inline void merge_flush_func_00419530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00419530 */

/* merge_units: begin func_00419590 */
#pragma push /* merge_units */
typedef struct { char p[8]; void* item; } Node419590;
typedef struct { int size; int pad; Node419590* first; } List419590;
typedef struct { char p[0x14]; List419590 a; List419590 b; char s[0x10]; } Obj419590;
extern void GuiManager_DestroyWidget(Obj419590* o, void* item, int f);
extern void String_Dtor(void* p, int f);
extern void cLList_GuiWidgetPtr_dtor(void* p, int f);
extern void std_map_cString_cFontPtr_dtor(Obj419590* p, int f);
extern void operator_delete(void* p);
Obj419590* GuiManager_dtor(Obj419590* self, short del)
{
    if (self) {
        while (self->a.size) GuiManager_DestroyWidget(self, self->a.first->item, 1);
        if (self->s) String_Dtor(self->s, 0);
        if (&self->b) cLList_GuiWidgetPtr_dtor(&self->b, 0);
        if (&self->a) cLList_GuiWidgetPtr_dtor(&self->a, 0);
        if (self) std_map_cString_cFontPtr_dtor(self, -1);
        if (del > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00419590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00419590 */
