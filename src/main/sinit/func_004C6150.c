#include "types.h"
extern char D_004EE770[];
extern char D_004EE780[];
extern void __register_global_object();
extern void cSubclassId_dtor();
void StaticInit_terrain(void)
{
    *(int*)D_004EE780 = (int)"TERR";
    __register_global_object((int)D_004EE780, (int)cSubclassId_dtor, (int)D_004EE770);
}
