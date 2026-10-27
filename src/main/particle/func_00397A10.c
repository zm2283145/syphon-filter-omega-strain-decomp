#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void cParticleSpray_Definition();
extern "C" void cParticleSpray_GetRenderMatrix();
extern "C" void cParticleBase_Done();
extern "C" void cParticleSpray_Render();
extern "C" void cParticleSpray_NextFrame();
extern void * const D_004DFA80[];
extern "C" char D_004DFB50[];
extern "C" char D_004DFAD8[];
extern "C" VtableChainObject* cParticleSpray_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFA80);
        if (self) {
            self->vtable = D_004DFB50;
            if (self)
                self->vtable = D_004DFAD8;
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFA80[8] = { (void*)0x0, (void*)0x0, (void*)cParticleSpray_dtor, (void*)cParticleSpray_Render, (void*)cParticleSpray_NextFrame, (void*)cParticleSpray_Definition, (void*)cParticleBase_Done, (void*)cParticleSpray_GetRenderMatrix };
