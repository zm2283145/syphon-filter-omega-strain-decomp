#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { float x; int pad[3]; __int128 q; } S003C1880;
#pragma push
#pragma opt_propagation off
S003C1880 *func_003C1880(S003C1880 *arg0, S003C1880 *arg1) {
    S003C1880 *s = arg1;
    arg0->x = s->x;
    {
        __int128 *src = &s->q;
        __int128 *dst = &arg0->q;
        { typedef char uf_chk_[sizeof(*dst) == 16 ? 1 : -1]; VCopyF(&(*dst), &(*src)); }
    }
    return arg0;
}
#pragma pop