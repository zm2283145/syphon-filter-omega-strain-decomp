#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
char **Mem_Alloc(...);                        
int func_003E8EB0(...);                            
int func_003E9770(...);                              
int func_003E97B0(...);                      
int func_003E99B0(...);                   
char * func_003EF010(...);                           
extern char D_004A7210;
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
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
extern "C" void func_002610F0();
extern "C" void func_003CCFF0();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void func_003CD1C0();
extern "C" void func_003CD260();
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
extern "C" void func_003CDE00();
extern "C" void func_003CE790();
extern "C" void func_003CE7D0();
extern "C" void func_003CE810();
extern "C" void func_003CE9E0();
extern "C" void func_003CE9F0();
extern "C" void func_003CEA00();
extern "C" void func_003CEA10();
extern "C" void func_003E96F0();
extern "C" void func_003E9880();
extern "C" void func_003E9BA0();
void * const D_004E0480[72] = { (void*)0x0, (void*)0x0, (void*)func_003E9BA0, (void*)func_003CEA10, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)func_003E9880, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_002610F0, (void*)Object_Activate, (void*)func_003CE790, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)func_003CDE00, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)func_0014D340, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)func_003CD260, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice, (void*)func_003E96F0, (void*)0x0, (void*)0x0, (void*)0x0 };
extern unsigned char D_00533880;
typedef struct { char p0[92]; int f5C; int f60; int f64; int f68; } PS0_00244380;
}
extern "C" void func_00244380(PS0_00244380 *arg0, int arg1, int arg2) {
    char **temp_a0;
    char **temp_s0;
    char **temp_s0_2;
    int var_s0;
    char * temp_v1;

    if (arg2 == -1) {
        var_s0 = arg0->f5C;
    } else {
        var_s0 = arg0->f60;
    }
    temp_v1 = (char *)(arg0->f68);
    if (temp_v1 == NULL) {
        arg0->f68 = (int)(func_003EF010(var_s0));
        {
            AllocGuard g;
        temp_s0 = Mem_Alloc(0, 0x90, &D_004A7210, 0x3A1);
        }
        if (temp_s0 != NULL) {
            func_003E99B0(temp_s0, arg0->f68, arg1);
            *temp_s0 = &(*(char*)D_004E0480);
        }
        arg0->f64 = (int)(temp_s0);
    } else if (F_(temp_v1, 0x70, int) != var_s0) {
        temp_a0 = (char **)(arg0->f64);
        if (temp_a0 != NULL) {
            func_003E9770(temp_a0);
        } else {
            func_003E8EB0(temp_v1);
        }
        arg0->f68 = (int)(func_003EF010(var_s0));
        {
            AllocGuard g;
        temp_s0_2 = Mem_Alloc(0, 0x90, &D_004A7210, 0x3AD);
        }
        if (temp_s0_2 != NULL) {
            func_003E99B0(temp_s0_2, arg0->f68, arg1);
            *temp_s0_2 = &(*(char*)D_004E0480);
        }
        arg0->f64 = (int)(temp_s0_2);
    }
    func_003E97B0(arg0->f64, arg1, arg2);
}
