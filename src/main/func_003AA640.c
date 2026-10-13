#include "types.h"
typedef struct { char pad[0x1D0]; } SkelNode;
typedef struct { int cap; int count; SkelNode* data; } SkelVec;
extern void SkelNode_CopyConstruct(SkelNode* d, SkelNode* s);
extern void func_003BA9A0(SkelNode* p, int f);

SkelNode* func_003AA640(SkelVec* v, SkelNode* first, SkelNode* last)
{
    SkelNode* end;
    int n;
    SkelNode* p;
    if (first == last) return first;
    end = v->data + v->count;
    n = end - last;
    if (n != 0) {
        SkelNode* s;
        SkelNode* d;
        d = first; s = last;
        while (s < end) {
            SkelNode_CopyConstruct(d, s);
            s++; d++;
        }
    }
    p = first + n;
    while (p < end) {
        func_003BA9A0(p, -1);
        p++;
    }
    v->count -= last - first;
    return first;
}
