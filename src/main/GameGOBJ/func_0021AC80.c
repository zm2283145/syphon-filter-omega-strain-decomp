#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
struct VObj_21AC80 { virtual void Destroy(int f); };
struct Obj_21AC80 { void* vt; char pad04[0x60]; VObj_21AC80* obj; char pad68[0xC]; char m74[0x10]; char m84[0x10]; };
extern "C" {
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGameGOBJ_v0B();
extern "C" void cGameGOBJ_v0C();
extern "C" void func_0012ECE0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_00140E90();
extern "C" void func_00141850();
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
extern "C" void func_0015C080();
extern "C" void func_0015C0A0();
extern "C" void cGameGOBJ_GetBounds();
extern "C" void func_002152D0();
extern "C" void func_00216C50();
extern "C" void func_0021A840();
extern "C" void GObj_Tick();
extern "C" void func_0021A920();
extern "C" void cGameGOBJ_Receive();
extern "C" void cGameGOBJ_Disable();
extern "C" void cGameGOBJ_Enable();
extern "C" void func_0021AB00();
extern "C" void func_0021AB60();
extern "C" void func_0021ABC0();
extern "C" void func_0021AC20();
extern "C" void func_0021BD70();
extern "C" void func_0021BD80();
extern "C" void cGameGOBJ_GetModelCol();
extern "C" void func_0021BE50();
extern "C" void func_003CCFF0();
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
extern void * const D_004DB4C0[];
extern char D_004A4550[];
void Mem_Free(int pool, void* p, char* file, int line);
void func_0021BFA0(void* p, int f);
void func_001363C0(void* p, int f);
void cGOBJ_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void L3_21AC80(void* p) { if (p) func_0021BFA0(p, 0); }
static inline void L2_21AC80(void* p) { if (p) L3_21AC80(p); }
static inline void L1_21AC80(void* p) { if (p) L2_21AC80(p); }
extern "C" Obj_21AC80* cGameGOBJ_dtor(Obj_21AC80* l, short flag)
{
    if (l) {
        VObj_21AC80* o;
        l->vt = ((char*)D_004DB4C0);
        o = l->obj;
        if (o) {
            AllocGuard g;
            o->Destroy(-1);
            Mem_Free(0, o, D_004A4550, 0xFE);
        }
        L1_21AC80(l->m84);
        if (l->m74)
            func_001363C0(l->m74, -1);
        cGOBJ_dtor(l, 0);
        if (flag > 0)
            operator_delete(l);
    }
    return l;
}
void * const D_004DB4C0[72] = { (void*)0x0, (void*)0x0, (void*)cGameGOBJ_dtor, (void*)cGameGOBJ_Receive, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0021BE50, (void*)func_0012ED00, (void*)func_0021AB60, (void*)func_0021AB00, (void*)func_0021BD70, (void*)func_0021BD80, (void*)func_0012ED50, (void*)cGameGOBJ_v0B, (void*)cGameGOBJ_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)func_0021A920, (void*)GObj_Tick, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_0021A840, (void*)func_0021AC20, (void*)func_0021ABC0, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)cGameGOBJ_GetBounds, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)cGameGOBJ_GetModelCol, (void*)func_00153860, (void*)Object_GetEye, (void*)func_002152D0, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)func_003CD4A0, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice, (void*)func_00216C50, (void*)0x0, (void*)0x0, (void*)0x0 };
