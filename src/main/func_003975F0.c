#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void Group_Cleanup(void* p, int n);
}
extern "C" void opDelete_cSkaPlaybackGroupP_int_bool_charP_etc(char* p, int pool, int flag, char* file, int line)
{
    AllocGuard g;
    if (flag && p)
        Group_Cleanup(p + 4, -1);
    cMemMan_Deallocate(pool, p, file, line);
}
