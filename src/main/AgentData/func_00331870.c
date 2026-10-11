#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_00331870(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00331870(int v) { W16_00331870((unsigned short)v); W16_00331870(v >> 16); }
static inline void WF_00331870(float f) { W32_00331870(*(int*)&f); }
typedef struct { int v; char pad[0x1C]; } E_00331870;
typedef struct { char pad[8]; int a[31]; int b[17]; int n; E_00331870* e; char padd0[4]; float f; char padd8[0x8AC - 0xD8]; char sub[0xB74 - 0x8AC]; unsigned char c; } S_00331870;
extern int func_00334780(S_00331870* p);
extern void func_00281C80(void* p);
void func_00331870(S_00331870* p) {
    int i;
    int n = func_00334780(p);
    for (i = 0; i < n; i++) W32_00331870(p->b[i]);
    { int j; for (j = 0; j < 31; j++) W32_00331870(p->a[j]); }
    { int j = 0; while (j < p->n) { int k = j++; W32_00331870(p->e[k].v); } }
    func_00281C80(p->sub);
    WF_00331870(p->f);
    *D_005061D0++ = p->c;
}