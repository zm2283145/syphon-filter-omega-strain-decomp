#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; } Sub00136540;
typedef struct { void* vtable; Sub00136540 sub; char pad[0x14 - 4 - sizeof(Sub00136540)]; int unk14; } Obj00136540;
extern char D_004D9140[];
extern void func_001365C0(Sub00136540* sub);
extern int func_001361D0(void* src);
extern void func_001365B0(Sub00136540* sub, int value);
/* Constructor. */
Obj00136540* func_00136540(Obj00136540* obj, void* src)
{
    Sub00136540* sub;
    obj->vtable = D_004D9140;
    sub = &obj->sub;
    func_001365C0(sub);
    func_001365B0(sub, func_001361D0(src));
    sub->flag = 1;
    obj->unk14 = 0;
    return obj;
}
