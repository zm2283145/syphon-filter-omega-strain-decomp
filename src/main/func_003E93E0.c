#include "types.h"
typedef struct { void* vt; char pad[0x5C]; void* m60; } G9B20;
extern char D_004E0240[];
extern void Actor_ApplyContactDamage();
extern void Actor_BasePreLogic();
extern void Actor_BaseWorldUpdate();
extern void Actor_VirtualNop();
extern void Controller_DeathNotice();
extern void Node_ClearFlag2C();
extern void Node_GetFlag2C();
extern void Node_SetFlag2C();
extern void Object_Activate();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void cGOBJ_v0B();
extern void cGOBJ_v0C();
extern void func_0012ECE0();
extern void func_0012ED00();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_0013E060();
extern void func_0013EE60();
extern void func_00140E90();
extern void func_00141850();
extern void func_00148870();
extern void func_0014D340();
extern void func_00153860();
extern void func_0015BFB0();
extern void func_0015BFC0();
extern void func_0015BFD0();
extern void func_0015BFE0();
extern void func_0015BFF0();
extern void func_0015C000();
extern void func_0015C010();
extern void func_0015C020();
extern void func_0015C030();
extern void func_0015C040();
extern void func_0015C050();
extern void func_0015C080();
extern void func_0015C090();
extern void func_0015C0A0();
extern void func_002610F0();
extern void func_003CCFF0();
extern void func_003CD090();
extern void func_003CD110();
extern void func_003CD1C0();
extern void func_003CD260();
extern void func_003CD420();
extern void func_003CD4A0();
extern void func_003CD520();
extern void func_003CD7A0();
extern void func_003CD920();
extern void func_003CDA60();
extern void func_003CDBE0();
extern void func_003CDC20();
extern void func_003CDD40();
extern void func_003CDD80();
extern void func_003CDDC0();
extern void func_003CDE00();
extern void func_003CE790();
extern void func_003CE7D0();
extern void func_003CE810();
extern void func_003CE9E0();
extern void func_003CE9F0();
extern void func_003CEA00();
extern void func_003CEA10();
extern void func_003E97D0();
extern void func_003E9880();
extern void func_003E9940();
void * const D_004E05A0[72] = { (void*)0x0, (void*)0x0, (void*)func_003E9940, (void*)func_003CEA10, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)func_003E9880, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_002610F0, (void*)Object_Activate, (void*)func_003CE790, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)func_003CDE00, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)func_0014D340, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)func_003CD260, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice, (void*)func_003E97D0, (void*)0x0, (void*)0x0, (void*)0x0 };
extern void func_003E8EB0(void* p);
extern void cGOBJ_dtor(void* self, short del);
extern void operator_delete(void* p);
G9B20* func_003E93E0(G9B20* self, short del)
{
    if (self) {
        self->vt = D_004E0240;
        if (self) {
            self->vt = ((char*)D_004E05A0);
            func_003E8EB0(self->m60);
            cGOBJ_dtor(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
