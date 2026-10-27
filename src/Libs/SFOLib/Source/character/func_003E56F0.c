#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
class O3E56F0 { public: virtual void Destroy(int flags); };
extern "C" O3E56F0* D_0055A228;
extern "C" void cCharActionMsg_DestinationParams_ClearPrevMsg(void)
{
    O3E56F0* p = D_0055A228;
    if (p) {
        {
            AllocGuard g;
            p->Destroy(-1);
            cMemMan_Deallocate(0, p, "character.cc", 0x37B);
        }
        D_0055A228 = 0;
    }
}