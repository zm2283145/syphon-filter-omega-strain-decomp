#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004A5D88[];
}

struct ObjBase_227C60 {
    virtual void Destroy(int flags);
};

typedef struct {
    char pad0[0xB0];
    ObjBase_227C60* objs[32][32];
    ObjBase_227C60* extra[32];
    int counts[32];
    int extraCount;
} ObjMan_227C60;

static inline void DelObj(ObjBase_227C60* o, int line)
{
    AllocGuard g;
    o->Destroy(-1);
    Mem_Free(0, o, D_004A5D88, line);
}

extern "C" void ObjMan_DeleteAll(ObjMan_227C60* m)
{
    ObjBase_227C60* p;
    int i;
    int j;
    int k;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < m->counts[i]; j++) {
            if (m->objs[i][j]) {
                DelObj(m->objs[i][j], 0x292);
                m->objs[i][j] = 0;
            }
        }
        m->counts[i] = 0;
    }
    for (k = 0; k < m->extraCount; k++) {
        p = m->extra[k];
        if (p) {
            DelObj(p, 0x29C);
            m->extra[k] = 0;
        }
    }
    m->extraCount = 0;
}




