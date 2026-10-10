#pragma cplusplus on
#include "types.h"
struct C5Phys { char pad[0xE8]; unsigned char floor; char pad2[0x17]; char data[1]; };
struct C5Obj13E { char pad[0x3310]; C5Phys* phys; };
static inline bool C5Ready(C5Phys* ph) { return ph != 0 && ph->floor != 0; }extern "C" void* func_0013E020(C5Obj13E* p) {
    C5Phys* ph = p->phys;
    bool ok = C5Ready(ph);
    return ok ? ph->data : 0;
}