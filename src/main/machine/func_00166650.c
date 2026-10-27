#include "types.h"
extern int D_0048A038;
extern void VBLANKInterruptHandler(void);
extern int AddIntcHandler(int id, void (*fn)(void), int arg);
extern void EnableIntc(int id);
/* Register handler 2 and start it. */
void RegisterVBLANKHandler(void)
{
    D_0048A038 = AddIntcHandler(2, VBLANKInterruptHandler, 0);
    EnableIntc(2);
}
