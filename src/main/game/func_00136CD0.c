#include "types.h"

typedef struct { int unk0; } Guard;
typedef struct { char pad[0x90]; void* resource; } Holder90;
extern char D_0049A890[];
extern void cTimerDisable_ctor(Guard* g);
extern void cArray_cNodePtr_dtor(void* resource, int flags);
extern void Mem_Free(void* a0, void* p, const char* file, int line);
extern void cTimerDisable_dtor(Guard* g, int flags);

/* Releases the held resource (destroy + free) under a guard and clears the pointer. */
void cGameSystem_ClearNodeList(Holder90* self)
{
    void* res = self->resource;
    if (res) {
        Guard g;
        cTimerDisable_ctor(&g);
        cArray_cNodePtr_dtor(res, -1);
        Mem_Free(0, res, D_0049A890, 0xFA);
        cTimerDisable_dtor(&g, -1);
        self->resource = 0;
    }
}
