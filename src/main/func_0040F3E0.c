#pragma cplusplus on
#include "types.h"
struct WObj {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C();
    virtual void v50(float dt);
    virtual void v54(float dt);
    char pad[0x8];
    int serial;
    char pad10[0x1C];
    bool f2C;
    bool f2D;
    bool f2E;
};
struct WHandle { WObj* obj; int serial; };
struct WNode { char pad[0x10]; WHandle h; };
struct WIt { WNode* n; WIt() {} };
extern "C" {
extern void* g_MotionManager;
void Tree_Begin(WIt* out, void* tree);
void Tree_End(WIt* out, void* tree);
void Tree_Successor(WIt* it);
void World_ClearPending(void* tree);
}
static inline WObj* WHandle_Get(WHandle* h)
{
    bool isnull = !(bool)h->obj;
    return (isnull || h->obj->serial == h->serial) ? h->obj : 0;
}
static inline void WStep(WHandle* h, float dt)
{
    WObj* o = WHandle_Get(h);
    if (o) {
        o->v54(dt);
        bool act = o->f2D && o->f2C && !o->f2E;
        if (act)
            o->v50(dt);
    }
}
extern "C" void World_PhysicsTraversal(float dt)
{
    WIt it;
    WIt end;
    {
        WIt tb;
        Tree_Begin(&tb, g_MotionManager);
        it = tb;
    }
    {
        WIt te;
        Tree_End(&te, g_MotionManager);
        end = te;
    }
    for (; (it.n == end.n) ^ 1; Tree_Successor(&it))
        WStep(&it.n->h, dt);
    World_ClearPending(g_MotionManager);
}
