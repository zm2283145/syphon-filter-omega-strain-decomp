#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { int unk0; int unk4; int unk8; int unkC; } Obj;

/* Resets an object; returns 2 if it is NULL, 0 otherwise. */
int func_002F5398(Obj* obj)
{
    int ret = 2;
    if (obj != 0) {
        obj->unk0 = 0;
        obj->unk4 = 0;
        obj->unkC = 0;
        ret = 0;
    }
    return ret;
}
