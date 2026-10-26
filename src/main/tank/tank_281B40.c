#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_00281B40(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00281B40(int v) { W16_00281B40((unsigned short)v); W16_00281B40(v >> 16); }
static inline void WF_00281B40(float f) { W32_00281B40(*(int*)&f); }
static inline short R16_00281B40(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00281B40(void) { unsigned short lo = R16_00281B40(); return lo + ((unsigned short)R16_00281B40() << 16); }
static inline float RF_00281B40(void) { int i = R32_00281B40(); return *(float*)&i; }
typedef struct { char pad[0xC]; int id; } O_00281B40;
typedef struct { char pad[0x1C]; int flags; char p20[4]; unsigned char type; char p25[3]; O_00281B40* obj; int owner; } M_00281B40;
extern void cBackpack_Pack(O_00281B40* o);
void cNetBackpackMsg_v04(M_00281B40* m) {
    *D_005061D0++ = m->type;
    *D_005061D0++ = m->owner;
    W32_00281B40(m->obj->id);
    if (m->type == 3 || m->type == 0) cBackpack_Pack(m->obj);
    m->flags = 0x40;
}