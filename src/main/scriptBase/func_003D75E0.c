#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BD3B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
int strlen(const char* s);
void* memcpy(void* d, const void* s, int n);
}
static inline void* SD_Alloc(int n)
{
    AllocGuard g;
    return Mem_Alloc(0, n, D_004BD3B0, 0x130);
}
extern "C" char* Str_Duplicate(char* s)
{
    char* p = 0;
    if (s) {
        int len = strlen(s) + 1;
        int n = (len + 31) / 32 * 32;
        p = (char*)SD_Alloc(n);
        memcpy(p, s, n);
    }
    return p;
}
