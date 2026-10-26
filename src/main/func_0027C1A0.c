#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_0027C1A0(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_0027C1A0(int v) { W16_0027C1A0((unsigned short)v); W16_0027C1A0(v >> 16); }
static inline void WF_0027C1A0(float f) { W32_0027C1A0(*(int*)&f); }
typedef struct { char pad[0x24]; int id; char pad28[8]; float x; float y; float z; char pad3c[4]; float w; } M_0027C1A0;
extern void cNetMsg_PutFloat(float f);
void cNetGrenadeMsg_v04(M_0027C1A0* m) {
    W32_0027C1A0(m->id);
    cNetMsg_PutFloat(m->x);
    cNetMsg_PutFloat(m->y);
    cNetMsg_PutFloat(m->z);
    WF_0027C1A0(m->w);
}