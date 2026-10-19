#include "types.h"
typedef struct { char pad[0x4C]; unsigned char state; char pad4D[8]; char name[1]; } Obj00441C20;
extern char g_Game[];
extern char* Agent_GetSelected(void* mgr, int index);
extern void String_Copy(char* dst, const char* src);
extern void AgentData_SetName(void* agent, int value);
extern void GuiSaveAgentWidget_HandleEvent(Obj00441C20* obj);
/* Enter state 3 with the selected agent's name. */
void SaveAgentWidget_Rename(Obj00441C20* obj, int value)
{
    obj->state = 3;
    String_Copy(obj->name, Agent_GetSelected(g_Game, -1) + 0x8AC);
    AgentData_SetName(Agent_GetSelected(g_Game, -1), value);
    GuiSaveAgentWidget_HandleEvent(obj);
}
