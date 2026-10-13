/*
 * main/MoviePlayer: 2 files, 003F8840-003F8D20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F8840 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_003F8840 */

/* merge_units: begin func_003F8D20 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004BE1E0[];
void* Mem_Alloc(int heap, int size, char* file, int line);
}
static inline char* New_003F8D20(int size, int line) { AllocGuard g; return (char*)Mem_Alloc(1, size, D_004BE1E0, line); }
struct E_003F8D20 { char* al; char* raw; };
struct S_003F8D20 { E_003F8D20 e[10]; };
extern "C" void func_003F8D20(S_003F8D20* self)
{
    self->e[0].raw = New_003F8D20(0x32A040, 0x51);
    self->e[0].al = (char*)(((int)self->e[0].raw + 0x3F) & ~0x3F);
    self->e[1].raw = New_003F8D20(0x99CC0, 0x55);
    self->e[1].al = (char*)(((int)self->e[1].raw + 0x3F) & ~0x3F);
    self->e[2].raw = New_003F8D20(0x1050, 0x59);
    self->e[2].al = (char*)(((int)self->e[2].raw + 0x3F) & ~0x3F);
    self->e[3].raw = New_003F8D20(0x1CA240, 0x5E);
    self->e[3].al = (char*)(((int)self->e[3].raw + 0x3F) & ~0x3F);
    self->e[4].raw = New_003F8D20(0xC040, 0x62);
    self->e[4].al = (char*)(((int)self->e[4].raw + 0x3F) & ~0x3F);
    self->e[5].raw = New_003F8D20(0x840, 0x67);
    self->e[5].al = (char*)(((int)self->e[5].raw + 0x3F) & ~0x3F);
    self->e[6].raw = New_003F8D20(0x5004C, 0x6B);
    self->e[6].al = (char*)(((int)self->e[6].raw + 0x3F) & ~0x3F);
    self->e[7].raw = New_003F8D20(0x80040, 0x6F);
    self->e[7].al = (char*)(((int)self->e[7].raw + 0x3F) & ~0x3F);
    self->e[8].raw = New_003F8D20(0x4040, 0x73);
    self->e[8].al = (char*)(((int)self->e[8].raw + 0x3F) & ~0x3F);
    self->e[9].raw = New_003F8D20(0x3000, 0x77);
    self->e[9].al = self->e[9].raw;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F8D20 */
