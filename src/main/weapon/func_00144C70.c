#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
class O_4C70 { public: int pad0; virtual void Destroy(int f); };
struct S_4C70 { void* snd; char pad[0xD0]; O_4C70* obj; void* node; };
extern "C" {
extern char D_0049B1D0[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_00266470(void* p, int f);
void WeaponInv_StopLoopSound(S_4C70* self, int slot);
void Object_Unregister(void* n);
void func_003CB230(float t, void* n);
void operator_delete(void* p);
}
extern "C" S_4C70* func_00144C70(S_4C70* self, short del)
{
    if (self) {
        void* s = self->snd;
        O_4C70* o;
        if (s) {
            AllocGuard g;
            func_00266470(s, -1);
            Mem_Free(0, s, D_0049B1D0, 0x4CE);
        }
        WeaponInv_StopLoopSound(self, 0);
        WeaponInv_StopLoopSound(self, 1);
        o = self->obj;
        if (o) {
            if (o)
                o->Destroy(1);
        }
        if (self->node) {
            Object_Unregister(self->node);
            func_003CB230(0.1f, self->node);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}