#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int heap, void* p, char* file, int line);
}
static inline void Del_003F8840(void* p, int line) { AllocGuard g; Mem_Free(1, p, "MoviePlayer.cc", line); }
struct S_003F8840 { char pad0[4]; void* p4; char pad8[0x4]; void* pC; char pad10[0x4]; void* p14; char pad18[0x4]; void* p1C; char pad20[0x4]; void* p24; char pad28[0x4]; void* p2C; char pad30[0x4]; void* p34; char pad38[0x4]; void* p3C; char pad40[0x4]; void* p44; char pad48[0x4]; void* p4C; };
extern "C" void func_003F8840(S_003F8840* self)
{
    Del_003F8840(self->p4, 0x7E);
    Del_003F8840(self->pC, 0x7F);
    Del_003F8840(self->p14, 0x80);
    Del_003F8840(self->p1C, 0x82);
    Del_003F8840(self->p24, 0x83);
    Del_003F8840(self->p2C, 0x85);
    Del_003F8840(self->p34, 0x86);
    Del_003F8840(self->p3C, 0x87);
    Del_003F8840(self->p44, 0x88);
    Del_003F8840(self->p4C, 0x89);
}