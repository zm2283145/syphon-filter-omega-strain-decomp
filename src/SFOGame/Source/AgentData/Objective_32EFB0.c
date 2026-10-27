#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char data[0x18]; } F1Row32EF;
extern int D_00532BC0;
extern char D_005329F0[];
extern char D_00532A10[];
extern char D_00532A40[];
extern char g_Game[];
extern void* cAgentData_Record_ctor_charP_int_int(F1Row32EF* r, int a, int b, int id);
extern void cArray_Record_PushBackActual(void* registry, void* item);
extern void* cGameSystem_GetAgentData(void* list, int index);
extern void cAgentData_SetBit(void* agent, void* mask, int id);
int Objective_RegisterMp(ScriptArg* args)
{
    F1Row32EF r;
    int p0[1];
    int p1[1];
    int id;
    int c;
    int b;
    c = args[3].i != 0;
    b = args[2].i != 0;
    
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    id = D_00532BC0++;
    cArray_Record_PushBackActual(D_005329F0, cAgentData_Record_ctor_charP_int_int(&r, *(int*)p0, *(int*)p1, id));
    if (b) cAgentData_SetBit(cGameSystem_GetAgentData(g_Game, -1), D_00532A10, id);
    if (c) cAgentData_SetBit(cGameSystem_GetAgentData(g_Game, -1), D_00532A40, id);
    return 0;
}