#pragma cplusplus on


#include "types.h"
#include "alloc_guard.h"
struct Pt2_TimedEv { int time; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; void* target; };
extern "C" {
extern char D_004BD1A8[];
extern char D_004D9DE0[];
extern char D_004DFE20[];
void* Mem_Alloc(int, int, char*, int);
void EventQueue_Admit(Pt2_TimedEv*);
}
extern "C" void func_003CB230(void* target, float secs) {
    Pt2_TimedEv* e;
    {
        AllocGuard g;
        e = (Pt2_TimedEv*)Mem_Alloc(0, 0x10, D_004BD1A8, 0x6C);
    }
    if (e) {
        e->vt = D_004D9DE0;
        e->b4 = 1;
        e->time = 1000.0f * secs;
        e->b5 = 1;
        e->vt = D_004DFE20;
        e->target = target;
    }
    EventQueue_Admit(e);
}