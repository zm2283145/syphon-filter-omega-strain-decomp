#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 a; V4 b; } B_32D0;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
V4 cBox_Center(B_32D0* b) {
    V4 m; V4 v; V4 r; V4 s;
    V4* ss;
    V4* p;
    V4* q;
    V4* dd;
    V4* mm;
    V4* dm;
    { V4* q; V4* y; y = &b->b; q = &s; asm { lqc2 vf1, 0x0(b); lqc2 vf2, 0x0(y); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(q) } }
    
ss = &s;
dd = &v;
*dd = *ss;
    { __int128 t = 0; float f = 0.5f; 
p = &v;
q = &r;

      asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 t, f; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
    }
    dm = &m; *dm = *q;
    mm = &m; return *mm;
}
#pragma pop