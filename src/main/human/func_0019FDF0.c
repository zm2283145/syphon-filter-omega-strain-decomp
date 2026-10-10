#include "types.h"

typedef struct VecPair {
    Q a;
    Q b;
} VecPair;

typedef struct RootB0 {
    char pad00[0xB0];
    void* owner; /* 0xB0 */
} RootB0;

extern int func_001A0280(RootB0* root);
extern void* Root_GetWorldPlacement(RootB0* root);
extern void VecPair_Copy(VecPair* dst, void* src);
extern void* Root_GetWorldMotion(RootB0* root);
extern void Vec4_Assign(Q* dst, void* src);
extern void* func_001A0110(RootB0* root);
extern void func_001A0080(RootB0* root);
extern void Root_SetWorldPlacement(RootB0* root, VecPair* placement);
extern void func_0019FFC0(RootB0* root, Q* motion);
extern void func_0019FE90(RootB0* root, VecPair* pair);

/* When owned by owner and dirty, snapshots placement/motion, resets the root and restores them. */
void func_0019FDF0(void* owner, RootB0* root) {
    VecPair saved;
    Q motion;
    VecPair placement;
    if (root->owner == owner && func_001A0280(root)) {
        VecPair_Copy(&placement, Root_GetWorldPlacement(root));
        Vec4_Assign(&motion, Root_GetWorldMotion(root));
        VecPair_Copy(&saved, func_001A0110(root));
        func_001A0080(root);
        Root_SetWorldPlacement(root, &placement);
        func_0019FFC0(root, &motion);
        func_0019FE90(root, &saved);
    }
}
