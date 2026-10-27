#include "types.h"
typedef struct { char pad[0x1175C]; char tail[1]; } Obj003D5B90;
extern void __construct_array(void* arr, void (*ctor)(void), void (*dtor)(void), int size, int count);
extern void cShadowMan_tCaster_ctor(void);
extern void cShadowMan_tCaster_dtor(void);
extern void cShadowMan_tReceiver_ctor(void);
extern void cShadowMan_tReceiver_dtor(void);
extern void cShadowMan_tShadow_ctor(void);
extern void cShadowMan_tShadow_dtor(void);
extern void std_list_deleter_int_ctor(void* p);
/* Constructor: build the three member arrays and the trailing member. */
Obj003D5B90* cShadowMan_ctor(Obj003D5B90* obj)
{
    __construct_array(obj->pad + 0x10, cShadowMan_tCaster_ctor, cShadowMan_tCaster_dtor, 0x130, 4);
    __construct_array(obj->pad + 0x4D0, cShadowMan_tReceiver_ctor, cShadowMan_tReceiver_dtor, 0x80, 0x200);
    __construct_array(obj->pad + 0x10540, cShadowMan_tShadow_ctor, cShadowMan_tShadow_dtor, 0xC0, 0x18);
    std_list_deleter_int_ctor(obj->tail);
    return obj;
}
