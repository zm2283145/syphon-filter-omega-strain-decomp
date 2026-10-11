#include "types.h"
extern void* D_0048C160[];
extern char D_004FFB50[];
extern char D_004BAAD0[];
extern void* Agent_GetSelected(void* list, int idx);
extern __int128 func_003FDA40(void* p);
extern int func_00332FE0(void* agent, __int128 v);
extern void* func_004147A0(void);
extern void func_0041E0F0(void* self, void* mgr, int a, int b, int c);
extern void func_003569F0(void* self, char* s, int a, int idx, int b, int c);
void func_0034F940(void* self, int idx)
{
    void* p = idx <= 16 ? D_0048C160[idx] : 0;
    if (p) {
        void* ag = Agent_GetSelected(D_004FFB50, -1);
        if (func_00332FE0(ag, func_003FDA40(p))) {
            func_0041E0F0(self, func_004147A0(), 0x10, 1, 0);
            func_003569F0(self, D_004BAAD0, 6, idx, 0, 0);
            return;
        }
    }
    func_0041E0F0(self, func_004147A0(), 0x10, 4, 0);
}