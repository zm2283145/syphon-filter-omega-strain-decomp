#include "types.h"
extern void* D_0048C160[];
extern char D_004FFB50[];
extern void* Agent_GetSelected(void* list, int idx);
extern __int128 func_003FDA40(void* p);
extern int AgentData_IsLevelDone(void* agent, __int128 v);
extern void* Gui_GetScreenStack(void);
extern void func_0041E0F0(void* self, void* mgr, int a, int b, int c);
extern void func_003569F0(void* self, char* s, int a, int idx, int b, int c);
void func_0034F940(void* self, int idx)
{
    void* p = idx <= 16 ? D_0048C160[idx] : 0;
    if (p) {
        void* ag = Agent_GetSelected(D_004FFB50, -1);
        if (AgentData_IsLevelDone(ag, func_003FDA40(p))) {
            func_0041E0F0(self, Gui_GetScreenStack(), 0x10, 1, 0);
            func_003569F0(self, "CSUBMENU", 6, idx, 0, 0);
            return;
        }
    }
    func_0041E0F0(self, Gui_GetScreenStack(), 0x10, 4, 0);
}