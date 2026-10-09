/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern AnimChannel* Model_GetChannelData(ChannelVec*, int);

/* Current value of a channel in the collection at +0x88 (index is not set by the caller-side code). */
float AnimChannel_GetCurrentValue(char* owner) {
    int index;

    return Model_GetChannelData((ChannelVec*)(owner + 136), index)->base.current;
}

/* Current value of channel i in the collection at +0x78. */
float AnimChannel_GetCurrent(char* owner, int i) {
    ChannelVec* v = (ChannelVec*)(owner + 120);

    return ((AnimChannel*)((char*)v->data + (((i << 4) - i) << 2)))->base.current;
}
