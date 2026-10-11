#ifndef ZERO_QUAD_STORE_H
#define ZERO_QUAD_STORE_H
/* Store a zeroed 16-byte value through a stack temporary.
   Use with opt_propagation and opt_common_subs off. */
typedef struct ZeroQuad { int x, y, z, w; } __attribute__((aligned(16))) ZeroQuad;
#define ZERO_QUAD_STORE(name) \
    void name(ZeroQuad* dst) { ZeroQuad t; __int128* zp = (__int128*)&t; *zp = 0; *dst = t; }
#endif