#include "types.h"
typedef struct { char pad[0x2FC]; int effect; char pad300[0x14]; int unk314; } Obj002579E0;
extern void* g_HotboxTracker;
extern void Hotbox_RemoveObjectBox(void* mgr, int effect);
extern void Object_Unregister(int effect);
extern void Object_DeleteLater(int effect, float time);
/* Stop and release the attached effect. */
void cBackpack_FadeOut(Obj002579E0* obj)
{
    obj->unk314 = 0;
    if (obj->effect) {
        Hotbox_RemoveObjectBox(g_HotboxTracker, obj->effect);
        Object_Unregister(obj->effect);
        Object_DeleteLater(obj->effect, 0.1f);
        obj->effect = 0;
    }
}
