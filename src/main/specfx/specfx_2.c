/*
 * main/specfx: 3 files, 003EC130-003EC220
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC130 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003EC130 { char vpad[4]; virtual int v0(...); };
extern "C" {
int List_Erase(...);              
extern int D_0055C090;
typedef struct { int f0; char p4[4]; int f8; } PS0_003EC130;
}
extern "C" void func_003EC130(int d0, PS0_003EC130 *arg1) {
    int sp3C;
    char * sp38;
    char * temp_a0;
    char * temp_s1;

    if (arg1->f0 > 0) {
        do {
            temp_s1 = (char *)(F_(arg1->f8, 0x8, int));
            temp_a0 = (char *)(F_(temp_s1, 0x0, int));
            if (temp_a0 != NULL) {
                ((VC003EC130 *)(temp_a0))->v0(1);
            }
            F_(temp_s1, 0x0, int) = NULL;
            F_(temp_s1, 0xC, signed char) = 0;
            D_0055C090 -= 1;
            sp38 = (char *)(arg1->f8);
            List_Erase(&sp3C, arg1, &sp38);
        } while (arg1->f0 > 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC130 */

/* merge_units: begin func_003EC1D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Special effect base-class constructor.
 */

#include "specfx_types.h"

/* SpecFx vtable */
extern char D_004E0760[];
/* vtable installed while the base part is built */
extern void Effect_Draw();
extern void Effect_Update();
void * const D_004E0780[8] = { (void*)0x0, (void*)0x0, (void*)0x0, (void*)Effect_Update, (void*)Effect_Draw, (void*)0x0, (void*)0x0, (void*)0x0 };
extern int ScalarCollection_Init(void* list);
extern void SpecFx_Register(SpecFx* fx);

/* Builds the effect and adds it to the global effect list. */
SpecFx* SpecFx_Construct(SpecFx* self) {
    self->vtable = ((char*)D_004E0780);
    ScalarCollection_Init(self->list);
    self->unk0C = 0;
    self->unk10 = 0;
    self->vtable = D_004E0760;
    SpecFx_Register(self);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC1D0 */

/* merge_units: begin func_003EC220 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_003EC220)
#pragma pop /* merge_units */
/* merge_units: end func_003EC220 */
