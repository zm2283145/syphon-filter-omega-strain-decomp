/*
 * Matched functions (byte-identical with the retail executable).
 * Special effect base-class constructor.
 */

#include "types.h"
#include "specfx_types.h"

/* SpecFx vtable */
extern char D_004E0760[];
/* vtable installed while the base part is built */
extern void func_003EC5E0();
extern void func_003EC6C0();
void * const D_004E0780[8] = { (void*)0x0, (void*)0x0, (void*)0x0, (void*)func_003EC6C0, (void*)func_003EC5E0, (void*)0x0, (void*)0x0, (void*)0x0 };
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
