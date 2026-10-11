#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_00330F00(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00330F00(int v) { W16_00330F00((unsigned short)v); W16_00330F00(v >> 16); }
typedef struct { char pad[8]; int v[31]; } S_00330F00;
void func_00330F00(S_00330F00* p) {
    int i;
    for (i = 14; i < 31; i++) {
        W32_00330F00(p->v[i]);
    }
}