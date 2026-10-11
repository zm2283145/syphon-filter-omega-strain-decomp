#pragma cplusplus on
#include "types.h"
extern "C" {
extern char D_004DE180[];
void func_002CB160(void* self);
void func_002CC520(void* m, int flags);
void Receiver_Destruct(void* self, int flags);
void operator_delete(void* p);
}
struct ObjC480 { void* vtable; char pad[0x24]; unsigned char active; char pad2[0x2FC - 0x29]; char member[4]; };
extern "C" ObjC480* func_002CC480(ObjC480* self, short deleteFlag)
{
    if (self) {
        void* m;
        self->vtable = D_004DE180;
        if (self->active)
            func_002CB160(self);
        m = self->member;
        if (m)
            func_002CC520(m, 0);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}