#include "types.h"

/* Converts a fixed-point value with 13 fractional bits to float. */
float Fixed13ToFloat(int value) {
    return (1.0f / 8192.0f) * (float)value;
}
