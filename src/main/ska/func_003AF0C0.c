#include "types.h"

typedef struct { char b[0x50]; } AnimRegion;
typedef struct { char b[0x10]; } AnimDirty;
typedef struct { char b[0xC]; unsigned char valid; } AnimRelations;
typedef struct {
    AnimRegion a;
    AnimRegion b;
    AnimDirty dirty;
    int unkB0;
    AnimRelations rel;
} AnimRoot;
extern void AnimRoot_CopyRegion(AnimRegion* dst, AnimRegion* src);
extern void AnimRoot_CopyDirtyFlags(AnimDirty* dst, AnimDirty* src);
extern void AnimRoot_InitRelations(AnimRelations* rel);

/* Copies an animation root: both regions and the dirty flags; resets the relations. */
AnimRoot* AnimRoot_Copy(AnimRoot* dst, AnimRoot* src)
{
    AnimRelations* rel;
    AnimRoot_CopyRegion(&dst->a, &src->a);
    AnimRoot_CopyRegion(&dst->b, &src->b);
    AnimRoot_CopyDirtyFlags(&dst->dirty, &src->dirty);
    rel = &dst->rel;
    dst->unkB0 = 0;
    AnimRoot_InitRelations(rel);
    rel->valid = 1;
    return dst;
}
