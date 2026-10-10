#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; } Obj00290A50;
extern void func_00290B90(Obj00290A50* obj, int* src, unsigned char flag);
extern void func_001396D0(Obj00290A50* obj, int value);
/* Construct from src and flag; returns obj. */
Obj00290A50* func_00290A50(Obj00290A50* obj, int* src, unsigned char flag)
{
    func_00290B90(obj, src, flag);
    func_001396D0(obj, *src);
    obj->flag = flag;
    return obj;
}
