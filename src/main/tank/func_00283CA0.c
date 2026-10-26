#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_00283CA0(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00283CA0(int v) { W16_00283CA0((unsigned short)v); W16_00283CA0(v >> 16); }
static inline void WF_00283CA0(float f) { W32_00283CA0(*(int*)&f); }
static inline short R16_00283CA0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00283CA0(void) { unsigned short lo = R16_00283CA0(); return lo + ((unsigned short)R16_00283CA0() << 16); }
static inline float RF_00283CA0(void) { int i = R32_00283CA0(); return *(float*)&i; }
typedef struct { char pad[0x24]; unsigned char b; char p25[3]; void* obj; float f; } M_00283CA0;
extern void cNetMsg_PutGOBJ(void* o);
void cNetUpdateTankMsg_v04(M_00283CA0* m) {
    *D_005061D0++ = m->b;
    cNetMsg_PutGOBJ(m->obj);
    WF_00283CA0(m->f);
}