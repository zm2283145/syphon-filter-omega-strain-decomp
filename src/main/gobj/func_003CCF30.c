#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { void Mem_Free(int pool, void* p, char* file, int line); extern char D_004BD228[]; }
class C3CCF30 { public: virtual void Destroy(int flags); };
struct O3CCF30 { char pad[0x58]; C3CCF30* m; };
extern "C" void func_003CCF30(O3CCF30* self)
{
    C3CCF30* m = self->m;
    if (m) {
        {
            AllocGuard g;
            m->Destroy(-1);
            Mem_Free(0, m, D_004BD228, 0x291);
        }
        self->m = 0;
    }
}