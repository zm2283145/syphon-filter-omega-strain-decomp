#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct KV { unsigned int cap; unsigned int count; int* data; };
extern "C" {
extern char D_0049CAA0[];
extern char D_0049CAD8[];
extern char D_0049CAC8[];
void func_00174FF0(KV* a, KV* b);
}

extern "C" void KeyVector_Reserve(KV* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x1800000) {
            func_00123BE8(D_00489738->stream, D_0049CAA0);
            Libc_Abort();
        }
        KV tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (int*)TStr_Alloc(n * 4, D_0049CAD8, 0x5C);
        tmp.cap = n;
        int* d;
        int* s;
        int* e;
        s = v->data;
        e = s + v->count;
        d = tmp.data;
        while (s < e) {
            if (d)
                *d = *s;
            s++;
            d++;
            tmp.count++;
        }
        func_00174FF0(&tmp, v);
        tmp.count = 0;
        int* fp = tmp.data;
        if (fp) {
            if (fp)
                TStr_Free((char*)fp, D_0049CAC8, 0x64);
        }
    }
}

