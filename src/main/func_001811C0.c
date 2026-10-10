#pragma cplusplus on
#include "types.h"
struct IntegPG { virtual void v00(); virtual void Gather(void* st); virtual void Integrate(float dt, void* a, int b, int c); };
struct PhysPG { int body; char pad[0xC]; char state[0x20]; int f30; IntegPG* integ; };
extern "C" int D_004EA0C0;
extern "C" void func_00181260(int body, int b, void* st, int c);
extern "C" void Physical_GatherIntegrate(PhysPG* p, void* a, float dt)
{
    if (p->body && p->integ) {
        p->integ->Gather(p->state);
        func_00181260(p->body, D_004EA0C0, p->state, p->f30);
        p->integ->Integrate(dt, a, D_004EA0C0, p->body);
    }
}