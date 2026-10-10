#include "types.h"

typedef struct { int unk0; } Guard;
typedef struct { char pad[0x90]; void* resource; } Holder90;
extern char D_0049A890[];
extern void func_00136DA0(Guard* g);
extern void func_00136D40(void* resource, int flags);
extern void Mem_Free(void* a0, void* p, const char* file, int line);
extern void func_0012F530(Guard* g, int flags);

/* Releases the held resource (destroy + free) under a guard and clears the pointer. */
void func_00136CD0(Holder90* self)
{
    void* res = self->resource;
    if (res) {
        Guard g;
        func_00136DA0(&g);
        func_00136D40(res, -1);
        Mem_Free(0, res, D_0049A890, 0xFA);
        func_0012F530(&g, -1);
        self->resource = 0;
    }
}
