/*
 * SFOGame/Source/GuiEndGameStatistics: 1 file, 00462FA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00462FA0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int f0; char p4[0xC]; __int128 q10; int f20; int f24; char p28[8]; int f30; int f34; int f38; char p3C[0xC]; char m48[0x9C]; char mE4[0x9C]; int f180; short h184; unsigned char b186; } S462FA0;
typedef struct { char p[0xC]; unsigned char bC; char pD[3]; int f10; char p14[0xC]; S462FA0 s; int f1B0; } T462FA0;
extern void func_00463040(T462FA0* t);
extern void cFileMan_ctor_void(void* s);
static inline void SetH462FA0(int* d, int* p) { int none; *d = *(p ? p : (none = -1, &none)); }
#pragma push

T462FA0* cQuipList_ctor(T462FA0* t)
{
    S462FA0* s;
    func_00463040(t);
    t->bC = 1;
    s = &t->s;
    *(int*)((char*)t + 0x44) = -2;
    *(int*)((char*)t + 0x40) = 0;
    cFileMan_ctor_void(s->m48);
    cFileMan_ctor_void(s->mE4);
    s->f0 = -1;
    s->q10 = -1;
    s->f20 = 0;
    SetH462FA0(&s->f24, 0);
    s->f30 = 0;
    s->f34 = 0;
    s->f38 = 0;
    s->h184 = -1;
    s->f180 = 0;
    s->b186 = 0;
    t->f10 = 0;
    t->f1B0 = 0;
    return t;
}
#pragma pop
static inline void merge_flush_func_00462FA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00462FA0 */
