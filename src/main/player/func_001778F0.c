#include "types.h"
extern char D_004D9CF0[];
extern void func_00177A30(void* p, int f);
extern void func_001779E0(void* p, int f);
extern void func_00177990(void* p, int f);
extern void cGameGobjController_dtor(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_78F0;
S_78F0* cPlayer_dtor(S_78F0* self, short flag)
{
    if (self) {
        self->vt = D_004D9CF0;
        if ((char*)self + 0x50) {
            func_00177A30((char*)self + 0x13C, -1);
            func_001779E0((char*)self + 0x98, -1);
            func_00177990((char*)self + 0x80, -1);
        }
        cGameGobjController_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}