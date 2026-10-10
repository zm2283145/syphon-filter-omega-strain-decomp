#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char data[0x18]; } F1Row32EF;
extern int D_00532BC0;
extern char D_005329F0[];
extern char D_00532A10[];
extern char D_00532A40[];
extern char D_004FFB50[];
extern void* ObjectiveRow_Construct(F1Row32EF* r, int a, int b, int id);
extern void func_00147600(void* registry, void* item);
extern void* Agent_GetSelected(void* list, int index);
extern void Objective_SetMaskBit(void* agent, void* mask, int id);
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
    func_00147600(D_005329F0, ObjectiveRow_Construct(&r, *(int*)p0, *(int*)p1, id));
    if (b) Objective_SetMaskBit(Agent_GetSelected(D_004FFB50, -1), D_00532A10, id);
    if (c) Objective_SetMaskBit(Agent_GetSelected(D_004FFB50, -1), D_00532A40, id);
    return 0;
}