#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int cGOBJ_dtor(char **, int);                              
int func_00238850(char * , int);                         
int func_00240390(char * , int);                         
int func_00240480(int, int);                            
int operator_delete(char **);                            
extern void Actor_ApplyContactDamage();
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
extern void func_0015C000();
extern void func_0015C010();
extern void func_0015C020();
extern void func_0015C030();
extern void func_0015C040();
extern void func_0015C050();
extern void func_0015C080();
extern void func_0015C0A0();
extern void func_0023D1D0();
extern void func_0023D290();
extern void func_0023D6D0();
extern void func_0023DDA0();
extern void func_0023E5D0();
extern void func_0023E720();
extern void func_0023E790();
extern void func_0023E820();
extern void func_0023E890();
extern void func_0023E9B0();
extern void func_0023EA10();
extern void func_0023EA50();
extern void func_0023EE90();
extern void func_0023FCD0();
extern void func_0023FCE0();
extern void func_0023FCF0();
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
extern void Object_Deactivate();
extern void func_003CE7D0();
extern void func_003CE810();
extern void func_003CE9D0();
extern void func_003CE9E0();
extern void func_003CE9F0();
extern void func_003CEA00();
extern void * const D_004DC190[];

char **func_00238780(char **arg0, long long arg1) {
    int temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_a0 = (int)((char *)arg0 + 0xC4);
        *arg0 = &(*(char*)D_004DC190);
        if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
            func_00240480(temp_a0, 0);
        }
        temp_a0_2 = (char *)arg0 + 0xAC;
        if ((temp_a0_2 != NULL) && (temp_a0_2 != NULL) && (temp_a0_2 != NULL)) {
            func_00240390(temp_a0_2, 0);
        }
        temp_a0_3 = (char *)arg0 + 0x9C;
        if (temp_a0_3 != NULL) {
            func_00238850(temp_a0_3, -1);
        }
        cGOBJ_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DC190[80] = { (void*)0x0, (void*)0x0, (void*)func_00238780, (void*)func_0023E890, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0023FCF0, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)func_0023EA10, (void*)func_0023E9B0, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_003CE9D0, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0023FCE0, (void*)func_0023FCD0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)func_003CDE00, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)func_0014D340, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)func_003CD260, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice, (void*)func_0023EA50, (void*)func_0023E820, (void*)func_0023E790, (void*)func_0023E720, (void*)func_0023DDA0, (void*)func_0023EE90, (void*)func_0023E5D0, (void*)func_0023D290, (void*)func_0023D6D0, (void*)func_0023D1D0, (void*)0x0, (void*)0x0 };
