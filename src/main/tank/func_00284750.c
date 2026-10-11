#pragma cplusplus on
#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_00284750(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00284750(int v) { W16_00284750((unsigned short)v); W16_00284750(v >> 16); }
static inline void WF_00284750(float f) { W32_00284750(*(int*)&f); }
static inline short R16_00284750(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00284750(void) { unsigned short lo = R16_00284750(); return lo + ((unsigned short)R16_00284750() << 16); }
static inline float RF_00284750(void) { int i = R32_00284750(); return *(float*)&i; }
typedef struct { void* a; void* b; void* c; } P_00284750;
typedef struct { char pad[0x64]; P_00284750* s0; P_00284750* s1; P_00284750* turret; unsigned char b70; } T_00284750;
extern "C" void func_00282020(void* o);
extern "C" void func_00284D80(P_00284750* p);
extern "C" void func_00284750(T_00284750* t) {
    bool n = t->s0 && t->s1;
    bool tu = t->turret != 0;
    *D_005061D0++ = n;
    *D_005061D0++ = tu;
    *D_005061D0++ = t->b70;
    if (n) {
        func_00282020(t->s0->a);
        func_00282020(t->s0->b);
        func_00282020(t->s1->a);
        func_00282020(t->s1->b);
    }
    if (tu) {
        func_00282020(t->turret->a);
        func_00282020(t->turret->b);
        func_00282020(t->turret->c);
        func_00284D80(t->turret);
    }
}