#include "types.h"
extern char D_0049CAC0[];
extern char D_004EE770[];
extern char D_004EE780[];
extern void __register_global_object();
extern void func_00144930();
void func_004C6150(void)
{
    *(int*)D_004EE780 = (int)D_0049CAC0;
    __register_global_object((int)D_004EE780, (int)func_00144930, (int)D_004EE770);
}
