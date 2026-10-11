#include "types.h"
extern unsigned char* D_005061D0;
extern void AgentData_Reset(void);
extern int func_00334780(void);
extern void func_00281E90(char* s, int n);
extern void awards_SetAwardsAndBonuses(void* p, int a, int b);
extern void func_00335D50(void* p, int a);
static inline short R16_003314F0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_003314F0(void) { unsigned short lo = R16_003314F0(); return lo + ((unsigned short)R16_003314F0() << 16); }
static inline float RF_003314F0(void) { int i = R32_003314F0(); return *(float*)&i; }
typedef struct { int v; char pad[0x1C]; } E_003314F0;
typedef struct {
    char pad0[8]; int v[31]; int w[17]; int count; E_003314F0* e; int pad_d0; float f;
    char padd8[0x8AC - 0xD8]; char s0[16]; char s1[16]; char s2[16];
    char pad8dc[0xB70 - 0x8DC]; unsigned char done; char padb71[3]; unsigned char flag;
} S_003314F0;
#pragma push
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
void func_003314F0(S_003314F0* p, int awards) {
    int i; int j; int k; int n; S_003314F0* q; S_003314F0* r;
    AgentData_Reset();
    p->s0[0] = 0;
    p->s1[0] = 0;
    p->s2[0] = 0;
    n = func_00334780();
    i = 0; if (i < n) { q = p; do { q->w[0] = R32_003314F0(); q = (S_003314F0*)((int*)q + 1); } while (++i < n); }
    for (j = 0, r = p; j < 31; j++) { r->v[0] = R32_003314F0(); r = (S_003314F0*)((int*)r + 1); }
    for (k = 0; k < p->count; k++) { E_003314F0* e = &p->e[k]; e->v = R32_003314F0(); }
    func_00281E90(p->s0, 0x10);
    p->f = RF_003314F0();
    {
        char c = *D_005061D0++;
        p->flag = c != 0;
    }
    if (awards) awards_SetAwardsAndBonuses(p, 0, 0);
    else func_00335D50(p, 0);
    p->done = 1;
}
#pragma pop
