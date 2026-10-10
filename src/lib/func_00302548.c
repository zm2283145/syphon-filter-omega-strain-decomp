#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

typedef struct { int pad[3]; int sema; } Obj;
extern int func_0010D1A0(int sema); /* syscall 0x44: WaitSema */

/* Waits on the object's semaphore: returns 2 for NULL, 1 if WaitSema failed (-1), else 0. */
int func_00302548(Obj* obj)
{
    int ret = 2;
    if (obj != 0)
        ret = func_0010D1A0(obj->sema) == -1;
    return ret;
}
