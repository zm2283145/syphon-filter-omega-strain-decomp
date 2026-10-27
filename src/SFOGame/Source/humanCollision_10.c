/*
 * SFOGame/Source/humanCollision: 2 files, 001E1E60-001E1EF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E1E60 */
#pragma push /* merge_units */
#include "types.h"

typedef struct AnimHdr {
    char pad00[3];
    unsigned char version; /* 0x03 */
    char pad04[0x14];
    int dataOffset;        /* 0x18 */
} AnimHdr;

typedef struct AnimRef {
    AnimHdr* hdr;
} AnimRef;

typedef struct AnimOwner {
    int unk00;
    AnimRef* ref; /* 0x04 */
} AnimOwner;

extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(AnimHdr* hdr, int* offset);

/* Returns the address of record `index`; the record size depends on the format version. */
char* cCollisionModel_GetFace(AnimOwner* owner, int index) {
    int offset16;
    int offset32;
    int offset64;
    AnimHdr* hdr = owner->ref->hdr;
    if (hdr->version < 4) {
        offset64 = hdr->dataOffset;
        return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset64) + index * 64;
    } else if (hdr->version < 5) {
        offset32 = hdr->dataOffset;
        return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset32) + index * 32;
    } else {
        offset16 = hdr->dataOffset;
        return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset16) + index * 16;
    }
}
static inline void merge_flush_func_001E1E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1E60 */

/* merge_units: begin func_001E1EF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

int cCollisionModel_FaceLocator_FaceIndex(IntPair* p) {
    return p->a;
}

int cCollisionModel_FaceLocator_ParentModel(IntPair* p) {
    return p->b;
}
static inline void merge_flush_func_001E1EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1EF0 */
