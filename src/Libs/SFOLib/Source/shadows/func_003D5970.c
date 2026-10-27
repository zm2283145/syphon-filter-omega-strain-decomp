#include "types.h"
extern void std_list_int_dtor(void* self, short del);
extern void cShadowMan_tShadow_dtor(void);
extern void cShadowMan_tReceiver_dtor(void);
extern void cShadowMan_tCaster_dtor(void);
extern void __destroy_array(void* arr, void* dtor, int size, int n);
extern void operator_delete(void* p);
void* cShadowMan_dtor(void* self, short del)
{
    if (self) {
        void* m = (char*)self + 0x1175C;
        if (m)
            std_list_int_dtor(m, 0);
        __destroy_array((char*)self + 0x10540, (void*)cShadowMan_tShadow_dtor, 0xC0, 0x18);
        __destroy_array((char*)self + 0x4D0, (void*)cShadowMan_tReceiver_dtor, 0x80, 0x200);
        __destroy_array((char*)self + 0x10, (void*)cShadowMan_tCaster_dtor, 0x130, 4);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
