#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { int a; int b; char c; char pad[7]; __int128 q; float f; } XFC30;
#pragma opt_propagation off
XFC30* PlayerInput_BuildFirePayload(XFC30* d, int* pa, int b, char c, __int128* q, float f) {
    d->a = *pa;
    d->b = b;
    d->c = c;
    { typedef char uf_chk_[sizeof(d->q) == 16 ? 1 : -1]; VCopyF(&(d->q), &(*q)); }
    d->f = f;
    return d;
}
#pragma opt_propagation reset
#pragma peephole reset
