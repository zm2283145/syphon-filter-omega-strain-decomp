#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
void Group_Cleanup(void* p, int n);
}
extern "C" void GroupPayload_Destroy(char* p, int pool, int flag, char* file, int line)
{
    AllocGuard g;
    if (flag && p)
        Group_Cleanup(p + 4, -1);
    Mem_Free(pool, p, file, line);
}
