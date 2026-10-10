#include "types.h"
typedef struct { char pad[0xF00]; char sub[1]; } Obj00379B20;
extern void func_0037D9A0(Obj00379B20* obj, int a, int b);
extern void Model_BoundsIntersect(Obj00379B20* obj, void* sub, int a, int b);
/* Initialise base, then the sub-object at 0xF00. */
void func_00379B20(Obj00379B20* obj, int a, int b)
{
    func_0037D9A0(obj, a, b);
    Model_BoundsIntersect(obj, obj->sub, a, b);
}
