#include "types.h"
extern char D_00571CD8[];
extern char D_00571CF0[];
extern void __register_global_object();
extern void func_00412BF0();
void func_004D7020(void)
{
    __register_global_object((int)D_00571CF0, (int)func_00412BF0, (int)D_00571CD8);
}
