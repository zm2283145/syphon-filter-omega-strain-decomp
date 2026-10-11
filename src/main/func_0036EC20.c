#include "types.h"
#include "q4_asm_copy.h"
typedef struct { __int128 q[4]; } M36EC20;
typedef struct { int p; } It36EC20;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0xF]; M36EC20 m60; char padA0[4]; int lA4[3]; } S36EC20;
extern void func_001CF100(It36EC20* it, void* c);
extern void func_001CF0E0(It36EC20* it, void* c);
extern int func_001CEF10(It36EC20* a, It36EC20* b);
extern void** func_001CF0D0(It36EC20* it);
extern void func_001CEF50(void* p);
extern void func_001CEF30(It36EC20* it);

#pragma opt_rotateloops off

void func_0036EC20(S36EC20* o, M36EC20* src)
{
    It36EC20 b;
    It36EC20 e;
    M36EC20* d = &o->m60;
    Q4Copy(d, src);
    if (!o->a50) {
        It36EC20* pe;
        o->a50 = 1;
        func_001CF100(&b, o->lA4);
        func_001CF0E0(&e, o->lA4);
        pe = &e;
        while (func_001CEF10(&b, pe)) {
            func_001CEF50(*func_001CF0D0(&b));
            func_001CEF30(&b);
        }
    }
}
#pragma opt_rotateloops reset
#pragma peephole reset