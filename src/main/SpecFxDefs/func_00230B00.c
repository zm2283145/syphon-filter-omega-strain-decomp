#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_00230B00(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00230B00(int v) { W16_00230B00((unsigned short)v); W16_00230B00(v >> 16); }
static inline void WF_00230B00(float f) { W32_00230B00(*(int*)&f); }
typedef struct { char pad[0x24]; void* obj; float a; float b; } M_00230B00;
extern void func_00282020(void* o);
void cNetSpawnLightMsg_v04(M_00230B00* m) {
    func_00282020(m->obj);
    WF_00230B00(m->a);
    WF_00230B00(m->b);
}