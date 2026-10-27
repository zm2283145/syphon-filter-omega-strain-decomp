#include "types.h"
typedef struct { int a, b, c; } D6Scale;
typedef struct { int unk0; unsigned int count; D6Scale* data; } D6Scales;
extern void std_vector_imp_cBoneScale_insert(D6Scales* s, D6Scale* at, unsigned int n, int v);
extern void std_vector_imp_cBoneScale_erase(D6Scales* s, D6Scale* from, D6Scale* to, int v);
#pragma opt_common_subs off
void std_vector_imp_cBoneScale_resize(D6Scales* s, unsigned int n, int v)
{
    unsigned int c = s->count;
    D6Scale* d;
    if (c < n) {
        std_vector_imp_cBoneScale_insert(s, &s->data[s->count], n - c, v);
    } else if (n < c) {
        d = s->data;
        std_vector_imp_cBoneScale_erase(s, &d[n], &d[s->count], v);
    }
}
#pragma opt_common_subs reset