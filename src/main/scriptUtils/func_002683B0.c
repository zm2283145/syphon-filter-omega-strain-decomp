#include "types.h"

extern void* D_004FFC2C;
extern void func_00242FA0(void* mgr, void* target, int id, int a3, int a4, int a5, float delay, float a7);

/* Registers a callout for obj (at +0xC) with id, delay (seconds as int) and extra value. */
void Global_SetCallout(char* obj, int id, int delay, int extra)
{
    func_00242FA0(D_004FFC2C, obj + 0xC, id, 0, 0, extra, (float)delay, 0.0f);
}
