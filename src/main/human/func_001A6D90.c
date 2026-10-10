#include "types.h"

typedef struct VecPair {
    Q a;
    Q b;
} VecPair;

typedef struct RootIdentity {
    char pad00[0x50];
    char orientation[0x50]; /* 0x50 */
    unsigned char dirty;    /* 0xA0 */
} RootIdentity;

extern void Root_BaseConstruct(VecPair* base);
extern RootIdentity* Root_IdentityAccessor(void* root);
extern void Transform_SetOrientation(void* xform, VecPair* base);
extern void Root_PropagateChildren(void* root);

/* Resets the root's local base to identity and propagates it to the children. */
void Root_ResetLocalBase(void* root) {
    VecPair base;
    int one;
    Root_BaseConstruct(&base);
    Transform_SetOrientation(Root_IdentityAccessor(root)->orientation, &base);
    one = 1;
    Root_IdentityAccessor(root)->dirty = one;
    Root_PropagateChildren(root);
}
