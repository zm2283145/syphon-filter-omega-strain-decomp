/*
 * Matched functions (byte-identical with the retail executable).
 * Vector-argument forwarder.
 */

#include "types.h"
#include "particle_types.h"

extern void func_003A5E30(int a0, int a1, float x, float y, float z);

/* Unpacks the vector v and forwards to func_003A5E30. */
void func_003A5E20(int a0, int a1, float* v) {
    float y = v[1];
    float z = v[2];
    float x = v[0];

    func_003A5E30(a0, a1, x, y, z);
}
