#pragma cplusplus on
#include "types.h"
/* lq/sq quad copy written as GCC-style volatile asm; the unused `xx` reproduces retail's dead addiu */
struct V { float x, y, z, w; V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; } } __attribute__((aligned(16)));
struct H0 { V m0; V m1; };
struct H2 { V m0; V m1; };
struct T5 { H0 m0; V m1; H2 m2; };
extern "C" T5* cSkaAnimAnchor_TreeNodeData_tData_ctor(T5* t, const T5* s);
T5* cSkaAnimAnchor_TreeNodeData_tData_ctor(T5* t, const T5* s) {
    *t = *s;
    return t;
}
