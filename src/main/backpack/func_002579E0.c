#include "types.h"
typedef struct { char pad[0x2FC]; int effect; char pad300[0x14]; int unk314; } Obj002579E0;
extern void* D_004FFBD0;
extern void func_00170DB0(void* mgr, int effect);
extern void func_0040C9A0(int effect);
extern void func_003CB230(int effect, float time);
/* Stop and release the attached effect. */
void func_002579E0(Obj002579E0* obj)
{
    obj->unk314 = 0;
    if (obj->effect) {
        func_00170DB0(D_004FFBD0, obj->effect);
        func_0040C9A0(obj->effect);
        func_003CB230(obj->effect, 0.1f);
        obj->effect = 0;
    }
}
