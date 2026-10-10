#include "types.h"

extern void func_001F3280(void);

/* Calls func_001F3280. */
#pragma optimization_level 1
void func_001F3260(void)
{
    func_001F3280();
}
#pragma optimization_level reset
