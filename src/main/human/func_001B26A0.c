#include "types.h"
typedef struct E4Rid {
    char pad00[0x50];
    char orientation[0x50];
    unsigned char dirty;
} E4Rid;
typedef struct { Q a; Q b; } E4Pair;
extern E4Rid* Root_IdentityAccessor(void* root);
extern void* func_001B2830(void* o);
extern void Vec4_Copy(void* dst, void* src);
extern int func_001A0280(void* root);
extern void func_001A7530(E4Pair* m);
extern void* Root_GetParentInverse(void* root, E4Pair* m);
extern void Placement_TransformPointConj(void* p, void* m);
extern void Root_PropagateChildren(void* root);
void Root_PublishPosition(void* root, void* pos)
{
    int one;
    Vec4_Copy(func_001B2830(Root_IdentityAccessor(root)->orientation), pos);
    if (func_001A0280(root)) {
        E4Pair m;
        void* p;
        func_001A7530(&m);
        p = func_001B2830(Root_IdentityAccessor(root)->orientation);
        Placement_TransformPointConj(p, Root_GetParentInverse(root, &m));
    }
    one = 1;
    Root_IdentityAccessor(root)->dirty = one;
    Root_PropagateChildren(root);
}