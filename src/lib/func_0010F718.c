#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { char pad[0x14]; int a; int b; } State;
extern State D_004E2D58;

/* Replaces the (a, b) pair in a global state and returns the previous a. */
int func_0010F718(int a, int b)
{
    int old = D_004E2D58.a;
    D_004E2D58.a = a;
    D_004E2D58.b = b;
    return old;
}
