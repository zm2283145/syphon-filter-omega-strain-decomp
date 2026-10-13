#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
extern "C" {
int Mem_Free(int, int, char *, int);
int cGOBJ_dtor(char *, int);
int func_00135D80(char *, int);
int func_00177B80(char *, int);
int Player_ClearRecentTargets(int *, char *, int *, char **);
int operator_delete(char *);
extern char D_004A4A90;
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGenerator_v01();
extern "C" void cGenerator_v04();
extern "C" void cGenerator_v05();
extern "C" void cGenerator_v06();
extern "C" void cGenerator_v07();
extern "C" void cGenerator_v08();
extern "C" void cGenerator_v09();
extern "C" void cGenerator_v0B();
extern "C" void cGenerator_v0C();
extern "C" void cGenerator_v0E();
extern "C" void cGenerator_v0F();
extern "C" void cGenerator_v10();
extern "C" void cGenerator_v11();
extern "C" void cGenerator_v15();
extern "C" void cGenerator_v16();
extern "C" void cGenerator_v17();
extern "C" void cGenerator_v18();
extern "C" void cGenerator_v3D();
extern "C" void func_0012ECE0();
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
extern "C" void func_0015C0A0();
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
extern "C" void func_003CE9D0();
extern "C" void func_003CEA00();
extern void * const D_004DB680[];
}
static inline char* Identity(char*a){return a;} static inline void clr0(char*a){int r;int f;char*l;l=Identity(a+0xA0);f=F_(a,0xA4,int);Player_ClearRecentTargets(&r,a+0x9C,&f,&l);}
static inline void clr1(char *a) { clr0(a); }
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" char *cGenerator_dtor(char *arg0, long long arg1) {
    int temp_s2;
    char *temp_a0;

    if (arg0 != NULL) {
        F_(arg0, 0x0, char *) = &(*(char*)D_004DB680);
        F_(arg0, 0x78, int) = 0;
        clr0(arg0);
        temp_s2 = F_(arg0, 0x64, int);
        {
            AllocGuard g;
            Mem_Free(0, temp_s2, &D_004A4A90, 0x23C);
        }
        temp_a0 = arg0 + 0x9C;
        if (temp_a0 != NULL) func_00177B80(temp_a0, 0);
        temp_a0 = arg0 + 0x90;
        if (temp_a0 != NULL) func_00177B80(temp_a0, 0);
        temp_a0 = arg0 + 0x74;
        if (temp_a0 != NULL) func_00135D80(temp_a0, -1);
        cGOBJ_dtor(arg0, 0);
        if (((long long)(arg1 << 0x30) >> 0x30) > 0) operator_delete(arg0);
    }
    return arg0;
}
#pragma pop
void * const D_004DB680[68] = { (void*)0x0, (void*)0x0, (void*)cGenerator_dtor, (void*)cGenerator_v01, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)cGenerator_v04, (void*)cGenerator_v05, (void*)cGenerator_v06, (void*)cGenerator_v07, (void*)cGenerator_v08, (void*)cGenerator_v09, (void*)func_0012ED50, (void*)cGenerator_v0B, (void*)cGenerator_v0C, (void*)func_003CEA00, (void*)cGenerator_v0E, (void*)cGenerator_v0F, (void*)cGenerator_v10, (void*)cGenerator_v11, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_003CE9D0, (void*)cGenerator_v15, (void*)cGenerator_v16, (void*)cGenerator_v17, (void*)cGenerator_v18, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)func_0014D340, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)PathObj_GetPosition, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)cGenerator_v3D, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice };
