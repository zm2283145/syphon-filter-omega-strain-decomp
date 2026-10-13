#include "types.h"
extern char* func_004294C0(void);
extern char D_004FFB50[];
extern void* Agent_GetSelected(char* name, int index);
extern int D_0052FE80;
extern void* func_00336E80(void* agent, int i);
extern void LobbyArray_Append(void* list, void* item);
int func_002C7FC0(void)
{
    char* owner = func_004294C0();
    void* agent = Agent_GetSelected(D_004FFB50, -1);
    void* list;
    int i;
    if (!owner || !agent)
        return 0;
    list = owner + 0x1C;
    if (!list)
        return 0;
    for (i = 0; i < D_0052FE80; i++)
        LobbyArray_Append(list, func_00336E80(agent, i));
    return 1;
}