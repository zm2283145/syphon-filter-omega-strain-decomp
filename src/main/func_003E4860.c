#include "types.h"
/* Convert a 2.14 fixed-point integer to float. */
float Fixed14ToFloat(int value)
{
    return (1.0f / 16384.0f) * (float)value;
}
