#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; } Obj003D8EF0;
extern void func_003D8F40(Obj003D8EF0* obj, int* src, unsigned char flag);
extern void func_001396D0(Obj003D8EF0* obj, int value);
/* Construct from src and flag; returns obj. */
Obj003D8EF0* func_003D8EF0(Obj003D8EF0* obj, int* src, unsigned char flag)
{
    func_003D8F40(obj, src, flag);
    func_001396D0(obj, *src);
    obj->flag = flag;
    return obj;
}
