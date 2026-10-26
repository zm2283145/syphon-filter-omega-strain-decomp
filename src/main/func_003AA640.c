#include "types.h"
typedef struct { char pad[0x1D0]; } SkelNode;
typedef struct { int cap; int count; SkelNode* data; } SkelVec;
extern void SkelNode_CopyConstruct(SkelNode* d, SkelNode* s);
extern void cBone_dtor(SkelNode* p, int f);

SkelNode* std_vector_imp_cBone_erase(SkelVec* v, SkelNode* first, SkelNode* last)
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
        cBone_dtor(p, -1);
        p++;
    }
    v->count -= last - first;
    return first;
}
