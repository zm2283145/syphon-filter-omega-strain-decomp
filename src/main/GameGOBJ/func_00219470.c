#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004A4550[];
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void PathObj_Receive();
extern "C" void PathObj_ScriptFilter();
extern "C" void PathObj_Update();
extern "C" void cPathedGOBJ_v06();
extern "C" void cPathedGOBJ_v07();
extern "C" void cPathedGOBJ_v0B();
extern "C" void cPathedGOBJ_v15();
extern "C" void cPathedGOBJ_v16();
extern "C" void cPathedGOBJ_v3D();
extern "C" void GObj_GetID();
extern "C" void func_0012ED00();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_00140E90();
extern "C" void GObj_GetLifeState();
extern "C" void func_00148870();
extern "C" void Object_GetEye();
extern "C" void func_00153860();
extern "C" void func_0015BFB0();
extern "C" void func_0015BFC0();
extern "C" void func_0015BFD0();
extern "C" void func_0015BFE0();
extern "C" void func_0015BFF0();
extern "C" void func_0015C000();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C0A0();
extern "C" void cGameGOBJ_GetBounds();
extern "C" void func_002152D0();
extern "C" void func_00216C50();
extern "C" void cGameGOBJ_Draw();
extern "C" void GObj_Tick();
extern "C" void cGameGOBJ_Disable();
extern "C" void cGameGOBJ_Enable();
extern "C" void func_0021BD70();
extern "C" void func_0021BD80();
extern "C" void cGameGOBJ_GetModelCol();
extern "C" void func_0021BE50();
extern "C" void GObj_GetWorldMatrix();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void Node_GetComponentMatrix();
extern "C" void PathObj_GetPosition();
extern "C" void Node_GetLightRefPoint();
extern "C" void func_003CD4A0();
extern "C" void Node_GetWorldMatrix();
extern "C" void func_003CD7A0();
extern "C" void func_003CD920();
extern "C" void func_003CDA60();
extern "C" void func_003CDBE0();
extern "C" void func_003CDC20();
extern "C" void func_003CDD40();
extern "C" void func_003CDD80();
extern "C" void func_003CDDC0();
extern "C" void Player_GetActiveWeapon();
extern "C" void func_003CE9E0();
extern "C" void func_003CE9F0();
extern "C" void func_003CEA00();
extern void * const D_004DB280[];
extern unsigned char D_005721C8;
void Mem_Free(int heap, void* p, char* file, int line);
void cGameGOBJ_dtor(void* p, int flag);
void func_001810D0(void* p, int flag);
int func_00211DA0(void);
void func_00219730(void* p, int flag);
void func_0021C090(void* p, int flag);
void func_002EC2A8(int a);
void FileMan_Release(void* p, int flag);
void operator_delete(void* p);
}
struct E_00219470 { char pad[0x48]; char m48[0xE4 - 0x48]; char mE4[4]; };
struct D_00219470s { char pad[0xC]; unsigned char c; };
struct S_00219470 { void* vt; char pad4[0x90]; char m94[0x10]; char mA4[0x10]; char mB4[0x1C]; D_00219470s* pD0; char padd4[0x10]; E_00219470* pE4; };
static inline void Free_00219470(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004A4550, line); }
static inline void M3_0021C090(void* m) { if (m) { if (m) { if (m) func_0021C090(m, 0); } } }
static inline void M3_001810D0(void* m) { if (m) { if (m) { if (m) func_001810D0(m, 0); } } }
extern "C" S_00219470* cPathedGOBJ_dtor(S_00219470* self, short flag)
{
    if (self) {
        void* m;
        E_00219470* e;
        D_00219470s* d;
        self->vt = ((char*)D_004DB280);
        e = self->pE4;
        if (e) {
            AllocGuard g;
            if (e) {
                FileMan_Release(e->mE4, -1);
                FileMan_Release(e->m48, -1);
            }
            Mem_Free(0, e, D_004A4550, 0x266);
        }
        if (D_005721C8) {
            d = self->pD0;
            if (d) {
                if (d->c) func_002EC2A8(func_00211DA0());
                else Free_00219470(d, 0xB83);
                self->pD0 = 0;
            }
        } else {
            d = self->pD0;
            if (d) {
                Free_00219470(d, 0x270);
                self->pD0 = 0;
            }
        }
        m = self->mB4; if (m) func_00219730(m, -1);
        M3_0021C090(self->mA4);
        M3_001810D0(self->m94);
        cGameGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DB280[72] = { (void*)0x0, (void*)0x0, (void*)cPathedGOBJ_dtor, (void*)PathObj_Receive, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0021BE50, (void*)func_0012ED00, (void*)cPathedGOBJ_v06, (void*)cPathedGOBJ_v07, (void*)func_0021BD70, (void*)func_0021BD80, (void*)func_0012ED50, (void*)cPathedGOBJ_v0B, (void*)PathObj_ScriptFilter, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)PathObj_Update, (void*)GObj_Tick, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cGameGOBJ_Draw, (void*)cPathedGOBJ_v15, (void*)cPathedGOBJ_v16, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)cGameGOBJ_GetBounds, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)cGameGOBJ_GetModelCol, (void*)func_00153860, (void*)Object_GetEye, (void*)func_002152D0, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)func_003CD4A0, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)func_003CD110, (void*)func_003CD090, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)cPathedGOBJ_v3D, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)func_00216C50, (void*)0x0, (void*)0x0, (void*)0x0 };
