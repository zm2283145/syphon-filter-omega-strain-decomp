#include "types.h"

typedef struct { int priority; int count; int flags; unsigned char attr; } ThreadParams;
extern int D_004EE610;
extern char D_0049C660[];
extern int func_002E9B60(int a);
extern int func_002E9BE8(int* out, int a, int b, int c, int size, ThreadParams* params);
extern int func_002E9CD0(int* out, const char* name, int size);
extern int func_002E9D88(int handle, void* f1, void* f2, void* f3);
extern void func_0016A580(void);
extern void func_0016A550(void);
extern void func_0016A450(void);

/* Initialises the service: creates its worker and handle and installs the callbacks; returns 1 on success. */
unsigned char func_0016A690(int a)
{
    unsigned char result;
    ThreadParams params;
    int handle;
    int worker;
    params.priority = 100;
    result = 0;
    params.flags = 0;
    params.count = 1;
    params.attr = 0x40;
    if (func_002E9B60(a) == 0 &&
        func_002E9BE8(&worker, 0, 1, 1, 0x100, &params) == 0 &&
        func_002E9CD0(&handle, D_0049C660, 0x100) == 0 &&
        func_002E9D88(handle, func_0016A580, func_0016A550, func_0016A450) == 0) {
        result = 1;
        D_004EE610 = handle;
    }
    return result;
}
