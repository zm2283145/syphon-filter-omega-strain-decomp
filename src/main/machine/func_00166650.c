#include "types.h"
extern int D_0048A038;
extern void LoadingScreen_VblankHandler(void);
extern int AddIntcHandler(int id, void (*fn)(void), int arg);
extern void Alloc_Unlock(int id);
/* Register handler 2 and start it. */
void LoadingScreen_InstallVblank(void)
{
    D_0048A038 = AddIntcHandler(2, LoadingScreen_VblankHandler, 0);
    Alloc_Unlock(2);
}
