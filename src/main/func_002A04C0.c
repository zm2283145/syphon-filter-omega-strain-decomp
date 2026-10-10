#include "types.h"

typedef struct { char pad[0x32]; unsigned char flag; } Hud32;
extern unsigned char D_00532FE8;
extern Hud32* D_004FFC04;
extern char D_004AAE80[];
extern char D_004AAE98[];
extern void func_002CCA20(Hud32* hud, int a1);
extern void* func_00414790(void);
extern void* func_00418A80(void* manager, const char* a, const char* b);
extern void* func_004147A0(void);
extern void func_00414AC0(void* target, void* self, void* handle);

/* Resets HUD state and registers self with a handle created from the two names. */
void func_002A04C0(void* self)
{
    void* handle;
    D_00532FE8 = 0;
    func_002CCA20(D_004FFC04, 1);
    D_004FFC04->flag = 0;
    handle = func_00418A80(func_00414790(), D_004AAE80, D_004AAE98);
    func_00414AC0(func_004147A0(), self, handle);
}
