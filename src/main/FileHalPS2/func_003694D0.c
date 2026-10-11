#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocate the stream buffer (size rounded up to a 2 KB multiple) and start it. */
extern "C" {
extern char D_004BBDD0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
}
struct S3694D0 { char pad[0x2C]; int size; char pad30[0xC]; int cap; unsigned char active; char pad41[0x83]; void* buf; };
extern "C" {
int func_00368F60(S3694D0* o, int a);
int func_003694D0(S3694D0* o);
}
int func_003694D0(S3694D0* o)
{
    void* p;
    int cap;
    if (o->size != 0) {
        o->cap = o->size / 2048 * 2048 + 2048;
        cap = o->cap;
        {
            AllocGuard guard;
            p = Mem_Alloc(0, cap, D_004BBDD0, 0x87);
        }
        o->buf = p;
        o->active = 1;
        return func_00368F60(o, 0);
    }
    return 0;
}

