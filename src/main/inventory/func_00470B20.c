#include "types.h"
extern char* D_005061D0;
static inline short R16_00470B20(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00470B20(void) { unsigned short lo = R16_00470B20(); return lo + ((unsigned short)R16_00470B20() << 16); }
static inline float RF_00470B20(void) { int i = R32_00470B20(); return *(float*)&i; }
static inline char R8_00470B20(void) { return *D_005061D0++; }
typedef struct { void* vtable; char pad[0x20]; short a; char b; char c; char pad28[8]; } M_00470B20;
typedef struct { char pad[0x3528]; void* mgr; } T_00470B20;
extern char D_00587FC0[];
extern char D_004E1AC0[];
extern char D_004DCF10[];
extern void Event_Construct(M_00470B20* m, void* type);
extern void cMessage_dtor(M_00470B20* m, int flags);
extern void ItemInv_Add(void* mgr, int a, int b, int c);
extern void ItemInv_Remove(void* mgr, int a, int b, int c);
static inline void Read_00470B20(M_00470B20* m) { m->a = R16_00470B20(); m->b = R8_00470B20(); m->c = R8_00470B20(); }
void func_00470B20(T_00470B20* t) {
    M_00470B20 m;
    Event_Construct(&m, D_00587FC0);
    m.vtable = D_004E1AC0;
    Read_00470B20(&m);
    if (t) {
        if (m.c) ItemInv_Add(t->mgr, m.a, m.b, 1);
        else ItemInv_Remove(t->mgr, m.a, m.b, 1);
    }
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}