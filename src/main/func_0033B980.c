#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct V33B980 { unsigned int cap; unsigned int count; char* data; };
extern "C" {
extern char D_004B99B8[];
extern char D_004B98B8[];
}
static inline void Cp33B980(char* d, const char* f, const char* l) { memcpy(d, f, l - f); }
/* Byte vector assign(first, last): grows the buffer when needed, then copies. */
extern "C" void std_vector_pod_eRequirementState_do_assign(V33B980* v, char* first, char* last)
{
    unsigned int n = last - first;
    if (v->cap < n) {
        if (n > 0x6000000) {
            Libc_Fprintf(D_00489738->stream, "vector::assign length error\n");
            Libc_Abort();
        }
        v->count = 0;
        if (v->data) {
            if (v->data) TStr_Free(v->data, D_004B99B8, 0x64);
            v->data = 0;
            v->cap = 0;
        }
        { char** pdata = &v->data; *pdata = TStr_Alloc(n, D_004B98B8, 0x5C); }
        v->cap = n;
    }
    Cp33B980(v->data, first, last);
    v->count = n;
}
