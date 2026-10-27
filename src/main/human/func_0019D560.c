#include "types.h"

typedef struct { char pad[0x10]; float value; } AnimTarget;
extern AnimTarget* std_vector_cSkaSliderValue_opIndex(void* curve);

/* Returns the target value (+0x10) of the channel's curve at +0x88. */
float cSkaSystem_GetSliderValue(char* self)
{
    return std_vector_cSkaSliderValue_opIndex(self + 0x88)->value;
}
