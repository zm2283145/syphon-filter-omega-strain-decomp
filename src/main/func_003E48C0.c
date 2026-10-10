#include "types.h"

/* Converts an unsigned fixed-point value with 15 fractional bits to float. */
float UFixed15ToFloat(unsigned int value) {
    return (1.0f / 32768.0f) * (float)value;
}
