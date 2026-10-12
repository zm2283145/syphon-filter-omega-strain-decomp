#pragma cplusplus on
#include "types.h"
extern "C" { extern unsigned char D_00533880; extern int D_00533888; int Alloc_Lock(int); int Alloc_Unlock(int); }
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
struct VC003C99B0 { virtual int v0(...); };
extern "C" {
int Mem_Free(...);
int func_003C9B20(...);
int func_003C9B30(...);
char *func_003C9B40(...);
int func_003C9FE0(...);
extern char D_004BD118;
extern char D_005435C0;
extern char D_005435C4;
}
typedef struct { int first; void **second; } Pr3C;
#pragma push
#pragma inline_depth(10)
#pragma opt_common_subs off

typedef struct { int r; char *n; int ret[2]; } SL3C;
static inline int ite0(SL3C *s) { func_003C9B20(&s->r, func_003C9B30(&D_005435C0)); return s->r; }
static inline void er1(char *n);
static inline void er0(SL3C *s, char *n) { s->n = n; func_003C9FE0(s->ret, &D_005435C0, &s->n); }
extern "C" int func_003C99B0(int *arg0) {
    char *var_s0;
    char *temp_a0;
    void **temp_s1;
    Pr3C *pr;
    SL3C sl;

    var_s0 = (char *)(F_(func_003C9B40(&D_005435C4), 0x4, int));
    while (var_s0 != (char *)ite0(&sl)) {
        temp_a0 = (char *)(F_(var_s0, 0xC, int));
        if ((temp_a0 != NULL) && (*(int *)F_(temp_a0, 0x4, int) == *arg0)) {
            pr = (Pr3C *)(var_s0 + 8);
            if (temp_a0 != NULL) {
                F_(temp_a0, 0x8, int) = 0;
                temp_s1 = pr->second;
                if (D_00533880 != 0) Alloc_Lock(9); D_00533888 += 1; ((VC003C99B0 *)(temp_s1))->v0(-1); Mem_Free(0, temp_s1, &D_004BD118, 0xCF); if (D_00533880 != 0) Alloc_Unlock(9); D_00533888 -= 1;
            }
            er0(&sl, var_s0);
            return 1;
        }
        var_s0 = (char *)(F_(var_s0, 0x4, int));
    }
    return 0;
}
#pragma pop