#pragma cplusplus on
#include "types.h"
/* lq/sq quad copy written as GCC-style volatile asm; the unused `xx` reproduces retail's dead addiu */
struct V { float x, y, z, w; V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; } } __attribute__((aligned(16)));
struct G0 { V m0; V m1; };
struct G2 { V m0; V m1; V m2; V m3; };
struct G4 { V m0; V m1; };
struct R { G0 g0; V g1; G2 g2; V g3; G4 g4; unsigned char a, b, c; };
extern "C" R* cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR(R* d, const R* s);
R* cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR(R* d, const R* s) { *d = *s; return d; }
