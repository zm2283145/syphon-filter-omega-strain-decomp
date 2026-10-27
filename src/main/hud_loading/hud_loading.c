/*
 * main/hud_loading: 4 files, 002720A0-00272170
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002720A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
void cInterface_dtor(void* p, int flag);
}
struct OwnedPtrHolder { void* p; };
extern "C" OwnedPtrHolder* cHudLoading_dtor(OwnedPtrHolder* self, short deleteFlag) {
    if (self) {
        void* p = self->p;
        {
            AllocGuard guard;
            cInterface_dtor(p, -1);
            cMemMan_Deallocate(0, p, "hud_loading.cc", 0x5B);
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002720A0 */

/* merge_units: begin func_00272170 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

/* Clears all 14 slots (handle at 0x00 is left untouched). */
void cHudLoading_Init(SlotTable14* self) {
    self->slots[0] = 0;
    self->slots[1] = 0;
    self->slots[2] = 0;
    self->slots[3] = 0;
    self->slots[4] = 0;
    self->slots[5] = 0;
    self->slots[6] = 0;
    self->slots[7] = 0;
    self->slots[8] = 0;
    self->slots[9] = 0;
    self->slots[10] = 0;
    self->slots[11] = 0;
    self->slots[12] = 0;
    self->slots[13] = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00272170 */

/* merge_units: begin func_002721B0 */
#pragma push /* merge_units */
typedef struct { int* model; } Obj002721B0;
extern int* LoadInterface_charP_cHogFileR(int name);
extern void cInterfaceModel_Activate(int a, int b, int c);
#if 0 /* merge_units */
extern void cHudLoading_Init(Obj002721B0* obj);
#endif /* merge_units */
#define cHudLoading_Init(a0) (cHudLoading_Init((SlotTable14 *)(a0))) /* merge_units */


/* Construct: look up the model by name, activate it and finish setup. */
Obj002721B0* cHudLoading_ctor(Obj002721B0* obj, int unused, int name)
{
    obj->model = LoadInterface_charP_cHogFileR(name);
    cInterfaceModel_Activate(*obj->model, 0, 1);
    cHudLoading_Init(obj);
    return obj;
}
#undef cHudLoading_Init /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002721B0 */

/* merge_units: begin func_00272200 */
#pragma push /* merge_units */
typedef struct { char p[0x20]; int f20; } H272200;
typedef struct { char p[0x19]; unsigned char b19; char p1A[0x5A]; H272200* h; } O272200;
typedef struct { char p[0x280]; int f280; } G272200;
extern O272200* nHud_CreateHudElement(int a, int b);
extern void cInterfaceElement_SetText(O272200* o, void* x);
extern void cTextArea_SetColor(H272200* h, void* c);
extern G272200* GetMachine(void);
extern char D_004A8DA0[];
O272200* CreateTextElement(int a, int b, void* x)
{
    O272200* o = nHud_CreateHudElement(a, b);
    if (o && x && o->h) {
        cInterfaceElement_SetText(o, x);
        o->b19 = 0;
        cTextArea_SetColor(o->h, D_004A8DA0);
        o->h->f20 = GetMachine()->f280;
    }
    return o;
}
#pragma pop /* merge_units */
/* merge_units: end func_00272200 */
