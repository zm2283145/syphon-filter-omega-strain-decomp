#include "types.h"

typedef struct SkaClip {
    char pad[0x40];
    int grouping;
} SkaClip;

typedef struct GroupingPair {
    SkaClip* clip;
    int grouping;
} GroupingPair;

/* Fills (clip, grouping); clip is NULL unless the clip's grouping is -1. */
void SkaClip_GetGroupingPair(GroupingPair* out, SkaClip* clip) {
    out->clip = clip->grouping == -1 ? clip : 0;
    out->grouping = clip->grouping;
}
