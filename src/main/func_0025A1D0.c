#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
struct Vec25A { int cap; int count; int* data; };
struct VObj25A;

struct VObj25A { int head; virtual ~VObj25A(); };
struct GObj25A { void* vt; char pad[0xCC]; VObj25A* fD0; };
extern "C" {
extern Vec25A D_004F8040; extern int D_004F8044; extern int* D_004F8048;
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void AreaEffect_Update();
extern "C" void Controller_DeathNotice();
extern "C" void Node_ClearFlag2C();
extern "C" void Node_GetFlag2C();
extern "C" void Node_SetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGOBJ_v0B();
extern "C" void cGOBJ_v0C();
extern "C" void func_0012ECE0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_0013EE60();
extern "C" void func_00140E90();
extern "C" void func_00141850();
extern "C" void func_00148870();
extern "C" void func_0014D340();
extern "C" void func_00153860();
extern "C" void func_0015BFB0();
extern "C" void func_0015BFC0();
extern "C" void func_0015BFD0();
extern "C" void func_0015BFE0();
extern "C" void func_0015BFF0();
extern "C" void func_0015C000();
extern "C" void func_0015C010();
extern "C" void func_0015C020();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C080();
extern "C" void func_0015C090();
extern "C" void func_0015C0A0();
extern "C" void func_00259490();
extern "C" void func_003CCFF0();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void func_003CD1C0();
extern "C" void PathObj_GetPosition();
extern "C" void func_003CD420();
extern "C" void func_003CD4A0();
extern "C" void func_003CD520();
extern "C" void func_003CD7A0();
extern "C" void func_003CD920();
extern "C" void func_003CDA60();
extern "C" void func_003CDBE0();
extern "C" void func_003CDC20();
extern "C" void func_003CDD40();
extern "C" void func_003CDD80();
extern "C" void func_003CDDC0();
extern "C" void Player_GetActiveWeapon();
extern "C" void Object_Deactivate();
extern "C" void func_003CE7D0();
extern "C" void func_003CE810();
extern "C" void func_003CE9E0();
extern "C" void func_003CE9F0();
extern "C" void func_003CEA00();
extern "C" void Object_HandleMessage();
extern void * const D_004DC5B0[];
void PtrVector_Resize(Vec25A* v, int n, int* fill);
void cGOBJ_dtor(void* self, short flag);
}
#pragma opt_strength_reduction off
extern "C" GObj25A* func_0025A1D0(GObj25A* self, short deleteFlag) {
    if (self) {
        self->vt = ((char*)D_004DC5B0);
        {
            int i;
            int last = D_004F8044 - 1;
            int fill;
            for (i = 0; last >= i; i++) {
                int* e = &D_004F8048[i];
                if (*e == (int)self) {
                    *e = D_004F8048[last];
                    last--;
                }
            }
            fill = 0;
            PtrVector_Resize(&D_004F8040, last + 1, &fill);
        }
        {
            VObj25A* m = self->fD0;
            if (m) delete m;
        }
        cGOBJ_dtor(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#pragma opt_strength_reduction reset
void * const D_004DC5B0[68] = { (void*)0x0, (void*)0x0, (void*)func_0025A1D0, (void*)Object_HandleMessage, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)AreaEffect_Update, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_00259490, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)func_0014D340, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)PathObj_GetPosition, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice };
