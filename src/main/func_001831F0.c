#include "types.h"
#include "vc_copy.h"
typedef struct { float f; char pad[0xC]; __int128 q; } X31F0;
X31F0* func_001831F0(X31F0* d, X31F0* s) {
    __int128* sp; __int128* dp; __int128 v;
    d->f = s->f;
    sp = &s->q; dp = &d->q;
    v = VLoadF(sp);
    VStoreN(dp, v);
    return d;
}