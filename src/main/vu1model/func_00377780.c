#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct L377780 { void* light; int x4; };
struct H377780 { char pad[0x10]; int x10; int nIds; int x18; int nLights; char pad20[0x38]; L377780* lights; };
struct M377780 { int loaded; H377780* h; short* ids; };
extern "C" {
extern char D_004BC170[];
extern char D_00535D20[];
extern void* D_00539248;
void LightMgr_Unregister(void* mgr, void* light, void* owner);
void func_003813A0(void* mgr, int id, int f);
void func_00376930(M377780* m);
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void Rel377780(void* p, int line)
{
    AllocGuard g;
    Mem_Free(0, p, D_004BC170, line);
}
extern "C" void Model_Unload(M377780* m)
{
    int i;
    if (!m->loaded)
        return;
    if (!m->h->x18 || !m->h->x10) {
        m->loaded = 0;
        m->h = 0;
        return;
    }
    for (i = 0; i < m->h->nLights; i++)
        LightMgr_Unregister(D_00535D20, m->h->lights[i].light, m);
    {
        int j;
        for (j = 0; j < m->h->nIds; j++)
            func_003813A0(D_00539248, m->ids[j], 1);
    }
    if (m->ids) {
        Rel377780(m->ids, 0x122);
        m->ids = 0;
    }
    func_00376930(m);
    m->loaded = 0;
    m->h = 0;
}