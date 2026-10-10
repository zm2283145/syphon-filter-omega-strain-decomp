#include "types.h"

typedef struct { char pad[0x10]; float value; } AnimTarget;
extern AnimTarget* Model_GetChannelData(void* curve);

/* Returns the target value (+0x10) of the channel's curve at +0x88. */
float AnimChannel_GetTarget(char* self)
{
    return Model_GetChannelData(self + 0x88)->value;
}
