#include "types.h"
extern void ColQuery_InitTransformed(void* q, float a, float b, float c, float d, float e, float f, float g);
/* Calls ColQuery_InitTransformed with the last two parameters zeroed. */
void ColQuery_InitTransformedThunk(void* q, float a, float b, float c, float d, float e)
{
    ColQuery_InitTransformed(q, a, b, c, d, e, 0.0f, 0.0f);
}
