#include "types.h"
typedef struct { int a, b, c; } V3_4D59F0;
extern char D_00543680[];
extern char D_005436A0[];
extern char D_00543670[];
extern char D_00543690[];
extern char func_00138350[];
extern void __register_global_object(void* obj, void* dtor, void* link);
void func_004D59F0(void)
{
    V3_4D59F0* p;
    p = (V3_4D59F0*)D_00543680; p->a = 0; p->b = 0; p->c = 0;
    __register_global_object(p, func_00138350, D_00543670);
    p = (V3_4D59F0*)D_005436A0; p->a = 0; p->b = 0; p->c = 0;
    __register_global_object(p, func_00138350, D_00543690);
}