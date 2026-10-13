#include "types.h"
extern int D_0048A038;
extern void func_001667C0(void);
extern int AddIntcHandler(int id, void (*fn)(void), int arg);
extern void Alloc_Unlock(int id);
/* Register handler 2 and start it. */
void func_00166650(void)
{
    D_0048A038 = AddIntcHandler(2, func_001667C0, 0);
    Alloc_Unlock(2);
}
