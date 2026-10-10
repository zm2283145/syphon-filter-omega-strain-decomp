#include "types.h"

/* Temporary model description built by RootCollection_Construct. */
typedef struct ModelDesc {
    char header[0x10];
    char first[0x20];
    char second[0x20];
} ModelDesc;

extern void RootCollection_Construct(ModelDesc* desc);
extern void RootCollection_Copy(void* self, ModelDesc* desc);
extern void Transform_SetOrientation(void* dst, void* src);
extern void func_003961E0(ModelDesc* desc, int flags);

/* Initializes a root collection from a temporary model description. */
void RootCollection_InitFromModel(char* self) {
    ModelDesc desc;
    RootCollection_Construct(&desc);
    RootCollection_Copy(self, &desc);
    Transform_SetOrientation(self + 0x10, desc.first);
    Transform_SetOrientation(self + 0x30, desc.second);
    func_003961E0(&desc, 0);
}
