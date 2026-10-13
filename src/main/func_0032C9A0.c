#include "types.h"

typedef struct { char pad[0x68]; unsigned int flags; } Mgr;
extern void func_0041EBF0(void* self);
extern Mgr* Gui_GetScreenStack(void);
extern void func_0041E0F0(void* self, Mgr* mgr, int a, int b, int c);

/* Runs base setup, clears manager flag 0x40, then registers self with the manager. */
void func_0032C9A0(void* self)
{
    func_0041EBF0(self);
    Gui_GetScreenStack()->flags &= ~0x40;
    func_0041E0F0(self, Gui_GetScreenStack(), 0x10, 3, 0);
}
