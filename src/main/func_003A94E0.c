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
void cBone_ctor_void(SNode* n);
void std_vector_imp_cBone_resize(SArr* a, unsigned int n, const SNode& fill);
void cBone_dtor(SNode* n, int flag);
void cBone_Init(SNode* n, SRec* r);
void cBone_SetParent(SNode* n, SNode* parent);
SArr* cSkeleton_GetBoneList(SkelNodesT* s);
SNode* cArray_cBone_opIndex_int_2(SArr* a, int i);
int cArray_cBone_Size(SArr* a);
void* cBone_GetMatrix(SNode* n);
void cMatrix_Copy_InvertRotTrans(SMtx* out, void* in);
void cBone_SetMeshSpaceToBoneSpaceMatrix(SNode* n, SMtx* m);
void cSkeleton_SetupBoneScaleMatrices(SkelNodesT* s);
void cSkeleton_CreateBones(SkelNodesT* s);
}

void cSkeleton_CreateBones(SkelNodesT* s)
{
    SNode tmp;
    SMtx m;
    int i;

    cBone_ctor_void(&tmp);
    std_vector_imp_cBone_resize(&s->nodes, s->hdr->count, tmp);
    cBone_dtor(&tmp, -1);
    for (i = 0; i < s->nodes.count; i++) {
        cBone_Init(&s->nodes.At(i), &s->hdr->recs[i]);
    }
    for (i = 0; i < s->nodes.Size(); i++) {
        SNode* n = &s->nodes.At(i);
        unsigned char p = **(unsigned char**)(n->b + 0xC0);
        if (p != 0xFF)
            cBone_SetParent(n, &s->nodes.At(p));
        else
            cBone_SetParent(n, 0);
    }
    if (s->flag) {
        SArr* a = cSkeleton_GetBoneList(s);
        SNode* n = cArray_cBone_opIndex_int_2(a, 0);
        for (i = 0; i < cArray_cBone_Size(a); i++) {
            cMatrix_Copy_InvertRotTrans(&m, cBone_GetMatrix(n));
            cBone_SetMeshSpaceToBoneSpaceMatrix(n, &m);
            n++;
        }
    }
    cSkeleton_SetupBoneScaleMatrices(s);
}
