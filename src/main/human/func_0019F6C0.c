#include "types.h"
#pragma opt_common_subs off
typedef struct { int top; int words[1]; } C3PSet19F;
typedef struct {
    char pad0[0x320C];
    C3PSet19F set;
} C3Ag19F;
extern void func_0019F7F0(void* a, void* b);
extern void func_0019F7E0(void* a);
extern void func_0019F7C0(void* a, void* b);
extern void func_0019F890(C3Ag19F* p);
extern void func_00189590(C3Ag19F* p, int idx);
extern void func_001A2C00(C3Ag19F* p, float dt);
extern signed char D_0049D5E0[];
static inline int C3PTest19F(C3PSet19F* s, int n)
{
    return (*(int*)((char*)s + (n / 32) * 4 + 4) >> (n & 31)) & 1;
}
void func_0019F6C0(C3Ag19F* p, float dt)
{
    int cur;
    int i;
    func_0019F7F0((char*)p + 0x3234, (char*)p + 0x3220);
    func_0019F7F0((char*)p + 0x3220, (char*)p + 0x320C);
    func_0019F7E0((char*)p + 0x320C);
    func_0019F7C0((char*)p + 0x3258, (char*)p + 0x3250);
    func_0019F7C0((char*)p + 0x3250, (char*)p + 0x3248);
    func_0019F890(p);
    cur = p->set.top;
    for (i = 0; i < 5; i++) {
        int idx = D_0049D5E0[i];
        if (idx != cur && C3PTest19F(&p->set, idx)) {
            func_00189590(p, idx);
        }
    }
    func_001A2C00(p, dt);
}