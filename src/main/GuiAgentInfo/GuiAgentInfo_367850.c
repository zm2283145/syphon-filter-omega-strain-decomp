/*
 * main/GuiAgentInfo: 5 files, 00367850-00367A80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00367850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00367850(char* self) {
    *(int*)(self + 4) = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00367850 */

/* merge_units: begin func_00367860 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; } E3678;
typedef struct { int unk0; int count; E3678* data; } V3678;
extern void cSkaSliderValue_dtor(E3678* e, int a);
void func_00367860(V3678* v)
{
    E3678* b = v->data;
    E3678* e = b + v->count;
    while (b < e) {
        e--;
        cSkaSliderValue_dtor(e, -1);
    }
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00367860 */

/* merge_units: begin func_003678E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#include "v4_asm_copy.h"
struct V3 { float x, y, z; } __attribute__((aligned(16)));
struct S364590 { void* vtable; char pad4[0x44]; int unk48; char pad4C[0x34]; V3 v80; char pad90[0x4E0 - 0x90]; float f4E0; };
extern "C" {
char GuiAgentDisplay_vtable[];
char D_004BBB00[];
void GuiWidget_ctor(S364590* self);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
}
#pragma opt_propagation off
extern "C" S364590* ConcreteWidgetClassRep_GuiAgentDisplay_Create_void(void) {
    S364590* p;
    {
        AllocGuard guard;
        p = (S364590*)cMemMan_Allocate(0, 0x4F0, D_004BBB00, 0x2A);
    }
    if (p) {
        V3 t;
        float z;
        __int128 q;
        V3* d;
        GuiWidget_ctor(p);
        p->vtable = GuiAgentDisplay_vtable;
        t.x = 0.0f; t.y = 0.0f; t.z = 3.1415927f;
        d = &p->v80;
        q = V4Load(&t);
        asm { mtc1 zero, z }
        V4Store(d, q);
        p->unk48 = 0;
        p->f4E0 = z;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_003678E0 */

/* merge_units: begin func_003679D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

DEFINE_GUARDED_NEW_CTOR(GuiAgentInfo_Create, 0x124, D_004BBB00, GuiAgentInfo_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_003679D0 */

/* merge_units: begin func_00367A80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiObjectives_GetClassName();
extern "C" void GuiObjectives_IsClass();
extern "C" void GuiObjectives_onMessage();
extern "C" void GuiObjectives_onInput();
extern "C" void GuiObjectives_onAdvanceTime();
extern "C" void GuiObjectives_onWake();
extern "C" void GuiObjectives_onAdd();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DF5C0[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiEndGameObjectives_dtor_void(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DF5C0);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DF5C0[24] = { (void*)0x0, (void*)0x0, (void*)GuiEndGameObjectives_dtor_void, (void*)GuiObjectives_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiObjectives_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiObjectives_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiObjectives_onAdvanceTime, (void*)GuiObjectives_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiObjectives_GetClassName, (void*)GuiObjectives_IsClass, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_00367A80 */
