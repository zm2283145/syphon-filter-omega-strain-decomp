#include "types.h"
#include "vu0_addeq.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_9300;
typedef struct { char p0[0x40]; V_9300 a; char p50[0x20]; V_9300 b; char p80[0x2F0 - 0x80]; V_9300 c; V_9300 d; } Act_9300;
/* shift both teleport lanes and two positions by dv (VU0 adds) */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void Actor_AddTeleportLanes(Act_9300* act, V_9300* dv)
{
    V_9300 t;
    {
        /* by-value copy of the offset (VCopyF idiom: lq free, sq unfolded) */
        V_9300* td;
        __int128 q;
        asm { .set reorder; lq q, 0(dv) }
        td = &t;
        asm { sq q, 0(td) }
    }
    VU0_ADDEQ3(V_9300, &act->c, &t);
    VU0_ADDEQ3(V_9300, &act->d, &t);
    VU0_ADDEQ1(V_9300, &act->a, dv);
    VU0_ADDEQ1(V_9300, &act->b, dv);
}
#pragma pop
