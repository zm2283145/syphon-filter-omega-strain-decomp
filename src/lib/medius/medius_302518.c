/*
 * lib/medius: 2 files, 00302518-00302548
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00302518 */
#include "types.h"
typedef struct { char pad[0xC]; int handle; } Obj;
extern int DeleteSema(int h);
/* Returns 2 when o is NULL, else whether DeleteSema(o->handle) returned -1. */
int rt_mutex_platform_destroy(Obj* o)
{
    int ret = 2;
    if (o != 0) {
        ret = DeleteSema(o->handle) == -1;
    }
    return ret;
}
/* merge_units: end func_00302518 */

/* merge_units: begin func_00302548 */
/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

typedef struct { int pad[3]; int sema; } Obj_00302548;
extern int WaitSema(int sema); /* syscall 0x44: WaitSema */

/* Waits on the object's semaphore: returns 2 for NULL, 1 if WaitSema failed (-1), else 0. */
int rt_mutex_platform_lock(Obj_00302548* obj)
{
    int ret = 2;
    if (obj != 0)
        ret = WaitSema(obj->sema) == -1;
    return ret;
}
/* merge_units: end func_00302548 */
