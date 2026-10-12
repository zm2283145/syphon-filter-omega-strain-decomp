#include "types.h"
#pragma opt_common_subs off
typedef struct { int top; int words[1]; } C3PSet19F;
typedef struct {
    char pad0[0x320C];
    C3PSet19F set;
} C3Ag19F;
extern void Actor_ShiftPriorityHistory(void* a, void* b);
extern void func_0019F7E0(void* a);
extern void Actor_ShiftBitsHistory(void* a, void* b);
extern void Actor_ReactToActionChanges(C3Ag19F* p);
extern void func_00189590(C3Ag19F* p, int idx);
extern void Actor_UpdateJumpApex(C3Ag19F* p, float dt);
static const unsigned int dat_0049D5E0[2] = { 0x15111005, 0x1F };
static inline int C3PTest19F(C3PSet19F* s, int n)
{
    return (*(int*)((char*)s + (n / 32) * 4 + 4) >> (n & 31)) & 1;
}
void Actor_UpdateAirState(C3Ag19F* p, float dt)
{
    int cur;
    int i;
    Actor_ShiftPriorityHistory((char*)p + 0x3234, (char*)p + 0x3220);
    Actor_ShiftPriorityHistory((char*)p + 0x3220, (char*)p + 0x320C);
    func_0019F7E0((char*)p + 0x320C);
    Actor_ShiftBitsHistory((char*)p + 0x3258, (char*)p + 0x3250);
    Actor_ShiftBitsHistory((char*)p + 0x3250, (char*)p + 0x3248);
    Actor_ReactToActionChanges(p);
    cur = p->set.top;
    for (i = 0; i < 5; i++) {
        int idx = ((signed char*)dat_0049D5E0)[i];
        if (idx != cur && C3PTest19F(&p->set, idx)) {
            func_00189590(p, idx);
        }
    }
    Actor_UpdateJumpApex(p, dt);
}