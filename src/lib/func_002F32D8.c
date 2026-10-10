#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern void func_002F3450(void);
extern void func_002FB3C0(int* handle);

/* If the handle is non-zero, runs func_002F3450 and then releases it via func_002FB3C0(&handle). */
void func_002F32D8(int handle)
{
    int local = handle;
    if (handle != 0) {
        func_002F3450();
        func_002FB3C0(&local);
    }
}
