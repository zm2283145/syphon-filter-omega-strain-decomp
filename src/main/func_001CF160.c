#include "types.h"
#include "v4_asm_copy.h"
typedef struct { __int128 q; } V_F160;
typedef struct { int p; } It_F160;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0x3F]; V_F160 v90; char padA0[4]; int lA4[3]; } S_F160;
extern void func_001CF100(It_F160* it, void* c);
extern void func_001CF0E0(It_F160* it, void* c);
extern int func_001CEF10(It_F160* a, It_F160* b);
extern void** func_001CF0D0(It_F160* it);
extern void func_001CEF50(void* p);
extern void func_001CEF30(It_F160* it);
#pragma opt_rotateloops off
void Bone_SetLocalTranslation(S_F160* o, V_F160* src)
{
    It_F160 b;
    It_F160 e;
    V4Copy(&o->v90, src);
    if (!o->a50) {
        It_F160* pe;
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