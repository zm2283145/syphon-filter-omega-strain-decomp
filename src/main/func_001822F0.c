#include "types.h"

/* Two consecutive quadwords (32 bytes). */
typedef struct QPair {
    Q a;
    Q b;
} QPair;

/* Copies a 32-byte pair of quadwords and returns the destination. */
QPair* cBox_opAssign(QPair* dst, QPair* src) {
    *dst = *src;
    return dst;
}
