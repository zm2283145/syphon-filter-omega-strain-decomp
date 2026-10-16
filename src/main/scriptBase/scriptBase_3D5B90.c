#include "types.h"
typedef struct { char pad[0x1175C]; char tail[1]; } Obj003D5B90;
extern void __construct_array(void* arr, void (*ctor)(void), void (*dtor)(void), int size, int count);
extern void func_003D5C80(void);
extern void func_003D5A30(void);
extern void func_003D5C50(void);
extern void func_003D5AF0(void);
extern void func_003D5C30(void);
extern void func_003D5B40(void);
extern void func_00383660(void* p);
/* Constructor: build the three member arrays and the trailing member. */
Obj003D5B90* func_003D5B90(Obj003D5B90* obj)
{
    __construct_array(obj->pad + 0x10, func_003D5C80, func_003D5A30, 0x130, 4);
    __construct_array(obj->pad + 0x4D0, func_003D5C50, func_003D5AF0, 0x80, 0x200);
    __construct_array(obj->pad + 0x10540, func_003D5C30, func_003D5B40, 0xC0, 0x18);
    func_00383660(obj->tail);
    return obj;
}
