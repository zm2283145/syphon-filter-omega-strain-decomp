#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct SkelNode395EB0 { char p[0x1D0]; };
struct V395EB0 { unsigned int cap; unsigned int count; SkelNode395EB0* data; };
extern "C" {
extern char D_004BC460[];
extern char D_004BC510[];
void SkelNode_Assign(SkelNode395EB0* d, const SkelNode395EB0* s);
}

extern "C" void func_00395EB0(V395EB0* v, unsigned int n, const SkelNode395EB0* val)
{
    if (n) {
        if (n > 0x34F72) {
            func_00123BE8(D_00489738->stream, D_004BC460);
            func_00121B60();
        }
        SkelNode395EB0** pd = &v->data;
        *pd = (SkelNode395EB0*)TStr_Alloc(n * sizeof(SkelNode395EB0), D_004BC510, 0x5C);
        v->cap = n;
        SkelNode395EB0* p = v->data;
        SkelNode395EB0* e = p + n;
        for (; p < e; p++) {
            if (p) SkelNode_Assign(p, val);
            v->count++;
        }
    }
}

