#include "types.h"
typedef struct { char pad[0x2FC]; int effect; char pad300[0x14]; int unk314; } Obj002579E0;
extern void* g_HotboxTracker;
extern void cHotboxMan_RemoveHotbox(void* mgr, int effect);
extern void nGobjManager_RemoveGOBJ(int effect);
extern void cSystem_ActualScheduleDelete(int effect, float time);
/* Stop and release the attached effect. */
void cBackpack_FadeOut(Obj002579E0* obj)
{
    obj->unk314 = 0;
    if (obj->effect) {
        cHotboxMan_RemoveHotbox(g_HotboxTracker, obj->effect);
        nGobjManager_RemoveGOBJ(obj->effect);
        cSystem_ActualScheduleDelete(obj->effect, 0.1f);
        obj->effect = 0;
    }
}
