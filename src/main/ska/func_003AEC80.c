#include "types.h"

/* Temporary model description built by cSkaAnimAnchorList_ctor_cArrayR. */
typedef struct ModelDesc {
    char header[0x10];
    char first[0x20];
    char second[0x20];
} ModelDesc;

extern void cSkaAnimAnchorList_ctor_cArrayR(ModelDesc* desc);
extern void cArray_cSkaAnimAnchorListEntry_opAssign(void* self, ModelDesc* desc);
extern void cQuatVec_opAssign(void* dst, void* src);
extern void std_vector_deleter_cSkaAnimAnchorListEntry_dtor(ModelDesc* desc, int flags);

/* Initializes a root collection from a temporary model description. */
void cSkaAnimAnchorList_Reset(char* self) {
    ModelDesc desc;
    cSkaAnimAnchorList_ctor_cArrayR(&desc);
    cArray_cSkaAnimAnchorListEntry_opAssign(self, &desc);
    cQuatVec_opAssign(self + 0x10, desc.first);
    cQuatVec_opAssign(self + 0x30, desc.second);
    std_vector_deleter_cSkaAnimAnchorListEntry_dtor(&desc, 0);
}
