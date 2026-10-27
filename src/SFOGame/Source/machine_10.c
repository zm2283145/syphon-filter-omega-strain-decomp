/*
 * SFOGame/Source/machine: 1 file, 001696D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001696D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x28]; char sub[0x18]; char a44[0x108]; char a14C[0x12D]; char m279[4]; } S_96D0;
extern void cSystem_ScriptGetObjectId();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void cSystemContainer_HandleMessage();
extern void cSystem_getSOBJClassId();
extern void cSystem_ScriptHandleMessage();
extern void * const D_004D97B0[];
void cDME_dtor(void* p, int f);
void String_Dtor_138350(void* p, int f);
void __destroy_array(void* arr, void* dtor, int size, int n);
void cSystemContainer_dtor(S_96D0* p, int f);
void operator_delete(void* p);
S_96D0* cMachine_dtor(S_96D0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004D97B0);
        cDME_dtor(self->m279, -1);
        if (self->sub) {
            __destroy_array(self->a14C, String_Dtor_138350, 0xC, 0x14);
            __destroy_array(self->a44, String_Dtor_138350, 0xC, 0x16);
        }
        cSystemContainer_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D97B0[16] = { (void*)0x0, (void*)0x0, (void*)cMachine_dtor, (void*)cSystemContainer_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)0x0 };
static inline void merge_flush_func_001696D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001696D0 */
