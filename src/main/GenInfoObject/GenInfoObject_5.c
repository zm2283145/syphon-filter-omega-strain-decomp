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
extern "C" { extern char D_004BFDB0[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_0043B910(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004BFDB0, 0x64);
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


void* func_0043B9B0(char* self) {
    return self + 4;
}

void func_0043B9C0(void) {
}

void* func_0043B9D0(void* self) {
    return self;
}

Map* func_0043B9E0(Map* m, unsigned char* cmp) {
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
extern void func_0043B410(R1Tree_0043BA00* t, void* n);
extern void operator_delete(void* p);
R1Tree_0043BA00* func_0043BA00(R1Tree_0043BA00* t, short del)
{
    if (t) {
        if (t->m4)
            func_0043B410(t, t->m4);
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
extern void func_0043BA00(R1Tree_0043BA60* t, short del);
#endif /* merge_units */
#define func_0043BA00(a0, a1) ((void)func_0043BA00((R1Tree_0043BA00 *)(a0), (a1))) /* merge_units */

R1Own_0043BA60* func_0043BA60(R1Own_0043BA60* o, short del)
{
    if (o) {
        R1Tree_0043BA60* t = &o->tree;
        if (t)
            func_0043BA00(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef func_0043BA00 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043BA60 */

/* merge_units: begin func_0043BAC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0043BAC0, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_0043BAC0 */

/* merge_units: begin func_0043BB20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void func_00293950();
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
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void GuiScrollBarWidget_GetClassName();
extern "C" void func_0043BB90();
extern "C" void GuiScrollBarWidget_Wake();
extern "C" void GuiScrollBarWidget_Init();
extern void * const D_004E0F40[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_0043BB20(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0F40);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0F40[24] = { (void*)0x0, (void*)0x0, (void*)func_0043BB20, (void*)GuiScrollBarWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiScrollBarWidget_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)func_00293950, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiScrollBarWidget_GetClassName, (void*)func_0043BB90, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_0043BB20 */
