/*
 * main/GuiCanvas: 12 files, 00415F00-00416740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00415F00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
class V415F00 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24(int);
};
typedef struct { char pad[8]; int arg; } N415F00;
typedef struct { void* vt; char p0[0x24]; int count; N415F00* head; char p1[0x54 - 0x30]; char sub[4]; } T415F00;
extern "C" {
extern "C" void GuiCanvas_GetClassName();
extern "C" void GuiCanvas_IsType();
extern "C" void GuiCanvas_FinishDeferredPop();
extern "C" void GuiCanvas_PopScreen();
extern "C" void GuiCanvas_PushScreen();
extern "C" void GuiCanvas_Navigate();
extern "C" void GuiCanvas_DispatchInput();
extern "C" void GuiCanvas_UpdateStack();
extern "C" void GuiFrontendCanvas_Draw();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_BaseSleep();
extern "C" void GuiWidget_BaseWake();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void GuiWidget_Load();
extern void * const D_004E08D0[];
void cLList_GuiWidgetPtr_dtor(void* p, int f);
void GuiWidget_Destroy(T415F00* p, int f);
void operator_delete(void* p);
}
extern "C" T415F00* GuiCanvas_PopAll(T415F00* self, short flag) {
    if (self) {
        self->vt = ((char*)D_004E08D0);
        while (self->count) ((V415F00*)self)->s24(self->head->arg);
        if (self->sub) cLList_GuiWidgetPtr_dtor(self->sub, 0);
        GuiWidget_Destroy(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004E08D0[28] = { (void*)0x0, (void*)0x0, (void*)GuiCanvas_PopAll, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiWidget_BaseWake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiCanvas_Navigate, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiCanvas_FinishDeferredPop, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiCanvas_GetClassName, (void*)GuiCanvas_IsType, (void*)GuiFrontendCanvas_Draw, (void*)GuiCanvas_UpdateStack, (void*)GuiCanvas_PushScreen, (void*)GuiCanvas_PopScreen, (void*)GuiCanvas_DispatchInput };
#pragma pop /* merge_units */
/* merge_units: end func_00415F00 */

/* merge_units: begin func_00415FC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00415FC0, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_00415FC0 */

/* merge_units: begin func_00416020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor_mid.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_MID(func_00416020)
#pragma pop /* merge_units */
/* merge_units: end func_00416020 */

/* merge_units: begin func_004160A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

#if 0 /* merge_units */
extern char D_004E08D0[];         /* GuiWidget4160A0 vtable */
#endif /* merge_units */
#define D_004E08D0 ((char*)&D_004E08D0) /* merge_units */

extern int ScalarCollection_Init(L4ScalarCollection*);
extern GuiWidget* GuiWidget_ctor(GuiWidget*);

/* Constructor of a GuiWidget subclass; clears flag bit 2 of the base. */
GuiWidget4160A0* GuiCanvas_ctor(GuiWidget4160A0* self) {
    unsigned int flags;

    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004E08D0;
    ScalarCollection_Init(&self->unk54);
    self->unk50 = 0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk60 = 0;
    self->unk64 = 0;
    flags = self->base.flags; /* zero-extended load keeps the match */
    self->base.flags = flags & 0xFFFB;
    self->unk51 = 1;
    self->unk52 = 1;
    self->unk68 = 0xF000;
    return self;
}
#undef D_004E08D0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004160A0 */

/* merge_units: begin func_00416110 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00416110, std_list_GuiWidgetPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00416110 */

/* merge_units: begin func_00416170 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(ReceiverList_Dtor_416170)
#pragma pop /* merge_units */
/* merge_units: end func_00416170 */

/* merge_units: begin func_004161F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor_shallow.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_SHALLOW(func_004161F0)
#pragma pop /* merge_units */
/* merge_units: end func_004161F0 */

/* merge_units: begin func_00416260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_range.h"

/* Erase a range of nodes from a linked list. */
DEFINE_OBJECT_LIST_ERASE_RANGE(ObjectList_EraseRange_416260)
#pragma pop /* merge_units */
/* merge_units: end func_00416260 */

/* merge_units: begin func_004163A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_one.h"

/* Erase one node from a linked list. */
DEFINE_OBJECT_LIST_ERASE_ONE(List_Erase_4163A0)
#pragma pop /* merge_units */
/* merge_units: end func_004163A0 */

/* merge_units: begin func_004164A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "list_insert_before.h"

/* Insert an int value before a list position. */
DEFINE_LIST_INSERT_BEFORE(List_InsertBefore_4164A0)
#pragma pop /* merge_units */
/* merge_units: end func_004164A0 */

/* merge_units: begin func_00416660 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptr4_holder_dtor.h"

/* Free the owned allocation, optionally delete. */
DEFINE_PTR4_HOLDER_DTOR(func_00416660, D_0049AE80)
#pragma pop /* merge_units */
/* merge_units: end func_00416660 */

/* merge_units: begin func_00416740 */
#pragma push /* merge_units */
void* func_00416740(char* self) {
    return self + 4;
}

List* func_00416750(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_00416740 */
