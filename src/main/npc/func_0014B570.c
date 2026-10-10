#pragma cplusplus on
#include "types.h"
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
struct TgtNV { char pad[0xC]; int serial; };
struct HandleNV {
    char pad[0x40];
    TgtNV* obj;
    int serial;
    bool IsValid() { return IsNullNV(obj) || obj->serial == serial; }
    TgtNV* Get() { return IsValid() ? obj : 0; }
};
struct NpcNV {
    char pad[0x44];
    char anim[8];
    int timer;
    char pad2[0x1AC - 0x50];
    HandleNV* target;
};
extern "C" void func_0016E170(void* a, int b, int c);
extern "C" void cNPC_v36(NpcNV* n)
{
    if (n->timer > 20) {
        n->timer = 0;
        if (n->target->Get()) {
            func_0016E170(n->anim, 1, 0);
        } else {
            func_0016E170(n->anim, 0, 0);
        }
    }
}