#include "types.h"
typedef struct { int a, b, c; } D6Scale;
typedef struct { int unk0; unsigned int count; D6Scale* data; } D6Scales;
extern void func_003AAEE0(D6Scales* s, D6Scale* at, unsigned int n, int v);
extern void func_003AAD00(D6Scales* s, D6Scale* from, D6Scale* to, int v);
#pragma opt_common_subs off
void BoneScales_Init(D6Scales* s, unsigned int n, int v)
{
    unsigned int c = s->count;
    D6Scale* d;
    if (c < n) {
        func_003AAEE0(s, &s->data[s->count], n - c, v);
    } else if (n < c) {
        d = s->data;
        func_003AAD00(s, &d[n], &d[s->count], v);
    }
}
#pragma opt_common_subs reset