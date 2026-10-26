#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern void CleanupPlayerSet(void);
extern void rt_memory_free(int* handle);

/* If the handle is non-zero, runs CleanupPlayerSet and then releases it via rt_memory_free(&handle). */
void DestroyPlayerSet(int handle)
{
    int local = handle;
    if (handle != 0) {
        CleanupPlayerSet();
        rt_memory_free(&local);
    }
}
