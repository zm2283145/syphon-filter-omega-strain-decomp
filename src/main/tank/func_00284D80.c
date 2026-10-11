#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_00284D80(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00284D80(int v) { W16_00284D80((unsigned short)v); W16_00284D80(v >> 16); }
static inline void WF_00284D80(float f) { W32_00284D80(*(int*)&f); }
typedef struct { char pad[0x18]; float a[6]; char pad30[0x20]; float b; char pad54[0x18]; int c; } S_00284D80;
void func_00284D80(S_00284D80* p) {
    WF_00284D80(p->a[0]);
    WF_00284D80(p->a[1]);
    WF_00284D80(p->a[2]);
    WF_00284D80(p->a[3]);
    WF_00284D80(p->a[4]);
    WF_00284D80(p->a[5]);
    WF_00284D80(p->b);
    W32_00284D80(p->c);
}