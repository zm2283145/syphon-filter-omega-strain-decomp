#include "types.h"
typedef struct { char pad[0x2FC]; int effect; char pad300[0x14]; int unk314; } Obj002579E0;
extern void* D_004FFBD0;
extern void func_00170DB0(void* mgr, int effect);
extern void Object_Unregister(int effect);
extern void Object_DeleteLater(int effect, float time);
/* Stop and release the attached effect. */
void func_00256120(Obj002579E0* obj)
{
    if (obj->effect) {
        func_00170DB0(D_004FFBD0, obj->effect);
        Object_Unregister(obj->effect);
        Object_DeleteLater(obj->effect, 0.1f);
        obj->effect = 0;
    }
}
