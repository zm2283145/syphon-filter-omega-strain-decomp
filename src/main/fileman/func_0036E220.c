#include "types.h"
#pragma cplusplus on
#pragma exceptions off
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004BBF90[];
void func_00369700(void* p, int n);
void operator_delete(void* p);
}
typedef struct { int flags; char pad4[0x94]; void* p98; } F8Obj_36E;
extern "C" F8Obj_36E* func_0036E220(F8Obj_36E* o, short del)
{
    if (o) {
        if (o->flags & 0x10) {
            void* p = o->p98;
            AllocGuard g;
            func_00369700(p, -1);
            Mem_Free(0, p, D_004BBF90, 0x4C);
        }
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
