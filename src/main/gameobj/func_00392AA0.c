#pragma cplusplus on
#include "types.h"
struct UpdAW { virtual void v00(); virtual void Update(float dt); };
extern "C" void AnimModel_Update(void* m, float dt);
extern "C" void Physical_GatherIntegrate(void* p, void* a, float dt);
extern "C" void ModelCtx_ComputeBounds(void* m);
extern "C" void ModelCtx_ComputeCentroid(void* m);
extern "C" void ActorRender_Update(void* r, float dt);
extern "C" void Actor_BaseWorldUpdate(void* a, float dt);
extern "C" void Actor_WorldUpdate(char* a, float dt)
{
    UpdAW* o;
    AnimModel_Update(a + 0x2EC0, dt);
    Physical_GatherIntegrate(a + 0x2FE0, a, dt);
    o = *(UpdAW**)(a + 0x3024);
    if (o) {
        o->Update(dt);
    }
    if (*(unsigned char*)(a + 0x2E64)) {
        ModelCtx_ComputeBounds(a + 0x2E50);
        ModelCtx_ComputeCentroid(a + 0x2E50);
    }
    ActorRender_Update(a + 0x60, dt);
    Actor_BaseWorldUpdate(a, dt);
}