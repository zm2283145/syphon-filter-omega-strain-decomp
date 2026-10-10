#include "types.h"
typedef struct { char pad[0x4C]; unsigned char state; char pad4D[8]; char name[1]; } Obj00441C20;
extern char D_004FFB50[];
extern char* Agent_GetSelected(void* mgr, int index);
extern void String_Copy(char* dst, const char* src);
extern void func_003340B0(void* agent, int value);
extern void func_00441A10(Obj00441C20* obj);
/* Enter state 3 with the selected agent's name. */
void func_00441C20(Obj00441C20* obj, int value)
{
    obj->state = 3;
    String_Copy(obj->name, Agent_GetSelected(D_004FFB50, -1) + 0x8AC);
    func_003340B0(Agent_GetSelected(D_004FFB50, -1), value);
    func_00441A10(obj);
}
