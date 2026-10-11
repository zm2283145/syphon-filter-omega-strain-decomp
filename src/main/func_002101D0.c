#include "types.h"
extern unsigned char* D_005061D0;
static inline short R16_002101D0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_002101D0(void) { unsigned short lo = R16_002101D0(); return lo + ((unsigned short)R16_002101D0() << 16); }
static inline float RF_002101D0(void) { int i = R32_002101D0(); return *(float*)&i; }
static inline char R8_002101D0(void) { return *D_005061D0++; }
typedef struct { void* vtable; char pad[0x1C]; unsigned char one; char p21[3]; int f; } M_002101D0;
extern char D_004F53F8[];
extern char D_004DAE70[];
extern char D_004DCF10[];
extern void Event_Construct(M_002101D0* m, void* type);
extern void Event_Send(M_002101D0* m, void* target, int flags);
extern void cMessage_dtor(M_002101D0* m, int flags);
void func_002101D0(void* target) {
    M_002101D0 m;
    Event_Construct(&m, D_004F53F8);
    m.vtable = D_004DAE70;
    m.f = R32_002101D0();
    m.one = 1;
    if (target) Event_Send(&m, target, 0);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}