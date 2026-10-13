#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004A5D88[];
}

struct ObjBase_227450 {
    virtual void Destroy(int flags);
    char pad04[0x28];
    int kind;
};

typedef struct {
    char pad0[0xB0];
    ObjBase_227450* objs[33][32];
    int counts[32];
    int extraCount;
} ObjMan_227450;

static inline void DelObj(ObjBase_227450* o, int line)
{
    AllocGuard g;
    o->Destroy(-1);
    Mem_Free(0, o, D_004A5D88, line);
}

extern "C" void func_00227450(ObjMan_227450* m, ObjBase_227450* o)
{
    int k = o->kind;
    int i;
    for (i = 0; i < m->counts[k]; i++) {
        if (m->objs[k][i] == o) {
            m->counts[k]--;
            for (; i < m->counts[k]; i++) {
                m->objs[k][i] = m->objs[k][i + 1];
            }
            break;
        }
    }
    if (o) {
        DelObj(o, 0x3A8);
    }
}

