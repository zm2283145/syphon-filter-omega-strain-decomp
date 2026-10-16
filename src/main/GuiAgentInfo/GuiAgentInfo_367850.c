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
extern void func_001AEF70(E3678* e, int a);
void func_00367860(V3678* v)
{
    E3678* b = v->data;
    E3678* e = b + v->count;
    while (b < e) {
        e--;
        func_001AEF70(e, -1);
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
char D_004DF530[];
char D_004BBB00[];
void GuiWidget_ctor(S364590* self);
void* Mem_Alloc(int pool, int size, char* file, int line);
}
#pragma opt_propagation off
extern "C" S364590* func_003678E0(void) {
    S364590* p;
    {
        AllocGuard guard;
        p = (S364590*)Mem_Alloc(0, 0x4F0, D_004BBB00, 0x2A);
    }
    if (p) {
        V3 t;
        float z;
        __int128 q;
        V3* d;
        GuiWidget_ctor(p);
        p->vtable = D_004DF530;
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

DEFINE_GUARDED_NEW_CTOR(func_003679D0, 0x124, D_004BBB00, GuiAgentInfo_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_003679D0 */

/* merge_units: begin func_00367A80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiObjectives_GetClassName();
extern "C" void func_00367AF0();
extern "C" void GuiObjectives_HandleEvent();
extern "C" void GuiObjectives_HandleInput();
extern "C" void GuiObjectives_Update();
extern "C" void GuiObjectives_Wake();
extern "C" void GuiObjectives_Init();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Draw();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DF5C0[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00367A80(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DF5C0);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DF5C0[24] = { (void*)0x0, (void*)0x0, (void*)func_00367A80, (void*)GuiObjectives_Init, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)GuiObjectives_Wake, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiObjectives_HandleInput, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiObjectives_Update, (void*)GuiObjectives_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiObjectives_GetClassName, (void*)func_00367AF0, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_00367A80 */
