#include "types.h"
extern unsigned char* D_005061D0;
static inline short R16_20FFD0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_20FFD0(void) { unsigned short lo = R16_20FFD0(); return lo + ((unsigned short)R16_20FFD0() << 16); }
typedef struct { void* vtable; char pad[0x20]; signed char b; } M_20FFD0;
extern char D_004F5410[];
extern char D_004DAE50[];
extern char D_004DCF10[];
extern void Event_Construct(M_20FFD0* m, void* type);
extern void func_00232B50(int b);
extern void cMessage_dtor(M_20FFD0* m, int flags);
void func_0020FFD0(void) {
    M_20FFD0 m;
    Event_Construct(&m, D_004F5410);
    m.vtable = D_004DAE50;
    m.b = R32_20FFD0();
    func_00232B50(m.b);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}
