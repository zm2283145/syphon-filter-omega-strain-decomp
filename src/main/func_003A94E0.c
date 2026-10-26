#pragma cplusplus on
#include "types.h"

struct SNode { unsigned char b[0x1D0]; };
struct SRec { char pad[0x20]; };
struct SHdr { int count; char pad[0xC]; SRec recs[1]; };
struct SArr { int pad0; int count; SNode* data; SNode& At(unsigned int i) { return data[i]; } int Size() const { return count; } };
struct SMtx { float m[16]; };
struct SkelNodesT {
    SHdr* hdr;
    char pad4[0x10];
    unsigned char flag;
    char pad15[3];
    SArr nodes;
};

extern "C" {
void SkelNode_Construct(SNode* n);
void std_vector_imp_cBone_resize(SArr* a, unsigned int n, const SNode& fill);
void cBone_dtor(SNode* n, int flag);
void SkelNode_InitFromRecord(SNode* n, SRec* r);
void SkelNode_AttachParent(SNode* n, SNode* parent);
SArr* cSkeleton_GetBoneList(SkelNodesT* s);
SNode* SkelNodes_GetAt(SArr* a, int i);
int cArray_cBone_Size(SArr* a);
void* Node_GetTransform(SNode* n);
void Mtx_InvertRigid_13ECA0(SMtx* out, void* in);
void SkelNode_SetInverseBind(SNode* n, SMtx* m);
void SkelNodes_ApplyScale(SkelNodesT* s);
void SkelNodes_Construct(SkelNodesT* s);
}

void SkelNodes_Construct(SkelNodesT* s)
{
    SNode tmp;
    SMtx m;
    int i;

    SkelNode_Construct(&tmp);
    std_vector_imp_cBone_resize(&s->nodes, s->hdr->count, tmp);
    cBone_dtor(&tmp, -1);
    for (i = 0; i < s->nodes.count; i++) {
        SkelNode_InitFromRecord(&s->nodes.At(i), &s->hdr->recs[i]);
    }
    for (i = 0; i < s->nodes.Size(); i++) {
        SNode* n = &s->nodes.At(i);
        unsigned char p = **(unsigned char**)(n->b + 0xC0);
        if (p != 0xFF)
            SkelNode_AttachParent(n, &s->nodes.At(p));
        else
            SkelNode_AttachParent(n, 0);
    }
    if (s->flag) {
        SArr* a = cSkeleton_GetBoneList(s);
        SNode* n = SkelNodes_GetAt(a, 0);
        for (i = 0; i < cArray_cBone_Size(a); i++) {
            Mtx_InvertRigid_13ECA0(&m, Node_GetTransform(n));
            SkelNode_SetInverseBind(n, &m);
            n++;
        }
    }
    SkelNodes_ApplyScale(s);
}
