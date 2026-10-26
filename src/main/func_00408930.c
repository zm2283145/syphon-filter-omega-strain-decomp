#include "types.h"
extern void operator_delete(void* p);
extern void __destroy_array(void* arr, void* dtor, int size, int n);
extern void* cMaterialProperties_MatPropInfo_dtor(void* self, short del);
extern void* String_Dtor(void* self, short del);
/* Deleting destructor: destroys 5 members at +0xC, then the base. */
void* cMaterialProperties_dtor(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array((char*)self + 0xC, (void*)cMaterialProperties_MatPropInfo_dtor, 0x38, 5);
        if (self)
            String_Dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
