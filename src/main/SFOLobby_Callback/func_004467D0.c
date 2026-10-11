#include "types.h"
typedef struct { char pad[0x18]; int busy; char f1C[0x2C]; char f48[0xF4]; int f13C; } S67D0;
extern int D_00585E60;
extern int func_004505C0(int a, int b, int c, S67D0* s);
extern int func_00121BC8(S67D0* s);
extern void func_00450880(int h, int r, void* p, int q, int t);
void func_004467D0(int a, int b, int c, S67D0* s) {
    if (func_004505C0(a, b, c, s) == 0 && s->busy == 0) {
        int r = func_00121BC8(s);
        func_00450880(D_00585E60, r, s->f1C, s->f13C, (int)s->f48);
    }
}